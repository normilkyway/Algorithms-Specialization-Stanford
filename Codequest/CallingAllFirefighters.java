import java.text.CharacterIterator;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class CallingAllFirefighters {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int tt = Integer.parseInt(sc.nextLine().trim());
        while (tt-- > 0) {
            String line = sc.nextLine();
            Scanner ls = new Scanner(line);
            int a = Integer.parseInt(ls.next().trim());
            int b = Integer.parseInt(ls.next().trim());
            int c = Integer.parseInt(ls.next().trim());

            char[][] grid = new char[a][b];
            List<int[]> list = new ArrayList<>();
            int x = 0, y = 0;
            for (int i = 0; i < a; i++) {
                grid[i] = sc.nextLine().toCharArray();
                for (int k = 0; k < grid[i].length; k++)
                    if (grid[i][k] != ' ' && grid[i][k] != '#') {
                        if ((char)grid[i][k] == '0') {
                            x = i; y = k;
                            continue;
                        }
                        int[] toAdd = {i, k, (int)grid[i][k]};
                        list.add(toAdd);
                    }
            }

            List<Character> v = new ArrayList<>();

            for (int i = 0; i < list.size(); i++) {
                int x0 = list.get(i)[0];
                int y0 = list.get(i)[1];
                char val = (char)(list.get(i)[2]);
                // System.out.println("value: " + val);
                // 0 is to the right of our current
                // value therefore we run a bfs to the right
                int dx = (x - x0 > 0 ? 1 : -1);
                int[] dy = {-1, 0, 1};

                Queue<int[]> q = new LinkedList<>();
                q.add(new int[]{x0, y0});

                boolean[][] visited = new boolean[a][b];

                while (!q.isEmpty()) {
                    int[] p = q.poll();
                    // System.out.println(p[0] + " " + p[1]);
                    
                    visited[p[0]][p[1]] = true;

                    if (grid[p[0]][p[1]] == '0') {
                        v.add(val);
                        break;
                    }
                    else {
                        for (int k = 0; k < dy.length; k++) {
                            int xt = x0+dx;
                            int yt = y0+dy[k];
                            if (xt >= 0 && xt < grid.length 
                                        && yt >= 0 
                                        && yt < grid[xt].length 
                                        && grid[xt][yt] != '#' 
                                        && !visited[xt][yt])
                                if (xt == x && yt == y) System.out.println(val);        
                                q.add(new int[]{xt, yt});
                        }
                    }
                }
            }

            if (v.size() == 0)
                System.out.println("No viable locations");
            else {
                for (int coor : v) 
                    System.out.print(coor + " ");
            }
        }
    }
}
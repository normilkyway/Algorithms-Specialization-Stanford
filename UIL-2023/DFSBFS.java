import java.util.*;

public class DFSBFS {
    public static void main(String[] args) {
        char[][] grid1 = makeendlastgrid(40, 40);
        printgrid(grid1);
        dfs(grid1);
        bfs(grid1);

        doublebfs(grid1);
    }

    public static char[][] makerandgrid(int x, int y) {
        char[][] grid = makeendlastgrid(x, y);
        grid[x-1][y-1] = ' ';
        grid[(int)(Math.random()*grid.length)][(int)(Math.random()*grid[0].length)] = 'E';
        return grid;
    }

    public static char[][] makeendlastgrid(int x, int y) {
        char[][] grid = new char[x][y];       
        for (int i = 0; i < grid.length; i++) 
            for (int j = 0; j < grid.length; j++) 
                grid[i][j] = Math.random() > 0.9 ? 'x' : ' ';
        grid[0][0] = 'S';
        grid[x-1][y-1] = 'E';
        return grid;
    } 

    public static void printgrid(char[][] grid) {
        for (char[] row : grid) {
            for (char c : row)
                System.out.print(c + " ");
            System.out.println();
        }
        System.out.println("*".repeat(grid.length*2));
    }


    public static void dfs(char[][] grid) {
        int[] dx = {0,0,-1,1};
        int[] dy = {1, -1, 0, 0};

        Stack<String> stack = new Stack<>();
        stack.push("0|0");

        boolean visitedE = false;

        while (!stack.isEmpty() && !visitedE) {
            String coor = stack.pop();
            int x = pre(coor), y = post(coor);
            if (x >= 0 && x < grid.length && y >= 0 && y < grid.length) {
                if (grid[x][y] == ' ' || grid[x][y] == 'S') {
                    if (grid[x][y] != 'S')
                        grid[x][y] = '.';
                    for (int i = 0; i < 4; i++)
                        stack.push((x+dx[i])+"|"+(y+dy[i])); 
                }
                else if (grid[x][y] == 'E')
                    visitedE = true;
            }
        }
        
        System.out.println((visitedE ? "Successfully" : "Unsuccessfully") + " reached the end.");
        printgrid(grid);
    }

    public static void bfs(char[][] grid) {
        int[] dx = {0,0,-1,1};
        int[] dy = {1, -1, 0, 0};

        Queue<String> queue = new LinkedList<>();
        queue.offer("0|0");

        boolean visitedE = false;

        while(!queue.isEmpty() && !visitedE) {
            String coor = queue.poll();
            int x = pre(coor), y = post(coor);
            if (x >= 0 && x < grid.length && y >= 0 && y < grid.length) {
                if (grid[x][y] == ' ' || grid[x][y] == 'S') {
                    if (grid[x][y] != 'S')
                        grid[x][y] = '.';
                    for (int i = 0; i < 4; i++)
                        queue.offer((x+dx[i])+"|"+(y+dy[i])); 
                }
                else if (grid[x][y] == 'E')
                    visitedE = true;
            }
        }
        
        System.out.println((visitedE ? "Successfully" : "Unsuccessfully") + " reached the end.");
        printgrid(grid);
    }

    public static void doublebfs(char[][] grid) { 
        String coor = (grid.length-1)+"|"+(grid[0].length-1);
        doublebfs(grid, coor);
    }

    public static void doublebfs(char[][] grid, String endcoor) {
        int[] dx = {0,0,-1,1};
        int[] dy = {1, -1, 0, 0};

        Queue<String> qstart = new LinkedList<>(),
        qend = new LinkedList<>();
        
        qstart.offer("0|0");
        qend.offer(endcoor);

        boolean visitedE = false;

        while(!qstart.isEmpty() && !qend.isEmpty() && !visitedE) {
            String coor = qstart.poll();
            int x0 = pre(coor), y0 = post(coor);
            coor = qend.poll();
            int xf = pre(coor), yf = post(coor);

            int[] x = {x0, xf};
            int[] y = {y0, yf};

            for (int i = 0; i < x.length; i++) {
                if (x[i] >= 0 && x[i] < grid.length && y[i] >= 0 && y[i] < grid.length) {
                    if (grid[x[i]][y[i]] == ' ' || grid[x[i]][y[i]] == 'S') {
                        if (grid[x[i]][y[i]] != 'S')
                            grid[x[i]][y[i]] = '.';
                        for (int k = 0; k < 4; k++)
                            qstart.offer((x[i]+dx[k])+"|"+(y[i]+dy[k])); 
                    }
                    else if ((i == 0 && grid[x[i]][y[i]] == 'E') || (i == 1 && grid[x[i]][y[i]] == 'S'))
                        visitedE = true;
                }
            }
        }
        
        System.out.println((visitedE ? "Successfully" : "Unsuccessfully") + " reached the end.");
        printgrid(grid);
    }

    public static int pre(String s) {
        return Integer.parseInt(s.substring(0, s.indexOf("|")));
    }

    public static int post(String s) {
        return Integer.parseInt(s.substring(s.indexOf("|")+1));
    }
}

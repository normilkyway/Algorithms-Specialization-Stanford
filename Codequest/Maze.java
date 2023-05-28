import java.util.*;

public class Maze {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        scanner.nextLine();
        for (int q = t; q > 0; q--) {
            int y = scanner.nextInt();
        int x = scanner.nextInt();
        scanner.nextLine();
        Node start = new Node(-1, -1, -1), end = new Node(-1, -1, -1);
        char[][] maze = new char[(x-1)/3*2 + 1][y];
        for (int i = 0; i < y; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < (x-1)/3*2 + 1; j++) {
                char bob = line.charAt(j);

                if (bob == '+') {
                    maze[j][i] = '+';
                }
                else if (bob == '-' || bob =='|') {
                    maze[j][i] = '+';
                    //j++;
                }
                else if (bob == '^' || bob == '>' || bob == 'v' || bob == '<') {
                    if (i == 0) {
                        if (bob == 'v') {
                            start = new Node(j, i, 0);
                        }
                        if (bob == '^') {
                            end= new Node(j, i, 0);
                        }
                        //j++;
                    }
                    else if (i == y-1) {
                        if (bob == 'v') {
                            end = new Node(j, i, 0);
                        }
                        if (bob == '^') {
                            start = new Node(j, i, 0);
                        }
                       // j++;
                    }

                    else if (j == 0) {
                        if (bob == '>') {
                            start = new Node(j, i, 0);
                        }
                        else {
                            end = new Node(j, i, 0);
                        }
                    }
                    else {
                        if (bob == '>') {
                            end = new Node(j, i, 0);
                        }
                        else {
                            start = new Node(j, i, 0);
                        }
                    }
                }

                else {
                    maze[j][i] = ' ';
                    //j++;
                }
            }
        }

        Queue<Node> solve = new LinkedList<Node>();
        //solve.offer(start); 

        Node current = start;
        System.out.println(end.x + " " + end.y);
        while (!current.equals(end) ) {
            int a = current.x, b = current.y;
            if (b + 1 < y && maze[a][b+1] != '+') {
                solve.offer(new Node(a, b +1, current.size + .5));
                //maze[a][b+1]
            } 
            if (b - 1 >= 0 && maze[a][b+1] != '+') {
                solve.offer(new Node(a, b -1, current.size + .5));
            } 
            if (a - 1 >= 0 && maze[a - 1][b] != '+') {
                solve.offer(new Node(a-1, b , current.size + .5));
            } 
            if (a + 1 < ((x-1)/3*2 + 1) && maze[a+1][b] != '+') {
                solve.offer(new Node(a+1, b, current.size + .5));
            } 

            current = solve.poll();
            //System.out.println(current.size);
        }

        System.out.println((int)(current.size + .5));
        }
    }
}
class Node {
    int x, y;
    double size;
    public Node(int x, int y, double size) {
        this.x = x;
        this.y = y;
        this.size = size;
    }
    @Override
    public boolean equals(Object other) {
        if (other instanceof Node) {
            boolean a = x == ((Node) other).x;
            boolean b = y == ((Node) other).y;
            return a && b;
        }
        else return false;
    }
}
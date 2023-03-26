public class Shreya {
    public static void main(String[] args) {
        
        String[] v1 = "1 2 3 4 5 ".split(" ");
        boolean s1 = solve(new boolean[v1.length], v1, 25, 0);
        System.out.println(s1);

    }

    public static boolean solve(boolean[] used, String[] vals, int target, int current) {
        if (current == target) return true;
        else if (current > target) return false;
        else {
            for (int i = 0; i < used.length; i++) {
                if (!used[i]) {
                    used[i] = true;
                    boolean solved = solve(used, vals, target, current + Integer.parseInt(vals[i]));
                    if (solved) return true;
                    used[i] = false;
                }
            }
            return false;
        }
    }
}
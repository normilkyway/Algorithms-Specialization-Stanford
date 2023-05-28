import java.util.Scanner;
import java.util.StringTokenizer;

public class Bob{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        int[] months = new int[14];
        months[1] = 31;
        months[2] = 28 + months[1];
        months[3] = 31 + months[2];
        months[4] = 30 + months[3];
        months[5] = 31 + months[4];
        months[6] = 30 + months[5];
        months[7] = 31 + months[6];
        months[8] = 31 + months[7];
        months[9] = 30 + months[8];
        months[10] = 31 + months[9];
        months[11] = 30 + months[10];
        months[12] = 31 + months[11];
        months[13] = 31 + months[12];
        for(int i = 0; i < t; i++){
            String str = s.next();
            StringTokenizer st = new StringTokenizer(str, "/");
            String d = st.nextToken();
            String m = st.nextToken();
            int day = Integer.parseInt(d) + 
            months[Integer.parseInt(m)];
            int lastFriday = 5-months[Integer.parseInt(m)+1]%7 + months[Integer.parseInt(m)+1];
            if(lastFriday >= months[Integer.parseInt(m)+1]) lastFriday -= 7;
            if(day > lastFriday){
                lastFriday = 5-months[Integer.parseInt(m)+2]%7 + months[Integer.parseInt(m)+2];
            if(lastFriday >= months[Integer.parseInt(m)+2]) lastFriday -= 7;
                m = Integer.parseInt(m) + 1 + "";
            }
            int forty = 0, nine = 0, a = 0, b = 0;
            while(lastFriday > months[Integer.parseInt(m)]){
                forty += 5;
                nine += 4;
                a += 5;
                b += 5;
                if(lastFriday/7 % 2 == 1) a--;
                else b--;
                lastFriday -= 7;
            }
            System.out.println(forty + " " + nine + " " + a + " " + b);
            }

        }

    }

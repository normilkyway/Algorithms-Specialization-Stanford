import java.io.*;
import java.util.*;

public class Miguel {
    public static void main(String[] args) {
        
        String[] s = {
            "Wow my name is Siddhant",
            "University Drive Brother John",
            "Hola como estats123213 sdasdas 12-123 asdada"
        };

        for (String str : s)
            System.out.println(solve(str));
    }   

    public static String solve(String in) {
        String out = "", choosefrom = "";

        char[] c = in.toCharArray();
        for (char ch : c) {
            if (Character.isAlphabetic(ch))
                choosefrom+=ch;
        }

        char[] b = choosefrom.toLowerCase().toCharArray();
        Arrays.sort(b); // sorted

        int i = 0;
        for (char ch : c) {
            if (Character.isAlphabetic(ch)) {
                if (Character.isUpperCase(ch)) 
                    out += Character.toUpperCase(b[i]);
                else out += b[i];
                i++;
            }
            else out += ch;
        }

        return out;
    }
}

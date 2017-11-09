import java.util.Scanner;
import static java.lang.Math.*;
public class Bishwa {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int ans =0 ;
        String s ;
        s = new String(in.next());
        int l , d, u , r ;
        l = d = u = r =0 ;
        for(int i =0 ; i < s.length();i++){
            if(s.charAt(i) == 'L') l++;
            if(s.charAt(i) == 'R')r++;
            if(s.charAt(i) == 'U') u++;
            if(s.charAt(i) == 'D') d++;

        }
        ans = 2 * min(l, r) + 2 * min(u, d) ;

        System.out.println(ans);
    }
}
;


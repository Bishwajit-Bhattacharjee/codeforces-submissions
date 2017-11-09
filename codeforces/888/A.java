import java.util.Scanner;
public class Bishwa {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] ara = new int[n] ;
        for(int i = 0; i< n; i++){
            ara[i] = in.nextInt();
        }
        int ans = 0;
        for(int i = 1 ; i + 1 < n  ;i++){
            if(ara[i] > ara[i-1] && ara[i] > ara[i+1])
                ans++;
            else if(ara[i] < ara[i-1] && ara[i] < ara[i+1]) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}


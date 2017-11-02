import java.util.Scanner;

public class Bishwa {
    public static void main(String args[]){
        Scanner input = new Scanner(System.in) ;
        int n = input.nextInt() ;
        int m = input.nextInt() ;
        int ara[] = new int[15] ;
        int ara1[] = new int[15] ;
        int f1[] = new int[15]  ; int f2[] = new int[15];
        for(int i = 0 ; i < n; i++){
            ara[i] = input.nextInt();
            f1[ara[i]] = 1 ;
        }
        for(int i = 0; i < m ;i++){
            ara1[i] = input.nextInt() ;
            f2[ara1[i]] = 1;
        }
        int ans = 10000;
        for(int i = 0 ; i < n; i++){
            if(f2[ara[i]] == 1 ){
                ans = Math.min(ans , ara[i]) ;
            }
        }
        for(int i = 0 ; i < m ;i++)
            if(f1[ara1[i]] == 1 ){
            ans = Math.min(ans , ara1[i]);
            }
        for(int i =0 ; i < n; i++){
            for(int j= 0 ; j < m ; j++){
                ans = Math.min(ans , Math.min(ara[i]+ ara1[j]* 10 , ara1[j] + ara[i]* 10 )) ;
            }
        }
        System.out.println(ans);
    }

}

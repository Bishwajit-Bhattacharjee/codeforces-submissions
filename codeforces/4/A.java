import java.util.Scanner;

public class Bishwa {
    public static void main(String args[]){
        Scanner input = new Scanner(System.in) ;
        int n = input.nextInt() ;
        System.out.println(n % 2 == 0 && n != 2 ?"YES":"NO");
    }

}

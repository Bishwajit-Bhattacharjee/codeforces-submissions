import java.util.Scanner;
public class Bishwa {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        String str1 = new String() ;
        str1 = input.nextLine();
        //String str1 = new String();
        str1 = str1.toLowerCase();
        char[] tmp = new char[str1.length()] ;
        tmp = str1.toCharArray();

        for(char ch : tmp){
            if(ch == 'a'|| ch == 'e'||ch == 'i'
                    || ch == 'o' || ch == 'u'||ch == 'y')
                continue;
            else {
                System.out.printf(".%c",ch);
            }
        }

    }


}


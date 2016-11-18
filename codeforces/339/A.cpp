#include <stdio.h>
#include <string.h>

int main()
{
    char str[110];// str2[110];

    gets(str);
    //gets(str2);
    int length1 = strlen(str);
   // int length2 = strlen(str2);
    int c1= 0, c2 = 0 , c3 = 0;
    for(int i =0; i < length1; i++)
    {
        if(str[i] == '1')c1++;
        else if(str[i] == '2')c2++;
        else if(str[i] == '3')c3++;
    }
    int p_c = 0;int sum = c1 + c2 + c3;

    while(c1--)
    {
        printf("1");
        p_c++;
        if(p_c < sum)
            printf("+");
    }

    while(c2--)
    {
        printf("2");
        p_c++;
        if(p_c < sum)
            printf("+");
    }

    while(c3--)
    {
        printf("3");
        p_c++;
        if(p_c < sum)
            printf("+");
    }


    return 0;
}

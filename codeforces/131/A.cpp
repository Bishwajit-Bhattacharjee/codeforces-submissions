#include <stdio.h>
#include <string.h>

int main()
{
    char str[110];
    int count = 0;
    int len,i;
    gets(str);
    len = strlen(str);
    for(i=1;i<len;i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
            count++;
    }
    if(count == len-1 || len == 1)
    {
        for(i=0;i<len;i++){


                if(str[i]>='a'&&str[i]<='z')
                    str[i] = str[i] -'a' + 'A';
                else
                    str[i] = str[i] -'A' + 'a';
        }
    }
    puts(str);
    return 0;
}





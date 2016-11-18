#include <stdio.h>
#include <string.h>

int main()
{
    int a,b, n, length, count;
    char str[110], buf[6];
    scanf("%d", &n);
    gets(buf);
    while(n--)
    {
        gets(str);
        length = strlen(str);
        if(length < 11)
            printf("%s\n", str);
        else
        {
           printf("%c%d%c\n", str[0], length-2, str[length - 1]);
        }

    }
    return 0;
}

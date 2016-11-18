#include <stdio.h>
#include <string.h>

int main()
{
    char str[110];
    gets(str);
    int length = strlen(str);
    for(int i =0; i < length; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
    }
    for(int i = 0;i < length; i++)
    {
        if(str[i] == 'a'||str[i] == 'e'||str[i] == 'i'||str[i] == 'o'||str[i] == 'u'||str[i] == 'y')
            continue;
        else
        {
            printf(".%c", str[i]);
        }
    }
    printf("\n");
    //puts(str);
    return 0;
}

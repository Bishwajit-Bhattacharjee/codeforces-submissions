#include <stdio.h>
#include <string.h>

int main()
{
    char str1[110], str2[110];

    gets(str1);
    gets(str2);
    int length1 = strlen(str1);
   // int length2 = strlen(str2);

    for(int i =0; i < length1; i++)
    {
        if(str1[i] >= 'A' && str1[i] <= 'Z')
            str1[i] = str1[i] - 'A' + 'a';
    }

    for(int i =0; i < length1; i++)
    {
        if(str2[i] >= 'A' && str2[i] <= 'Z')
            str2[i] = str2[i] - 'A' + 'a';
    }
    int flag = 0;
    int count = 0;
    for(int i = 0; i < length1; i++)
    {
        if(str1[i] > str2[i])
        {
            flag = 1;
            break;
        }
        else if(str1[i] < str2[i])
        {
            flag = -1;
            break;
        }
        else
            count++;
    }
    if(count == length1)
        printf("0\n");
    else
        printf("%d\n", flag);

    //puts(str);
    return 0;
}

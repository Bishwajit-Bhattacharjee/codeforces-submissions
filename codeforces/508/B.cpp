#include <bits/stdc++.h>

#define char_to_num(ch) (ch-'0')
using namespace std;
int main()
{
    char str[100005], temp;
    gets(str);
    bool flag = false;
    int len = strlen(str), cur;
    char ch = str[len - 1];
    int last = char_to_num(ch);
    for(int i = 0; i < (len - 1); i++)
    {
        cur = char_to_num(str[i]);
        if(last > cur && cur % 2 == 0)
        {
            temp = str[len - 1];
            str[len - 1] = str[i];
            str[i] = temp;
            flag = true;
            break;

        }
    }
    if(!flag)
    {
        for(int i = len - 2; i >= 0 ; i--)
        {
            cur = char_to_num(str[i]);
            if(last < cur && cur % 2 == 0)
            {
            temp = str[len - 1];
            str[len - 1] = str[i];
            str[i] = temp;
            flag = true;
            break;
            }
        }
    }
    if(flag)
        puts(str);
    else
        printf("-1\n");



	return 0;
}

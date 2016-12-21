#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

//map <string, string> a;

int main()
 {
    char str1[110], str2[110];
    int cnt[27] = {0};
    bool sau;
    gets(str1);
    gets(str2);
    loop(i, 0, strlen(str1)-1)
    {
        cnt[str1[i]-'a']++;
    }
    loop(i, 0, strlen(str2)-1)
      cnt[str2[i]-'a']--;
    bool n_t = false;
    bool array = false;
    int count = 0;
    loop(i, 0, 25)
    {
        if(cnt[i] < 0)
        {
            n_t = true;
            break;
        }
        else if(!cnt[i])
            count++;
    }
    if(count == 26)
        array = true;
    bool a_m = false;
    int f_i, j;
    if(!n_t)
    {


            loop(i,0, strlen(str1)-1)
            {
                if(str1[i] == str2[0])
                {
                    f_i = i;
                    break;
                }
            }

            int m = strlen(str2);
            sau = false;
    for(int i=0,j=0; i<strlen(str1); ++i){
        if(j<m && str1[i]==str2[j]) ++j;
        if(j==m) sau = true;
    }
    }

    if(n_t)
        printf("need tree\n");
    else if(array)
        printf("array\n");
    else if(sau)
        printf("automaton\n");
    else
        printf("both\n");
    return 0;
}


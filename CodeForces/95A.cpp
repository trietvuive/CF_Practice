#include<cstdio>
#include<cstring>
#include<ctype.h>
bool v[105];
char s1[105], s2[105], t[100][105], w[5];
int main()
{
    int i, j, k, n;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", t[i]);
        for (j = 0; t[i][j]; j++)
            t[i][j] = tolower(t[i][j]);
    }
    scanf("%s%s", s1, w);
    w[1] = w[0] == 'a' ? 'b' : 'a';
    for (i = 0; s1[i]; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; t[j][k]; k++)
            {
                if (tolower(s1[i + k]) != t[j][k])
                    break;
            }
            if (t[j][k])continue;
            for (k = 0; t[j][k]; k++)
                v[i + k] = 1;
        }
    }
    for (i = 0; s1[i]; i++)
    {
        if (v[i])if (tolower(s1[i]) == w[0])s2[i] = w[1]; else s2[i] = w[0]; else s2[i] = s1[i];
        if (isupper(s1[i]))s2[i] = toupper(s2[i]);
    }
    printf("%s\n", s2);
}
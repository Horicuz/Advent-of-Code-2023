#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compare(char c1[1002][13], int i, int j, int frecv[1002][5], int k)
{

    if (frecv[i][0] > frecv[j][0])
        return 1;
    else if (frecv[i][0] < frecv[j][0])
        return 2;
    else
    {

        for (int p = 0; p < k; p++)
        {

            if (c1[i][p] != c1[j][p])
            {
                if ((c1[i][p] - '0') > (c1[j][p] - '0') && isdigit(c1[i][p]) && isdigit(c1[j][p]))
                    return 1;
                else if ((c1[i][p] - '0') < (c1[j][p] - '0') && isdigit(c1[i][p]) && isdigit(c1[j][p]))
                    return 2;
                else if (isdigit(c1[i][p]) && !isdigit(c1[j][p]))
                    return 2;
                else if (!isdigit(c1[i][p]) && isdigit(c1[j][p]))
                    return 1;
                else if (!isdigit(c1[i][p]) && !isdigit(c1[j][p]))
                {

                    if (c1[i][p] == 'A')
                        return 1;
                    if (c1[j][p] == 'A')
                        return 2;
                    if (c1[i][p] == 'K')
                        return 1;
                    if (c1[j][p] == 'K')
                        return 2;
                    if (c1[i][p] == 'Q')
                        return 1;
                    if (c1[j][p] == 'Q')
                        return 2;
                    if (c1[i][p] == 'J')
                        return 1;
                    if (c1[j][p] == 'J')
                        return 2;
                    if (c1[i][p] == 'T')
                        return 1;
                    if (c1[j][p] == 'T')
                        return 2;
                }
            }
        }
    }

    return 1;
}

int main()
{
    char s[13];
    int bids[1002];
    char c[1002][13];
    int frecv[1002][5];

    int p = 0;
    do
    {
        if (strlen(s) < 3)
            break;
        fgets(s, 13, stdin);
        for (int k = 0; k < 5; k++)
        {
            frecv[p][k] = 1;
        }

        for (int j = 0; j < 5; j++)
        {
            c[p][j] = s[j];
        }
        for (int j = 0; j < 5; j++)
        {
            for (int g = 0; g < 5; g++)
            {
                if (c[p][j] == c[p][g] && j != g)
                {
                    frecv[p][j]++;
                }
            }
        }
        printf("%d\n", frecv[p][0]);
        int ok3 = 0, ok2 = 0, cnt = 0, ok4 = 0, ok5 = 0;
        for (int j = 0; j < 5; j++)
        {
             printf("%d\n", frecv[p][j]);
            if (frecv[p][j] == 5)
            {
                frecv[p][0] = 7;
                ok5 = 1;
                break;
            }
            if (frecv[p][j] == 4)
            {
                frecv[p][0] = 6;
                ok4 = 1;
                break;
            }
            if (frecv[p][j] == 3)
            {
                ok3 = 1;
            }
            else if (frecv[p][j] == 2)
            {
                ok2 = 1;
                cnt++;
            }
            if (ok3 == 1 && ok2 == 1)
            {
                frecv[p][0] = 5;
                break;
            }
        }
        if (ok5 == 0 && ok4 == 0)
        {
            if (ok3 == 1)
            {
                if (ok2 == 1)
                {
                    frecv[p][0] = 5;
                }
                else
                {
                    frecv[p][0] = 4;
                }
            }
            else if (ok2 == 1)
            {
                if (cnt == 4)
                {
                    frecv[p][0] = 3;
                }
                else
                {
                    frecv[p][0] = 2;
                }
            }
            else
            {
                frecv[p][0] = 1;
            }
        }

        bids[p] = s[6] - '0';
        if (strlen(s) > 8)
        {
            bids[p] = bids[p] * 10 + s[7] - '0';
        }
        if (strlen(s) > 9)
        {
            bids[p] = bids[p] * 10 + s[8] - '0';
        }
        if (strlen(s) > 10)
        {
            bids[p] = bids[p] * 10 + s[9] - '0';
        }

        p++;

    } while (strlen(s) > 3);

    p--;
    for (int i = 0; i < p; i++)
    {
        for (int j = i + 1; j < p; j++)
        {
            if (compare(c, i, j, frecv, p) == 1)
            {
                char aux[11];
                strcpy(aux, c[i]);
                strcpy(c[i], c[j]);
                strcpy(c[j], aux);

                int aux1 = frecv[i][0];
                frecv[i][0] = frecv[j][0];
                frecv[j][0] = aux1;

                int aux2 = bids[i];
                bids[i] = bids[j];
                bids[j] = aux2;
            }
        }
    }


    printf("%d\n", p);
    for (int i = 0; i < p; i++)
    {
        printf("%d\n", bids[i]);
        printf("%d\n", frecv[i][0]);
    }
    unsigned int sum = 0;
    for (int i = 0; i < p; i++)
    {
        sum = sum + bids[i] * (i + 1);
    }
    printf("%u", sum);

    return 0;
}
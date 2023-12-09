#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compare(char c1[1002][13], int i, int j, int frecv[1002][5])
{

    if (frecv[i][0] > frecv[j][0])
        return 1;
    else if (frecv[i][0] < frecv[j][0])
        return 2;
    else
    {
        char auxiliarul_masii1[5];
        char auxiliarul_masii2[5];

        for (int p = 0; p < 5; p++)
        {
            if (c1[i][p] != c1[j][p])
            {
                if (c1[i][p] == 'T')
                {
                    auxiliarul_masii1[p] = 'A';
                }
                else if (c1[i][p] == 'J')
                {
                    auxiliarul_masii1[p] = '1';
                }
                else if (c1[i][p] == 'Q')
                {
                    auxiliarul_masii1[p] = 'B';
                }
                else if (c1[i][p] == 'K')
                {
                    auxiliarul_masii1[p] = 'C';
                }
                else if (c1[i][p] == 'A')
                {
                    auxiliarul_masii1[p] = 'D';
                }
                else
                {
                    auxiliarul_masii1[p] = c1[i][p];
                }

                if (c1[j][p] == 'T')
                {
                    auxiliarul_masii2[p] = 'A';
                }
                else if (c1[j][p] == 'J')
                {
                    auxiliarul_masii2[p] = '1';
                }
                else if (c1[j][p] == 'Q')
                {
                    auxiliarul_masii2[p] = 'B';
                }
                else if (c1[j][p] == 'K')
                {
                    auxiliarul_masii2[p] = 'C';
                }
                else if (c1[j][p] == 'A')
                {
                    auxiliarul_masii2[p] = 'D';
                }
                else
                {
                    auxiliarul_masii2[p] = c1[j][p];
                }

                if (auxiliarul_masii1[p] > auxiliarul_masii2[p])
                {
                    return 1;
                }
                else if (auxiliarul_masii1[p] < auxiliarul_masii2[p])
                    return 2;
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

        int ok3 = 0, ok2 = 0, cnt = 0, ok4 = 0, ok5 = 0;
        for (int j = 0; j < 5; j++)
        {
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
        printf("%d\n", frecv[p][0]);
        for (int j = 0; j < 5; j++)
        {
            printf("tee C ESTE %c\n", c[p][j]);
            if (c[p][j] == 'J')
            {
                printf("LA NOI C ESTE %c\n", c[p][j]);
                if (frecv[p][0] == 1)
                {
                    frecv[p][0] = 2;
                    break;
                }
                else if (frecv[p][0] == 2)
                {
                    frecv[p][0] = 4;
                    break;
                }
                else if (frecv[p][0] == 3)
                {
                    for (int m = j + 1; m < 5; m++)
                    {
                        printf("LA VoI C ESTE %c\n", c[p][m]);
                        if (c[p][m] == 'J')
                        {
                            frecv[p][0] = 6;
                            j = 6;
                            break;
                        }
                    }
                    if (j < 6)
                    {
                        frecv[p][0] = 5;
                        break;
                    }
                }
                else if (frecv[p][0] == 4)
                {
                    frecv[p][0] = 6;
                    break;
                }
                else if (frecv[p][0] == 5)
                {
                    frecv[p][0] = 7;
                    break;
                }
                else if (frecv[p][0] == 6)
                {
                    frecv[p][0] = 7;
                    break;
                }
            }
        }
        printf("%d\n", frecv[p][0]);
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
            if (compare(c, i, j, frecv) == 1)
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
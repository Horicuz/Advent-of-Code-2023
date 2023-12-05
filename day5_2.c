#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void number_creation(char s[], int *j, unsigned int *n1)
{
    *n1 = 0;
    if (isdigit(s[*j]) != 0)
    {
        while (isdigit(s[*j]) != 0)
        {
            (*n1) = (*n1) * 10 + (s[*j] - '0');
            (*j)++;
        }
        (*j)++;
    }
}

FILE *f;

int main()
{
    unsigned int seed[100][2];

    int m = 0;
    char s[500];
    fgets(s, 500, stdin);

    unsigned int n1, n2;
    for (int i = 7; i < strlen(s); i++)
    {
        n1 = 0;
        n2 = 0;
        number_creation(s, &i, &n1);
        number_creation(s, &i, &n2);
        i--;

        seed[m][0] = n1;
        seed[m][1] = n2;
        m++;
    }

    char c[1000][1000];
    getchar();

    int linii = 0;
    int l = 0;

    int sec[10];
    do
    {

        fgets(c[linii], 1000, stdin);
        printf("L is %d\n", l);

        if (isdigit(c[linii][0]) == 0)
        {
            if (c[linii][0] == '\n')
            {
                l++;
                if (l == 7)
                    break;
                printf("IT'S AN EMPTY ROW\n");
            }
            else
            {
                sec[l] = linii;
                printf("IT'S A NAME ROW\n");
            }
        }
        else
        {
            printf("IT'S A ROW WITH NUMBERS\n");
        }
        linii++;

    } while (linii < 1000);

    
    int ok = 1;
    unsigned int beg = 0, end = 0, ratio = 0;
    unsigned int magicianul;
    int linpoz;
    int superok = 1;
    for (magicianul = 69841001; magicianul <= 698418034; magicianul= magicianul + 1)
    {   
        printf("MAGICIANUL ESTE: %u\n", magicianul);
        unsigned int magician_false = magicianul; 
        superok = 1;
        for (int i = 6; i >= 0; i--)
        {
            linpoz = sec[i] + 1;
            do
            {
                if (c[linpoz][0] == '\n')
                    break;
                beg = 0;
                end = 0;
                ratio = 0;
                int hopa = 0;

                number_creation(c[linpoz], &hopa, &beg);
               
                number_creation(c[linpoz], &hopa, &end);
                
                number_creation(c[linpoz], &hopa, &ratio);
                
                
                if (magician_false >= beg && magician_false<= beg + ratio)
                {
                    unsigned int dif = magician_false - beg;
                    magician_false = end + dif;
                    superok = 0;
                    break;
                }
                linpoz++;

            } while (1);
        }
        if (superok == 0)
        {
            for (int i = 0; i < m; i++)
            {
                if (seed[i][0] <= magician_false && magician_false <= seed[i][0] + seed[i][1])
                    {   
                        printf("MAGICIANUL ADV ESTE: %u ", magicianul);
                        ok = 0;
                        i = m;
                        break;
                            
                    }
            }
            if (ok == 0)
                break;
        }

        
    }

    return 0;
}
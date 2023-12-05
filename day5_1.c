#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void number_creation(char s[], int *j, unsigned int *n1)
{   
    *n1 = 0;
    if(isdigit(s[*j]) != 0)
                {     
                    while(isdigit(s[*j]) != 0)
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
    unsigned int seed[100];
    unsigned int seedv[100];

    int m = 0;
    f = fopen("junior.txt", "r");

    char s[500];
    fgets(s, 500, stdin);

    unsigned int n1;
    for(int i = 7;i<strlen(s);i++)
    {   
        n1 = 0;
        number_creation(s, &i, &n1);
        i--;
        if(n1)
        {
            seed[m] = n1;
            seedv[m] = 0;
            m++;
        }
    }
    char c[100];
    char degeaba[100];
    getchar();
    for(int i = 1;i<=7;i++)
    {
        for(int i = 0;i<m;i++)
            {   
                printf("%u ", seed[i]);
                seedv[i] = 0;
            }
        fgets(degeaba, 100, stdin);
        do
        {  
            int beg =0 , end = 0, ratio = 0;

            fgets(c, 100, stdin);
            if(c[0] == '\n')
                break;

            int j = 0;   
            number_creation(c, &j, &beg);
            number_creation(c, &j, &end);
            number_creation(c, &j, &ratio);
            
            for(int k = 0;k<m;k++)
            {
                if(seed[k] >= end && seed[k] <= end + ratio && seedv[k] == 0)
                {
                    int dif = seed[k] - end;
                    seed[k] = beg + dif;
                    seedv[k] = 1;
                }
            }
           

        }while(1);
    }

    for(int i = 0;i<m;i++)
        printf("%u ", seed[i]);
    printf("\n");
    unsigned int min = seed[0];
    for(int i = 1;i<m;i++)
       {
              if(seed[i] < min)
                 min = seed[i];
       }
    printf("%u\n", min);
    fclose(f);
    return 0;
}
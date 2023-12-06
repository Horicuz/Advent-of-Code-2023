#include <stdio.h>
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

int main()
{

    int timp[10];
    int distanta[10];
    char s[200];

    int prod = 1;

    int n1;
    int m = 0;
    int n = 0;

    fgets(s, 200, stdin);

    for (int i = 11; i < strlen(s); i++)
    {
        n1 = 0;
        number_creation(s, &i, &n1);
        if (n1)
        {
            timp[m] = n1;
            m++;
        }
    }

    fgets(s, 200, stdin);

    for (int i = 11; i < strlen(s); i++)
    {
        n1 = 0;
        number_creation(s, &i, &n1);
        if (n1)
        {
            distanta[n] = n1;
            n++;
        }
    }
    int cnt;
    int dist = 0; 
    for (int i = 0; i < m; i++)
    {
        cnt = 0;
        for (int j = 0; j <= timp[i]; j++)
        {  
            dist = j * (timp[i] - j);
            if(dist > distanta[i])
                cnt++;
            
        }
        prod = prod*cnt;
    }

    printf("%d", prod);
    return 0;
}
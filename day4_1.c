#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *f;    


int pow_2(int n)
{
    if(n == 0)
        return 1;
    else
        return 2 * pow_2(n - 1);
}


int main()
{
    int n1;
    int k = 0;
    int puncte;
    f = fopen("text.txt", "r");
    char s[1000];
    int sum = 0;

    for (int i = 1; i <= 218;i++)
    {   
        int vector[10];
        k = 0;
        puncte = 0;
        fgets(s, 1000, f);
        for (int j = 10; j < 39;j++)
        {
            
            
            n1 = 0;
            if(isdigit(s[j]) != 0)
                {   
                    while(isdigit(s[j]) != 0)
                    {
                        n1 = n1 * 10 + (s[j] - '0');
                        j++;    
                    }
                    
                    vector[k++] = n1;
                }
        }
        for (int j = 42; j < strlen(s);j++)
        {   
            n1 = 0;
            if(isdigit(s[j]) != 0)
                {     
                    while(isdigit(s[j]) != 0)
                    {
                        n1 = n1 * 10 + (s[j] - '0');
                        j++;    
                    }
                    for (int l = 0; l < k;l++)
                    {
                        if(vector[l] == n1)
                            puncte++;
                    }    
                }     
        }
        if (puncte != 0)
                sum = sum + pow_2(puncte - 1);
    }
    printf("%d", sum);
    return 0;
}

#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    int sum = 0;
    
    do
    {
        gets(s);

        if(strcmp(s,"")==0)
            break;

        int n1 = -1,n2;
        int n3;
        for(int i = 0;i<strlen(s);i++)
        {
            if(isdigit(s[i]) == 1)
                {
                    if(n1 == -1)
                    {
                        n1 = s[i] - '0';
                    }
                    n2 = s[i] - '0'; 
                }   
        }
        n3 = n1*10 + n2;
        sum = sum + n3;

    }while(strcmp(s,"")!=0);
    
    printf("%d\n",sum);

    return 0;


}
#include <stdio.h>
#include <string.h>

int is_one(char s[], int i)
{
    if(s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e')
        return 1;
    else
        return 0;
}

int is_two(char s[], int i)
{
    if(s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o')
        return 1;
    else
        return 0;
}

int is_three(char s[], int i)
{
    if(s[i] == 't' && s[i+1] == 'h' && s[i+2] == 'r' && s[i+3] == 'e' && s[i+4] == 'e')
        return 1;
    else
        return 0;
}

int is_four(char s[], int i)
{
    if(s[i] == 'f' && s[i+1] == 'o' && s[i+2] == 'u' && s[i+3] == 'r')
        return 1;
    else
        return 0;
}
int is_five(char s[], int i)
{
    if(s[i] == 'f' && s[i+1] == 'i' && s[i+2] == 'v' && s[i+3] == 'e')
        return 1;
    else
        return 0;
}

int is_six(char s[], int i)
{
    if(s[i] == 's' && s[i+1] == 'i' && s[i+2] == 'x')
        return 1;
    else
        return 0;
}

int is_seven(char s[], int i)
{
    if(s[i] == 's' && s[i+1] == 'e' && s[i+2] == 'v' && s[i+3] == 'e' && s[i+4] == 'n')
        return 1;
    else
        return 0;
}

int is_eight(char s[], int i)
{
    if(s[i] == 'e' && s[i+1] == 'i' && s[i+2] == 'g' && s[i+3] == 'h' && s[i+4] == 't')
        return 1;
    else
        return 0;
}

int is_nine(char s[], int i)
{
    if(s[i] == 'n' && s[i+1] == 'i' && s[i+2] == 'n' && s[i+3] == 'e')
        return 1;
    else
        return 0;
}

int main()
{
    char s[1000];
    int sum = 0;
    
    do
    {
        gets(s);
        if(strcmp(s,"") == 0)
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
            else 
            {
                if(is_one(s,i) == 1)
                {
                    if(n1 == -1)
                    {
                        n1 = 1;
                    }
                    n2 = 1;
                }
                else if(is_two(s,i) == 1)
                {
                    if(n1 == -1)
                    {
                        n1 = 2;
                    }
                    n2 = 2;
                }
                else if(is_three(s,i) == 1)
                {
                    if(n1 == -1)
                    {
                        n1 = 3;
                    }
                    n2 = 3;
                }
                else if(is_four(s,i) == 1)
                {
                    if(n1 == -1)
                    {
                        n1 = 4;
                    }
                    n2 = 4;
                }
                else if(is_five(s,i) == 1)
                {
                    if(n1 == -1)
                    {
                        n1 = 5;
                    }
                    n2 = 5;
                }
                else if(is_six(s,i) == 1)
                {
                    if(n1 == -1)
                    {
                        n1 = 6;
                    }
                    n2 = 6;
                }
                else if(is_seven(s,i) == 1)
                {
                    if(n1 == -1)
                    {
                        n1 = 7;
                    }
                    n2 = 7;
                }
                else if(is_eight(s,i) == 1)
                {
                    if(n1 == -1)
                    {
                        n1 = 8;
                    }
                    n2 = 8;
                }
                else if(is_nine(s,i) == 1)
                {
                    if(n1 == -1)
                    {
                        n1 = 9;
                    }
                    n2 = 9;
                }
            } 
        }
        n3 = n1*10 + n2;
        printf("  %d  ",n3);
        sum = sum + n3;

    }while(strcmp(s,"")!=0);
    
    printf("%d\n",sum);

    return 0;


}
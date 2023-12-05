#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{  
    long int sum = 0;
    char s1[10000],s2[10000],s3[10000], s4[10000];
    int length1 = 0,length2 = 0;
    int n1 = 0,n2 = 0;

    gets(s1);
    gets(s2);
    gets(s3);

    for(int i = 0;i<strlen(s1);i++)
    {   
        n1 = 0;
        n2 = 0;
        length1 = 0;
        length2 = 0;
        int ko1 = 0, ko2 = 0;
        if(s1[i] == '*')
        {  
            int ok = 0;
            if(isdigit(s1[i-1]) != 0)
            {   
                
                printf("Are o cifra in stanga mijloc\n");
                if(isdigit(s1[i-2])!=0)
                {   
                    printf("Are doua cifre in stanga mijloc spre stanga\n");
                    if(isdigit(s1[i-3])!=0)
                    {   
                        printf("Are trei cifre in stanga mij;oc spre stanga\n");
                        n1 = 100*(s1[i-3] - '0') + 10*(s1[i-2] - '0') + (s1[i-1] - '0');
                        ok++;
                        length1 = 3;
                    }
                    else
                    {
                        n1 = 10*(s1[i-2] - '0') + (s1[i-1] - '0');
                        ok++;
                        length1 = 2;
                    }
                }
                else
                {
                    if(n1 == 0)
                    {n1 = (s1[i-1] - '0');
                    ok++;
                    length1 = 1;}
                    else
                    {
                        n2 = (s1[i-1] - '0');
                        ok++;
                        length2 = 1;
                    }
                }
            }
            if(isdigit(s1[i+1]) != 0)
            {   
                printf("Are o cifra in dreapta mijloc\n");
                if(isdigit(s1[i+2])!=0)
                {   
                    printf("Are doua cifre in dreapta mijloc spre dreapta\n");
                    if(isdigit(s1[i+3])!=0)
                    {
                        printf("Are trei cifre in dreapta mijloc spre dreapta\n");
                        if(n1 != 0)
                        {
                            n2 = 100*(s1[i+1] - '0') + 10*(s1[i+2] - '0') + (s1[i+3] - '0');
                            ok++;
                            length2 = 3;
                        }
                        else
                        {
                            n1 = 100*(s1[i+1] - '0') + 10*(s1[i+2] - '0') + (s1[i+3] - '0');
                            ok++;
                            length1 = 3;
                        }
                    }
                    else
                    {
                        if(n1 != 0)
                        {
                            n2 = 10*(s1[i+1] - '0') + (s1[i+2] - '0');
                            ok++;
                            length2 = 2;
                        }
                        else
                        {
                            n1 = 10*(s1[i+1] - '0') + (s1[i+2] - '0');
                            ok++;
                            length1 = 2;
                        }
                    }
                }
                else
                {
                    if(n1 != 0)
                    {
                        n2 = (s1[i+1] - '0');
                        length2 = 1;
                    }
                    else
                    {
                        n1 = (s1[i+1] - '0');
                        length1 = 1;
                    }
                }
            }
                
            if(isdigit(s2[i-1]) != 0)
                   {     
                        ko1 = 1;
                        printf("Are o cifra in stanga jos spre stanga\n");
                        if(isdigit(s2[i-2])!=0)
                        {   
                            printf("Are doua cifre in stanga jos spre stanga\n");
                            if(isdigit(s2[i-3])!=0)
                            {   
                                printf("Are trei cifre in stanga jos spre stanga\n");
                                if(n1!=0)
                                {
                                    n2 = 100*(s2[i-3] - '0') + 10*(s2[i-2] - '0') + (s2[i-1] - '0');
                                    ok++;
                                    length2 = 3;
                                }
                                else
                                {
                                    n1 = 100*(s2[i-3] - '0') + 10*(s2[i-2] - '0') + (s2[i-1] - '0');
                                    ok++;
                                    length1 = 3;
                                }
                                
                            }
                            else if(isdigit(s2[i])!=0)
                            {
                                ko2 = 1;
                                printf("Are 3 stanga jos pe mijloc\n");
                                if(n1!=0)
                                {
                                    n2 = 100*(s2[i-2] - '0') + 10*(s2[i-1] - '0') + (s2[i] - '0');
                                    ok++;
                                    length2 = 3;
                                }
                                else
                                {
                                    n1 = 100*(s2[i-2] - '0') + 10*(s2[i-1] - '0') + (s2[i] - '0');
                                    ok++;
                                    length1 = 3;
                                }
                            }
                            else
                            {
                                
                                if(n1 == 0)
                                {
                                    n1 = 10*(s2[i-2] - '0') + (s2[i-1] - '0');
                                    ok++;
                                    length1 = 2;
                                }
                                else
                                {
                                    n2 = 10*(s2[i-2] - '0') + (s2[i-1] - '0');
                                    ok++;
                                    length2 = 2;
                                }
                            }
                        }
                        else if(isdigit(s2[i])!=0)
                        {   
                            ko2 = 1;
                            printf("Are doua cifre in stanga jos spre dreapta\n");
                            if(isdigit(s2[i+1])!=0)
                            {
                                printf("Are 3 cifre in stanga jos spre dreapta\n");
                                if(n1!=0)
                                {
                                    n2 = 100*(s2[i-1] - '0') + 10*(s2[i] - '0') + (s2[i+1] - '0');
                                    ok++;
                                    length2 = 3;
                                }
                                else
                                {
                                    n1 = 100*(s2[i-1] - '0') + 10*(s2[i] - '0') + (s2[i+1] - '0');
                                    ok++;
                                    length1 = 3;
                                }
                            }
                            else
                            {
                                if(n1!=0)
                                {
                                    n2 = 10*(s2[i-1] - '0') + (s2[i] - '0');
                                    ok++;
                                    length2 = 2;
                                }
                                else
                                {
                                    n1 = 10*(s2[i-1] - '0') + (s2[i] - '0');
                                    ok++;
                                    length1 = 2;
                                }
                            }
                        }
                        else
                        {
                            if(n1 == 0)
                            {n1 = (s2[i-1] - '0');
                            ok++;
                            length1 = 1;}
                            else
                            {
                                n2 = (s2[i-1] - '0');
                                ok++;
                                length2 = 1;
                            }
                        }
                   }
            if(isdigit(s2[i])!=0 && ko1 == 0)
                   {    
                    printf("Are o cifra jos pe mijloc\n");
                        ko2 = 1;
                        if(isdigit(s2[i+1])!=0)
                        {
                            printf("Are doua cifre jos pe mijloc spre dreapta\n");
                            if(isdigit(s2[i+2])!=0)
                            {   
                                printf("Are trei cifre jos pe mijloc spre dreapta\n");
                                if(n1!=0)
                                {
                                    n2 = 100*(s2[i] - '0') + 10*(s2[i+1] - '0') + (s2[i+2] - '0');
                                    ok++;
                                    length2 = 3;
                                }
                                else
                                {
                                    n1 = 100*(s2[i] - '0') + 10*(s2[i+1] - '0') + (s2[i+2] - '0');
                                    ok++;
                                    length1 = 3;
                                }
                            }
                            else
                            {
                                if(n1!=0)
                                {
                                    n2 = 10*(s2[i] - '0') + (s2[i+1] - '0');
                                    ok++;
                                    length2 = 2;
                                }
                                else
                                {
                                    n1 = 10*(s2[i] - '0') + (s2[i+1] - '0');
                                    ok++;
                                    length1 = 2;
                                }
                            }
                        }
                        else
                        {
                            if(n1 == 0)
                            {n1 = (s2[i] - '0');
                            ok++;
                            length1 = 1;}
                            else
                            {
                                n2 = (s2[i] - '0');
                                ok++;
                                length2 = 1;
                            }
                        }
                   }
            if(isdigit(s2[i+1]) != 0 && ko2 == 0)
                   {    
                        printf("are o cifra dreapta jos spre dreapta\n");
                        if(isdigit(s2[i+2])!= 0)
                        {   
                            printf("Are doua cifre dreapta jos spre dreapta\n");
                            if(isdigit(s2[i+3])!= 0)
                            {
                                printf("Are trei cifre dreapta jos spre dreapta\n");
                                if(n1!=0)
                                {
                                    n2 = 100*(s2[i+1] - '0') + 10*(s2[i+2] - '0') + (s2[i+3] - '0');
                                    ok++;
                                    length2 = 3;
                                }
                                else
                                {
                                    n1 = 100*(s2[i+1] - '0') + 10*(s2[i+2] - '0') + (s2[i+3] - '0');
                                    ok++;
                                    length1 = 3;
                                }
                            }
                            else
                            {
                                if(n1!=0)
                                {
                                    n2 = 10*(s2[i+1] - '0') + (s2[i+2] - '0');
                                    ok++;
                                    length2 = 2;
                                }
                                else
                                {
                                    n1 = 10*(s2[i+1] - '0') + (s2[i+2] - '0');
                                    ok++;
                                    length1 = 2;
                                }
                            }
                        }
                        else
                        {
                            if(n1 == 0)
                            {n1 = (s2[i+1] - '0');
                            ok++;
                            length1 = 1;}
                            else
                            {
                                n2 = (s2[i+1] - '0');
                                ok++;
                                length2 = 1;
                            }
                        }
                   }
            printf("%d %d\n",n1,n2);
            printf("OK = %d\n",ok);   
            if(ok == 2)
                {  
                    sum = sum + n1*n2;   
                }
        }         
    }
    length1 = 0;
    length2 = 0;
    n1 = 0;
    n2 = 0;

    

    do
    {
        length1 = 0;
        length2 = 0;
        n1 = 0; 
        n2 = 0;
        for(int i = 0;i<strlen(s1);i++)
            {   
                
                n1 = 0;
                n2 = 0;
                length1 = 0;
                length2 = 0;
                int ok = 0;
                int ok1 = 0, ok2 = 0;
                int ko1= 0, ko2 = 0;

                if(s2[i] == '*')
                {   
                    
                    if(isdigit(s1[i-1]) != 0)
                    {       
                        ok1 = 1;
                        printf("Are o cifra in stanga sus\n");

                        if(isdigit(s1[i-2])!=0)
                            {   
                                printf("Are doua cifre in stanga sus spre stanga\n");
                                if(isdigit(s1[i-3])!= 0)
                                {   
                                    printf("Are trei cifre in stanga sus spre stanga\n");
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s1[i-3] - '0') + 10*(s1[i-2] - '0') + (s1[i-1] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s1[i-3] - '0') + 10*(s1[i-2] - '0') + (s1[i-1] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                    
                                }
                                else if(isdigit(s1[i]) !=0 )
                                {   
                                    ok2 = 1;
                                    printf("Are 3 cifre dreapta sus pe mijloc\n");
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s1[i-2] - '0') + 10*(s1[i-1] - '0') + (s1[i] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s1[i-2] - '0') + 10*(s1[i-1] - '0') + (s1[i] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                }
                                else
                                {
                                    if(n1 == 0)
                                    {n1 = (s1[i-2]- '0')*10 + (s1[i-1] - '0');
                                    ok++;
                                    length1 = 2;}
                                    else
                                    {
                                        n2 = (s1[i-2]- '0')*10 + (s1[i-1] - '0');
                                        ok++;
                                        length2 = 2;
                                    }
                                }
                            }
                            else if(isdigit(s1[i])!=0)
                            {   
                                ok2 = 1;
                                printf("Are doua cifre in stanga sus spre dreapta\n");
                                if(isdigit(s1[i+1])!=0)
                                {
                                    printf("Are 3 cifre in stanga sus spre dreapta\n");
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s1[i-1] - '0') + 10*(s1[i] - '0') + (s1[i+1] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s1[i-1] - '0') + 10*(s1[i] - '0') + (s1[i+1] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                }
                                else
                                {   
                                    if(n1!=0)
                                    {
                                        n2 = 10*(s1[i-1] - '0') + (s1[i] - '0');
                                        ok++;
                                        length2 = 2;
                                    }
                                    else
                                    {
                                        n1 = 10*(s1[i-1] - '0') + (s1[i] - '0');
                                        ok++;
                                        length1 = 2;
                                    }
                                }
                            }
                            else
                            {
                                n1 = (s1[i-1] - '0');
                                ok++;
                                length1 = 1;
                            }
                    }
                    if(isdigit(s1[i]) !=0 && ok1 == 0)
                    {       ok2 = 1;
                            printf("Are o cifra sus pe mijloc\n");
                            if(isdigit(s1[i+1])!=0)
                            {   
                                printf("Are doua cifre sus pe mijloc spre dreapta\n");
                                if(isdigit(s1[i+2])!=0)
                                {
                                    printf("Are trei cifre sus pe mijloc spre dreapta\n");
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s1[i] - '0') + 10*(s1[i+1] - '0') + (s1[i+2] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s1[i] - '0') + 10*(s1[i+1] - '0') + (s1[i+2] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                }
                                else
                                {
                                    if(n1!=0)
                                    {
                                        n2 = 10*(s1[i] - '0') + (s1[i+1] - '0');
                                        ok++;
                                        length2 = 2;
                                    }
                                    else
                                    {
                                        n1 = 10*(s1[i] - '0') + (s1[i+1] - '0');
                                        ok++;
                                        length1 = 2;
                                    }
                                }
                            }
                            else
                            {
                                if(n1 == 0){
                                n1 = (s1[i] - '0');
                                ok++;
                                length1 = 1;}
                                else
                                {
                                    n2 = (s1[i] - '0');
                                    ok++;
                                    length2 = 1;
                                }
                            }
                    }
                    if(isdigit(s1[i+1]) != 0 && ok2 == 0)
                    {        
                            printf("are o cifra dreapta sus spre dreapta\n");
                            if(isdigit(s1[i+2])!= 0)
                            {   
                                printf("Are doua cifre dreapta sus spre dreapta\n");
                                if(isdigit(s1[i+3])!= 0)
                                {   
                                    printf("Are trei cifre dreapta sus spre dreapta\n");
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s1[i+1] - '0') + 10*(s1[i+2] - '0') + (s1[i+3] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s1[i+1] - '0') + 10*(s1[i+2] - '0') + (s1[i+3] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                }
                                else
                                {
                                    if(n1!=0)
                                    {
                                        n2 = 10*(s1[i+1] - '0') + (s1[i+2] - '0');
                                        ok++;
                                        length2 = 2;
                                    }
                                    else
                                    {
                                        n1 = 10*(s1[i+1] - '0') + (s1[i+2] - '0');
                                        ok++;
                                        length1 = 2;
                                    }
                                }
                            }
                            else
                            {
                               if(n1 == 0)
                                {n1 = (s1[i+1] - '0');
                                ok++;
                                length1 = 1;}
                                else
                                {
                                    n2 = (s1[i+1] - '0');
                                    ok++;
                                    length2 = 1;
                                }
                            }
                    }

                    if(isdigit(s2[i-1]) != 0)
                    {   printf("Are o cifra in stanga mijloc\n");
                    if(isdigit(s2[i-2])!=0)
                    {   
                        printf("Are doua cifre in stanga mijloc spre stanga\n");
                        if(isdigit(s2[i-3])!=0)
                        {
                            printf("Are trei cifre in stanga mijloc spre stanga\n");
                            if(n1 == 0)
                            {   
                                n1 = 100*(s2[i-3] - '0') + 10*(s2[i-2] - '0') + (s2[i-1] - '0');
                                ok++;
                                length1 = 3;
                                
                            }
                            else
                            {
                                n2 = 100*(s2[i-3] - '0') + 10*(s2[i-2] - '0') + (s2[i-1] - '0');
                                ok++;
                                length2 = 3;
                            }
                        }
                        else
                        {
                            if(n1 == 0)
                            {n1 = 10*(s2[i-2] - '0') + (s2[i-1] - '0');
                            ok++;
                            length1 = 2;}
                            else
                            {
                                n2 = 10*(s2[i-2] - '0') + (s2[i-1] - '0');
                                ok++;
                                length2 = 2;
                            }
                        }
                    }
                    else
                    {
                        if(n1 == 0)
                        {n1 = (s2[i-1] - '0');
                        ok++;
                        length1 = 1;}
                        else
                        {
                            n2 = (s2[i-1] - '0');
                            ok++;
                            length2 = 1;
                        }
                    }
                    }
                    if(isdigit(s2[i+1]) != 0)
                    {   
                    printf("Are o cifra in dreapta mijloc\n");
                    if(isdigit(s2[i+2])!=0)
                    {   
                        printf("Are doua cifre in dreapta mijloc spre dreapta\n");  
                        if(isdigit(s2[i+3])!=0)
                        {
                            printf("Are trei cifre in dreapta mijloc spre dreapta\n");
                            if(n1 != 0)
                            {
                                n2 = 100*(s2[i+1] - '0') + 10*(s2[i+2] - '0') + (s2[i+3] - '0');
                                ok++;
                                length2 = 3;
                            }
                            else
                            {
                                n1 = 100*(s2[i+1] - '0') + 10*(s2[i+2] - '0') + (s2[i+3] - '0');
                                ok++;
                                length1 = 3;
                            }
                        }
                        else
                        {
                            if(n1 != 0)
                            {
                                n2 = 10*(s2[i+1] - '0') + (s2[i+2] - '0');
                                ok++;
                                length2 = 2;
                            }
                            else
                            {
                                n1 = 10*(s2[i+1] - '0') + (s2[i+2] - '0');
                                ok++;
                                length1 = 2;
                            }
                        }
                    }
                    else
                    {
                        if(n1 != 0)
                        {
                            n2 = (s2[i+1] - '0');
                            ok++;
                            length2 = 1;
                        }
                        else
                        {
                            n1 = (s2[i+1] - '0');
                            ok++;
                            length1 = 1;
                        }
                    }
                    }
                
                    if(isdigit(s3[i-1]) != 0)
                    {       
                            ko1 = 1;
                            printf("Are o cifra in stanga jos\n");
                            if(isdigit(s3[i-2])!=0)
                            {   
                                printf("Are doua cifre in stanga jos spre stanga\n");
                                if(isdigit(s3[i-3])!=0)
                                {   
                                    printf("Are trei cifre in stanga jos spre stanga\n");
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s3[i-3] - '0') + 10*(s3[i-2] - '0') + (s3[i-1] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s3[i-3] - '0') + 10*(s3[i-2] - '0') + (s3[i-1] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                    
                                }
                                else if(isdigit(s3[i])!=0)
                                {      
                                    ko2 = 1;
                                    printf("Are 3 cifre dreapta jos pe mijloc\n");
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s3[i-2] - '0') + 10*(s3[i-1] - '0') + (s3[i] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s3[i-2] - '0') + 10*(s3[i-1] - '0') + (s3[i] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                }
                                else
                                {   
                                    if(n1 == 0)
                                    {
                                        n1 = 10*(s3[i-2] - '0') + (s3[i-1] - '0');
                                        ok++;
                                        length1 = 2;
                                    }
                                    else
                                    {
                                        n2 = 10*(s3[i-2] - '0') + (s3[i-1] - '0');
                                        ok++;
                                        length2 = 2;
                                    }
                                }
                            }
                            else if(isdigit(s3[i])!=0)
                            {
                                ko2 = 1;
                                if(isdigit(s3[i+1])!=0)
                                {
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s3[i-1] - '0') + 10*(s3[i] - '0') + (s3[i+1] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s3[i-1] - '0') + 10*(s3[i] - '0') + (s3[i+1] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                }
                                else
                                {
                                    if(n1!=0)
                                    {
                                        n2 = 10*(s3[i-1] - '0') + (s3[i] - '0');
                                        ok++;
                                        length2 = 2;
                                    }
                                    else
                                    {
                                        n1 = 10*(s3[i-1] - '0') + (s3[i] - '0');
                                        ok++;
                                        length1 = 2;
                                    }
                                }
                            }
                            else
                            {
                                if(n1 == 0)
                                {n1 = (s3[i-1] - '0');
                                ok++;
                                length1 = 1;}
                                else
                                {
                                    n2 = (s3[i-1] - '0');
                                    ok++;
                                    length2 = 1;
                                }
                            }
                    }
                    if(isdigit(s3[i]) !=0 && ko1 == 0)
                    {    ko2 = 1;
                            printf("Are o cifra jos pe mijloc\n");
                            if(isdigit(s3[i+1])!=0)
                            {
                                printf("Are doua cifre jos pe mijloc spre dreapta\n");
                                if(isdigit(s3[i+2])!=0)
                                {   
                                    printf("Are trei cifre jos pe mijloc spre dreapta\n");
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s3[i] - '0') + 10*(s3[i+1] - '0') + (s3[i+2] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s3[i] - '0') + 10*(s3[i+1] - '0') + (s3[i+2] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                }
                                else
                                {
                                    if(n1!=0)
                                    {
                                        n2 = 10*(s3[i] - '0') + (s3[i+1] - '0');
                                        ok++;
                                        length2 = 2;
                                    }
                                    else
                                    {
                                        n1 = 10*(s3[i] - '0') + (s3[i+1] - '0');
                                        ok++;
                                        length1 = 2;
                                    }
                                }
                            }
                            else
                            {
                                if(n1 == 0)
                                {n1 = (s3[i] - '0');
                                ok++;
                                length1 = 1;}
                                else
                                {
                                    n2 = (s3[i] - '0');
                                    ok++;
                                    length2 = 1;
                                }
                            }
                    }
                    if(isdigit(s3[i+1]) != 0 && ko2 == 0)
                    {   
                            printf("are o cifra dreapta jos spre dreapta\n");
                            if(isdigit(s3[i+2])!= 0)
                            {   
                                printf("Are doua cifre dreapta jos spre dreapta\n");
                                if(isdigit(s3[i+3])!= 0)
                                {   
                                    printf("Are trei cifre dreapta jos spre dreapta\n");
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s3[i+1] - '0') + 10*(s3[i+2] - '0') + (s3[i+3] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s3[i+1] - '0') + 10*(s3[i+2] - '0') + (s3[i+3] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                }
                                else
                                {
                                    if(n1!=0)
                                    {
                                        n2 = 10*(s3[i+1] - '0') + (s3[i+2] - '0');
                                        ok++;
                                        length2 = 2;
                                    }
                                    else
                                    {
                                        n1 = 10*(s3[i+1] - '0') + (s3[i+2] - '0');
                                        ok++;
                                        length1 = 2;
                                    }
                                }
                            }
                            else
                            {
                                if(n1 == 0)
                                {n1 = (s3[i+1] - '0');
                                ok++;
                                length1 = 1;}
                                else
                                {
                                    n2 = (s3[i+1] - '0');
                                    ok++;
                                    length2 = 1;
                                }
                            }
                    }

                    printf("%d %d\n",n1,n2);
                    printf("OK = %d\n",ok); 

                    if(ok == 2)
                    {
                        sum = sum + n1*n2;   
                    }
                }
            }

            gets(s4);
        if(strlen(s4) < 3)
            break;
        for(int i = 0;i<strlen(s1);i++)
            {
                s1[i] = s2[i];
                s2[i] = s3[i];
                s3[i] = s4[i];
            }

        }while(strlen(s4) > 3);

    puts(s3);

    for(int i = 0;i<strlen(s1);i++)
    {   
        s1[i] = s2[i];
        s2[i] = s3[i];
         
    }

    for(int i = 0;i<strlen(s1);i++)
    {
        n1 = 0;
        n2 = 0;
        length1 = 0;
        length2 = 0;
        int ok = 0;
        int ok1 = 0;
        int ok2 = 0;
        
        if(s2[i] == '*')
        {
            if(isdigit(s1[i-1]) != 0)
                    {       
                        ok1 = 1;
                            if(isdigit(s1[i-2])!=0)
                            {
                                if(isdigit(s1[i-3])!=0)
                                {
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s1[i-3] - '0') + 10*(s1[i-2] - '0') + (s1[i-1] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s1[i-3] - '0') + 10*(s1[i-2] - '0') + (s1[i-1] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                    
                                }
                                else if(isdigit(s1[i])!=0)
                                {   
                                    ok2 = 1;
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s1[i-2] - '0') + 10*(s1[i-1] - '0') + (s1[i] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s1[i-2] - '0') + 10*(s1[i-1] - '0') + (s1[i] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                }
                                else
                                {
                                    if(n1 == 0)
                                    {
                                       n1 = 10*(s1[i-2] - '0') + (s1[i-1] - '0');
                                        ok++;
                                        length1 = 2;
                                    }
                                    else
                                    {
                                        n2 = 10*(s1[i-2] - '0') + (s1[i-1] - '0');
                                        ok++;
                                        length2 = 2;
                                    }
                                }
                            }
                            else if(isdigit(s1[i])!=0)
                            {
                                ok2 = 1;
                                if(isdigit(s1[i+1])!=0)
                                {
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s1[i-1] - '0') + 10*(s1[i] - '0') + (s1[i+1] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s1[i-1] - '0') + 10*(s1[i] - '0') + (s1[i+1] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                }
                                else
                                {
                                    if(n1!=0)
                                    {
                                        n2 = 10*(s1[i-1] - '0') + (s1[i] - '0');
                                        ok++;
                                        length2 = 2;
                                    }
                                    else
                                    {
                                        n1 = 10*(s1[i-1] - '0') + (s1[i] - '0');
                                        ok++;
                                        length1 = 2;
                                    }
                                }
                            }
                            else
                            {
                                if(n1 == 0)
                                {
                                    n1 = (s1[i-1] - '0');
                                    ok++;
                                    length1 = 1;}
                                else
                                {
                                    n2 = (s1[i-1] - '0');
                                    ok++;
                                    length2 = 1;
                                }
                            }
                    }
            if(isdigit(s1[i]) != 0 && ok1 == 0)
                    {       
                        ok2 = 1;
                            if(isdigit(s1[i+1])!=0)
                            {
                                if(isdigit(s1[i+2])!=0)
                                {
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s1[i] - '0') + 10*(s1[i+1] - '0') + (s1[i+2] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s1[i] - '0') + 10*(s1[i+1] - '0') + (s1[i+2] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                }
                                else
                                {
                                    if(n1!=0)
                                    {
                                        n2 = 10*(s1[i] - '0') + (s1[i+1] - '0');
                                        ok++;
                                        length2 = 2;
                                    }
                                    else
                                    {
                                        n1 = 10*(s1[i] - '0') + (s1[i+1] - '0');
                                        ok++;
                                        length1 = 2;
                                    }
                                }
                            }
                            else
                            {
                                if(n1 == 0)
                                {n1 = (s1[i] - '0');
                                ok++;
                                length1 = 1;}
                                else
                                {
                                    n2 = (s1[i] - '0');
                                    ok++;
                                    length2 = 1;
                                }
                            }
                    }
            if(isdigit(s1[i+1]) != 0 && ok2 == 0)
                    {
                            if(isdigit(s1[i+2])!= 0)
                            {
                                if(isdigit(s1[i+3])!= 0)
                                {
                                    if(n1!=0)
                                    {
                                        n2 = 100*(s1[i+1] - '0') + 10*(s1[i+2] - '0') + (s1[i+3] - '0');
                                        ok++;
                                        length2 = 3;
                                    }
                                    else
                                    {
                                        n1 = 100*(s1[i+1] - '0') + 10*(s1[i+2] - '0') + (s1[i+3] - '0');
                                        ok++;
                                        length1 = 3;
                                    }
                                }
                                else
                                {
                                    if(n1!=0)
                                    {
                                        n2 = 10*(s1[i+1] - '0') + (s1[i+2] - '0');
                                        ok++;
                                        length2 = 2;
                                    }
                                    else
                                    {
                                        n1 = 10*(s1[i+1] - '0') + (s1[i+2] - '0');
                                        ok++;
                                        length1 = 2;
                                    }
                                }
                            }
                            else
                            {
                                n1 = (s1[i+1] - '0');
                                ok++;
                                length1 = 1;
                            }
                    }

            if(isdigit(s2[i-1]) != 0)
                {
                    if(isdigit(s2[i-2])!=0)
                    {
                        if(isdigit(s2[i-3])!=0)
                        {
                            n1 = 100*(s2[i-3] - '0') + 10*(s2[i-2] - '0') + (s2[i-1] - '0');
                            ok++;
                            length1 = 3;
                        }
                        else
                        {
                            n1 = 10*(s2[i-2] - '0') + (s2[i-1] - '0');
                            ok++;
                            length1 = 2;
                        }
                    }
                    else
                    {
                        if(n1 == 0)
                        {n1 = (s2[i-1] - '0');
                        ok++;
                        length1 = 1;}
                        else
                        {
                            n2 = (s2[i-1] - '0');
                            ok++;
                            length2 = 1;
                        }
                    }
                }
            if(isdigit(s2[i+1]) != 0)
                {
                    if(isdigit(s2[i+2])!=0)
                    {
                        if(isdigit(s2[i+3])!=0)
                        {
                            if(n1 != 0)
                            {
                                n2 = 100*(s2[i+1] - '0') + 10*(s2[i+2] - '0') + (s2[i+3] - '0');
                                ok++;
                                length2 = 3;
                            }
                            else
                            {
                                n1 = 100*(s2[i+1] - '0') + 10*(s2[i+2] - '0') + (s2[i+3] - '0');
                                ok++;
                                length1 = 3;
                            }
                        }
                        else
                        {
                            if(n1 != 0)
                            {
                                n2 = 10*(s2[i+1] - '0') + (s2[i+2] - '0');
                                ok++;
                                length2 = 2;
                            }
                            else
                            {
                                n1 = 10*(s2[i+1] - '0') + (s2[i+2] - '0');
                                ok++;
                                length1 = 2;
                            }
                        }
                    }
                    else
                    {
                        if(n1 != 0)
                        {
                            n2 = (s2[i+1] - '0');
                            length2 = 1;
                        }
                        else
                        {
                            n1 = (s2[i+1] - '0');
                            length1 = 1;
                        }
                    }
                }
            
            printf("%d %d\n",n1,n2);
            printf("OK = %d\n",ok); 

            if(ok == 2)
                    {
                        sum = sum + n1*n2;   
                    }        
        }
    }

    printf("%ld\n\n",sum);
    return 0;   
}
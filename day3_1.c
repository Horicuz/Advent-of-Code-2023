#include <stdio.h>
#include <string.h>
#include <ctype.h>



void is_part_number(char s1[], char s2[], char s3[], int* n1, int* length, int* sum, int* i)
{

                if(isdigit(s2[*i]) != 0)
                {   
                    *length = 0;
                    *n1 = 0;
                    int k = *i;
                    while(isdigit(s2[k]) != 0)
                    {
                        (*length)++;
                        *n1 = (*n1)*10 + (s2[k] - '0');
                        k++;
                    }
                    int ok = 0;
                    for(int j = *i;j<*i+*length;j++)
                    {
                        if(s1[j+1] != '.' && (isdigit(s1[j+1]) == 0) && s1[j+1] != '\0')
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT LA DREAPTA SUS\n");
                            break;
                        }
                        if(s2[j+1] != '.' && (isdigit(s2[j+1]) == 0) && s2[j+1] != '\0')
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT LA DREAPTA\n");
                            break;
                        }
                        if(s3[j+1] != '.' && (isdigit(s3[j+1]) == 0) && s3[j+1] != '\0')
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT LA DREAPTA JOS\n");
                            break;
                        }
                        if(s1[j] != '.' && (isdigit(s1[j]) == 0))
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT SUS\n");
                            break;
                        }
                        if(s1[j-1] != '.' && (isdigit(s1[j-1]) == 0) && s1[j-1] != '\0')
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT LA STANGA SUS\n");
                            break;
                        }
                        if(s2[j-1] != '.' && (isdigit(s2[j-1]) == 0) && s2[j-1] != '\0')
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT LA STANGA\n");
                            break;
                        }
                        if(s3[j-1] != '.' && (isdigit(s3[j-1]) == 0) && s3[j-1] != '\0')
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT LA STANGA JOS\n");
                            break;
                        }
                        if(s3[j] != '.' && (isdigit(s3[j]) == 0))
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT JOS\n");
                            break;
                        }

                    }
                    *i = *i + *length;
                    if(ok == 1)
                        *sum = *sum + *n1;


                }
}

int main()
{  
    int sum = 0;
    char s1[1000],s2[1000],s3[1000], s4[1000];
    int length = 0;
    int n1 = 0;

    gets(s1);
    gets(s2);
    gets(s3);
    for(int i = 0;i<strlen(s1);i++)
    {   
        
        if(isdigit(s1[i]) != 0)
                {   
                    n1 = 0;
                    length = 0;
                    int k = i;
                    while(isdigit(s1[k]) != 0)
                    {
                        length++;
                        n1 = n1*10 + (s1[k] - '0');
                        k++;
                    }
                    int ok = 0;
                    for(int j = i;j<i+length;j++)
                    {
                        if(s1[j+1] != '.' && (isdigit(s1[j+1]) == 0) && s1[j+1] != '\0')
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT LA DREAPTA\n");
                            break;
                            
                        }
                        if(s2[j+1] != '.' && (isdigit(s2[j+1]) == 0) && s2[j+1] != '\0')
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT LA DREAPTA JOS\n");
                            break;
                            
                        }
                        if(s2[j] != '.' && (isdigit(s2[j]) == 0))
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT JOS\n");
                            break;
                        }
                        if(s1[j-1] != '.' && (isdigit(s1[j-1]) == 0) && s1[j-1] != '\0')
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT LA STANGA\n");
                            break;
                        }
                        if(s2[j-1] != '.' && (isdigit(s2[j-1]) == 0) && s2[j-1] != '\0')
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT LA STANGA JOS\n");
                            break;
                        }
                    }
                    i = i + length;
                    if(ok == 1)
                        {   
                            sum = sum + n1;
                        }
                }
                    
    }
    length = 0;
    n1 = 0;

    for(int i = 0;i<strlen(s1);i++)
    {
        is_part_number(s1,s2,s3,&n1,&length,&sum,&i);
    }

    do
    {
        length = 0;
        n1 = 0; 
        gets(s4);
        if(strlen(s4) < 3)
            break;

        for(int i = 0;i<strlen(s1);i++)
            {
                s1[i] = s2[i];
                s2[i] = s3[i];
                s3[i] = s4[i];
            }

        for(int i = 0;i<strlen(s1);i++)
            {
                is_part_number(s1,s2,s3,&n1,&length,&sum,&i);
                printf("%d\n",sum);
                printf("%d\n",n1);
                printf("\n");
            }

        }while(strlen(s4) > 3);

    puts(s3);
    for(int i = 0;i<strlen(s1);i++)
    {   
        
        if(isdigit(s3[i]) != 0)
                {   
                    n1 = 0;
                    length = 0;
                    int k = i;
                    while(isdigit(s3[k]) != 0)
                    {
                        length++;
                        n1 = n1*10 + (s3[k] - '0');
                        k++;
                    }
                    int ok = 0;
                    for(int j = i;j<i+length;j++)
                    {
                        if(s3[j+1] != '.' && (isdigit(s3[j+1]) == 0) && s3[j+1] != '\0')
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT LA DREAPTA\n");
                            break;
                            
                        }
                        if(s2[j+1] != '.' && (isdigit(s2[j+1]) == 0) && s2[j+1] != '\0')
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT LA DREAPTA SUS\n");
                            break;
                            
                        }
                        if(s2[j] != '.' && (isdigit(s2[j]) == 0))
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT SUS\n");
                            break;
                        }
                        if(s3[j-1] != '.' && (isdigit(s3[j-1]) == 0) && s3[j-1] != '\0')
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT LA STANGA\n");
                            break;
                        }
                        if(s2[j-1] != '.' && (isdigit(s2[j-1]) == 0) && s2[j-1] != '\0')
                        {
                            ok = 1;
                            printf("AM GASIT ELEMENT LA STANGA SUS\n");
                            break;
                        }
                    }
                    i = i + length;
                    if(ok == 1)
                        {   
                            sum = sum + n1;
                            printf("%d\n",sum);
                            printf("%d\n",n1);
                        }
                }
                    
    }
    printf("%d\n\n",sum);
    return 0;   
}
    
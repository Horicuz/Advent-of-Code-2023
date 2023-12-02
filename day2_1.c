#include <stdio.h>
#include <string.h>



//Game 1: 12 red, 2 green, 5 blue; 9 red, 6 green, 4 blue; 10 red, 2 green, 5 blue; 8 blue, 9 red



int main()
{
    int sum = 0;
    char s[1000];

    for(int i=1;i<=100;i++)
    {   
        
        int n1 = 0;
        int ok = 0;
        gets(s);
    
        for(int j = 7;j<strlen(s);j++)
        {
            if((s[j-2] == ':' && s[j-1] == ' ') || (s[j-2] == ';' && s[j-1]== ' '))
                {   
                    printf("A abgat mana in sac\n");
                    int red = 0,green = 0,blue = 0;
                    while(s[j] != ';' && s[j] != '\0')
                    {   
                        n1 = 0;
                        if(s[j] == ',')
                        {
                            j=j+2;
                        }
                        else
                        {
                             while(s[j] != ' ')
                            {
                                
                                n1 = n1 * 10 + (int)(s[j] - '0');
                                j++;
                            }
                            j++;
                            if(s[j] == 'r')
                            {
                                red = n1;
                                printf("ROSU SCHIMBAT\n");
                                if(s[j+3] != ';')
                                    j = j+3;
                                else
                                    break;
                            }
                            else if(s[j] == 'g')
                            {
                                green = n1;
                                printf("Verde SCHIMBAT\n");
                                if(s[j+5] != ';')
                                    j = j+5;
                                else
                                    break;
                            }
                            else if(s[j] == 'b')
                            {
                                blue = n1;
                                printf("Bleu SCHIMBAT\n");
                                if(s[j+4] != ';')
                                    j = j+4;
                                else
                                    break;
                            }
                        
                            printf("R%d G%d B%d ", red, green, blue);
                        }
                       
                    }
                    if(red <= 12 && green <= 13 && blue <= 14 )
                    {
                        printf("  %d  ",i);
                        ok = 1;


                    }
                    else
                        {
                            ok = 0;
                            break;
                        }
                    

                }
        }

       if(ok == 1)
       {
        sum = sum + i;
       } 


    }

    printf("\n%d\n",sum);
    return 0;
    
    
}
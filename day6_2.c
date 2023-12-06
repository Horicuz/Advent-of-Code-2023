#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

void number_creation(char s[], int *j, int64_t *n1)
{
    *n1 = 0;
    if (isdigit(s[*j]) != 0)
    {
        for (int i = *j; i < strlen(s); i++)
        {
            if (isdigit(s[i]) != 0)
            {
                (*n1) = (*n1) * 10 + (s[i] - '0');
            }
        }
    }
}


int main()
{

    char s[200];

    int64_t hex1, hex2;
    int prod = 1;

    int n1;
    int m = 0;
    int n = 0;

    fgets(s, 200, stdin);

    for (int i = 13; i < strlen(s); i++)
    {
        number_creation(s, &i, &hex1);
        break;
    }
    printf("%ld\n", hex1);

    fgets(s, 200, stdin);

    for (int i = 12; i < strlen(s); i++)
    {
        number_creation(s, &i, &hex2);
        break;
    }
    printf("%ld\n", hex2);

    unsigned int cnt = 0;
    int64_t dist = 0;

    for (int j = 0; j <= hex1; j++)
    {
        dist = j * (hex1 - j);
        if (dist > hex2)
            cnt++;
    }

    printf("%u", cnt);
    return 0;
}
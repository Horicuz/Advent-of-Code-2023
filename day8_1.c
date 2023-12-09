#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    struct node *left;
    struct node *right;
    char name[5];
};

struct node *createNode(char name[5])
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int main()
{
    char instr[300];
    struct node Nodes[1000];

    char com[20];
    fgets(instr, 300, stdin);
    getchar();
    int i = 0;
    int fulga = 0;
    int v[1000];
    char beg[1000][5];

    do
    {
        fgets(com, 20, stdin);
        if (strlen(com) < 3)
            break;

        char name[5];
        name[0] = com[0];
        name[1] = com[1];
        name[2] = com[2];
        if (name[2] == 'A')
        {
            v[fulga] = i;
            strcpy(beg[fulga], name);
            fulga++;
        }

        char left[5];
        left[0] = com[7];
        left[1] = com[8];
        left[2] = com[9];

        char right[5];
        right[0] = com[12];
        right[1] = com[13];
        right[2] = com[14];

        Nodes[i] = *createNode(name);
        Nodes[i].left = createNode(left);
        Nodes[i].right = createNode(right);

       

        i++;
    } while (strlen(com) > 3);
    i--;

    unsigned int count = 0;

   
    
    while (1)
    {   
        for (int j = 0; j < strlen(instr) - 1; j++)
        {   printf("%d\n", count);
            if (instr[j] == 'R')
            {   
                count++;
                for (int poz = 0; poz < fulga; poz++)
                {
                    for (int z = 0; z <= i; z++)
                    {
                        if (strcmp(Nodes[v[poz]].right->name, Nodes[z].name) == 0)
                        {
                            v[poz] = z;
                            strcpy(beg[poz], Nodes[z].name);
                            printf("%s\n", beg[poz]);

                            break;
                        }
                    }
                }
                int ok = 1;
                for (int poz = 0; poz < fulga; poz++)
                {
                    if (beg[poz][2] != 'Z')
                    {
                        ok = 0;
                        break;
                    }
                }
                if (ok == 1)
                {
                    printf("%u\n", count);
                    return 0;
                }
            }
            if (instr[j] == 'L')
            {   
                count++;
                for (int poz = 0; poz < fulga; poz++)
                {
                    for (int z = 0; z <= i; z++)
                    {
                        if (strcmp(Nodes[v[poz]].left->name, Nodes[z].name) == 0)
                        {
                            v[poz] = z;
                            strcpy(beg[poz], Nodes[z].name);
                            printf("%s\n", beg[poz]);
                            break;
                        }
                    }
                    
                }
                int ok = 1;
                for (int poz = 0; poz < fulga; poz++)
                {
                    if (beg[poz][2] != 'Z')
                    {
                        ok = 0;
                        break;
                    }
                }
                if (ok == 1)
                {
                    printf("%u\n", count);
                    return 0;
                }
            }
        }
    }

    return 0;
}

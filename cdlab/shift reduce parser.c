//Neil John 37
// Shift reduce parser

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct production 
{
    char key[20];
    char value[20];
} p[10];

void main() {
    int n, top = 0;
    char str[30], stack[35];
    stack[top++] = '$';
    stack[top] = '\0';

    printf("Enter the number of productions: ");
    scanf("%d", &n);
    getchar();

    printf("Enter the grammar:\n");
    for (int i=0;i < n;i++) 
    {
        scanf("%[^-]s", p[i].key);
        getchar();
        getchar(); 
        scanf("%[^\n]s", p[i].value); 
        getchar(); 
    }
    printf("\nEnter the string to parse: ");
    scanf("%[^\n]s", str);
    getchar();

    printf("\n");

    char *inpt = str;

    printf("%-10s %-10s %-10s\n", "STACK", "INPUT", "ACTION");

    while(*inpt != '\0') 
    {
        int reduce;

        stack[top++] = *inpt;
        stack[top] = '\0';
        inpt++;

        printf("%-10s %-10s %-10s\n", stack, inpt, "Shift");

        do {
            reduce=0;
            for(int j=0;j<n;j++) 
            {
                int len = strlen(p[j].value);
                if (strcmp(&stack[1],p[0].key)!=0 && top >=len && strncmp(&stack[top - len], p[j].value, len) == 0) 
                {

                    char temp[20];
                    strcpy(temp, &stack[top - len]);
                    top -= len;
                    strcpy(&stack[top], p[j].key);
                    top += strlen(p[j].key);
                    stack[top] = '\0';
                    
                    printf("%-10s %-10s %-10s %s -> %s\n", stack, inpt, "Reduce", temp, p[j].key);
                    reduce = 1;
                    break;
                }
            }
        } while (reduce);
    }

    if(strcmp(&stack[1], p[0].key)==0 && top==2)
    {
        printf("%-10s %-10s %-10s\n", stack, inpt, "ACCEPT");
    } 
    else 
    {
        printf("%-10s %-10s %-10s\n", stack, inpt, "REJECT");
    }
}

/*________________________OUTPUT_____________________________________________
Enter the number of productions: 3
Enter the grammar:
S->S+S
S->S*S
S->i

Enter the string to parse: i+i+i

STACK      INPUT      ACTION    
$i         +i+i       Shift     
$S         +i+i       Reduce     i -> S
$S+        i+i        Shift     
$S+i       +i         Shift
$S+S       +i         Reduce     i -> S
$S         +i         Reduce     S+S -> S       
$S+        i          Shift
$S+i                  Shift
$S+S                  Reduce     i -> S
$S                    Reduce     S+S -> S
$S                    ACCEPT
*/

//Neil John
//S7 CS2 37
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char expr[25],pro[25];
int ptr,len;
void replace(char oldSub[], char newSub[])
{
    char result[1000];
    int i, j = 0, k;
    int oldLen = strlen(oldSub);
    int newLen = strlen(newSub);
    int found = 0;
    
    for (i = 0; pro[i] != '\0'; i++) {

        if (strncmp(&pro[i], oldSub, oldLen) == 0) {

            for (k = 0; k < newLen; k++) {
                result[j++] = newSub[k];
            }
            i += oldLen - 1; 
            found = 1;
        } else {
            result[j++] = pro[i];
        }
    }
    result[j] = '\0';  
    strcpy(pro,result);

    if (found)
        printf("%-25s\t", result);
    else
        printf("Substring not found.\n");
}
void _remove(char sub[]) 
{
    char result[1000];
    int i, j = 0, k;
    int subLen = strlen(sub);
    int found = 0;

    for (i = 0; pro[i] != '\0'; i++) {
        
        if (strncmp(&pro[i], sub, subLen) == 0) {
            i += subLen - 1; 
            found = 1;
        } else {
            result[j++] = pro[i];
        }
    }
    result[j] = '\0';  
    strcpy(pro,result);
    if (found)
        printf("%-25s\t", result);
    else
        printf("Substring not found.\n");
}
void E()
{
    printf("E->TE'\n");
    replace("E","TE'");
    T();
    E_();
}
void E_()
{
    
    if(expr[ptr]=='+' && ptr<len)
    {
        printf("E'->+TE'\n");
        replace("E'","+TE'");
        ptr++;
        T();
        E_();
    }
    else{
        printf("E'->e\n");
        _remove("E'");
        return;
    }
}
void T()
{
    printf("T->FT'\n");
    replace("T","FT'");
    F();
    T_();
}
void T_()
{
    
    if(expr[ptr]=='*' && ptr<len)
    {
        printf("T'->*FT'\n");
        replace("T'","*FT'");
        ptr++;
        F();
        T_();
    }
    else{
        printf("T'->e\n");
        _remove("T'");
    }
}
void F()
{
    
   if(expr[ptr]>='0' && expr[ptr]<='9' &&ptr<len)
    {
        printf("F->i\n");
        char str[3];
        str[0]=expr[ptr];
        str[1]='\0';
        replace("F",str);
        ptr++;
    }
}
void main()
{
    printf("\nGrammar Parser");
    printf("\n\t E->TE' \n\t E'->+TE'|e \n\t T->FT' ");
    printf("\n\t T'->*FT'|e \n\t F->i");
    printf("\n Enter the input :");
    scanf("%s",expr);
    len=strlen(expr);
    strcpy(pro,"E");
    printf("E                            \t");
    E();
    if(ptr==len && expr[ptr]=='\0')
    {
        printf("String accepted");
    }
    else
    {
         printf("\n String not accepted");
    }
    
}
/*______________________OUTPUT________________________
Grammar Parser
         E->TE' 
         E'->+TE'|e 
         T->FT' 
         T'->*FT'|e 
         F->i
 Enter the input :3+7
E                               E->TE'
TE'                             T->FT'
FT'E'                           F->i
3T'E'                           T'->e
3E'                             E'->+TE'
3+TE'                           T->FT'
3+FT'E'                         F->i
3+7T'E'                         T'->e
3+7E'                           E'->e
3+7                             String accepted
*/

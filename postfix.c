#include<stdio.h> 
#include<stdlib.h> 
#include<ctype.h> 
#include<string.h> 
 
char stack[20]; 
int top = -1; 
int count1=0,count2=0; 
 
void push(char x) 
{ 
    stack[++top] = x; 
} 
 
char pop() 
{ 
    if(top == -1) 
        return -1; 
    else 
        return stack[top--]; 
} 
 
int priority(char x) 
{ 
    if(x == '(') 
        return 0; 
    if(x == '+' || x == '-') 
        return 1; 
    if(x == '*' || x == '/') 
        return 2; 
    return 0; 
} 
 
int main() 
{ 
    int j=0; 
    char exp[100]; 
    char res[100]; 
    char *e, x; 
    printf("Enter the expression : "); 
    scanf("%s",exp); 
    printf("\n"); 
    e = exp; 
    int k=strlen(exp);
    for(int i=0;i<k;i++) 
    { 
        if(exp[i]=='(') 
            count1++; 
        else if(exp[i]==')') 
            count2++; 
    } 
 
    while(*e !='\0') 
    { 
        if(isalnum(*e)) 
            res[j++]=*e; 
        else if(*e == '(') 
            push(*e); 
        else if(*e == ')') 
        { 
            while((x = pop()) != '(') 
                res[j++]=x; 
        } 
        else 
        { 
            while(priority(stack[top]) >= priority(*e)) 
                res[j++]=pop(); 
            push(*e); 
        } 
        e++; 
    } 
 
    while(top != -1) 
        res[j++]=pop(); 
 
    if(count1 == count2) 
        printf("%s",res); 
    else  
    {  
        printf("Invalid expression\n"); 
        exit(0); 
    } 
    return 0; 
}

/*
date  : 29/04/2022
author: VISHNU V

QUESTION
To write a c program to convert an infix to postfix form
*/

//SOURCE CODE
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[50];
int top=-1;
void push(char x){
    top=top+1;
    stack[top]=x;
}
char pop(){
    char x;
    x=stack[top];
    top=top-1;
    return x;
}
int pri(char symbol){
    if(symbol=='^'){
        return (6);
    }
    else if (symbol=='*'||symbol=='/'){
        return (3);
    }
    else if (symbol=='+'||symbol=='-'){
        return (1);
    }   
    else{
        return (0);
    }
}
int prs(char symbol){
    if (symbol=='^'){
        return (5);
    }
    else if (symbol=='*'||symbol=='/'){
        return (4);
    }
    else if (symbol=='+'||symbol=='-'){
        return (2);
    }
    else{
        return (0);
    }
}
void main(){
    char infix[50],postfix[50],ch,elem;
    int i=0,k=0;
    printf("///////// TO CONVERT INFIX TO POSTFIX //////////");
    printf("\ninputing......\nenter the infix expression :");
    scanf("%s",infix);
    push('#');
    while ( (ch=infix[i])!='\0'){
        if(ch=='('){
            push(ch);
        }
        else if(isalnum(ch)){
            postfix[k++]=ch;
        }
        else if(ch==')'){
            while(stack[top]!='('){
                postfix[k++]=pop();
                elem=pop();
            }
        }
        else{
            while(pri(ch)<prs(stack[top]))
            postfix[k++]=pop();
            push(ch);
        }
        i++;
    }
    while(stack[top]!='#'){
        postfix[k++]=pop();
        postfix[k]='\0';
        printf("\nOUTPUT\nthe postfix expression is: %s",postfix);
    }
}
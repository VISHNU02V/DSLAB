/*
author  : VISHNU V
class   : CSE 
rollno  : 53

question 
Implement allocation using best fit algorithm using linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct node {  
    int data;
    struct node * link;
};

struct node *avail=NULL , *currentnode,*newnode,*prev,*temp,*smallestadd;
int bal=0,smallest=0,best,count=0,nblocks,nprocess,block,process;

struct node * get_node(int ele){
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp=NULL){
        return NULL;
    }
    else{
        temp->data=ele;
        temp->link=NULL;
    }
    return temp;
}

void insert(int ele){
    newnode=get_node(ele);
    if(newnode!=NULL){
        if(avail==NULL){
            avail=newnode;
        }
        else{
            currentnode=avail;
            while(currentnode->link!=NULL){
                currentnode=currentnode->link;
            }
            currentnode->link=newnode;
        }
    }
    else{
        printf("no node created");
    }
}

void display(){
    printf("Avail List\n");
    currentnode=avail;
    while(currentnode!=NULL){
        printf("|%d||%u|",currentnode->data,currentnode->link);
        currentnode=currentnode->link;
        if(currentnode!=NULL){
            printf("--->");
        }
    }
}

void delete(struct node * address){
    prev=avail;
    currentnode=prev->link;
    while(currentnode!=NULL && currentnode!=address){
        count++;
        currentnode=currentnode->link;
        prev=prev->link;
    }
    if(currentnode!=NULL){
        prev->link=currentnode->link;
        free(currentnode);
    }
    else if(currentnode!=NULL && count==0){
        avail=NULL;
        free(currentnode);
    }
    else if(currentnode==NULL){
        prev->link=NULL;
        free(currentnode);
    }
    count=0;
}

int allocate(int process){
    currentnode=avail;
    smallest=10000;
    best=0;
    while(currentnode!=NULL){
        bal=currentnode->data-process;
        if(smallest>bal && bal>=0){
            smallest=bal;
            smallestadd=currentnode;
            best=currentnode->data;
        }
        currentnode=currentnode->link;
    }
    if(smallestadd==avail){
        avail=smallestadd->link;
        free(smallestadd);
    }
    else{
        delete(smallestadd);
        return best;
    }
}
void main(){
    printf(" TO IMPLEMENT THE BEST FIT ALGORITHM \n");
    printf(" \n\n enter the number of blocks required:");
    scanf("%d",&nblocks);
    LABEL:
        printf("Enter the number of process");
        scanf("%d",&nprocess);
    int a[nprocess];
    if(nprocess>nblocks){
        printf("Only %d blocks available",nblocks);
        goto LABEL;
    }
    else{
        for(int i=1;i<=nblocks ;i++){
            printf("enter block size %d:",i);
            scanf("%d",&block);
            insert(block);
        }
    }
    printf("\n");
    for(int i=1;i<=nprocess;i++){
        printf("Enter process size %d:",i);
        scanf("%d",&process);
        a[i]=process;
    }
    display();                       
    for(int i=1;i<nprocess;i++){
        int bestspace=allocate(a[i]);
        if(bestspace==0){
            printf("\n Lack of space for allocation %d\n",a[i]);
        }
        else{
            printf("\n %d is allocates at %d\n",a[i],bestspace);
        }
    }
}
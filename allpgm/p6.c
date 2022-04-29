/*
NAME : VISHNU V
CLASS : CSE B
ROLLNO: 53
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
    int data;
    struct node *before_link;
    struct node *next_link;
};
struct node *head=NULL;
struct node *new_node,*current_node,*prev_node,*next_node;
int pos;

struct node * get_node(){
    int ele;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
   	 return NULL;
    }
    else{
   	 printf(" enter the element to insert::");
   	 scanf("%d",&ele);
   	 temp->data=ele;
   	 temp->next_link=NULL;
    }
    return temp;
}
void insert_beg(){
    new_node=get_node();
    if(new_node!=NULL){
   	 if(head==NULL){
   		 head=new_node;
   	 }
   	 else{
   		 new_node->before_link=NULL;
   		 new_node->next_link=head;
   		 head=new_node;
   		 current_node=new_node->next_link;
   		 current_node->before_link=new_node;
   	 }
    }
    else{
   	 printf("\nno node created\n");
    }
printf("// Successfully added the element at the beginning"); }
void insert_last(){
    new_node=get_node();
    if(new_node!=NULL){
   	 if(head==NULL){
   		 head=new_node;
   	 }
   	 else{
   		 current_node=head;
   		 while(current_node->next_link!=NULL) {
   			 current_node=current_node->next_link;
   		 }
   		 current_node->next_link=new_node;
   		 new_node->before_link=current_node;
   	 }
    }
    else{
   	 printf("no node created\n");
    }
}
void insert_mid(int pos){
    int i;
    new_node=get_node();
    if(new_node!=NULL){
   	 current_node=head;
   	 while(current_node!=NULL&&current_node->data!=pos)
			 current_node=current_node->next_link;
			 if(current_node==NULL){
				 printf("\nelement not found\n");
			 }
			 else{
				 new_node->before_link=current_node;
				 new_node->next_link=current_node->next_link;
   			 next_node=new_node->next_link;
   			 next_node->before_link=new_node;
				 current_node->next_link=new_node;
			 }
   	 }
    else{
   	 printf("\nno node created\n");
    }
}
void display(){
    int count=0;
    printf("\n---------- Doubly linked list ---------\n\n");
    if(head==NULL)
   	 printf("empty");
    else{
   	 current_node=head;
   	 while(current_node!=NULL){
     		 printf(" |%d|",current_node->data);
     		 current_node=current_node->next_link;
        	 if(current_node!=NULL){
        		 printf("-->");
        	 }
   		 count=count+1;
   	 }
    }
    printf("\n\ncount : %d",count);
}
void delete_beg(){
    current_node=head;
	 if(head==NULL){
		 printf("\nempty\n");
	 }
    else if(current_node->next_link==NULL){
   	 free(current_node);
   	 head=NULL;
    }
	 else{
		 head=current_node->next_link;
		 next_node=head;
		 next_node->before_link=NULL;
		 free(current_node);
	 }
}
void delete_last(){
	 current_node=head;
	 if(head==NULL){
		 printf("\nempty\n");
	 }
    else if(current_node->next_link==NULL){
   	 free(current_node);
   	 head=NULL;
    }
	 else{
   	 while(current_node->next_link!=NULL) {
   		 current_node=current_node->next_link;
   	 }
   	 prev_node=current_node->before_link;
   	 prev_node->next_link=NULL;
		 free(current_node);
	 }
}
void delete_mid(int pos){
	 if(head==NULL){
		 printf("\nempty\n");
	 }
	 else{
         current_node=head;
         next_node=current_node->next_link;
         while(current_node->data!=pos&&current_node->next_link!=NULL){  
   		 next_node=next_node->next_link;
        	 current_node=current_node->next_link;
         }
         current_node->next_link=next_node->next_link;
         new_node=next_node->next_link;
         new_node->before_link=current_node->next_link;
         free(next_node);
     }
}
void main(){
    int ch;
    do{
   	 printf("\n ^^^^^^^^^^^^ M E N U ^^^^^^^^^^^^^\n");
   	 printf("\n1.insert first");
   	 printf("\n2.insert end");
   	 printf("\n3.insert mid");
   	 printf("\n4.delete first");
   	 printf("\n5.delete last");
   	 printf("\n6.delete mid");
   	 printf("\n7.display and count");
   	 printf("\n8.exit\n\nInputing...............\n\n\n");
   	 printf("- enter the choice(1/2/3/4/5/6/7/8)::_:_::");
   	 scanf("%d",&ch);

   	 switch(ch){
   		 case 1:
				 printf("\n// 1.To input at the first in the doubly linked list\n"); insert_beg();
   			 break;
   		 case 2:
   			 insert_last();
   			 break;
   		 case 3:
   			 printf("key : ");
   			 scanf("%d",&pos);
   			 insert_mid(pos);
   			 break;
   		 case 4:
				 delete_beg();
   			 break;
   		 case 5:
				 delete_last();
   			 break;
   		 case 6:
				 printf("key : ");
   			 scanf("%d",&pos);
				 delete_mid(pos);
   			 break;
   		 case 7:
   			 display();
   			 break;
   		 
   		 case 8:
   			 printf("EXIT");
   			 break;
   	 }
    }while(ch!=9);
}

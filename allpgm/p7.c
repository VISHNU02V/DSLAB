#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *lchild, *rchild;
};
struct node *root = NULL, *head, *ptr, *parent;
struct node *readData();
void insert();
void traversal();
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
void main(){
	int ch;
	do{
    	printf("Enter your choice:\n");
    	printf("1. Insertion\n");
    	printf("2. Traversal\n");
    	printf("3. Exit\n");
    	printf("Enter choice: ");
    	scanf("%d", &ch);
  
    	switch(ch){
        	case 1:
            	insert();
            	break;
        	case 2:
            	traversal();
            	break;
        	case 3:
            	printf("Goodbye\n");
            	break;
        	default:
            	printf("Invalid");
	}
	}while(ch!=3);
} 
struct node *readData(){
	struct node *new;
	new = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &new->data);
	new->lchild = new->rchild = NULL;
	return new;
}
void insert(){
	head = readData();
	if(root == NULL)
    	root = head;
	else{
    	ptr = root;
    	int flag = 0;
    	while(ptr!=NULL && flag == 0){
        	if(ptr->data < head->data){
                	parent = ptr;
                	ptr = ptr->rchild;
        	}
        	else if(ptr->data > head->data){
            	parent = ptr;
            	ptr = ptr->lchild;
        	}
        	else
            	flag = 1;
    	}
    	if(flag == 1)
        	printf("%d already exists\n", head->data);
    	else{
        	if(parent->data < head->data)
            	parent->rchild = head;
        	else
            	parent->lchild = head;
    	}
	}
}
void postorder(struct node *link){
	if(root == NULL)
    	printf("Tree is empty\n");
	else{
    	if(link != NULL){
        	postorder(link->lchild);
        	postorder(link->rchild);
        	printf("%d ", link->data);
    	}
	}
}
void preorder(struct node *link){
	if(root == NULL)
    	printf("Tree is empty\n");
	else{
    	if(link != NULL){
        	printf("%d ", link->data);
        	preorder(link->lchild);
        	preorder(link->rchild);
    	}
	}
}
 
void inorder(struct node *link){
	if(root == NULL)
    	printf("Tree is empty\n");
	else{
    	if(link != NULL){
            inorder(link->lchild);
        	printf("%d ", link->data);
        	inorder(link->rchild);
        }	
    }
}
void traversal(){
	int ch;
	do{
    	printf("Enter your traversal option:  \n");
    	printf("1. Preorder\n");
    	printf("2. Inorder\n");
    	printf("3. Postorder\n");
    	printf("4. EZxit\n");
    	printf("Enter choice: ");
    	scanf("%d", &ch);
  
    	switch(ch){
        	case 1:
            	preorder(root);
            	break;
        	case 2:
            	inorder(root);
            	break;
            case 3:
            	postorder(root);
	            break;
        	case 4:
            	printf("Back to the main menu...\n");
            	break;
        	default:
            	printf("Invalid");
        };
	}while(ch!=4);
}






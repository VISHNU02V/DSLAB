#include <stdio.h>
#include <math.h>
#define HASH_TABLE_SIZE 10

int hash_table[HASH_TABLE_SIZE]={0};
int hash(int data){
int sum=0;
while(data!=0){
sum+=(data%10)^2;
data/=10;
}
return sum%HASH_TABLE_SIZE;
}
int insert_ht(int ele){
int index=hash(ele);
if( hash_table[index]==0 ){
hash_table[index]=ele;
return 1;
}
int new_index=(index+1)%HASH_TABLE_SIZE;
while(new_index!=index){
if(hash_table[new_index]==0){
hash_table[new_index]=ele;
return 1;
}
new_index=(new_index+1)%HASH_TABLE_SIZE;
}
return 0;
}
int delete_ht(int ele){
int index=hash(ele);
if(hash_table[index]==ele){
hash_table[index]=0;
return 1;
}
int new_index=(index+1)%HASH_TABLE_SIZE;
while(new_index!=index){
if(hash_table[new_index]==ele){
hash_table[new_index]=0;
return 1;
}
new_index=(new_index+1)%HASH_TABLE_SIZE;
}
return 0;
}
void display_ht(){
printf("\n~~~~~ HASH TABLE ~~~~~\n\n\t--------\n");
for(int i=0;i<HASH_TABLE_SIZE;i++){

printf("\t| %d : ",i);
if(hash_table[i] !=0)
printf("%d",hash_table[i]);
printf(" |\n");
}
printf("\t--------");
}
int main(){
int value,ch;
char c;
do{
printf("\n\n////////// H A S H T A B L E ///////////\n\n\t- - - 1.INSERT - - - \n\t- - - 2.DELETE - - -\n\t- - - 3.DISPLAY - - -\n\t- - -4.exit - - -\n");
printf("\nenter your choice::");
scanf("%d",&ch);
switch(ch){
case 1:
printf("\n^^^^^^ TO INSERT INTO THE HASH TABLE ^^^^^^^^\n");
printf("Enter the key : ");
scanf("%d",&value);
if( insert_ht(value)==0 ){
printf("\nTable Full\n");
}
else{
printf("\n// %d has been inserted into the table successfully !!!!!!",value);
}
break;
case 2:
printf("\n^^^^^^ TO DELETE ELEMENT FROM THE HASH TABLE ^^^^^^^^\n");
printf("Enter the key : ");
scanf("%d",&value);
if( delete_ht(value)==0 ){
printf("\nElement not found\n");
}
else{
printf("\n// %d has been deleted from the table successfully !!!!!!",value);
}
break;
case 3:
display_ht();
break;
case 4:
printf(" E X I T ");
break;
break;
default:
printf("\nEnter a valid option\n");
}
}while(ch!=5);
return 0;
}

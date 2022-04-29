/*
AUTHOR : VISHNU V
CLASS  : S3 CSEB
ROLLNO : 53
*/
#include <stdio.h>
#include <stdlib.h>
int n;
void selection(int b[]){
for(int i=0;i<n;i++){
int min_index=i;
for(int j=i+1;j<n;j++){
if(b[j]<b[min_index]){
min_index=j;
}
}
if(min_index!=i){
int temp;
temp=b[i];
b[i]=b[min_index];
b[min_index]=temp;
}
}
printf("\noutput...................\nAfter selection sort\n");
for(int i=0;i<n;i++){
printf("%d ",b[i]);
}
printf("\n");
}
void insertion(int c[]) {
int i, j, current_val;
for(i = 1 ; i < n; i++){
current_val = c[i];
j = i-1;
while(j>=0 && current_val < c[j]){
c[j+1]=c[j];
j--;
}
c[j+1]=current_val;
}
printf("\noutput...................\nAfter selection sort\n");
for(int i=0;i<n;i++){
printf("%d ",c[i]);
}
printf("\n");
}
void main() {
char ch ='y';
int a[20],b[20],c[20];
int option;
printf("/////////////// S E L E C T I O N A N D I N S E R T I O N S O R T /////////// \n\n");
printf(" Enter the number of elements : ");
scanf("%d",&n);
printf(" Enter the elements : \n");

for(int i=0;i<n;i++){
scanf("%d",&a[i]);
b[i]=a[i];
c[i]=a[i];
}
do{
printf("\n########## M E N U ###########\n");
printf("\t1.Selection Sort");
printf("\n\t2.Insertion Sort");
printf("\n\t3.Display entered array");
printf("\n\t4.to exit");
printf("\nenter your chose(1:2:3:4)::_");
scanf("%d",&option);
printf("\n");
if(option==1){
selection(b);
}
else if(option==2){
insertion(c);
}
else if(option==3){
for(int i=0; i<n; i++)
printf("%d ", a[i]);
printf("\n\n");
}
else{
printf("E X I T E D .....");
break;
}
}while(ch=='y');
}

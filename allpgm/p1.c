/*
Question : Implementation of searching algorithms - linear and binary search
Author   : VISHNU V
Class    : CSE B
*/

#include <stdio.h>

void main(){
    int s,a[30];
    char ch='y';
    label:
    printf("\n\n\tCREATION OF ARRAY TO PERFORM THE SEARCHES ");
    printf("\n\nenter the max size of the array::");
    scanf("%d",&s);
    printf("\nenter the elements into the array:");
    for(int i=0;i<s;i++){
        scanf("%d",&a[i]);
    }
    do{
        int c;
        printf("\n  TO IMPLEMENT LINEAR AND BINARY SEARCH ");
        printf(" \n *************************************\n");
        printf("\n1. Linear Search");
        printf("\n2. Binary Search");
        printf("\n3. To enter new array");
        printf("\n4. Exit");
        printf("\nEnter your choice(1/2/3):: ");
        scanf("%d",&c);
        if(c==1){
            int b=0,flag=0;
            printf("\n// Have selected to implement : LINEAR SEARCH ");
            printf("\n\n L I N E A R    S E A R C H \n");
            printf(" \n ***************************\n");
            printf("\n enter the element to be found:\n ");
            scanf("%d",&b);
            printf(" \n  THE ARRAY IS :\n\n  [ ");
            for(int j=0;j<s;j++){
                printf("%d ,",a[j]);
            }
            printf("]");
            printf(" \n\n O U T P U T   F R O M   L I N E A R   S E A R C H ");
            printf(" \n ****************************************************\n");
            for(int i=0;i<s;i++){
                if(b==a[i]){
                    printf("\nelement found");
                    printf("\nelement ,%d, is found at %dth position of the array",a[i],i+1);
                    flag=1;
                }
            }
            if(flag==0){
                printf("\nelement is not found inside the array");
            }
            printf("\n\n  *---------------* *----------------*");
        }
        else if(c==2){
            int b=0,temp,mid,m;
            printf("\n// Have selected to implement : BINARY SEARCH ");
            printf("\n\n B I N A R Y   S E A R C H \n");
            printf(" \n ***************************\n");
            printf("\n enter the element to be found:\n ");
            scanf("%d",&b);
            printf(" \n  THE ARRAY IS :\n\n  [ ");
            for(int j=0;j<s;j++){
                printf("%d ,",a[j]);
            }
            printf("]");
            for(int i=0;i<s+1;i++){
                for(int j=0;j<(s);j++){
                    if(a[j]>a[j+1]){
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }
                }
            }
            printf(" \n  THE ARRAY AFTER SORTING IS :\n\n  [ ");
            for(int j=0;j<s;j++){
                printf("%d ,",a[j]);
            }
            printf("]");
            printf(" \n\n O U T P U T   F R O M   B I N A R Y   S E A R C H ");
            printf(" \n ****************************************************\n");
            int first=0,last=s-1;
            while(last>first){
                mid=(int)(last+first)/2;
                if(a[mid]==b){
                    m=mid;
                    break;
                }
                else if (a[mid]>b){
                    last=mid;
                }
                else{
                    first=mid;
                }
            }
            printf("The element ,%d, is found at %d th position",a[m],m+1);
        }
        else if(c==3){
            goto label;
        }
        else if(c==4){
            printf("E X I T I N G ..................");
            break;
        }
        printf("\n\n\n\n\ndo you want to continue: ");
        scanf("%s",&ch);
    }while(ch=='y');
    printf("\n\n\n***********************  T H A N K   Y O U  **************************");
}

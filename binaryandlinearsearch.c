// To search an element in array by linear and binary search

#include <stdio.h>
void sort(int a[],int n){
    int temp;
    for(int j=0;j<n;j++){                                                               // Sorting
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
}

void main(){
    char ch='y';
    int a[50],n,i=0;
    printf("Inputing ...........\n");
    front:
    printf("enter the limit:");
    scanf("%d",&n);
    printf("\nenter the elements into the array::\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);                                                              // Inputing array
    }
    do{
        int c,s,b,i=0,flag=0,low=0,high=n-1,mid;
        printf("\n\n ////// MENU DRIVEN ///// \n\n");
        printf("\n1.Linear Search");                                                    // Menu
        printf("\n2.Binary search");
        printf("\n3.To change array");
        printf("\nenter the chose(1/2)::");
        scanf("%d",&c);
        if(c==1){
            printf("\nLINEAR SEARCH ");
            printf("\nenter the number to be searched:");
            scanf("%d",&s);
            for(i=0;i<n;i++){
                if (a[i]==s){
                    printf("the element , %d , is present at %dth position of the array",s,i+1);
                    flag=1;
                }
            }
            if(flag==0){
                printf("\n %d is not found in the array",s);
            }
        }
        else if (c==2){
            printf("\n\n~~~~~~~~~~~ B I N A R Y   S E A R C H ~~~~~~~~~~\n\n");
            printf("THE ARRAY\n  [");
            for(i=0;i<n;i++){
                printf(" %d,",a[i]);
            }
            printf("]");
            printf("\nTHE SORTED ARRAY\n  [");
            for(i=n;i>0;i--){
                sort(a,n);
            }
            for(i=0;i<n;i++){
                printf(" %d,",a[i]);
            }
            printf("]\n\n\n\n# binary search starting ..............\n\n");
            printf("enter the element to be searched::");
            scanf("%d",&b);
            low=0;
            high=n-1;
            printf("\n~~~~~~~~~~~~~~ Output ...............\n");
            while (low<=high){
                mid=(int)(low+high)/2;
                if(b>a[mid]){
                    low=mid+1;
                }
                else if (b<a[mid]){
                    high=mid-1;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if (flag==0){
                printf("\n  element not found");
            }
            else{
                    printf("\n  element ,%d, found at %d th position",b,mid+1);
            }
        }
        else if (c==3){
            printf("ENTER THE NEW... ARRAY\n");
            goto front;
        }
        printf("\ndo you want to continue::");
        scanf("%s",&ch);
    }while(ch=='y');
}

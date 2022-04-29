// write program to implement the sparse matrix
#include <Stdio.h>

void main(){
    int a[30][30],r,c,b[30][3],c1[30][3],k=1,z=1;
    printf("\n\ninputing the array ......");
    printf("\nenter the row and column of the array:_r,c_:");
    scanf("%d,%d",&r,&c);
    printf("\nenter the elements into the array:");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nTHE ORIGINAL MATRIX IS :\n\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("  %d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]!=0){
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    b[0][0]=r;
    b[0][1]=c;
    b[0][2]=k-1;
    printf("\n SPARSE MATRIX\n\n");
    for(int i=0;i<k;i++){
        for(int j=0;j<3;j++){
            printf("     %d  ",b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n TRANSPOSE OF SPARSE MATRIX\n");
    for(int i=0;i<b[0][1];i++){
        for(int j=1;j<=b[0][2];j++){
            if(b[j][1]==i){
                c1[z][0]=b[j][1];
                c1[z][1]=b[j][0];
                c1[z][2]=b[j][2];
                z++;
            }
        }
    }
    c1[0][0]=b[0][1];
    c1[0][1]=b[0][0];
    c1[0][2]=b[0][2];
    printf("\n");
    for(int i=0;i<k;i++){
        for(int j=0;j<3;j++){
            printf("    %d  ",c1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
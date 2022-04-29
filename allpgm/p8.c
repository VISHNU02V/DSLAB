#include<stdio.h>
void DFS(int);
int g[10][10],visited[10],n;
void main(){
    int i,j,ch;
    printf("enter the number of vertices");
    scanf("%d",&n); 
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            printf("if you want an edge from %d to %d (0/1)",i,j);
            scanf("%d",&ch);
            if(ch==1){
                g[i][j]=1;
                g[j][i]=1;
            }
            if(ch==0){
                g[i][j]=0;
                g[j][i]=0;
            }
        }
    }
    printf("     \n\n\t\tO U T P U T  \n\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("\t%d",g[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++){
        visited[i]=0;
        DFS(0);
    }
}

void DFS(int i){
    int j;
    printf("\n%d",i);
    visited[i]=1;
    for(j=0;j<n;j++){
        if(!visited[j]&&g[i][j]==1){
            DFS(j);
        }
    }
}

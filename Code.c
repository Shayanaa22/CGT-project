#include<stdio.h>
#include<stdlib.h>
int a, b;
struct node{
    int data;
    struct node* nxt;
};

//adjacency list

void insert(struct node**arr,int h, int data){
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->nxt=NULL;
    if(arr[h]==NULL){
        arr[h]=newnode;
        return;
    }
    struct node* temp=arr[h];
    while(temp->nxt!=NULL){
        temp=temp->nxt;
    }
    temp->nxt=newnode;
}

struct node** create_ll(){
    struct node** arr= (struct node**)malloc(sizeof(struct node)*a);
    for(int i=0; i<a; i++){
        arr[i]=NULL;
    }

    for(int i=0; i<b; i++){
        int a, b;
        scanf("%d %d",&a, &b);
        insert(arr,a,b);
        insert(arr,b,a);
    }

    return arr;
}

void checker(struct node** arr, int r){
    for(int k=0; k<r; k++){
        struct node*temp=arr[k];
        printf("%d ",k);
        if(temp!=NULL){
        while(temp->nxt!=NULL){
            printf("%d ",temp->data);
            temp=temp->nxt;
        }
        printf("%d",temp->data);
        }
        printf("\n");
    }
}

//DFS
int *visited;;

void DFS(int start, struct node** arr){
    
    struct node* temp=arr[start];
    visited[start]=1;
    printf("%d ",start);
    if(temp!=NULL){
    while(temp->nxt !=NULL){
        if(visited[temp->data]==0)
           DFS(temp->data, arr);
        temp=temp->nxt;
    }
    if(visited[temp->data]==0)
      DFS(temp->data,arr);
    }
}

int next_start(){
    for(int i=0; i<a; i++){
        if(visited[i]==0){
            return i;
        }
    }
    return -1;
}




int main(){
    struct node** arr;
    scanf("%d %d", &a, &b); //a=no_vertices, b=no_edges
    visited=(int *)malloc(sizeof(int)*a);
    arr=create_ll(a,b);
    //checker(arr,a);
    for(int i=0;i<a;i++)
    {
        visited[i]=0;
    }
    int k=0;
    int t=next_start(a);
    printf("CONNECTED COMPONENTS:\n");
    while(t!=-1){
        DFS(t,arr);
        printf("\n");
        k++;
        t=next_start(a);
    }
    printf("NUMBER OF CONNECTED COMPONENTS: %d", k);
    

    return 0;
}

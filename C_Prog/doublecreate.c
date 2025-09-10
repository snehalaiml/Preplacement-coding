#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
int main (){
    int n,i;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    struct node *head=NULL;
    struct node *current=NULL;
    for(i=0;i < n;i++){
        int v;
        scanf("%d",&v);
        struct node *newnode=malloc(sizeof(struct node));
        newnode -> data=v;
        newnode -> next=NULL;
        newnode -> prev=NULL;
        if(head == NULL){
            head=newnode;
            current=head;
        }
        else{
            current -> next=newnode;
            newnode -> prev=current;
            current=newnode;
        }
    }
   // printf("list forward\n");
    struct node *temp=head;
    while(temp != NULL){
        printf("%d <->",temp -> data);
        temp=temp -> next;
    }
    printf("null\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node* prev;
struct node* next;
}node;

node* getnew(int value)
{
node* temp=(node*)malloc(sizeof(node));
temp->data=value;
temp->prev=NULL;
temp->next=NULL;
return temp;
}

node* insert(node* head,int value)
{
node* temp;
if(head==NULL){
head=getnew(value);
//printf("%d ",head->data);
}
else
{
temp=getnew(value);
temp->next=head;
head->prev=temp;
head=temp;
//printf("%d ",head->data);
}
return head;

}

void revprint(node* head)
{
node* temp=head;
while((temp->next)!=0)
{
    temp=temp->next;
}
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->prev;
}

}

node* insertend(node* head,int value)
{
node* temp;
node* temp1;
temp1=head;
if(head==NULL)
    head=getnew(value);
else
{
temp=getnew(value);
while((temp1->next)!=NULL)
{
    temp1=temp1->next;
}
temp1->next=temp;
temp->prev=temp1;
}
return head;
}


int main()
{
int n,i,x;
printf("\nenter the size of the doubly linked list:");
scanf("%d",&n);
node* head;
node* temp;

head=NULL;
for(i=0;i<n;i++)
{
printf("\nenter the element:");
scanf("%d",&x);
head=insertend(head,x);
revprint(head);
}


}

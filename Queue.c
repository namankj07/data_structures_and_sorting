#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node* next;
}node;


node* getnew(int value)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=value;
    temp->next=NULL;

    return temp;
}

void push(node** front,node** rear,int value)
{
node* temp;
  if((*front)==NULL && (*rear)==NULL)
  {
          temp=getnew(value);
          (*front)=temp;
          (*rear)=temp;
  }
  else if((*front)==(*rear) && (*front)!=NULL)
  {
        temp=getnew(value);
        (*rear)->next=temp;
        (*rear)=temp;
  }
  else if ((*front)!=(*rear) && (*front)!=NULL)
  {

        temp=getnew(value);
        (*rear)->next=temp;
        (*rear)=temp;
  }
//printf("%d",(*front)->data);
}

void pop(node** front,node** rear)
{
node* temp;
    if((*front)==NULL && (*rear)==NULL)
    {
        printf("\nlist is already empty");
        return;
    }
    else if((*front)==(*rear) && (*front)!=NULL)
    {
        temp=(*front);
        free(temp);
        (*front)=NULL;
        (*rear)=NULL;
        printf("\n list is now empty");
        return;
    }
    else if ((*front)!=(*rear) && (*front)!=NULL)
    {
        temp=(*front);
        (*front)=(*front)->next;
        free(temp);
    }

}

void print(node* head)
{
printf("\n");
node* temp;
temp=head;

while(temp!=NULL)
{
    printf("%d ",temp->data);
    temp=temp->next;
}

}


int main()
{
node* front;
node* rear;
front=NULL;
rear=NULL;
push(&front,&rear,10);
print(front);
push(&front,&rear,20);
print(front);
push(&front,&rear,30);
print(front);
push(&front,&rear,40);
print(front);
push(&front,&rear,50);
print(front);
pop(&front,&rear);
print(front);
pop(&front,&rear);
print(front);
pop(&front,&rear);
print(front);
pop(&front,&rear);
print(front);
pop(&front,&rear);
print(front);
pop(&front,&rear);
print(front);
pop(&front,&rear);
print(front);
push(&front,&rear,50);
print(front);

}

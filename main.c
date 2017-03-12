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

void push(node** top,int value)
{
    node* temp1;

    if((*top)==NULL)
    {
        (*top)=getnew(value);

    }
    else
    {
        temp1=getnew(value);
        temp1->next=(*top);
        *top=temp1;
    }

}

void pop(node** top)
{
    node* temp=(*top);
    (*top)=(*top)->next;
    free(temp);
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

int top(node* head)
{
    int x;
    x=head->data;
    return x;
}

void reverse(node** head)
{
node* stack;
stack=NULL;
node* temp;
temp=(*head);

while(temp!=NULL)
{
    push(&stack,temp);
    temp=temp->next;
}

temp=top(stack);
(*head)=temp;
pop(&stack);

while(stack!=NULL)
{

    temp->next=top(stack);
    pop(&stack);
    temp=temp->next;

}
temp->next=NULL;

}



int main()
{
int n,i,x;
node* head;
head=NULL;
printf("\nenter the number of integers you want in your list:");
scanf("%d",&n);


for(i=0;i<n;i++)
{
    printf("\nenter the number:");
    scanf("%d",&x);
    push(&head,x);

}
printf("\nthe list after insertion looks like:");
print(head);
reverse(&head);
printf("\nthe list after reversal looks like:");
print(head);

}

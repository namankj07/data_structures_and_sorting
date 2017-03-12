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

node* insert_end(node* head,int value)
{
  node* temp1;

    if(head==NULL)
    {
          head=getnew(value);
    }
    else
    {
            temp1=head;
            while(temp1->next!=NULL)
            {
             temp1=temp1->next;
            }
            temp1->next=getnew(value);
    }

return head;

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
node* reverse(node* head)
{
node *temp,*temp1;
temp=head;
temp1=head;
temp=temp->next;
temp1->next=NULL;
while (temp!=NULL)
{
    temp1=temp;
    temp=temp->next;
    temp1->next=head;
    head=temp1;
}
return head;
}

void recursive_rev(node** head,node* p)
{
if(p->next==NULL)
{
   *head=p;
   return;
}
else{
//printf("\nloop entered");
recursive_rev(&(*head),p->next);
(p->next)->next=p;
p->next=NULL;
}

}

int main()
{
    int n,i,x,y,z,k,q,p;
node* head;
head=NULL;
printf("\nenter the number of integers you want in your list:");
scanf("%d",&n);


for(i=0;i<n;i++)
{
    printf("\nenter the number:");
    scanf("%d",&x);
    head=insert_end(head,x);
    printf("\nthe list after insertion looks like:");
    print(head);
}

printf("\nthe list after reversal looks like:");
recursive_rev(&head,head);
print(head);


}

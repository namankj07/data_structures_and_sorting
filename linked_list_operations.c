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

node* insert_beg(node* head,int value)
{
    node* temp1;

    if(head==NULL)
    {
        head=getnew(value);

    }
    else
    {
        temp1=getnew(value);
        temp1->next=head;
        head=temp1;
    }
return head;

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

node* insert_nth(node* head, int n,int value)
{
node *temp,*temp1;
int i;
temp=head;

if(n==1)
{
temp1=getnew(value);
temp1->next=temp;
head=temp1;
}
else if(n==2)
{
temp1=getnew(value);
temp1->next=temp->next;
temp->next=temp1;
}

else if(n>=3)
{

for(i=1;i<n-1;i++)
{
temp=temp->next;
}

temp1=getnew(value);
temp1->next=temp->next;
temp->next=temp1;

}
return head;

}

node* delete(node* head,int n)
{
int i;
node *temp,*temp1;
temp=head;
if(n==1)
{
    head=head->next;
    free(temp);
}
else if(n==2)
{
temp1=temp->next;
temp->next=(temp->next)->next;
free(temp1);
}

else if(n>=3)
{
int i;
for(i=0;i<n-2;i++)
{
    temp=temp->next;
}
temp1=temp->next;
temp->next=(temp->next)->next;
free(temp1);
}
return head;
}

void print(node* head)
{
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

printf("\nenter the number of values that you want to insert");
scanf("%d",&q);

for(i=0;i<q;i++)
{
printf("\nenter the value you want to insert:");
scanf("%d",&y);
printf("\nenter the position at which u want to add the number:");
scanf("%d",&z);
head=insert_nth(head,z,y);
print(head);

}
printf("\nenter the number of values that you want to delete");
scanf("%d",&p);

for(i=0;i<q;i++)
{
printf("\nenter the position at which u want to delete the number:");
scanf("%d",&z);
head=delete(head,z);
print(head);

}

}

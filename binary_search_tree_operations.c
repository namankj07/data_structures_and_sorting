#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
int data;
struct node* left;
struct node* right;
}node;

node* getnew(int value)
{
node* temp=(node*)malloc(sizeof(node));
temp->data=value;
temp->left=NULL;
temp->right=NULL;
return temp;
}

void inorder(node* head)
{
if(head!=NULL)
{
//printf("\ninfinite loop entering");
inorder(head->left);
printf("%d ",head->data);
inorder(head->right);
}
else
return;

}

void insert(node** head,int value)
{
    if(*head==NULL)
    {
        *head=getnew(value);
    }
    else
    {
        if(value<(*head)->data &&  (*head)->left==NULL)
            (*head)->left=getnew(value);
        else if(value>=(*head)->data && (*head)->right==NULL)
            (*head)->right=getnew(value);
        else if(value<((*head)->data) && (*head)->left!=NULL)
            insert(&((*head)->left),value);
        else if(value>=(*head)->data && (*head)->right!=NULL)
            insert(&((*head)->right),value);
    }

}

int find_max(node* head)
{
if(head->right==NULL)
    return head->data;
else
    find_max(head->right);

}

void delete(node** head,int value)
{
if(((*head)->data)<value && (*head)->right!=NULL)
{
    delete (&((*head)->right),value);
}
if(((*head)->data)>value && (*head)->left!=NULL)
{
    delete (&((*head)->left),value);
}

if((*head)->data==value)
{
    if((*head)->left == NULL && (*head)->right==NULL)
    {
        node* temp=(*head);
        (*head)=NULL;
        free(temp);
    }

    else if((*head)->left==NULL && (*head)->right!=NULL)
    {
        node* temp=(*head);
        (*head)=(*head)->right;
        free(temp);
    }

    else if((*head)->left!=NULL && (*head)->right==NULL)
    {
        node* temp=(*head);
        (*head)=(*head)->left;
        free(temp);
    }
    else if((*head)->left!=NULL && (*head)->right!=NULL)
    {
        int x;
        x=find_max((*head)->left);
        (*head)->data=x;
        delete(&((*head)->left),x);
    }
}
}

int search(node* head,int value)
{
if((head->data)>value && head->left!=NULL)
        search(head->left,value);
else if((head->data)<value && head->right!=NULL)
        search(head->right,value);
else if((head->data)>value && head->left==NULL)
        return 0;
else if((head->data)<value && head->right==NULL)
        return 0;
else if((head->data)==value)
        return 1;
}

int main()
{
int n,x,i,z,q,p,r,w;
node* head;
head=NULL;

printf("\nenter the number of values that you want to insert in the tree:");
scanf("%d",&n);

for(i=0;i<n;i++)
{
 printf("\nenter the value:");
 scanf("%d",&x);
 insert(&head,x);
}
//z=find_max(head);
//printf("\nthe maximum integer in the list is %d ",z);

printf("\nthe tree after insertion looks like:");
inorder(head);

printf("\nenter the number of values that you want to delete:");
scanf("%d",&q);
for(i=0;i<q;i++)
{
  printf("\nenter the value:");
  scanf("%d",&p);
  delete(&head,p);
  printf("\nthe tree after deletion looks like:");
  inorder(head);
}
printf("\nenter the number of values that you need to search:");
scanf("%d",&r);
for(i=0;i<r;i++)
{
printf("\nenter the value:");
scanf("%d",&p);
w=search(head,p);
if(w==1)
    printf("\nthe number is found");
else if(w==0)
    printf("\nthe number is not found");
}
}

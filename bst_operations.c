#include <stdio.h>
#include <stdlib.h>


typedef struct node {
int value;
struct node* left;
struct node* right;
}node;

node* newnode(int data)
{

node* new1 = (node*)malloc(sizeof(node));
new1->value=data;
new1->left=NULL;
new1->right=NULL;

return new1;
}

void insert(node** root,int data)
{

if(*root==NULL)
{
*root=newnode(data);
}

else if(data<=((*root)->value))
{
insert(&((*root)->left),data);
}

else if(data>((*root)->value))
insert(&((*root)->right),data);
}



void inorder(node* root)
{
if(root!=NULL)
{
inorder(root->left);
printf("%d ",root->value);
inorder(root->right);
}
}

node* find_min(node* root)
{
while(root->left!=NULL)
find_min(root->left);
return root;
}






void delete(node** root,int data)
{
//printf("the current value of root is %d \n",(*root)->value);
if((*root)!=NULL)
{

if(((*root)->value)>data)
{
//printf( "loop entered \n");
delete(&((*root)->left),data);
}
else if((*root)->value<data)
{
//printf("1st loop entered \n");
delete(&((*root)->right),data);

}
else if((*root)->value==data)
{
//printf("2nd loop entered \n");

if((*root)->left==NULL && (*root)->right==NULL)
{
//printf("final loop entered \n");
//printf("the root value is %d ",(*root)->value);
node* temp= *root;
*root=NULL;
free(temp);
}

else if((*root)->left==NULL && (*root)->right!=NULL )
{
//printf(" wrong loop entered");
//printf("the final loop entered");
node* temp = (*root)->right;
free(*root);
*root=temp;
}

else if((*root)->right==NULL && (*root)->left!=NULL )
{
//printf(" wrong loop entered");
node* temp = (*root)->left;
free(*root);
*root=temp;
}

else if((*root)->left!=NULL && (*root)->right!=NULL)
{
//printf(" 1st loop entered");
node* root2;
root2=find_min((*root)->right);
//printf("the minimum value is %d",root2->value);
(*root)->value=root2->value;
delete(&((*root)->right),root2->value);
}
//printf("%d",(*root)->value);
}


}




}





void main()
{

int n,i,j,x;
printf("enter the size of the array \n");
scanf("%d",&n);
int a[n];
printf("enter the elements of the array \n");
for(i=0;i<n;i++)
{
 scanf("%d",&a[i]);
}
node* root=NULL;
for(j=0;j<n;j++)
{
insert(&root,a[j]);
}
inorder(root);

printf(" \n enter the data to be deleted:");
scanf("%d",&x);
delete(&root,x);
//printf("the root value is %d ",root->value);

printf("\n");

printf("the tree after deletion of the element looks like :");
inorder(root);
}

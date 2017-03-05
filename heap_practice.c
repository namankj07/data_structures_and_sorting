#include <stdio.h>
#include <stdlib.h>

int* siftdown(int a[],int n,int i)
{
int left=2*i+1;
int right=2*i+2;
int largest=i;

if(i<=n/2-1)
{
if(a[left]>a[i])
{
    largest=left;
}
if(a[right]>a[largest])
{
    largest=right;
}
if(largest!=i)
{
  int temp=a[i];
  a[i]=a[largest];
  a[largest]=temp;
  a=siftdown(a,n,largest);
}
}

return a;
}

int* percolation(int a[],int n,int i)
{
if((i/2-1)>=0)
{
if(a[i]>a[i/2-1])
{
int temp=a[i];
a[i]=a[i/2-1];
a[i/2-1]=temp;
a=percolation(a,n,(i/2-1));
}
}
return a;
}

int* buildmax(int a[],int n)
{
int i;
for(i=n/2-1;i>=0;i--)
{
    a=siftdown(a,n,i);
}
return a;
}

int* heapsort(int a[],int n)
{
int i,j;
printf("\n");
for(i=0;i<n;i++)
{
    a=buildmax(a,n-i-1);
    int temp=a[0];
    a[0]=a[n-i-1];
    a[n-i-1]=temp;
}
return a;
}

int* deletemax(int a[],int n)
{
int i;
a=buildmax(a,n);
int temp=a[0];
a[0]=a[n-1];
a[n-1]=temp;
printf("\n");
for(i=0;i<n;i++)
    printf("%d ",a[i]);
a=buildmax(a,n-2);
for(i=0;i<n;i++)
    printf("%d ",a[i]);
return a;
}

int* insert(int a[],int n,int val)
{
a[n]=val;
a=buildmax(a,n+1);
return a;
}


int main()
{
int n,i,x;
int* a=(int*)malloc(sizeof(int));
printf("\nenter the number of elements of a max heap:");
scanf("%d",&n);
printf("\nenter the elements of the array:");
for(i=0;i<n;i++)
{
        scanf("%d",&a[i]);
}
a=buildmax(a,n);
printf("\nthe elements of max heap are:");
for(i=0;i<n;i++)
{
    printf("%d ",a[i]);
}
printf("enter the value to be inserted");
scanf("%d",&x);

a=insert(a,n,x);
printf("\nthe elements of max heap after inserting one more element are:");
for(i=0;i<=n;i++)
{
    printf("%d ",a[i]);
}



}

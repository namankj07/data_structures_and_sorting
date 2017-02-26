#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>



int* max_heapify(int a[],int n,int i)
{

    if(i<=n/2-1)
    {
        int k;
        int temp;
        int left=2*i+1;
        int right=2*i+2;
        int largest;
        if(left<n && a[left]>a[i])
        {
            largest=left;
        }
        else
            largest=i;

        if(right<n && a[right]>a[largest])
        {
            largest=right;
        }
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        //for(k=0;k<n;k++)
        //{
          //  printf("%d ",a[k]);
        //}
        if(largest!=i)
        max_heapify(a,n,largest);
    }

return a;
}

int* build_heap(int a[],int n)
{
int j;

 for(j=n/2-1;j>=0;j--)
{
    a=max_heapify(a,n,j);
}
return a;
}

int* delete_max(int a[],int n)
{
    int temp;
    temp=a[0];
    a[0]=a[n-1];
    a[n-1]=temp;

    a=max_heapify(a,n-1,0);
}

int* heap_sort(int a[],int n)
{
int i,j,temp;
int temp1[n];

for(i=0;i<n;i++)
temp1[i]=0;

for(i=0;i<n;i++)
{   temp=a[0];
    a[0]=a[n-i-1];
    a[n-i-1]=temp;


    a=max_heapify(a,n-i-1,0);
    //for(j=0;j<n;j++)
    //printf("%d ",a[j]);
    //printf("\n");
}
//for(j=0;j<n;j++)
//printf("%d ",a[j]);

return a;

}

int* insert(int a[],int n,int x)
{
a[n]=x;
a=build_heap(a,n+1);

return a;
}

int main()
{

int i,n,j,k,val,x;
printf("enter the size of the array: \n");
scanf("%d",&n);
int* a=(int*)malloc(sizeof(int));

printf("\nenter the elements of the array:");

for (i=0;i<n;i++)
{
    scanf("%d",&a[i]);
}
a=build_heap(a,n);

printf("the build heap is: \n");
for(k=0;k<n;k++)
{
    printf("%d ",a[k]);
}
printf("\nenter the value of the element that you want to insert:");
scanf("%d",&x);

a=insert(a,n+1,x);
printf("\n");

printf("the heap after inserting an element is : \n");
for(k=0;k<=n-1;k++)
{
    printf("%d ",a[k]);
}
a=delete_max(a,n);



printf("\nthe heap after deleting the max element is: \n");
for(k=0;k<n-1;k++)
{
    printf("%d ",a[k]);
}
printf("\n");
a=heap_sort(a,n-1);
printf("\nthe heap after sorting is : \n");
for(k=0;k<n-1;k++)
{
    printf("%d ",a[k]);
}



}

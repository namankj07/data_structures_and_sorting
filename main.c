#include <stdio.h>
#include <stdlib.h>
#include<conio.h>


int* insertionsort(int n,int a[])
{
  int x,i,j;
  for(i=2;i<n;i++)
    {
      x=a[i];
      j=i-1;
      while(j>=0 && x<a[j])
    {
              a[j+1]=a[j];
              j--;
     }
      a[j+1]=x;
}

  return (a);
}

void merge(int a[],int p, int q,int r)
{
int i,j,k,n1,n2;
n1=q-p+1;
n2=r-q;
//int L=(int*)malloc(sizeof(int)*(n1));
//int *R=(int*)malloc(sizeof(int)*(n2));
int L[n1];
int R[n2];

for(i=0;i<n1;i++)
{
   L[i]=a[p+i];
}
for(j=0;j<n2;j++)
{
   R[j]=a[j+q+1];
}
i=0;
j=0;
k=p;

while(i<n1 && j<n2)
{

if (L[i]<=R[j])
{
    a[k]=L[i];
    i++;
}
else
{
    a[k]=R[j];
    j++;
}
k++;
}
while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }


while (j < n2)
  {
        a[k] = R[j];
        j++;
        k++;
    }

}

void merge_sort(int a[],int p,int r)
{

int q,i;
//c=0;
if((r-p)>4)
{
    q=p+(r-p)/2;
    merge_sort(a,p,q);
    merge_sort(a,q+1,r);
    merge(a,p,q,r);
    //printf("the count is %d \n",c);
    //c++;
}
else
{   int comp,swap;
    comp=0;
    swap=0;
    int i,j,temp;
    for (i=p+1;i<=r;i++)
    {  temp=a[i];
        for(j=i-1;j>=p;j--)
        { comp++;
            if(a[j]>temp)

            {
               swap++;
               a[j+1]=a[j];

            }
            else
            {
              break;
            }
        }
a[j+1]=temp;
    }
}

}
void main()
{
  int n,i,j;
  int *numlist = (int*)malloc(n*sizeof(int));
  int *sorted_array;
 // int *sortedarray = (int*)malloc(n*sizeof(int));
printf("enter the size of the array \n");
scanf("%d",&n);
printf("enter the values of the elements of the array \n ");
for(i=0;i<n;i++)
   {
     scanf("%d",&numlist[i]);
   }

//sortedarray=merge_sort(numlist,0,(n-1));

merge_sort(numlist,0,(n-1));
sorted_array = numlist;
for(j=0;j<n;j++)
 {
   printf("%d ",sorted_array[j]);
 }

}

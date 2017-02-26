#include <stdio.h>
#include <stdlib.h>

int partition(int a[],int low,int high)
{
int i,j,k,temp,temp1,pivot;
i=low;
pivot=a[low];
for(j=i+1;j<=high;j++)
{
 if(a[j]<pivot)
 {
    i++;
    //printf("the valur of i is %d ",i);
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    //printf("\n");
    //for (k=low;k<=high;k++)
    //{
      //printf("%d ",a[k]);

    //}
 }
}
temp1=a[i];
a[i]=a[low];
a[low]=temp1;
return (i);
}

void quick_sort(int a[],int low,int high)
{
if(low<high)
{
int x;
x=partition(a,low,high);
 //printf("the place of pivot element is at %d ",x);
  quick_sort(a,low,x-1);
  quick_sort(a,x+1,high);
}
}
/*
else if(x==0)
{
quick_sort(a,x+1;high);
}
else if (x==high)
{
quick_sort(a,low,x-1);
}
}
else
return;
}

*/
void main()
{
int n,i,j;
printf("enter the size of the array \n");
scanf("%d",&n);
int arr[n];
printf("enter the elements of the array \n");
for(i=0;i<n;i++)
{
 scanf("%d",&arr[i]);
}
quick_sort(arr,0,n-1);

printf("The sorted array is \n ");
for(j=0;j<n;j++)
{
printf("%d ",arr[j]);
}



}



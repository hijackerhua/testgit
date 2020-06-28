#include<stdio.h>
#include<malloc.h>

typedef int ElemType;

void Merge(ElemType A[],int low,int mid,int high);
void Mergesort(ElemType A[],int low,int high);
ElemType B[9];

int main()
{
    int A[8] = {7,6,5,4,3,2,1,0};
    Mergesort(A,0,7);
    int i;
    for(i=1;i<8;i++)
        printf("%d",B[i]);
}

void Merge(ElemType A[],int low,int mid,int high)
{
    int i,j,k;
    for(k=low;k<=high;k++)
        B[k] = A[k];
    for(i=low,j=mid+1,k=i;i<=mid && j<=high;k++)
    {
        if(B[i]<=B[j])
            A[k]=B[i++];
        else 
            A[k]=B[j++];
    }
    while(i<=mid)
    {
        A[k++] = B[i++];
    }
    while(j<=high)
    {
        A[k++] = B[j++];
    }
}
void Mergesort(ElemType A[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        Mergesort(A,low,mid);
        Mergesort(A,low+1,high);
        Merge(A,low,mid,high);
    }
}
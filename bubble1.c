#include<stdio.h>

void BubbleSort(int *arr,int sz);
//函数指针
void Test(void (*BubbleSort)(int *arr,int sz));

int main()
{
    Test(BubbleSort);
    return 0;
}

//从尾向头遍历
//相邻两数进行比较
//将最小数冒泡到头部
void BubbleSort(int *arr,int sz)
{
    int i = 0;
    int j = 0;
    for(i=0;i<sz-1;i++){
        for(j=sz-1;j>i;j--){
            if(arr[j]<arr[j-1]){
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
}

//测试函数
//为了方便起见,将参数设定为一个函数指针
void Test(void (*BubbleSort)(int *arr,int sz)){
    int arr[]={1,3,5,7,9,2,4,6,8,0};
    int i = 0;
    int sz = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,sz);
    for(i=0; i<sz; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
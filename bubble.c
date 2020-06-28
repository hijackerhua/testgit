#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//从头向尾遍历
//相邻两数进行比较
//将最大数(相对)沉入尾部(相对)
void BubbleSort1(int *arr,int sz){
    int i = 0;
    int j = 0;
    assert(arr);
    for(i=0;i<sz-1;i++){
        for(j=0;j<sz-i-1;j++){
            if(arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
//从尾向头遍历dddddddd
//相邻两数进行比较
//将最小数(相对)冒泡到头部(相对)
void BubbleSort2(int *arr,int sz){
    int i = 0;
    int j = 0;
    assert(arr);
    for(i=0;i<sz-1;i++){
        for(j=sz;j>i;j--){
            if(arr[j]>arr[j-1]){
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
    //mmmmmm
}
//测试函数
//为了方便起见,将参数设定为一个函数指针
void TestBubbleSort(void (*BubbleSort)(int *arr,int sz)){
    int arr[]={1,3,5,7,9,2,4,6,8,0};
    int i = 0;
    int sz = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,sz);
    for(i=0; i<sz; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    TestBubbleSort(BubbleSort1);
    TestBubbleSort(BubbleSort2);
    system("pause");
    return 0;
}
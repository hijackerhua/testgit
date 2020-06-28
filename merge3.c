#include<stdio.h>
#include<string.h>

//分组归并
void _Merge(int *a, int left1, int right1, int left2, int right2, int *tmp);
//归并排序
void MergeSort(int *a, int left, int right, int *tmp);
//打印数组
void PrintArray(int *a, int len);

int main()
{
    int a[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	int *tmp = (int *)malloc(sizeof(int)*(sizeof(a) / sizeof(int)));
    //初始化tmp
	memset(tmp, 0, sizeof(a) / sizeof(int));
	MergeSort(a, 0, sizeof(a) / sizeof(int)-1, tmp);
	PrintArray(a, sizeof(a) / sizeof(int));
    return 0;
}

//分组归并
void Merge(int *a, int left1, int right1, int left2, int right2, int *tmp)
{
	int index = left1;
	int i = left1, j = right2;
	//二路归并
	while (i <= right1&&j <= right2){
		if (a[i]<=a[j])
			tmp[index++] = a[i++];
		else
			tmp[index++] = a[j++];
	}
	//将左边元素填充到tmp中
	while (i <= right1)
		tmp[index++] = a[i++];
	//将右边元素填充的tmp中
	while (j <= right2)
		tmp[index++] = a[j++];
	//将tmp中的数据拷贝到原数组对应的序列区间
	memcpy(a + left1, tmp + left1, sizeof(int)*(right2 - left1 + 1));
}
//归并排序
void MergeSort(int *a, int left, int right, int *tmp)
{
	if (left >= right)
		return;
	//mid将数组二分
	int mid = (left+right)/2;
	//左边归并排序,使得左子序列有序
	MergeSort(a, left, mid, tmp);
	//右边归并排序,使得右子序列有序
	MergeSort(a, mid + 1, right, tmp);
	//将两个有序子数组合并
	Merge(a, left, mid, mid + 1, right, tmp);
}
//打印数组
void PrintArray(int *a, int len)
{
    int i;
	for (i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");
}
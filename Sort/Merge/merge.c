// 1. 归并排序是递归的
// 2. 递归退出条件是待排序数组只有一个元素，此时数组的已排序的
// 3. 最后执行对已排序的两个数组进行Merge操作
// 4. O(N log N)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "index.h"

#define MAX 100
#define TEST_COUNT 100
#define TEST_MAX 1000

void CreateRandomNumber(int *arr, int n, int max)
{
	srand((unsigned)time(NULL));
	int i;
	for (i = 0; i < n; i++) 
		*arr++ = rand() % max;
	*arr = '\0';
}
void printArr(int *arr)
{
	int *tmp = arr;
	while (*tmp) printf("%d  ", *tmp++);
}

void Swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b; 
	*b = tmp;
}

int main(int argc, char const *argv[])
{
	int test_number[MAX];
	CreateRandomNumber(test_number, TEST_COUNT, TEST_MAX);
	MergeSort(test_number, TEST_COUNT);
	printArr(test_number);
	return 0;
}


void MSort(int *a, int *tmp, int left, int right)
{
	int middle;
	if (left < right) {
		middle = (left+right) / 2;
		MSort(a, tmp, left, middle);
		MSort(a, tmp, middle+1, right);
		// Merge并不是退出基条件后执行的，所以放在函数返回后执行是正确的
		// 主要区分基条件执行和退出前一递归后执行所在的位置
		Merge(a, tmp, left, middle+1, right);
	}
}

void Merge(int *a, int *tmp, int Lpos, int Rpos, int RightEnd)
{
	int leftEnd, tmpPos, Lpos_tmp;
	leftEnd = Rpos-1;
	Lpos_tmp = tmpPos = Lpos;

	while (Lpos <= leftEnd && Rpos <= RightEnd) {
		if (a[Lpos] < a[Rpos])
			tmp[tmpPos++] = a[Lpos++];
		else 
			tmp[tmpPos++] = a[Rpos++];
	}
	while (Lpos <= leftEnd)
		tmp[tmpPos++] = a[Lpos++];
	while (Rpos <= RightEnd)
		tmp[tmpPos++] = a[Rpos++];
	// 执行完毕后 Lpos 和 RightEnd 是已排序序列
	while(Lpos_tmp <= RightEnd)
		a[Lpos_tmp] = tmp[Lpos_tmp++];
}

void MergeSort(int *a, int n)
{
	int *tmp;
	// 我们在这里生成一个tmp数组，而不是在递归的时候再生成，在很多情况下，会节省大量的空间
	tmp = (int*)malloc(n*sizeof(int));
	if (tmp != NULL) {
		MSort(a, tmp, 0, n-1);
		free(tmp);
	}
}
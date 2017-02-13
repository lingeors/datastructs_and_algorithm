#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TEST_COUNT 100
#define TEST_MAX 1000

void QuickSort(int *a, int n);
void Quick(int *a, int left, int right);

// 生成n位随机数，最大值为max
void CreateRandomNumber(int *arr, int n, int max)
{
	srand((unsigned)time(NULL));
	int i;
	max += 1;
	for (i = 0; i < n; i++)
		*arr++ = rand() % max;
	*arr = '\0';
}
void printArr(int *arr)
{
	int *tmp = arr;
	while (*tmp) printf("%d,  ", *tmp++);
}

int main(int argc, char const *argv[])
{
	int test_number[MAX];
	CreateRandomNumber(test_number, TEST_COUNT, TEST_MAX);
	printArr(test_number);
	printf("\n\n");
	QuickSort(test_number, TEST_COUNT);
	printArr(test_number);
	return 0;
}

void QuickSort(int *a, int n)
{
	Quick(a, 0, n-1);
}

void Quick(int *a, int left, int right)
{
	if (left >= right) return;
	int prvot = (left+right) / 2;
	int tmp = a[prvot];
	int i = left;
	int j = right;
	while (i < j) {
		while (i < j && a[j] > tmp) j--;
		if (i < j) {
			a[prvot] = a[j];
			prvot = j;
			
		}
		while (i < j && a[i] < tmp) i++;
		if (i < j) {
			a[prvot] = a[i];
			prvot = i;
			j--; // 这里注意，否则出现重复值时可能进入死循环
		}
		 
	}
	a[prvot] = tmp;
	Quick(a, prvot+1, right);
	Quick(a, left, prvot-1);
}

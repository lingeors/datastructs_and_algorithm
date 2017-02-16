// 参考《数据结构与算法分析》

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define TEST_NUMBER_COUNT 20

typedef struct TreeNode TreeNode;
typedef TreeNode *ProToTreeNode;
typedef ProToTreeNode TreeNodePosition;
typedef ProToTreeNode SearchTree;

struct TreeNode
{
	int Element;
	// 根据递归定义我们这里的left指向的也是一棵树
	SearchTree left; 
	SearchTree right;
};

ProToTreeNode createTreeNode(int x);
SearchTree insert(int x, SearchTree T);
void midTraverse(SearchTree T);
TreeNodePosition find(int x, SearchTree T);
TreeNodePosition findMin(SearchTree T);
TreeNodePosition findMax(SearchTree T);
SearchTree Delete(int x, SearchTree T);
void getRandNumber(int *arr, int n, int max);
{
	srand((unsigned)time(NULL));
	int i;
	for (i = 0; i < n; i++) 
		*arr++ = rand() % max;
}

int main(int argc, char const *argv[])
{
	int arr[MAX];
	getRandNumber(arr, TEST_NUMBER_COUNT, 100);
	SearchTree T = NULL;
	int i;
	for (i = 0; i < TEST_NUMBER_COUNT; i++) {
		T = insert(arr[i], T);
		// printf("%d => %d  ", i, arr[i]);
	}
	midTraverse(T);
	putchar('\n');
	T = Delete(arr[0], T); // 注意返回的新的查找树
	printf("%d\n", arr[0]);
	midTraverse(T);
	putchar('\n');
	printf("%d\n", findMin(T)->Element);
	printf("%d\n", findMax(T)->Element);
	return 0;
}

SearchTree Delete(int x, SearchTree T)
{
	TreeNodePosition p;
	if (T == NULL) {
		printf("找不到待删除元素\n");
		exit;
	} else if (x < T->Element)
		T->left = Delete(x, T->left);
	else if (x > T->Element)
		T->right = Delete(x, T->right);
	// 左右子树都存在，替换后删除用来替换的元素
	else if (T->left != NULL && T->right != NULL) {
		p = findMin(T->right); 
		T->Element = p->Element;
		// 这里注意使用新的元素进行查找
		T->right = Delete(p->Element, T->right); 
	} else {
		p = T;
		if (T->left == NULL) {
			T = T->right;
		}
		else if (T->right == NULL)
			T = T->left;
		free(p);
	}
	return T;
}

TreeNodePosition findMax(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->right == NULL)
		return T;
	else 
		return findMax(T->right);
}

TreeNodePosition findMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->left == NULL)
		return T;
	else 
		return findMin(T->left);
}

TreeNodePosition find(int x, SearchTree T)
{
	TreeNodePosition p;
	if (T == NULL)
		p = NULL; 
	else if (T->Element == x)
		p = T;
	else if (x < T->Element)
		p = find(x, T->left);
	else if (x > T->Element)
		p = find(x, T->right);
	return p;
}
void midTraverse(SearchTree T)
{
	if (T == NULL) {
		printf("查找树为空");
		return;
	}
	if (T->left != NULL) 
		midTraverse(T->left);
	printf("%d  ", T->Element);
	if (T->right != NULL)
		midTraverse(T->right);
}
SearchTree insert(int x, SearchTree T)
{
	if (T == NULL) {
		T = createTreeNode(x);
	} else if(x < T->Element) {
		T->left = insert(x, T->left);
	} else if(x > T->Element) {
		T->right = insert(x, T->right);
	}
	return T;
}

ProToTreeNode createTreeNode(int x)
{
	ProToTreeNode node = (ProToTreeNode)malloc(sizeof(TreeNode));
	node->Element = x;
	node->left = node->right = NULL;
	return node;
}

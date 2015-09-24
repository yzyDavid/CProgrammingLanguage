/*by 孙明琦
*（递归）深度优先搜索v2.0
*自己写了一个可自动扩展长度的list接口
*就像c++的vector那样
*我自己有完整的接口实现，题目要求不高所以就没有全部搬过来
*大量使用了动态内存，检查内存泄漏用了好长时间
*最终版已经没有内存泄漏
*v1.0递归部分略难看
*v2.0修改了算法，比1.0快到不知哪里去了
*
*懒得写快速排序，就用插入排序了
*
*开启O3优化效果更佳lol
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX3(a, b, c) (a) > (b) ? ((a) > (c) ? (a):(c)):((b) > (c) ? (b):(c))

/************************************************************************/
/*列表接口声明                                                          */
/************************************************************************/
#define VAL(list, i, type) (*(type)(list->elem[(i)]))
/*提取列表中第i个元素指针所指向的值（右值）*/
struct list_t
{
	void** elem;
	int len;
	int head;
};
typedef struct list_t* list_t;
void list_expand(list_t list);
int list_compare(const list_t a, const list_t b);
list_t list_new(int len);
void list_push(list_t list, void* pElem);
void list_free(list_t* plist);
int list_member(list_t list, void* pElem, int(*cmp)(const void* a, const void* b));
void list_sort(list_t resultList);
/************************************************************************/
/* 递归函数声明                                                         */
/************************************************************************/
void partition(list_t numlist);
/************************************************************************/
/* 全局变量                                                             */
/************************************************************************/
list_t resultList;
int main(void)
{
	int* num = malloc(sizeof(*num));
	int i, j;
	list_t tmp;
	list_t numList; 
	
	numList = list_new(1);
	resultList = list_new(1);
	scanf("%d", num);
	list_push(numList, num);
	partition(numList);
	list_sort(resultList);
	/*输出*/
	for (i = 0; i < resultList->head; i++)
	{
		printf("%d = ", *num);
		tmp = resultList->elem[i];
		for (j = 0; j < tmp->head; j++)
		{
			printf("%d", *(int*)(tmp->elem[j]));
			if (j != tmp->len - 1)
			{
				printf(" + ");
			}
		}
		printf("\n");
	}

	/*释放内存*/
	for (i = 0; i < resultList->head; ++i)
	{
		tmp = resultList->elem[i];
		free(tmp->elem[0]);
		list_free((list_t*)&(resultList->elem[i]));
	}
	list_free(&resultList);

}
void partition(list_t numlist)
{
	int i, j;
	int nleft = INT_MIN;
	int nright = INT_MIN;
	/*检查递归终止点*/
	if (!list_member(resultList, numlist, (int(*)(const void*, const void*))list_compare))
	{ /*不存在于输出数组，添加进，继续递归（有一个复杂类型的强制转换）*/
		list_push(resultList, numlist);
	}
	else
	{ /*列表为降序，又已在输出数组中存在，则没有继续递归的必要，释放分配的内存，停止*/
		free(numlist->elem[0]);
		list_free(&numlist);
		return;
	}
	/*循环递归部分*/
	for (i = 0; i < numlist->head; ++i)
	{
		if (VAL(numlist, i, int*) == 1)
		{ /*降序列表，如果遇到1，那么后面的也一定都是1，所以break*/
			break;
		}
		else
		{
			int k = 0;
			list_t newList;
			int* newNumList;

			if (i != 0)
			{
				nleft = VAL(numlist, i - 1, int*);
			}
			if (i + 1 != numlist->head)
			{
				nright = VAL(numlist, i + 1, int*);
			}
			for (j = MAX3(nleft, nright, 1); j <= VAL(numlist, i, int*) / 2; ++j)
			{
				newNumList = malloc((numlist->head + 1)*sizeof(newNumList[0]));
				newList = list_new(numlist->head + 1);
				/*拆分数字，形成新的列表*/
				for (k = 0; k < i; ++k)
				{
					newNumList[k] = VAL(numlist, k, int*);
				}
				newNumList[k++] = VAL(numlist, i, int*) - j;
				newNumList[k++] = j;
				for (; k < numlist->head + 1; ++k)
				{
					newNumList[k] = VAL(numlist, k - 1, int*);
				}

				for (k = 0; k < numlist->head + 1; ++k)
				{
					list_push(newList, &newNumList[k]);
				}
				partition(newList);
			}
		}
	}
}
/************************************************************************/
/*列表函数实现                                                          */
/************************************************************************/
void list_sort(list_t list)
{//插入排序
	int i, j;
	void* tmp;

	for (j = 1; j < list->head; j++)
	{
		tmp = list->elem[j];
		i = j - 1;
		while (i >= 0 && list_compare(list->elem[i], tmp) < 0)
		{
			list->elem[i + 1] = list->elem[i];
			i--;
		}
		list->elem[i + 1] = tmp;
	}
}
void list_expand(list_t list)
{
	list->elem = realloc(list->elem, (1 + list->len) * sizeof(list->elem[0]));
	assert(list->elem);
	list->len += 1;
}
int list_compare(const list_t a, const list_t b)
{
	int lenmin = a->head > b->head ? b->head : a->head;
	int i;
	for (i = 0; i < lenmin; i++)
	{
		if (*(int*)(a->elem)[i] > *(int*)(b->elem)[i])
		{
			return 1;
		}
		else if (*(int*)(a->elem)[i] < *(int*)(b->elem)[i])
		{
			return -1;
		}
	}
	if (a->head == b->head)
	{
		return 0;
	}
	else if (a->head < b->head)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
list_t list_new(int len)
{
	list_t list;

	if (len <= 0)
	{
		len = 16;
	}
	list = malloc(sizeof(*list));
	assert(list);
	list->elem = calloc(len, sizeof(list->elem[0]));
	assert(list->elem);
	list->len = len;
	list->head = 0;

	return list;
}
void list_push(list_t list, void* pElem)
{
	if (list->head == list->len)
	{
		list_expand(list);
	}
	list->elem[list->head++] = pElem;
}
void list_free(list_t* plist)
{
	free((*plist)->elem);
	free((*plist));
	*plist = NULL;
}
int list_member(list_t list, void* pElem, int(*cmp)(const void* a, const void* b))
{
	int i;
	for (i = 0; i < list->head; i++)
	{
		if ((*cmp)(list->elem[i], pElem) == 0)
		{
			return 1;
		}
	}
	return 0;
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct list_t
{
	struct list_t* succ, *prev;
	int val;
}*node_t, *list_t;/*定义两个类型别名，便于函数可读性*/
node_t list_newnode(int val);
node_t list_find(list_t list, node_t node);
list_t list_link(list_t list1, list_t list2);
void list_print(list_t list);
void list_sort(list_t list);
void list_freenode(node_t node);
void list_free(list_t list);
list_t list_rand(list_t list, int count);
int main()
{
	int num;
	list_t list;
	node_t newnode;
	char cmd;
	
	list = list_rand(NULL, 10);
	while ((cmd = getchar()) != 'E')
	{
		switch (cmd)
		{
			case'L':{
				list_print(list);
				break;
			}
			case'D':{
				scanf("%d", &num);
				newnode = list_newnode(num);
				list_freenode(list_find(list, newnode));
				list_freenode(newnode);
				list_print(list);
				break;
			}
			case'I':{
				list_rand(list, 1);
				list_print(list);
				break;
			}
			case'S':{
				list_sort(list);
				list_print(list);
				break;
			}
			default:{
				/*do nothing*/
			}
		}
	}
	list_free(list);
	return 0;
}
node_t list_newnode(int val)
{
	node_t node;
	node = malloc(sizeof(*node));
	node->succ = NULL;
	node->prev = NULL;
	node->val = val;
	return node;
}
node_t list_find(list_t list, node_t node)
{
	node_t p;
	for (p = list; p != NULL; p = p->succ)
	{
		if (p->val == node->val)
		{
			return p;
		}
	}
	return NULL;
}
list_t list_link(list_t list1, list_t list2)
{
	node_t p;
	for (p = list1; p->succ != NULL; p = p->succ)
		/*do nothing*/;
	p->succ = list2;
	list2->prev = p;
	return list1;
}

void list_freenode(node_t node)
{
	if (node)
	{
		if (node->prev)
		{
			node->prev->succ = node->succ;
		}
		if (node->succ)
		{
			node->succ->prev = node->prev;
		}
		free(node);
	}
}

void list_print(list_t list)
{
	node_t p;
	for (p = list; p != NULL; p = p->succ)
	{
		printf("%d ", p->val);
	}
	printf("\n");
}

void list_sort(list_t list)
{
	node_t i,j;
	int tmp;
	for (i = list; i != NULL; i = i->succ)
	{
		for (j = i->succ; j != NULL; j = j->succ)
		{
			if (i->val > j->val)
			{
				tmp = i->val;
				i->val = j->val;
				j->val = tmp;
			}
		}
	}
}
void list_free(list_t list)
{
	node_t p;
	p = list;
	while (p && p->succ)
	{
		p = p->succ;
		list_freenode(p->prev);
	}
	list_freenode(p);
}
list_t list_rand(list_t list, int count)
{
	int num;
	list_t newnode;
	srand((unsigned long)time(NULL));
	if (list == NULL)
	{
		list = list_newnode(rand() % 100 + 1);
		count--;
	}
	while (count > 0)
	{
		num = rand() % 100 + 1;
		newnode = list_newnode(num);
		if (list_find(list, newnode) == NULL)
		{
			list_link(list, newnode);
			count--;
		}
		else
		{
			list_freenode(newnode);
		}
	}
	return list;
}
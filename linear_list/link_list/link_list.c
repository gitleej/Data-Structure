#include "link_list.h"

/*******************************************************************************
 *函数名：	init_LinkList
 *功能：		初始化链表
 *参数：		
 *返回值：	链表指针
 *******************************************************************************/
LinkList * init_LinkList()
{
	LinkList* linkList = (LinkList*)malloc(sizeof(LinkList));
	linkList->size = 0;

	// 头结点 不保存数据信息
	linkList->head = (LinkNode*)malloc(sizeof(LinkNode));
	linkList->head->data = NULL;
	linkList->head->next = NULL;

	return linkList;
}

/*******************************************************************************
 *函数名：	pushBack_LinkList
 *功能：		在链表尾部插入数据
 *参数：		链表指针
			节点值
 *返回值：
 *******************************************************************************/
void pushBack_LinkList(LinkList* linkList, void* value)
{
	if (linkList == NULL)
	{
		printf("[WARNING]：在链表尾部插入数据，链表为空！\n");
		return;
	}

	if (value == NULL)
	{
		printf("[WARNING]：在链表尾部插入数据，待插入数据无效！\n");
		return;
	}

	int pos = linkList->size;
	// 创建新的节点
	LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
	newNode->data = value;
	newNode->next = NULL;

	// 找节点
	LinkNode *pCurrent = linkList->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// 插入新节点
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	// 更新链表长度
	linkList->size++;
}

/*******************************************************************************
 *函数名：	insert_LinkList
 *功能：		插入节点
 *参数：		链表指针
			节点位置
			节点值
 *返回值：	
 *******************************************************************************/
void insert_LinkList(LinkList * linkList, int pos, void * value)
{
	if (linkList == NULL)
	{
		printf("[WARNING]：插入节点，链表为空！\n");
		return;
	}
	if (value == NULL)
	{
		printf("[WARNING]：插入节点，节点元素为空！\n");
		return;
	}

	// 友好的处理pos越界, 默认尾部插入
	if (pos < 0 || pos > linkList->size)
	{
		pos = linkList->size;
	}

	// 创建新的节点
	LinkNode *newNode = (LinkNode*)malloc(sizeof(LinkNode));
	newNode->data = value;
	newNode->next = NULL;

	// 找节点
	LinkNode *pCurrent = linkList->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// 插入新节点
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	// 更新链表长度
	linkList->size++;
}

/*******************************************************************************
 *函数名：	removeByPos_LinkList
 *功能：		按位置删除节点
 *参数：		链表指针
			位置
 *返回值：	
 *******************************************************************************/
void removeByPos_LinkList(LinkList * linkList, int pos)
{
	if (linkList == NULL)
	{
		printf("[WARNING]：按位置删除，链表为空！\n");
		return;
	}

	if (pos < 0 || pos >= linkList->size)
	{
		printf("[WARNING]：按位置删除，待删除位置无效！\n");
		return;
	}

	// 查找删除节点的前一个节点
	LinkNode *pCurrent = linkList->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// 缓存删除的节点
	LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;

	// 释放删除节点的内存
	free(pDel);

	// 更新链表长度
	linkList->size--;
}

/*******************************************************************************
 *函数名：	removeByValue_LinkList
 *功能：		按值删除节点
 *参数：		链表指针
			位置
 *返回值：
 *******************************************************************************/
void removeByValue_LinkList(LinkList * linkList, void * value, COMPARE compare)
{
	if (linkList == NULL)
	{
		printf("[WARNING]：按值删除，链表为空！\n");
		return;
	}
	if (value == NULL)
	{
		printf("[WARNING]：按值删除，待删除值无效！\n");
		return;
	}
	if (compare == NULL)
	{
		printf("[WARNING]：按值删除，回调函数无效！\n");
		return;
	}

	int pos = find_LinkList(linkList, value, compare);
	
	// 判断位置是否有效
	if (pos < 0)
	{
		printf("[WARNING]：按值删除，查无该值，无法删除！\n");
		return;
	}

	// 查找删除节点的前一个节点
	LinkNode* pCurrent = linkList->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	
	// 缓存待删除节点
	LinkNode *pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	
	// 释放缓存节点
	free(pDel);

	// 更新链表长度
	linkList->size--;
}

/*******************************************************************************
 *函数名：	getSize_LinkList
 *功能：		获取链表长度
 *参数：		链表指针
 *返回值：	链表长度
 *******************************************************************************/
int getSize_LinkList(LinkList * linkList)
{
	if (linkList == NULL)
	{
		printf("[WARNING]：获取链表长度，链表为空！\n");
		return -1;
	}

	return linkList->size;
}

/*******************************************************************************
 *函数名：	find_LinkList
 *功能：		查找节点
 *参数：		链表指针
			节点值
			比较回调函数
 *返回值：	动态数组首地址
 *******************************************************************************/
int find_LinkList(LinkList * linkList, void * value, COMPARE compare)
{
	if (linkList == NULL)
	{
		printf("[WARNING]：按值查找，链表为空！\n");
		return -1;
	}
	if (value == NULL)
	{
		printf("[WARNING]：按值查找，待查找值无效！\n");
		return -1;
	}

	// 遍历查找
	LinkNode *pCurrent = linkList->head->next;
	int pos = 0;
	while (pCurrent != NULL)
	{
		if (compare(pCurrent->data, value))
		{
			break;
		}
		// 指针往后移动
		pCurrent = pCurrent->next;
		pos++;
	}
	
	// 判断查找的pos是否有效
	if (pos >= linkList->size)
	{
		pos = -1;
	}
	return pos;
}

/*******************************************************************************
 *函数名：	getValue_LinkList
 *功能：		按位置查找元素值
 *参数：		链表指针
			位置
 *返回值：	动态数组首地址
 *******************************************************************************/
void * getValue_LinkList(LinkList * linkList, int pos)
{
	if (linkList == NULL)
	{
		printf("[WARNING]：按位置查找，链表为空！\n");
		return NULL;
	}
	if (pos < 0 || pos >= linkList->size)
	{
		printf("[WARNING]：按位置查找，待查找位置无效！\n");
		return NULL;
	}

	// 查找节点
	LinkNode *pCurrent = linkList->head->next;
	int i = 0;
	while (pCurrent != NULL)
	{
		if (pos == i)
		{
			break;
		}
		pCurrent = pCurrent->next;
		i++;
	}
	return pCurrent->data;
}

/*******************************************************************************
 *函数名：	print_LinkList
 *功能：		遍历链表输出
 *参数：		链表指针
			输出回调函数
 *返回值：	
 *******************************************************************************/
void print_LinkList(LinkList * linkList, PRINTLINKNODE print)
{
	if (linkList == NULL)
	{
		printf("[WARNING]：遍历链表输出，链表为空！\n");
		return;
	}
	if (print == NULL)
	{
		printf("[WARNING]：遍历链表输出，回调函数无效！\n");
		return;
	}

	// 遍历
	LinkNode *pCurrent = linkList->head->next;
	while (pCurrent != NULL)
	{
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

/*******************************************************************************
 *函数名：	front_LinkList
 *功能：		返回链表第一个节点
 *参数：		链表指针
 *返回值：	链表第一个节点
 *******************************************************************************/
void * front_LinkList(LinkList * linkList)
{
	if (linkList == NULL)
	{
		printf("[WARNING]：返回链表第一个节点，链表为空！\n");
		return NULL;
	}

	return linkList->head->next->data;
}

/*******************************************************************************
 *函数名：	freeSpace_LinkList
 *功能：		释放链表内存空间
 *参数：		链表指针
 *返回值：	
 *******************************************************************************/
void freeSpace_LinkList(LinkList * linkList)
{
	if (linkList == NULL)
	{
		printf("[WARNING]：释放链表内存空间，链表为空！\n");
		return;
	}

	LinkNode *pCurrent = linkList->head;
	while (pCurrent != NULL)
	{
		// 缓存下一个节点
		LinkNode *pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	linkList->size = 0;
	free(linkList);
}

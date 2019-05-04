#include "link_list.h"

/*******************************************************************************
 *��������	init_LinkList
 *���ܣ�		��ʼ������
 *������		
 *����ֵ��	����ָ��
 *******************************************************************************/
LinkList * init_LinkList()
{
	LinkList* linkList = (LinkList*)malloc(sizeof(LinkList));
	linkList->size = 0;

	// ͷ��� ������������Ϣ
	linkList->head = (LinkNode*)malloc(sizeof(LinkNode));
	linkList->head->data = NULL;
	linkList->head->next = NULL;

	return linkList;
}

/*******************************************************************************
 *��������	pushBack_LinkList
 *���ܣ�		������β����������
 *������		����ָ��
			�ڵ�ֵ
 *����ֵ��
 *******************************************************************************/
void pushBack_LinkList(LinkList* linkList, void* value)
{
	if (linkList == NULL)
	{
		printf("[WARNING]��������β���������ݣ�����Ϊ�գ�\n");
		return;
	}

	if (value == NULL)
	{
		printf("[WARNING]��������β���������ݣ�������������Ч��\n");
		return;
	}

	int pos = linkList->size;
	// �����µĽڵ�
	LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
	newNode->data = value;
	newNode->next = NULL;

	// �ҽڵ�
	LinkNode *pCurrent = linkList->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// �����½ڵ�
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	// ����������
	linkList->size++;
}

/*******************************************************************************
 *��������	insert_LinkList
 *���ܣ�		����ڵ�
 *������		����ָ��
			�ڵ�λ��
			�ڵ�ֵ
 *����ֵ��	
 *******************************************************************************/
void insert_LinkList(LinkList * linkList, int pos, void * value)
{
	if (linkList == NULL)
	{
		printf("[WARNING]������ڵ㣬����Ϊ�գ�\n");
		return;
	}
	if (value == NULL)
	{
		printf("[WARNING]������ڵ㣬�ڵ�Ԫ��Ϊ�գ�\n");
		return;
	}

	// �ѺõĴ���posԽ��, Ĭ��β������
	if (pos < 0 || pos > linkList->size)
	{
		pos = linkList->size;
	}

	// �����µĽڵ�
	LinkNode *newNode = (LinkNode*)malloc(sizeof(LinkNode));
	newNode->data = value;
	newNode->next = NULL;

	// �ҽڵ�
	LinkNode *pCurrent = linkList->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// �����½ڵ�
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	// ����������
	linkList->size++;
}

/*******************************************************************************
 *��������	removeByPos_LinkList
 *���ܣ�		��λ��ɾ���ڵ�
 *������		����ָ��
			λ��
 *����ֵ��	
 *******************************************************************************/
void removeByPos_LinkList(LinkList * linkList, int pos)
{
	if (linkList == NULL)
	{
		printf("[WARNING]����λ��ɾ��������Ϊ�գ�\n");
		return;
	}

	if (pos < 0 || pos >= linkList->size)
	{
		printf("[WARNING]����λ��ɾ������ɾ��λ����Ч��\n");
		return;
	}

	// ����ɾ���ڵ��ǰһ���ڵ�
	LinkNode *pCurrent = linkList->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// ����ɾ���Ľڵ�
	LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;

	// �ͷ�ɾ���ڵ���ڴ�
	free(pDel);

	// ����������
	linkList->size--;
}

/*******************************************************************************
 *��������	removeByValue_LinkList
 *���ܣ�		��ֵɾ���ڵ�
 *������		����ָ��
			λ��
 *����ֵ��
 *******************************************************************************/
void removeByValue_LinkList(LinkList * linkList, void * value, COMPARE compare)
{
	if (linkList == NULL)
	{
		printf("[WARNING]����ֵɾ��������Ϊ�գ�\n");
		return;
	}
	if (value == NULL)
	{
		printf("[WARNING]����ֵɾ������ɾ��ֵ��Ч��\n");
		return;
	}
	if (compare == NULL)
	{
		printf("[WARNING]����ֵɾ�����ص�������Ч��\n");
		return;
	}

	int pos = find_LinkList(linkList, value, compare);
	
	// �ж�λ���Ƿ���Ч
	if (pos < 0)
	{
		printf("[WARNING]����ֵɾ�������޸�ֵ���޷�ɾ����\n");
		return;
	}

	// ����ɾ���ڵ��ǰһ���ڵ�
	LinkNode* pCurrent = linkList->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	
	// �����ɾ���ڵ�
	LinkNode *pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	
	// �ͷŻ���ڵ�
	free(pDel);

	// ����������
	linkList->size--;
}

/*******************************************************************************
 *��������	getSize_LinkList
 *���ܣ�		��ȡ������
 *������		����ָ��
 *����ֵ��	������
 *******************************************************************************/
int getSize_LinkList(LinkList * linkList)
{
	if (linkList == NULL)
	{
		printf("[WARNING]����ȡ�����ȣ�����Ϊ�գ�\n");
		return -1;
	}

	return linkList->size;
}

/*******************************************************************************
 *��������	find_LinkList
 *���ܣ�		���ҽڵ�
 *������		����ָ��
			�ڵ�ֵ
			�Ƚϻص�����
 *����ֵ��	��̬�����׵�ַ
 *******************************************************************************/
int find_LinkList(LinkList * linkList, void * value, COMPARE compare)
{
	if (linkList == NULL)
	{
		printf("[WARNING]����ֵ���ң�����Ϊ�գ�\n");
		return -1;
	}
	if (value == NULL)
	{
		printf("[WARNING]����ֵ���ң�������ֵ��Ч��\n");
		return -1;
	}

	// ��������
	LinkNode *pCurrent = linkList->head->next;
	int pos = 0;
	while (pCurrent != NULL)
	{
		if (compare(pCurrent->data, value))
		{
			break;
		}
		// ָ�������ƶ�
		pCurrent = pCurrent->next;
		pos++;
	}
	
	// �жϲ��ҵ�pos�Ƿ���Ч
	if (pos >= linkList->size)
	{
		pos = -1;
	}
	return pos;
}

/*******************************************************************************
 *��������	getValue_LinkList
 *���ܣ�		��λ�ò���Ԫ��ֵ
 *������		����ָ��
			λ��
 *����ֵ��	��̬�����׵�ַ
 *******************************************************************************/
void * getValue_LinkList(LinkList * linkList, int pos)
{
	if (linkList == NULL)
	{
		printf("[WARNING]����λ�ò��ң�����Ϊ�գ�\n");
		return NULL;
	}
	if (pos < 0 || pos >= linkList->size)
	{
		printf("[WARNING]����λ�ò��ң�������λ����Ч��\n");
		return NULL;
	}

	// ���ҽڵ�
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
 *��������	print_LinkList
 *���ܣ�		�����������
 *������		����ָ��
			����ص�����
 *����ֵ��	
 *******************************************************************************/
void print_LinkList(LinkList * linkList, PRINTLINKNODE print)
{
	if (linkList == NULL)
	{
		printf("[WARNING]�������������������Ϊ�գ�\n");
		return;
	}
	if (print == NULL)
	{
		printf("[WARNING]����������������ص�������Ч��\n");
		return;
	}

	// ����
	LinkNode *pCurrent = linkList->head->next;
	while (pCurrent != NULL)
	{
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

/*******************************************************************************
 *��������	front_LinkList
 *���ܣ�		���������һ���ڵ�
 *������		����ָ��
 *����ֵ��	�����һ���ڵ�
 *******************************************************************************/
void * front_LinkList(LinkList * linkList)
{
	if (linkList == NULL)
	{
		printf("[WARNING]�����������һ���ڵ㣬����Ϊ�գ�\n");
		return NULL;
	}

	return linkList->head->next->data;
}

/*******************************************************************************
 *��������	freeSpace_LinkList
 *���ܣ�		�ͷ������ڴ�ռ�
 *������		����ָ��
 *����ֵ��	
 *******************************************************************************/
void freeSpace_LinkList(LinkList * linkList)
{
	if (linkList == NULL)
	{
		printf("[WARNING]���ͷ������ڴ�ռ䣬����Ϊ�գ�\n");
		return;
	}

	LinkNode *pCurrent = linkList->head;
	while (pCurrent != NULL)
	{
		// ������һ���ڵ�
		LinkNode *pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	linkList->size = 0;
	free(linkList);
}

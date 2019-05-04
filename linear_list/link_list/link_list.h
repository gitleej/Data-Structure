#pragma once

#ifndef LINK_LIST_H
#define LINK_LIST_H

// ����ͷ�ļ�
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ��������ڵ�
typedef struct LINKNODE
{
	void* data;
	struct LINKNODE* next;
}LinkNode;

// ����ṹ��
typedef struct LINKLIST
{
	LinkNode* head;		// �����ͷָ��
	int size;			// ����Ĵ�С��������Ҫ��������
}LinkList;

// ��ӡ����ָ��
typedef void(*PRINTLINKNODE)(void*);
typedef int(*COMPARE)(void *, void *);

// ��ʼ������
LinkList* init_LinkList();
// β����������
void pushBack_LinkList(LinkList* linkList, void* value);
// ָ��λ�ò���ֵ
void insert_LinkList(LinkList* linkList, int pos, void* value);
// ɾ��ָ��λ�õ�ֵ
void removeByPos_LinkList(LinkList* linkList, int pos);
// ɾ��ָ��ֵ
void removeByValue_LinkList(LinkList* linkList, void *value, COMPARE compare);
// �������ĳ���
int getSize_LinkList(LinkList* linkList);
// ��ֵ����
int find_LinkList(LinkList* linkList, void* value, COMPARE compare);
// ��λ�ò���
void* getValue_LinkList(LinkList* linkList, int pos);
// ���
void print_LinkList(LinkList* linkList, PRINTLINKNODE print);
// ���ص�һ���ڵ�
void* front_LinkList(LinkList* linkList);
// �ͷ��ڴ�
void freeSpace_LinkList(LinkList* linkList);

#endif //LINK_LIST_H
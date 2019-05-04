#pragma once

#ifndef LINK_LIST_H
#define LINK_LIST_H

// 包含头文件
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 定义链表节点
typedef struct LINKNODE
{
	void* data;
	struct LINKNODE* next;
}LinkNode;

// 链表结构体
typedef struct LINKLIST
{
	LinkNode* head;		// 链表的头指针
	int size;			// 链表的大小，链表不需要设置容量
}LinkList;

// 打印函数指针
typedef void(*PRINTLINKNODE)(void*);
typedef int(*COMPARE)(void *, void *);

// 初始化链表
LinkList* init_LinkList();
// 尾部插入数据
void pushBack_LinkList(LinkList* linkList, void* value);
// 指定位置插入值
void insert_LinkList(LinkList* linkList, int pos, void* value);
// 删除指定位置的值
void removeByPos_LinkList(LinkList* linkList, int pos);
// 删除指定值
void removeByValue_LinkList(LinkList* linkList, void *value, COMPARE compare);
// 获得链表的长度
int getSize_LinkList(LinkList* linkList);
// 按值查找
int find_LinkList(LinkList* linkList, void* value, COMPARE compare);
// 按位置查找
void* getValue_LinkList(LinkList* linkList, int pos);
// 输出
void print_LinkList(LinkList* linkList, PRINTLINKNODE print);
// 返回第一个节点
void* front_LinkList(LinkList* linkList);
// 释放内存
void freeSpace_LinkList(LinkList* linkList);

#endif //LINK_LIST_H
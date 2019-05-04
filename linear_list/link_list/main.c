#include "link_list.h"

// 定义存储数据类型
typedef struct PERSON
{
	char name[64];
	int age;
	int score;
}Person;

/*******************************************************************************
 *函数名：	myPrint
 *功能：		自定义链表数据输出回调函数
 *参数：		输出数据指针
 *返回值：
 *******************************************************************************/
void myPrint(void * value)
{
	Person *p = (Person*)value;
	printf("Name:%s\tAge:%d\tscore:%d\n", p->name, p->age, p->score);
}

/*******************************************************************************
 *函数名：	myCompare
 *功能：		链表数据比较回调函数
 *参数：		待比较数据1
			待比较数据2
 *返回值：	比较结果，一致返回1，否则返回0
 *******************************************************************************/
int myCompare(void* value1, void* value2)
{
	Person *p1 = (Person*)value1;
	Person *p2 = (Person*)value2;

	return ((strcmp(p1->name, p2->name) == 0) &&
		(p1->age == p2->age) &&
		(p1->score == p2->score));
}

/*******************************************************************************
 *函数名：	test_linkList
 *功能：		单向链表测试函数
 *参数：		
 *返回值：	
 *******************************************************************************/
void test_linkList()
{
	LinkList* linkList = init_LinkList();
	Person p1 = { "aaa", 10, 100 };
	Person p2 = { "bbb", 20, 200 };
	Person p3 = { "ccc", 30, 300 };
	Person p4 = { "ddd", 40, 400 };
	Person p5 = { "fff", 50, 500 };

	printf("[INFO]：链表长度\t%d\n", getSize_LinkList(linkList));

	// 插入链表，头插
	insert_LinkList(linkList, 0, &p1);
	insert_LinkList(linkList, 0, &p2);
	insert_LinkList(linkList, 0, &p3);
	insert_LinkList(linkList, 0, &p4);
	insert_LinkList(linkList, 0, &p5);
	
	// 插入链表，尾插
	pushBack_LinkList(linkList, &p1);
	pushBack_LinkList(linkList, &p2);
	pushBack_LinkList(linkList, &p3);
	pushBack_LinkList(linkList, &p4);
	pushBack_LinkList(linkList, &p5);

	printf("[INFO]：链表长度\t%d\n", getSize_LinkList(linkList));
	print_LinkList(linkList, myPrint);

	// 按位置删除
	printf("****************************************\n");
	printf("[INFO]：按位置删除，删除位置 0 的元素值为：\t");
	myPrint((Person*)getValue_LinkList(linkList, 0));
	removeByPos_LinkList(linkList, 0);
	printf("[INFO]：链表长度\t%d\n", getSize_LinkList(linkList));
	print_LinkList(linkList, myPrint);
	
	// 按值删除
	printf("****************************************\n");
	Person delP1 = { "aaa", 10, 100 };
	printf("[INFO]：链表长度\t%d\n", getSize_LinkList(linkList));
	print_LinkList(linkList, myPrint);

	Person delP2 = { "bbb", 10, 100 };
	removeByValue_LinkList(linkList, &delP1, myCompare);
	removeByValue_LinkList(linkList, &delP2, myCompare);
	printf("[INFO]：链表长度\t%d\n", getSize_LinkList(linkList));
	print_LinkList(linkList, myPrint);

	// 返回链表第一个节点值
	printf("****************************************\n");
	Person *ret = (Person *)front_LinkList(linkList);
	printf("[INFO]：链表的第一个节点值为：\t");
	myPrint(ret);
	
	// 释放链表内存空间
	freeSpace_LinkList(linkList);
}

/*******************************************************************************
 *函数名：	main
 *功能：		主函数
 *参数：		
 *返回值：	0
 *******************************************************************************/
int main()
{
	// 测试函数
	test_linkList();

	system("pause");
	return 0;
}
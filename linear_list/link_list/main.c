#include "link_list.h"

// ����洢��������
typedef struct PERSON
{
	char name[64];
	int age;
	int score;
}Person;

/*******************************************************************************
 *��������	myPrint
 *���ܣ�		�Զ���������������ص�����
 *������		�������ָ��
 *����ֵ��
 *******************************************************************************/
void myPrint(void * value)
{
	Person *p = (Person*)value;
	printf("Name:%s\tAge:%d\tscore:%d\n", p->name, p->age, p->score);
}

/*******************************************************************************
 *��������	myCompare
 *���ܣ�		�������ݱȽϻص�����
 *������		���Ƚ�����1
			���Ƚ�����2
 *����ֵ��	�ȽϽ����һ�·���1�����򷵻�0
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
 *��������	test_linkList
 *���ܣ�		����������Ժ���
 *������		
 *����ֵ��	
 *******************************************************************************/
void test_linkList()
{
	LinkList* linkList = init_LinkList();
	Person p1 = { "aaa", 10, 100 };
	Person p2 = { "bbb", 20, 200 };
	Person p3 = { "ccc", 30, 300 };
	Person p4 = { "ddd", 40, 400 };
	Person p5 = { "fff", 50, 500 };

	printf("[INFO]��������\t%d\n", getSize_LinkList(linkList));

	// ��������ͷ��
	insert_LinkList(linkList, 0, &p1);
	insert_LinkList(linkList, 0, &p2);
	insert_LinkList(linkList, 0, &p3);
	insert_LinkList(linkList, 0, &p4);
	insert_LinkList(linkList, 0, &p5);
	
	// ��������β��
	pushBack_LinkList(linkList, &p1);
	pushBack_LinkList(linkList, &p2);
	pushBack_LinkList(linkList, &p3);
	pushBack_LinkList(linkList, &p4);
	pushBack_LinkList(linkList, &p5);

	printf("[INFO]��������\t%d\n", getSize_LinkList(linkList));
	print_LinkList(linkList, myPrint);

	// ��λ��ɾ��
	printf("****************************************\n");
	printf("[INFO]����λ��ɾ����ɾ��λ�� 0 ��Ԫ��ֵΪ��\t");
	myPrint((Person*)getValue_LinkList(linkList, 0));
	removeByPos_LinkList(linkList, 0);
	printf("[INFO]��������\t%d\n", getSize_LinkList(linkList));
	print_LinkList(linkList, myPrint);
	
	// ��ֵɾ��
	printf("****************************************\n");
	Person delP1 = { "aaa", 10, 100 };
	printf("[INFO]��������\t%d\n", getSize_LinkList(linkList));
	print_LinkList(linkList, myPrint);

	Person delP2 = { "bbb", 10, 100 };
	removeByValue_LinkList(linkList, &delP1, myCompare);
	removeByValue_LinkList(linkList, &delP2, myCompare);
	printf("[INFO]��������\t%d\n", getSize_LinkList(linkList));
	print_LinkList(linkList, myPrint);

	// ���������һ���ڵ�ֵ
	printf("****************************************\n");
	Person *ret = (Person *)front_LinkList(linkList);
	printf("[INFO]������ĵ�һ���ڵ�ֵΪ��\t");
	myPrint(ret);
	
	// �ͷ������ڴ�ռ�
	freeSpace_LinkList(linkList);
}

/*******************************************************************************
 *��������	main
 *���ܣ�		������
 *������		
 *����ֵ��	0
 *******************************************************************************/
int main()
{
	// ���Ժ���
	test_linkList();

	system("pause");
	return 0;
}
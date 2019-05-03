#include "DynamicArray.h"

// ��������Ԫ�ؽṹ��
typedef struct PERSON
{
	char name[64];
	int age;
}Person;

/*******************************************************************************
 *��������	myPrint
 *���ܣ�		����ص�����
 *������		�������ֵ
 *����ֵ��
 *******************************************************************************/
void myPrint(void* value)
{
	Person *p = (Person*)value;
	/*printf("*****************************************\n");*/
	printf("Name: %s\tAge: %d\n", p->name, p->age);
}

/*******************************************************************************
 *��������	myCompare
 *���ܣ�		Ԫ�رȽϻص�����
 *������		�������Ƚϵ�Ԫ��ֵ
 *����ֵ��	�ȽϽ��
 *******************************************************************************/
int myCompare(void* value1, void* value2)
{
	Person *p1 = (Person*)value1;
	Person *p2 = (Person*)value2;

	return (strcmp(p1->name, p2->name) == 0 && (p1->age == p2->age));
}

void test_01()
{
	// ����һ����̬����
	Dynamic_Array* arr = init_DynamicArr(5);
	// ����̬�������Ԫ��
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };
	Person p4 = { "ddd", 40 };
	Person p5 = { "eee", 50 };
	Person p6 = { "fff", 60 };
	// ������������ʹ�С
	printf("[INFO]��������%4d\t��С��%4d\n", getCapacity_DynamicArr(arr), 
		getSize_DynamicArr(arr));
	pushBack_DynamicArr(arr, &p1);
	pushBack_DynamicArr(arr, &p2);
	pushBack_DynamicArr(arr, &p3);
	pushBack_DynamicArr(arr, &p4);
	pushBack_DynamicArr(arr, &p5);
	pushBack_DynamicArr(arr, &p6);
	// ������������ʹ�С
	printf("[INFO]��������%4d\t��С��%4d\n", getCapacity_DynamicArr(arr),
		getSize_DynamicArr(arr));
	// �����̬��������
	printf_DynamicArr(arr, myPrint);

	// ��λ��ɾ��Ԫ��
	removeByPos_DynamicArr(arr, 1);
	// �����̬��������
	printf("[INFO]��ɾ��λ��1��Ԫ��: ");
	myPrint(arr->pAddr[1]);
	printf_DynamicArr(arr, myPrint);

	// ��λ��1������Ԫ��
	Person newP = { "new", 70 };
	insert_DynamicArr(arr, 1, &newP);
	// �����̬��������
	printf("[INFO]������λ��1��Ԫ��: ");
	myPrint(&newP);
	printf_DynamicArr(arr, myPrint);

	// ��ȡλ��2��Ԫ��ֵ
	Person *findP = (Person *)getValue_DynamicArr(arr, 2);
	printf("[INFO]��λ��2��Ԫ��ֵΪ: ");
	myPrint(findP);

	// ����Ԫ��λ��
	Person fP = { "new", 30 };
	int pos = find_DynamicArr(arr, &fP, myCompare);
	printf("Name: %s\tAge: %d ��λ��Ϊ��\t%d\n", fP.name, fP.age, pos);

	// ����Ԫ��ֵɾ��Ԫ��
	removeByValue_DynamicArr(arr, &fP, myCompare);
	
	// �����̬��������
	printf("[INFO]��ɾ����Ԫ��ֵΪ: ");
	myPrint(&newP);
	printf_DynamicArr(arr, myPrint);

	// ��ն�̬����
	clear_DynamicArr(arr);
	// ������������ʹ�С
	printf("[INFO]��������%4d\t��С��%4d\n", getCapacity_DynamicArr(arr),
		getSize_DynamicArr(arr));

	// �ͷŶ�̬����ռ�
	freeSpace_DynamicArr(arr);
	// ������������ʹ�С
	printf("[INFO]��������%4d\t��С��%4d\n", getCapacity_DynamicArr(arr),
		getSize_DynamicArr(arr));
}

int main()
{
	// ����
	test_01();

	system("pause");
	return 0;
}
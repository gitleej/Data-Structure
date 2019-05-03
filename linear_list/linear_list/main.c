#include "DynamicArray.h"

// 定义数组元素结构体
typedef struct PERSON
{
	char name[64];
	int age;
}Person;

/*******************************************************************************
 *函数名：	myPrint
 *功能：		输出回调函数
 *参数：		待输出的值
 *返回值：
 *******************************************************************************/
void myPrint(void* value)
{
	Person *p = (Person*)value;
	/*printf("*****************************************\n");*/
	printf("Name: %s\tAge: %d\n", p->name, p->age);
}

/*******************************************************************************
 *函数名：	myCompare
 *功能：		元素比较回调函数
 *参数：		两个待比较的元素值
 *返回值：	比较结果
 *******************************************************************************/
int myCompare(void* value1, void* value2)
{
	Person *p1 = (Person*)value1;
	Person *p2 = (Person*)value2;

	return (strcmp(p1->name, p2->name) == 0 && (p1->age == p2->age));
}

void test_01()
{
	// 创建一个动态数组
	Dynamic_Array* arr = init_DynamicArr(5);
	// 往动态数组添加元素
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };
	Person p4 = { "ddd", 40 };
	Person p5 = { "eee", 50 };
	Person p6 = { "fff", 60 };
	// 输出数组容量和大小
	printf("[INFO]：容量：%4d\t大小：%4d\n", getCapacity_DynamicArr(arr), 
		getSize_DynamicArr(arr));
	pushBack_DynamicArr(arr, &p1);
	pushBack_DynamicArr(arr, &p2);
	pushBack_DynamicArr(arr, &p3);
	pushBack_DynamicArr(arr, &p4);
	pushBack_DynamicArr(arr, &p5);
	pushBack_DynamicArr(arr, &p6);
	// 输出数组容量和大小
	printf("[INFO]：容量：%4d\t大小：%4d\n", getCapacity_DynamicArr(arr),
		getSize_DynamicArr(arr));
	// 输出动态数组内容
	printf_DynamicArr(arr, myPrint);

	// 按位置删除元素
	removeByPos_DynamicArr(arr, 1);
	// 输出动态数组内容
	printf("[INFO]：删除位置1的元素: ");
	myPrint(arr->pAddr[1]);
	printf_DynamicArr(arr, myPrint);

	// 在位置1插入新元素
	Person newP = { "new", 70 };
	insert_DynamicArr(arr, 1, &newP);
	// 输出动态数组内容
	printf("[INFO]：插入位置1的元素: ");
	myPrint(&newP);
	printf_DynamicArr(arr, myPrint);

	// 获取位置2的元素值
	Person *findP = (Person *)getValue_DynamicArr(arr, 2);
	printf("[INFO]：位置2的元素值为: ");
	myPrint(findP);

	// 查找元素位置
	Person fP = { "new", 30 };
	int pos = find_DynamicArr(arr, &fP, myCompare);
	printf("Name: %s\tAge: %d 的位置为：\t%d\n", fP.name, fP.age, pos);

	// 根据元素值删除元素
	removeByValue_DynamicArr(arr, &fP, myCompare);
	
	// 输出动态数组内容
	printf("[INFO]：删除的元素值为: ");
	myPrint(&newP);
	printf_DynamicArr(arr, myPrint);

	// 清空动态数组
	clear_DynamicArr(arr);
	// 输出数组容量和大小
	printf("[INFO]：容量：%4d\t大小：%4d\n", getCapacity_DynamicArr(arr),
		getSize_DynamicArr(arr));

	// 释放动态数组空间
	freeSpace_DynamicArr(arr);
	// 输出数组容量和大小
	printf("[INFO]：容量：%4d\t大小：%4d\n", getCapacity_DynamicArr(arr),
		getSize_DynamicArr(arr));
}

int main()
{
	// 测试
	test_01();

	system("pause");
	return 0;
}
#include "DynamicArray.h"

/*******************************************************************************
 *函数名：	init_DynamicArr
 *功能：		初始化动态数组
 *参数：		数组容量
 *返回值：	动态数组首地址
 *******************************************************************************/
Dynamic_Array* init_DynamicArr(int capacity)
{
	if (capacity <= 0)
	{
		printf("[ERROR]：动态内存初始化，容量小于0。\n");
		return NULL;
	}
	// 申请内存
	Dynamic_Array* arr = (Dynamic_Array *)malloc(sizeof(Dynamic_Array));
	if (arr == NULL)
	{
		printf("[ERROR]：动态数组初始化，内存申请失败！\n");
		return NULL;
	}
	// 初始化
	arr->capacity = capacity;
	arr->size = 0;
	arr->pAddr = (void **)malloc(sizeof(void*)*arr->capacity);
	return arr;
}

/*******************************************************************************
 *函数名：	pushBack_DynamicArr
 *功能：		插入元素，从动态数组末尾插入
 *参数：		动态数组首地址
 *			待插入元素
 *返回值：	
 *******************************************************************************/
void pushBack_DynamicArr(Dynamic_Array * arr, void * value)
{
	if (arr == NULL)
	{
		printf("[ERROR]：插入元素，动态数组为空！\n");
		return;
	}

	// 判断容量是否足够
	if (arr->capacity == arr->size)
	{
		// 申请更大的空间，新空间是旧空间的2倍
		int newCapacity = arr->capacity * 2;
		void** newSpace = (void*)malloc(sizeof(void *) * newCapacity);
		// 拷贝数据到新的空间
		memcpy(newSpace, arr->pAddr, arr->capacity*sizeof(void *));
		// 释放旧空间的内存
		free(arr->pAddr);
		// 更新容量
		arr->capacity = newCapacity;
		// 更新内容
		arr->pAddr = newSpace;
	}

	// 插入新元素
	arr->pAddr[arr->size] = value;
	arr->size++;
}
 
/*******************************************************************************
 *函数名：	insert_DynamicArr
 *功能：		插入元素，从任意位置插入
 *参数：		动态数组首地址
			待插入元素位置
			待插入元素
 *返回值：	
 *******************************************************************************/
void insert_DynamicArr(Dynamic_Array * arr, int pos, void * value)
{
	if (arr == NULL)
	{
		printf("[WARNING]：插入元素，动态数组为空！\n");
		return;
	}

	// 判断插入元素是否有效
	if (value == NULL)
	{
		printf("[WARNING]：插入元素，待插入元素无效！\n");
		return;
	}
	
	// 判断位置是否有效
	if (pos < 0 || pos > arr->size)
	{
		pos = arr->size;
	}

	// 判断容量是否足够
	if (arr->capacity <= arr->size)
	{
		// 申请更大的空间，新空间是旧空间的2倍
		int newCapacity = arr->capacity * 2;
		void** newSpace = (void*)malloc(sizeof(void *) * newCapacity);
		// 拷贝数据到新的空间
		memcpy(newSpace, arr->pAddr, arr->capacity * sizeof(void *));
		// 释放旧空间的内存
		free(arr->pAddr);
		// 更新容量
		arr->capacity = newCapacity;
		// 更新内容
		arr->pAddr = newSpace;
	}

	// 移动元素，将pos位置空出
	for (int i =arr->size - 1; i >= pos; i--)
	{
		arr->pAddr[i + 1] = arr->pAddr[i];
	}

	// 在pos位置插入元素
	arr->pAddr[pos] = value;
	arr->size++;
}

/*******************************************************************************
 *函数名：	removeByPos_DynamicArr
 *功能：		删除元素，按照位置删除
 *参数：		动态数组首地址
			待删除元素位置
 *返回值：	
 *******************************************************************************/
void removeByPos_DynamicArr(Dynamic_Array * arr, int pos)
{
	// 判断动态数组是否有效
	if (arr == NULL)
	{
		printf("[ERROR]：按位置删除元素，动态数组为空！\n");
		return;
	}

	// 判断位置是否有效
	if (pos < 0 || pos >= arr->size)
	{
		printf("[ERROR]：按位置删除元素，待删除位置无效！\n");
		return;
	}

	// 删除元素
	for (int i = pos; i < arr->size - 1; i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->size--;
}

/*******************************************************************************
 *函数名：	removeByValue_DynamicArr
 *功能：		删除元素，按照元素值删除，默认删除第一个与之对应的元素
 *参数：		动态数组首地址
			待删除元素
 *返回值：	
 *******************************************************************************/
void removeByValue_DynamicArr(Dynamic_Array * arr, void * value, 
	int(*compare)(void *, void *))
{
	// 判断动态数组是否有效
	if (arr == NULL)
	{
		printf("[ERROR]：按元素值删除元素，动态数组为空！\n");
		return;
	}

	// 判断待查找元素是否有效
	if (value == NULL)
	{
		printf("[ERROR]：按元素值删除元素，待删除元素无效！\n");
		return;
	}

	// 判断回调函数是否有效
	if (compare == NULL)
	{
		printf("[ERROR]：按元素值删除元素，回调函数无效！\n");
		return -1;
	}

	// 删除元素
	int pos = find_DynamicArr(arr, value, compare);
	if (pos < 0)
	{
		printf("[WARNING]：按元素值删除元素，查无该元素！\n");
		return;
	}
	removeByPos_DynamicArr(arr, pos);
	/*for (int i = pos; i < arr->size; i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->size--;*/
}

/*******************************************************************************
 *函数名：	find_DynamicArr
 *功能：		查找元素
 *参数：		动态数组首地址
			需要查找的元素
 *返回值：	如果查找成功，返回该元素位置；否则，返回-1
 *******************************************************************************/
int find_DynamicArr(Dynamic_Array * arr, void * value, 
	int(*compare)(void *, void *))
{
	// 判断动态数组是否有效
	if (arr == NULL)
	{
		printf("[ERROR]：查找元素，动态数组为空！\n");
		return -1;
	}

	// 判断待查找元素是否有效
	if (value == NULL)
	{
		printf("[ERROR]：查找元素，待查找元素无效！\n");
		return -1;
	}

	// 判断回调函数是否有效
	if (compare == NULL)
	{
		printf("[ERROR]：查找元素，回调函数无效！\n");
		return -1;
	}

	// 遍历动态数组查找元素
	int pos;
	for (int i = 0; i < arr->size; i++)
	{
		if (compare(arr->pAddr[i], value))
		{
			pos = i;
			break;
		}
		else
		{
			pos = -1;
		}
	}

	return pos;
}

/*******************************************************************************
 *函数名：	printf_DynamicArr
 *功能：		遍历动态数组，并输出
 *参数：		动态数组首地址
			输出回调函数
 *返回值：	
 *******************************************************************************/
void printf_DynamicArr(Dynamic_Array * arr, void(*_callback)(void *))
{
	if (NULL == arr)
	{
		printf("[WARNING]：遍历动态数组，动态数组为空！\n");
		return;
	}

	if (NULL == _callback)
	{
		printf("[WARNING]：遍历动态数组，回调函数为空！\n");
		return;
	}

	for (int i = 0; i < arr->size; ++i)
	{
		_callback(arr->pAddr[i]);
	}
}

/*******************************************************************************
 *函数名：	clear_DynamicArr
 *功能：		清空动态数组
 *参数：		动态数组首地址
 *返回值：	
 *******************************************************************************/
void clear_DynamicArr(Dynamic_Array * arr)
{
	if (NULL == arr)
	{
		printf("[WARNING]：清空动态数组，动态数组为空！\n");
		return;
	}

	arr->size = 0;
}

/*******************************************************************************
 *函数名：	getCapacity_DynamicArr
 *功能：		获取动态数组容量
 *参数：		动态数组首地址
 *返回值：	如果成功获取动态数组容量，返回容量；否侧返回-1
 *******************************************************************************/
int getCapacity_DynamicArr(Dynamic_Array * arr)
{
	if (arr == NULL)
	{
		printf("[WARNING]：获取动态数组的容量，动态数组为空！\n");
		return -1;
	}

	return arr->capacity;
}

/*******************************************************************************
 *函数名：	getSize_DynamicArr
 *功能：		获取动态数组大小
 *参数：		动态数组首地址
 *返回值：	如果成功获取动态数组大小，返回大小；否侧返回-1
 *******************************************************************************/
int getSize_DynamicArr(Dynamic_Array * arr)
{
	if (arr == NULL)
	{
		printf("[WARNING]：获取动态数组的大小，动态数组为空！\n");
		return -1;
	}

	return arr->size;
}

/*******************************************************************************
 *函数名：	getValue_DynamicArr
 *功能：		获取元素，按位置获取
 *参数：		动态数组首地址
			元素位置
 *返回值：	元素值
 *******************************************************************************/
void * getValue_DynamicArr(Dynamic_Array * arr, int pos)
{
	if (arr == NULL)
	{
		printf("[WARNING]：获取动态数组的元素，动态数组为空！\n");
		return NULL;
	}
	if (pos < 0 || pos >= arr->size)
	{
		printf("[WARNING]：获取动态数组的元素，位置无效！\n");
	}

	return arr->pAddr[pos];
}

/*******************************************************************************
 *函数名：	freeSpace_DynamicArr
 *功能：		释放动态数组内存空间
 *参数：		动态数组首地址
 *返回值：	
 *******************************************************************************/
void freeSpace_DynamicArr(Dynamic_Array * arr)
{
	if (arr == NULL)
	{
		printf("[WARNING]：释放动态数组空间，动态数组为空！\n");
		return;
	}
	if (arr->pAddr == NULL)
	{
		printf("[WARNING]：释放动态数组空间，动态数组元素为空！\n");
		return;
	}
	free(arr->pAddr);
	free(arr);
}

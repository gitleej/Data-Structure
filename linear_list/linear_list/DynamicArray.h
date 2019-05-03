#pragma once

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

// 包含头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
 *说明：
 *	线性表的特性：
 *		1.数据元素之间是有顺序的；
 *		2.数据元素的个数是有限的；
 *		3.数据元素的类型必须相同。
 *	动态数组是线性表的顺序存储结构，指的是用一段地址连续的存储单元一次存储线性表的数
 *	据元素。
 *******************************************************************************/

// 定义动态数组的结构体
typedef struct DYNAMICARRAY
{
	void** pAddr;		// 存放数据的地址
	int size;			// 当前存储元素的个数
	int capacity;		// 动态数组容量
}Dynamic_Array;

// 初始化动态数组
Dynamic_Array* init_DynamicArr(int capacity);
// 插入元素，尾部插入
void pushBack_DynamicArr(Dynamic_Array* arr, void* value);
// 插入元素，任意位置插入
void insert_DynamicArr(Dynamic_Array* arr, int pos, void* value);
// 删除元素，根据位置删除
void removeByPos_DynamicArr(Dynamic_Array* arr, int pos);
// 删除元素，根据值删除，默认删除第一次找到的值
void removeByValue_DynamicArr(Dynamic_Array* arr, void* value, 
	int(*compare)(void *, void *));
// 查找元素
int find_DynamicArr(Dynamic_Array* arr, void* value, 
	int(*compare)(void *, void *));
// 输出动态数组
void printf_DynamicArr(Dynamic_Array* arr, void(*_callback)(void *));
// 清空数组
void clear_DynamicArr(Dynamic_Array* arr);
// 获取动态数组容量
int getCapacity_DynamicArr(Dynamic_Array* arr);
// 获取动态数组当前元素个数
int getSize_DynamicArr(Dynamic_Array* arr);
// 获取任意位置元素
void* getValue_DynamicArr(Dynamic_Array* arr, int pos);
// 释放动态数组的内存
void freeSpace_DynamicArr(Dynamic_Array* arr);


#endif // !DYNAMIC_ARRAY_H

#pragma once

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

// ����ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
 *˵����
 *	���Ա�����ԣ�
 *		1.����Ԫ��֮������˳��ģ�
 *		2.����Ԫ�صĸ��������޵ģ�
 *		3.����Ԫ�ص����ͱ�����ͬ��
 *	��̬���������Ա��˳��洢�ṹ��ָ������һ�ε�ַ�����Ĵ洢��Ԫһ�δ洢���Ա����
 *	��Ԫ�ء�
 *******************************************************************************/

// ���嶯̬����Ľṹ��
typedef struct DYNAMICARRAY
{
	void** pAddr;		// ������ݵĵ�ַ
	int size;			// ��ǰ�洢Ԫ�صĸ���
	int capacity;		// ��̬��������
}Dynamic_Array;

// ��ʼ����̬����
Dynamic_Array* init_DynamicArr(int capacity);
// ����Ԫ�أ�β������
void pushBack_DynamicArr(Dynamic_Array* arr, void* value);
// ����Ԫ�أ�����λ�ò���
void insert_DynamicArr(Dynamic_Array* arr, int pos, void* value);
// ɾ��Ԫ�أ�����λ��ɾ��
void removeByPos_DynamicArr(Dynamic_Array* arr, int pos);
// ɾ��Ԫ�أ�����ֵɾ����Ĭ��ɾ����һ���ҵ���ֵ
void removeByValue_DynamicArr(Dynamic_Array* arr, void* value, 
	int(*compare)(void *, void *));
// ����Ԫ��
int find_DynamicArr(Dynamic_Array* arr, void* value, 
	int(*compare)(void *, void *));
// �����̬����
void printf_DynamicArr(Dynamic_Array* arr, void(*_callback)(void *));
// �������
void clear_DynamicArr(Dynamic_Array* arr);
// ��ȡ��̬��������
int getCapacity_DynamicArr(Dynamic_Array* arr);
// ��ȡ��̬���鵱ǰԪ�ظ���
int getSize_DynamicArr(Dynamic_Array* arr);
// ��ȡ����λ��Ԫ��
void* getValue_DynamicArr(Dynamic_Array* arr, int pos);
// �ͷŶ�̬������ڴ�
void freeSpace_DynamicArr(Dynamic_Array* arr);


#endif // !DYNAMIC_ARRAY_H

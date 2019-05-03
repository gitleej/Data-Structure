#include "DynamicArray.h"

/*******************************************************************************
 *��������	init_DynamicArr
 *���ܣ�		��ʼ����̬����
 *������		��������
 *����ֵ��	��̬�����׵�ַ
 *******************************************************************************/
Dynamic_Array* init_DynamicArr(int capacity)
{
	if (capacity <= 0)
	{
		printf("[ERROR]����̬�ڴ��ʼ��������С��0��\n");
		return NULL;
	}
	// �����ڴ�
	Dynamic_Array* arr = (Dynamic_Array *)malloc(sizeof(Dynamic_Array));
	if (arr == NULL)
	{
		printf("[ERROR]����̬�����ʼ�����ڴ�����ʧ�ܣ�\n");
		return NULL;
	}
	// ��ʼ��
	arr->capacity = capacity;
	arr->size = 0;
	arr->pAddr = (void **)malloc(sizeof(void*)*arr->capacity);
	return arr;
}

/*******************************************************************************
 *��������	pushBack_DynamicArr
 *���ܣ�		����Ԫ�أ��Ӷ�̬����ĩβ����
 *������		��̬�����׵�ַ
 *			������Ԫ��
 *����ֵ��	
 *******************************************************************************/
void pushBack_DynamicArr(Dynamic_Array * arr, void * value)
{
	if (arr == NULL)
	{
		printf("[ERROR]������Ԫ�أ���̬����Ϊ�գ�\n");
		return;
	}

	// �ж������Ƿ��㹻
	if (arr->capacity == arr->size)
	{
		// �������Ŀռ䣬�¿ռ��Ǿɿռ��2��
		int newCapacity = arr->capacity * 2;
		void** newSpace = (void*)malloc(sizeof(void *) * newCapacity);
		// �������ݵ��µĿռ�
		memcpy(newSpace, arr->pAddr, arr->capacity*sizeof(void *));
		// �ͷžɿռ���ڴ�
		free(arr->pAddr);
		// ��������
		arr->capacity = newCapacity;
		// ��������
		arr->pAddr = newSpace;
	}

	// ������Ԫ��
	arr->pAddr[arr->size] = value;
	arr->size++;
}
 
/*******************************************************************************
 *��������	insert_DynamicArr
 *���ܣ�		����Ԫ�أ�������λ�ò���
 *������		��̬�����׵�ַ
			������Ԫ��λ��
			������Ԫ��
 *����ֵ��	
 *******************************************************************************/
void insert_DynamicArr(Dynamic_Array * arr, int pos, void * value)
{
	if (arr == NULL)
	{
		printf("[WARNING]������Ԫ�أ���̬����Ϊ�գ�\n");
		return;
	}

	// �жϲ���Ԫ���Ƿ���Ч
	if (value == NULL)
	{
		printf("[WARNING]������Ԫ�أ�������Ԫ����Ч��\n");
		return;
	}
	
	// �ж�λ���Ƿ���Ч
	if (pos < 0 || pos > arr->size)
	{
		pos = arr->size;
	}

	// �ж������Ƿ��㹻
	if (arr->capacity <= arr->size)
	{
		// �������Ŀռ䣬�¿ռ��Ǿɿռ��2��
		int newCapacity = arr->capacity * 2;
		void** newSpace = (void*)malloc(sizeof(void *) * newCapacity);
		// �������ݵ��µĿռ�
		memcpy(newSpace, arr->pAddr, arr->capacity * sizeof(void *));
		// �ͷžɿռ���ڴ�
		free(arr->pAddr);
		// ��������
		arr->capacity = newCapacity;
		// ��������
		arr->pAddr = newSpace;
	}

	// �ƶ�Ԫ�أ���posλ�ÿճ�
	for (int i =arr->size - 1; i >= pos; i--)
	{
		arr->pAddr[i + 1] = arr->pAddr[i];
	}

	// ��posλ�ò���Ԫ��
	arr->pAddr[pos] = value;
	arr->size++;
}

/*******************************************************************************
 *��������	removeByPos_DynamicArr
 *���ܣ�		ɾ��Ԫ�أ�����λ��ɾ��
 *������		��̬�����׵�ַ
			��ɾ��Ԫ��λ��
 *����ֵ��	
 *******************************************************************************/
void removeByPos_DynamicArr(Dynamic_Array * arr, int pos)
{
	// �ж϶�̬�����Ƿ���Ч
	if (arr == NULL)
	{
		printf("[ERROR]����λ��ɾ��Ԫ�أ���̬����Ϊ�գ�\n");
		return;
	}

	// �ж�λ���Ƿ���Ч
	if (pos < 0 || pos >= arr->size)
	{
		printf("[ERROR]����λ��ɾ��Ԫ�أ���ɾ��λ����Ч��\n");
		return;
	}

	// ɾ��Ԫ��
	for (int i = pos; i < arr->size - 1; i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->size--;
}

/*******************************************************************************
 *��������	removeByValue_DynamicArr
 *���ܣ�		ɾ��Ԫ�أ�����Ԫ��ֵɾ����Ĭ��ɾ����һ����֮��Ӧ��Ԫ��
 *������		��̬�����׵�ַ
			��ɾ��Ԫ��
 *����ֵ��	
 *******************************************************************************/
void removeByValue_DynamicArr(Dynamic_Array * arr, void * value, 
	int(*compare)(void *, void *))
{
	// �ж϶�̬�����Ƿ���Ч
	if (arr == NULL)
	{
		printf("[ERROR]����Ԫ��ֵɾ��Ԫ�أ���̬����Ϊ�գ�\n");
		return;
	}

	// �жϴ�����Ԫ���Ƿ���Ч
	if (value == NULL)
	{
		printf("[ERROR]����Ԫ��ֵɾ��Ԫ�أ���ɾ��Ԫ����Ч��\n");
		return;
	}

	// �жϻص������Ƿ���Ч
	if (compare == NULL)
	{
		printf("[ERROR]����Ԫ��ֵɾ��Ԫ�أ��ص�������Ч��\n");
		return -1;
	}

	// ɾ��Ԫ��
	int pos = find_DynamicArr(arr, value, compare);
	if (pos < 0)
	{
		printf("[WARNING]����Ԫ��ֵɾ��Ԫ�أ����޸�Ԫ�أ�\n");
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
 *��������	find_DynamicArr
 *���ܣ�		����Ԫ��
 *������		��̬�����׵�ַ
			��Ҫ���ҵ�Ԫ��
 *����ֵ��	������ҳɹ������ظ�Ԫ��λ�ã����򣬷���-1
 *******************************************************************************/
int find_DynamicArr(Dynamic_Array * arr, void * value, 
	int(*compare)(void *, void *))
{
	// �ж϶�̬�����Ƿ���Ч
	if (arr == NULL)
	{
		printf("[ERROR]������Ԫ�أ���̬����Ϊ�գ�\n");
		return -1;
	}

	// �жϴ�����Ԫ���Ƿ���Ч
	if (value == NULL)
	{
		printf("[ERROR]������Ԫ�أ�������Ԫ����Ч��\n");
		return -1;
	}

	// �жϻص������Ƿ���Ч
	if (compare == NULL)
	{
		printf("[ERROR]������Ԫ�أ��ص�������Ч��\n");
		return -1;
	}

	// ������̬�������Ԫ��
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
 *��������	printf_DynamicArr
 *���ܣ�		������̬���飬�����
 *������		��̬�����׵�ַ
			����ص�����
 *����ֵ��	
 *******************************************************************************/
void printf_DynamicArr(Dynamic_Array * arr, void(*_callback)(void *))
{
	if (NULL == arr)
	{
		printf("[WARNING]��������̬���飬��̬����Ϊ�գ�\n");
		return;
	}

	if (NULL == _callback)
	{
		printf("[WARNING]��������̬���飬�ص�����Ϊ�գ�\n");
		return;
	}

	for (int i = 0; i < arr->size; ++i)
	{
		_callback(arr->pAddr[i]);
	}
}

/*******************************************************************************
 *��������	clear_DynamicArr
 *���ܣ�		��ն�̬����
 *������		��̬�����׵�ַ
 *����ֵ��	
 *******************************************************************************/
void clear_DynamicArr(Dynamic_Array * arr)
{
	if (NULL == arr)
	{
		printf("[WARNING]����ն�̬���飬��̬����Ϊ�գ�\n");
		return;
	}

	arr->size = 0;
}

/*******************************************************************************
 *��������	getCapacity_DynamicArr
 *���ܣ�		��ȡ��̬��������
 *������		��̬�����׵�ַ
 *����ֵ��	����ɹ���ȡ��̬����������������������෵��-1
 *******************************************************************************/
int getCapacity_DynamicArr(Dynamic_Array * arr)
{
	if (arr == NULL)
	{
		printf("[WARNING]����ȡ��̬�������������̬����Ϊ�գ�\n");
		return -1;
	}

	return arr->capacity;
}

/*******************************************************************************
 *��������	getSize_DynamicArr
 *���ܣ�		��ȡ��̬�����С
 *������		��̬�����׵�ַ
 *����ֵ��	����ɹ���ȡ��̬�����С�����ش�С����෵��-1
 *******************************************************************************/
int getSize_DynamicArr(Dynamic_Array * arr)
{
	if (arr == NULL)
	{
		printf("[WARNING]����ȡ��̬����Ĵ�С����̬����Ϊ�գ�\n");
		return -1;
	}

	return arr->size;
}

/*******************************************************************************
 *��������	getValue_DynamicArr
 *���ܣ�		��ȡԪ�أ���λ�û�ȡ
 *������		��̬�����׵�ַ
			Ԫ��λ��
 *����ֵ��	Ԫ��ֵ
 *******************************************************************************/
void * getValue_DynamicArr(Dynamic_Array * arr, int pos)
{
	if (arr == NULL)
	{
		printf("[WARNING]����ȡ��̬�����Ԫ�أ���̬����Ϊ�գ�\n");
		return NULL;
	}
	if (pos < 0 || pos >= arr->size)
	{
		printf("[WARNING]����ȡ��̬�����Ԫ�أ�λ����Ч��\n");
	}

	return arr->pAddr[pos];
}

/*******************************************************************************
 *��������	freeSpace_DynamicArr
 *���ܣ�		�ͷŶ�̬�����ڴ�ռ�
 *������		��̬�����׵�ַ
 *����ֵ��	
 *******************************************************************************/
void freeSpace_DynamicArr(Dynamic_Array * arr)
{
	if (arr == NULL)
	{
		printf("[WARNING]���ͷŶ�̬����ռ䣬��̬����Ϊ�գ�\n");
		return;
	}
	if (arr->pAddr == NULL)
	{
		printf("[WARNING]���ͷŶ�̬����ռ䣬��̬����Ԫ��Ϊ�գ�\n");
		return;
	}
	free(arr->pAddr);
	free(arr);
}

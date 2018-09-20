#include "Stack.h"

static int IsLegal(int* in, int* out, int insize, int outsize)
{
	int i = 0;
	int j = 0;
	Stack st;
	StackInit(&st);
	assert(in&&out&&insize == outsize);//两个序列元素个数相等才能进行合法性判断
	while (i < insize)
	{
		StackPush(&st, in[i++]);
		if (StackTop(&st) == out[j])
		{
			StackPop(&st);
			j++; //跳过比较过的元素，下标要加1
		}
	}
	//此时栈中剩下的元素要与out数组中剩下的元素逐个比较，遇到不一样的就不匹配
	while (StackEmpty(&st) != 0)
	{
		if (StackTop(&st) != out[j++])
		{
			return 0;
		}
		StackPop(&st);
	}
	//此时为空栈，则说明匹配
	return 1;
}


int main(void)
{
	int in[5] = { 1, 2, 3, 4, 5 };
	int out[5] = { 4, 5, 3, 2, 1 };
	int ret = IsLegal(in, out, 5, 5);
	if (ret == 1)
		printf("匹配\n");
	else
		printf("不匹配\n");

	system("pause");
	return 0;
}
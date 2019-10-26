#include"calculation.h"



void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}


Stack Create_and_InitStack(int MaxElements)
{
	
	Stack S;
	//创建的大小要至少大于MinStackSize
	if (MaxElements < MinStackSize)
		printf("Stack size is too small");
	
	//为栈申请空间
	S = malloc(sizeof(struct StackRecord));
	if (S == NULL)
		printf("Out of space!!!");//检查是否申请到空间

	//申请数组空间
	S->Array = malloc((ElementType)sizeof(ElementType)*MaxElements);
	if (S->Array == NULL)
		printf("Out of space!!!");//检测是否申请到空间

	//初始化Capacity
	S->Capacity = MaxElements;

	//将TOP令为栈底部，相当于创建空栈
	MakeEmpty(S);

	return S;//返回栈低指针
}


void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);//先释放数组，数组的首地址存在栈，数组的值存在堆中
		free(S);//释放栈

	}
}



//函数判断是否为空栈
int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;//当TOP为栈底部，则为空栈，返回1；否则返回0

}



//函数：判断是否为满栈
int IsFull(Stack S)
{
	return(S->TopOfStack + 1) >= S->Capacity;
}


//函数：入栈

void Push(ElementType x, Stack S)
{
	if (IsFull(S))
		printf("Full stack!!!");
	else
	{
		
		S->Array[++S->TopOfStack] = x;
	}

}

//函数：弹出栈，不反悔

void Pop(Stack S)
{
	if (IsEmpty(S))
		printf("Empty satck!!!");
	else
		S->TopOfStack--;
}

//函数：读取Top

ElementType Top(Stack S)
{
	if (IsEmpty(S))
	{
		printf("Empty stack!!");
		return 0;
	}
		return S->Array[S->TopOfStack];
}


/*char Top1(Stack S)
{
	if (IsEmpty(S))
	{
		printf("Empty stack!!");
		return 0;
	}
	return S->Array[S->TopOfStack];
}*/



//函数：读取Top并弹出Pop
ElementType TopAndPop(Stack S)
{
	if (IsEmpty(S) != 0)
	{
		return S->Array[S->TopOfStack--];
	}
	else
		printf("Empty stack!!!");
		return 0;
}


int IsNumber(char ch)
{
	/*if ('+' == ch || '-' == ch || '*' == ch || '/' == ch)
		return 0;
	else
		return 1;*/
	if (ch >='0'&& ch<='9')
		return 1;
	else
		return 0;

}

int RPNValue(char* Ptr)
{
	
	int i = 0;
	int res = 0;
	int tem=0;
	Stack S;
	int _size = strlen(Ptr);
	//printf("%d", _size);
	S = Create_and_InitStack(_size);
	//while ((char)Ptr[i] != '\0')
	for (; i < _size; i++)
	{

		if (IsNumber((Ptr[i])))
		{
			
			tem = tem * 10 + Ptr[i] - '0';
			//printf("%d", res);
		}
		if (Ptr[i] == ' ')
		{
			//printf("%d", 100);
			if (IsNumber((Ptr[i - 1])))
			{
				Push(tem, S);
				//S->TopOfStack++;
				//printf("%d", S->TopOfStack);
				tem = 0;
				//printf("%d", Top(S));
				//printf("%d",Top(S));

			}
		}

			if ((Ptr[i] != ' ') && (!IsNumber((Ptr[i]))))
			{
				//printf("%d",100);

				if (S->TopOfStack < 1)
				{
					printf("eee");
					return 0;
				}
				int a, b;
				a = Top(S);
				Pop(S);

				b = Top(S);
				Pop(S);


				switch (Ptr[i])
				{
				case '+':
					res = a + b;
					Push(res, S);
					break;
				case '-':
					res = a - b;
					Push(res, S);
					break;
				case '*':
					res = a * b;
					Push(res, S);
					break;
				case '/':
					if (b == 0)
					{
						printf("error!!!");
						break;
					}
					if (b != 0)
					{
						res = a / b;
						Push(res, S);
						break;
					}




				}

			}
		



		}
		/*if (S->TopOfStack == 0)
			{

			}
			else
			printf("okk!!!");*/
	int c = Top(S);
	DisposeStack(S);
		return c;

	
	



	}

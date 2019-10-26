#include"calculation.h"



void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}


Stack Create_and_InitStack(int MaxElements)
{
	
	Stack S;
	//�����Ĵ�СҪ���ٴ���MinStackSize
	if (MaxElements < MinStackSize)
		printf("Stack size is too small");
	
	//Ϊջ����ռ�
	S = malloc(sizeof(struct StackRecord));
	if (S == NULL)
		printf("Out of space!!!");//����Ƿ����뵽�ռ�

	//��������ռ�
	S->Array = malloc((ElementType)sizeof(ElementType)*MaxElements);
	if (S->Array == NULL)
		printf("Out of space!!!");//����Ƿ����뵽�ռ�

	//��ʼ��Capacity
	S->Capacity = MaxElements;

	//��TOP��Ϊջ�ײ����൱�ڴ�����ջ
	MakeEmpty(S);

	return S;//����ջ��ָ��
}


void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);//���ͷ����飬������׵�ַ����ջ�������ֵ���ڶ���
		free(S);//�ͷ�ջ

	}
}



//�����ж��Ƿ�Ϊ��ջ
int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;//��TOPΪջ�ײ�����Ϊ��ջ������1�����򷵻�0

}



//�������ж��Ƿ�Ϊ��ջ
int IsFull(Stack S)
{
	return(S->TopOfStack + 1) >= S->Capacity;
}


//��������ջ

void Push(ElementType x, Stack S)
{
	if (IsFull(S))
		printf("Full stack!!!");
	else
	{
		
		S->Array[++S->TopOfStack] = x;
	}

}

//����������ջ��������

void Pop(Stack S)
{
	if (IsEmpty(S))
		printf("Empty satck!!!");
	else
		S->TopOfStack--;
}

//��������ȡTop

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



//��������ȡTop������Pop
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

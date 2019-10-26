#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#include<string.h>

//struct StackRecord;
//typedef struct StackRecord *Stack;
#define ElementType int
#define EmptyTOS (-1)
#define MinStackSize (5)

typedef struct StackRecord
{
	int Capacity;//容量
	int TopOfStack;//栈顶
	ElementType *Array;//定义一个数组指针

}*Stack,StackRecord;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack Create_and_InitStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType x, Stack S);
int Top(Stack S);
//char Top1(Stack S);
void Pop(Stack S);
int TopAndPop(Stack S);
int IsNumber(char ch);
int RPNValue(char* Ptr);
//int Priority(char ch);
//void InfixToSuffix(int* Ptr, int _size);
//void display_Stack(const Stack S);



#endif













 
#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<vld.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#pragma warning(disable:4996)

//typedef int STData;
//typedef struct StackNode{
//	STData Data;
//	struct StackNode *Next;
//}StackNode,*Stack;

typedef int QUData;

//链式队列结构定义
typedef struct QueueNode{
	QUData Data;
	struct QueueNode *Next;
}QueueNode;

typedef struct Queue{
	QueueNode *head;  //队头指针
	QueueNode *tail;   //队尾指针
}Queue;

#endif
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

//��ʽ���нṹ����
typedef struct QueueNode{
	QUData Data;
	struct QueueNode *Next;
}QueueNode;

typedef struct Queue{
	QueueNode *head;  //��ͷָ��
	QueueNode *tail;   //��βָ��
}Queue;

#endif
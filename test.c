#include"test.h"
#if 0
void StackInit(Stack *phead){    //初始化
	assert(phead != NULL);
	*phead = NULL;
}

void StackPush(Stack *phead, STData x){    //进栈(尾插)
	assert(phead != NULL);
	StackNode *s = (StackNode *)malloc(sizeof(StackNode));
	s->Data = x;
	s->Next = *phead;
	*phead = s;
}
//判空
bool IsEmpty(Stack phead){
	return phead == NULL;
}
//出栈
void StackPop(Stack *phead){
	assert(phead != NULL);
	StackNode *p = *phead;
	if (IsEmpty(*phead)){
		printf("栈为空，无法出栈\n");
		return;
	}
	*phead = (*phead)->Next;
	free(p);
}
//取栈顶元素
STData StackTop(Stack phead){
	assert(phead != NULL);
	return phead->Data;
}
//求栈的元素个数
int StackSize(Stack phead){
	StackNode *p = phead;
	int count = 0;
	while (p != NULL){
		count++;
		p = p->Next;
	}
	return count;
}
//摧毁栈
void StackDestroy(Stack *phead){
	assert(phead != NULL);
	StackNode *p = (*phead)->Next;
	StackNode *q = NULL;
	while (p != NULL){
		q = p;
		*phead = p;
		p = p->Next;
		free(q);
	}
	free(phead);
}
void StackShow(Stack phead){
	StackNode *p = phead;
	while (p != NULL){
		printf("|%d|\n", p->Data);
		p = p->Next;
	}
	printf(" - \n");
}
#endif
//初始化
void QueueInit(Queue *pq){
	pq->head = pq->tail = NULL;
}
//入队
void QueueEn(Queue *pq, QUData x){
	assert(pq != NULL);
	QueueNode *s = (QueueNode *)malloc(sizeof(QueueNode));
	s->Data = x;
	s->Next = NULL;
	if (pq->head == NULL){
		pq->head = pq->tail = s;
	}
	else{
		pq->tail->Next = s;
		pq->tail = s;
	}
}
//判空
bool IsEmpty(Queue *pq){
	assert(pq != NULL);
	return pq->head == NULL;
}
//出对
void QueueDe(Queue *pq){
	assert(pq != NULL);
	if (IsEmpty(pq)){
		printf("队列无元素,无法出对!\n");
		return;
	}
	QueueNode *p = pq->head;
	if (pq->head == pq->tail){
		pq->head = pq->tail = NULL;
	}
	else{
		pq->head = p->Next;
		free(p);
	}
}
//摧毁队列
void QueueDestroy(Queue *pq){
	assert(pq != NULL);
	QueueNode *p = pq->head;
	while (p != NULL){
		pq->head = p->Next;
		free(p);
		p = pq->head;
	}
}
//遍历
void QueueShow(Queue *pq){
	assert(pq != NULL);
	Queue *q = pq;
	while (q->head!=NULL){
		printf("%d ", q->head->Data);
		q->head = q->head->Next;
	}
}
//取队头元素
QUData QueueFront(Queue *pq){
	assert(pq != NULL);
	assert(IsEmpty(pq));
	return pq->head->Data;
}
//求队列元素个数
int QueueSize(Queue *pq){
	assert(pq != NULL);
	QueueNode *p = pq->head;
	int i = 0;
	while (p!= NULL){
		i++;
		p = p->Next;
	}
	return i;
}
int main(){
	Queue q;
	QueueInit(&q);
	QUData item;
	printf("Please enter your data(0 is end):>");
	while (scanf("%d", &item), item){
		QueueEn(&q, item);
	}
	QueueDe(&q);
	int n=QueueSize(&q);
	printf("size=%d\n", n);
	QueueDe(&q);
	n = QueueSize(&q);
	printf("size=%d\n", n);
	QueueShow(&q);
	//Stack p;
	//StackInit(&p);
	//STData item;
	//printf("Please enter your data(0 is end):>");
	//while (scanf("%d", &item), item){
	//	StackPush(&p,item);
	//}
	//int n=StackSize(p);
	////printf("Size=%d\n", n);
	////printf("%d出栈\n", StackTop(p));
	//StackPop(&p);
	////n = StackSize(p);
	////printf("Size=%d\n", n);
	//StackShow(p);
	return 0;
}
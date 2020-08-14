#include"test.h"
#if 0
void StackInit(Stack *phead){    //��ʼ��
	assert(phead != NULL);
	*phead = NULL;
}

void StackPush(Stack *phead, STData x){    //��ջ(β��)
	assert(phead != NULL);
	StackNode *s = (StackNode *)malloc(sizeof(StackNode));
	s->Data = x;
	s->Next = *phead;
	*phead = s;
}
//�п�
bool IsEmpty(Stack phead){
	return phead == NULL;
}
//��ջ
void StackPop(Stack *phead){
	assert(phead != NULL);
	StackNode *p = *phead;
	if (IsEmpty(*phead)){
		printf("ջΪ�գ��޷���ջ\n");
		return;
	}
	*phead = (*phead)->Next;
	free(p);
}
//ȡջ��Ԫ��
STData StackTop(Stack phead){
	assert(phead != NULL);
	return phead->Data;
}
//��ջ��Ԫ�ظ���
int StackSize(Stack phead){
	StackNode *p = phead;
	int count = 0;
	while (p != NULL){
		count++;
		p = p->Next;
	}
	return count;
}
//�ݻ�ջ
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
//��ʼ��
void QueueInit(Queue *pq){
	pq->head = pq->tail = NULL;
}
//���
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
//�п�
bool IsEmpty(Queue *pq){
	assert(pq != NULL);
	return pq->head == NULL;
}
//����
void QueueDe(Queue *pq){
	assert(pq != NULL);
	if (IsEmpty(pq)){
		printf("������Ԫ��,�޷�����!\n");
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
//�ݻٶ���
void QueueDestroy(Queue *pq){
	assert(pq != NULL);
	QueueNode *p = pq->head;
	while (p != NULL){
		pq->head = p->Next;
		free(p);
		p = pq->head;
	}
}
//����
void QueueShow(Queue *pq){
	assert(pq != NULL);
	Queue *q = pq;
	while (q->head!=NULL){
		printf("%d ", q->head->Data);
		q->head = q->head->Next;
	}
}
//ȡ��ͷԪ��
QUData QueueFront(Queue *pq){
	assert(pq != NULL);
	assert(IsEmpty(pq));
	return pq->head->Data;
}
//�����Ԫ�ظ���
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
	////printf("%d��ջ\n", StackTop(p));
	//StackPop(&p);
	////n = StackSize(p);
	////printf("Size=%d\n", n);
	//StackShow(p);
	return 0;
}
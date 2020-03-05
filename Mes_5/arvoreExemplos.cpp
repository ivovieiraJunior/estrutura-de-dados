#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct BTNode {
  int info;
  struct BTNode *lPtr, *rPtr;
} BTNode;

typedef BTNode *BTree;

BTNode *createBTNode(int info)
{
  BTNode *nnode = (BTNode *)malloc(sizeof(BTNode));
  nnode->info = info;
  nnode->lPtr = NULL;
  nnode->rPtr = nnode->lPtr;
  return nnode;
}

void insert(int info, BTree btree)
{
  if (info < btree->info)
    if (btree->lPtr == NULL)
      btree->lPtr = createBTNode(info);
    else
      insert(info, btree->lPtr);
  else if (info > btree->info)
    if (btree->rPtr == NULL)
      btree->rPtr = createBTNode(info);
    else
      insert(info, btree->rPtr);
}

typedef struct QNode {
  BTNode *info;
  struct QNode *next;
} QNode;

typedef struct Queue {
  QNode *head, *tail;
  int count;
} Queue;

QNode *createQNode(BTNode *info)
{
  QNode *nqn = (QNode *)malloc(sizeof(QNode));
  nqn->info = info;
  nqn->next = NULL;
  return nqn;
}

Queue *createQueue(void)
{
  Queue *nq = (Queue *)malloc(sizeof(Queue));
  nq->head = NULL;
  nq->tail = nq->head;
  nq->count = 0;
  return nq;
}

#define count(q) q->count

void push(BTNode *info, Queue *q)
{
  if (q->head == NULL) {
    q->head = createQNode(info);
    q->tail = q->head;
  }
  else {
    q->tail->next = createQNode(info);
    q->tail = q->tail->next;
  }
  q->count++;
}

BTNode *pop(Queue *q)
{
  BTNode *ret = q->head->info;
  q->head = q->head->next;
  q->count--;
  return ret;
}

void printBTree(BTree btree)
{
  Queue *q = createQueue();
  int tmp;
  BTNode *node;
  push(btree, q);
  tmp = count(q);
  while (tmp > 0) {
    int i = 0;
    for (;i < tmp;i++) {
      node = pop(q);
      if (node != NULL) {
        printf("%d ", node->info);
        push(node->lPtr, q);
        push(node->rPtr, q);
      }
      else
        printf ("~ ");
    }
    printf("\n");
    tmp = count(q);
  }
}

int main(void)
{
  BTree btree = createBTNode(8);
  insert(4, btree);
  insert(12, btree);
  insert(2, btree);
  insert(6, btree);
  insert(10, btree);
  insert(14, btree);
  insert(1, btree);
  insert(3, btree);
  insert(5, btree);
  insert(7, btree);
  insert(9, btree);
  insert(11, btree);
  insert(13, btree);
  insert(15, btree);
  printBTree(btree);
  return 0;
}

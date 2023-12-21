//（1）循环队列的类型定义如下：

typedef struct {
    ElemType data[MAXSIZE];
    int front;
    int rear;
} SqQueue;
//（2）（1）循环队列的类型定义：

#define MAXSIZE 100
typedef struct {
    int data[MAXSIZE];
    int front;
    int rear;
} Deque;
//（2）从队尾删除和从队头插入的算法：队列中，队尾指针处不保存元素，保留队尾指针所指位置为保留。

#define MAXSIZE 100
typedef struct {
    int data[MAXSIZE];
    int front;
    int rear;
} Deque;

// 检查队列是否满
int isFull(Deque *Q) {
    return (Q->rear + 1) % MAXSIZE == Q->front;
}

// 检查队列是否为空
int isEmpty(Deque *Q) {
    return Q->front == Q->rear;
}

// 从队尾删除
int deleteRear(Deque *Q) {
    if (isEmpty(Q)) {
        printf("队列为空，无法删除元素\n");
        return -1;
    }
    Q->rear = (Q->rear - 1 + MAXSIZE) % MAXSIZE;
    return Q->data[Q->rear];
}

// 从队头插入
void insertFront(Deque *Q, int e) {
    if (isFull(Q)) {
        printf("队列已满，无法插入元素\n");
        return;
    }
    Q->front = (Q->front - 1 + MAXSIZE) % MAXSIZE;
    Q->data[Q->front] = e;
}
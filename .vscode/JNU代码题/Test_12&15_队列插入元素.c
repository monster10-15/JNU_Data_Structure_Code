// 代码填空题
// 定义队列节点结构
typedef struct QNode {
    QElemType data; // 节点数据
    struct QNode *next; // 指向下一个节点的指针
} QNode, *QueuePtr;

// 定义链式队列结构
typedef struct {
    QueuePtr front; // 队头指针
    QueuePtr rear; // 队尾指针
} LinkQueue, *LinkQueuePtr;

// 元素e加入到队列Q中
Boolean EnQueue(LinkQueuePtr Q, QElemType e) {
    // 创建一个新的节点
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) return FALSE; // 如果内存分配失败，则返回FALSE

    p->data = e; // 设置节点数据
    p->next = NULL; // 设置节点的next指针指向NULL

    // 将新节点添加到队尾
    Q->rear->next = p;
    Q->rear = p; // 更新队尾指针

    return TRUE;
}

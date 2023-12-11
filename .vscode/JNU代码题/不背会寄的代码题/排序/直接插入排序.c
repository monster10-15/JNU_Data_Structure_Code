void insertionSort(Node **head_ref) {
    // 初始化排序后的链表
    Node *sorted = NULL;
    // 遍历给定的链表并插入到排序后的链表中
    Node *current = *head_ref;
    while (current != NULL) {
        // 保存下一个用于后续遍历
        Node *next = current->next;
        // 把当前节点插入到排序后的链表中
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        // 更新当前节点为下一个节点
        current = next;
    }
    // 更新头节点为排序后的链表的头节点
    *head_ref = sorted;
}
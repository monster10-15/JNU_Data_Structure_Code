struct node {
    int key;
    struct node *next;
};

void DeleteDuplicate(struct node* L) {
    struct node *p, *q;
    if (L == NULL || L->next == NULL) {  // 如果链表为空或只有一个节点，直接返回
        return;
    }
    p = L;  // 初始化p为链表的头节点
    q = p->next;  // 初始化q为p的下一个节点
    while (p->next != NULL) {  // 当p的下一个节点不为空时，执行循环
        if(p->key != q->key){  // 如果p和q的键值不同
            p = p->next;  //! (1) p移动到下一个节点
            q = p->next;  //! (2) q移动到p的下一个节点
        }
        else{  // 如果p和q的键值相同
            while(q != NULL && p->key == q->key){  //! (3) 当q不为空且p和q的键值相同时，执行循环
                struct node *temp = q;  // 创建一个临时节点temp，指向q
                q = q->next;  //! (4) q移动到下一个节点
                delete temp;  // 删除temp节点
            }
            if(q != NULL){  // 如果q不为空
                p->next = q;  //! (5) p的下一个节点指向q
                p = p->next;  // p移动到下一个节点
                q = p->next;  // q移动到p的下一个节点
            }
            else {
                p->next = NULL;  //! (6) 如果q为空，p的下一个节点指向NULL
            }
        }
    }
}

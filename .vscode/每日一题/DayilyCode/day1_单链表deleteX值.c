//TODO: 在带头结点的单链表L中删除所有值为x的结点并释放其空间，假设值为x的结点不唯一
// 算法思想：
// 在单链表中，要删除一个节点，需要找到待删除节点的前驱节点，
// 将前驱节点的指针指向待删除节点的后继节点，然后删除待删除节点。

void delete_x_1(Linklist &L, Elemtype x){
    LNode *p=L->next, *pre=L, *temp;
    // 定义三个指针，p用于遍历链表，pre指向被删除结点的前驱，（临时指针）temp用于删除结点
    while(p!=NULL){
        if (p->data==x){
            //如果p指向值为x的元素，则删除它（删除：前驱指向p的后继） 
            temp = p;
            p = p->next;
            pre->next = p;
            free(temp);
        }
        else {
            pre = p;
            p = p->next;
        }
    }
}

// 9.18 review:100/100
// 算法思想：设置仨指针，p遍历指针，pre指向要删除的结点，temp用于删除结点
void delete_x_2(Linklist &L, Elemtype x){
    LNode *p=L->next, *pre=L, *temp;
    while (p!=NULL){
        if (p->data==x){
            temp = p;
            pre->next=p->next;
            p = p->next;
            free(temp);

        }
        else {
            pre = pre -> next;
            p = p -> next;
        }
    }
}
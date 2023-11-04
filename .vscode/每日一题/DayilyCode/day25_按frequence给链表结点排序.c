// TODO: 使头指针为L的带有头结点的非循环双向链表，其每个结点中除了有prev(前驱指针)data(数据)和next(后继指针)域外还有一个访问频率域freq。在链表被启用前，其初值初始化为零。
// 每当在链表中进行一次Locate(L,x)运算时，令元素值为x的结点中freq域的值增加1, 并使此链表中结点保持按访问频度(递减)的顺序排列。
// 若频度相同: 最近访问的结点排前面，以便使频繁访问的结点总是靠近表头。
// 试编写符合上述要求的Locate(L,x)运算的算法。该运算为函数过程，返回找到结点的地址，类型为指针型
// 算法思想: 找到含x的结点，freq+1, 取下该结点，根据freq的大小插入表中
DLinkList Locate_1(DLinkList &L, Elemtype x) {
    DNode *p = L->next, *q;
    while (p && p->data != x) {
        p = p->next;
    }
    if (!p) { // 如果找不到节点，返回nullptr
        return nullptr;
    } else {
        p->freq++; // 找到节点，频度+1
        // 如果p的频度等于L的频度或者p的前驱节点的频度大于p的频度，直接返回p
        if (p->freq == L->freq || (p->prev && p->prev->freq > p->freq)) { 
            return p;
        } else { // 否则需要将p从链表中取下，再按照频度非递减的顺序插入链表中
            if (p->next) { // 如果p有后继节点，将后继节点的前驱指针指向p的前驱节点
                p->next->prev = p->prev;
            }
            p->prev->next = p->next; // 将p的前驱节点的后继指针指向p的后继节点
            q = p->prev; // 从p的前驱节点开始向前遍历链表，寻找插入位置
            while (q != L && q->freq <= p->freq) {
                q = q->prev;
            }
            p->next = q->next; // 将p的后继指针指向q的后继节点
            if (q->next) { // 如果q的后继节点存在，将其前驱指针指向p
                q->next->prev = p;
            }
            q->next = p; // 将q的后继指针指向p
            p->prev = q; // 将p的前驱指针指向q
            return p; // 返回p的地址
        }
    }
}
1011 review: 50/100
DLinkList Locate_2(DLinkList &L, Elemtype x) {
    DNode *p = L->next, *q;
    while (p && p->data != x) {
        p = p->next;
    }
    if (!p) { // 如果找不到节点，返回nullptr
        return nullptr;
    } else {
        p->freq++; // 找到节点，频度+1
        // 如果p的频度等于L的频度或者p的前驱节点的频度大于p的频度，直接返回p
        if (p->freq == L->freq || (p->prev && p->prev->freq > p->freq)) { 
            return p;
        } else { // 否则需要将p从链表中取下，再按照频度非递减的顺序插入链表中
            if (p->next) { // 如果p有后继节点，将后继节点的前驱指针指向p的前驱节点
                p->next->prev = p->prev;
            }
            p->prev->next = p->next; // 将p的前驱节点的后继指针指向p的后继节点
            // 从p的前驱节点开始向前遍历链表，寻找插入位置
            q = p->prev; 
            while (q != L && q->freq <= p->freq) {
                q = q->prev;
            }
            // 将p的后继指针指向q的后继节点
            p->next = q->next; 
            // 如果q的后继节点存在，将其前驱指针指向p
            if (q->next) { 
                q->next->prev = p;
            }
            q->next = p; // 将q的后继指针指向p
            p->prev = q; // 将p的前驱指针指向q
            return p; // 返回p的地址
        }
    }
}
1012 review: 70/100
DLinkList Locate_3(DLinkList &L, Elemtype x){
    LNode *pre=L, *p=L->next, *temp=null;
    while(p!=L){
        // 如果data域为x,freq++之后调整位置
        if(p->data==x){ 
            temp=p;
            temp->freq++;
            pre->next=temp->next;
            temp->next->prev=pre;
            }
            pre=p;
            p=p->next;
    }
    while(temp!=null){
        LNode *pp=L->next;
        // 根据freq的大小插入到表中
        while(pp!=L && pp->freq>=temp->freq){
            pp=pp->next;
        }
        temp->next=pp;
        ppre->next=temp;
        temp->prev=ppre;
        pp->prev=temp;
        pp=pp->next;
    }
    return temp;
}


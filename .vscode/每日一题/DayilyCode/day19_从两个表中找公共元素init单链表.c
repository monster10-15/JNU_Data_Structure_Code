// TODO: 设AB两个单链表（带头结点）其中元素递增有序。设计一个算法从AB中的公共元素产生单链表C，不得破坏A，B结点
// 算法思想: 依次比较AB元素，将值较小的指针后移，若两个相等即为公共元素，则创建一个新结点（值为公共结点的值）。
// 使用尾插法插入到新链表中。并将两个指针同时后移一位，若有剩余结点，则无需处理。
LinkList Common_1(LinkList &A, LinkList &B){
    LinkList C=(LinkList)malloc(sizeof(LNode));
    C->next=NULL;
    LNode *pa=A->next, *pb=B->next, *pc=C, *temp;
    while(pa!=NULL && pb!=NULL){
        if(pa->data==pb->data){
            temp=(LNode*)malloc(sizeof(LNode));
            temp->data=pa->data;
            pc->next=temp;
            pc=temp;
            pa=pa->next;
            pb=pb->next;
        }
        else if(pa->data > pb->data){
            pb=pb->next;
        }
        else if(pb->data > pa->data){
            pa=pa->next;
        }
    }
    pc->next=NULL; // 将C链表的尾节点指针置为NULL
    return C;
}
1007 review: 90/100
LinkList Common_2(LinkList &A, LinkList &B){
    LinkList C=(LinkList*)malloc(sizeof(LinkList));
    LNode *pa=A->next, *pb=B->next, *pc=C;
    C->next=NULL;
    while(pa!=NULL && pb!=NULL){
        if(pb->data>pa->data){
            pa=pa->next;
        }
        else if(pb->data<pa->data){
            pb=pb->next;
        }
        else if(pa->data==pb->data){
            LNode *temp =(LNode*)malloc(sizeof(LNode));
            temp->data=pa->data;
            pc->next=temp;
            pc=temp;
            pa=pa->next;
            pb=pb->next;
        }
    }
    pc->next=NULL;
    return C;
}
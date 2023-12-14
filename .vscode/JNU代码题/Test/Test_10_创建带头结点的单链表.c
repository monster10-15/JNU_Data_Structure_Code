// 输入n个元素的值，创建带头结点的单链表
SqList Create(int n){
    LinkList *L=malloc(LinkNode*);
    LinkNode *p=malloc(LinkNode*);
    L->next=p,p->next=null;
    int x;
    while(n>0){
        scanf("%d",&x);
        LinkNode *temp=malloc(LinkNode*);
        temp->data=x;
        p->next=temp;
        p=temp;
        p->next=null;
    }
    return L;
}
// TODO: 用头插法建立单链表
LinkList Insert_head_1(Linklist &L){
    LNode *s, int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    while(x!=-1){       
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}
//0927review:0/100
LinkList Insert_head_2(LinkList &L){
    LNode *s, int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=null;
    scanf("%d",&x);
    while(x!=-1){
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}
//0928review: 90/100
LinkList Insert_head_3(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    LNode *temp;
    int x;
    scanf("%d", &x);
    L->next = NULL;
    while (x != -1) {
        temp = (LinkList)malloc(sizeof(LNode));
        temp->data = x;
        temp->next = L->next;
        L->next = temp;
        scanf("%d", &x);
    }
    return L;
}
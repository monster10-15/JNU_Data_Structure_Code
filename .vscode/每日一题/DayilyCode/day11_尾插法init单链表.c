// TODO: 使用尾插法建立单链表
LinkList List_tail_insert_1(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s, *r;
    int x;
    r = L; // r是L的尾指针
    scanf("%d", &x);
    while (x != -1) {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL; // 设置新节点的next指针为NULL
        r->next = s; // 将新节点插入到尾指针r的后面
        r = s; // 更新尾指针r的指向
        scanf("%d", &x);
    }
    return L;
}

//0928review: 50/100
LinkList List_tail_insert_2(LinkList &L) {  
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s, *r;
    int x;
    r = L; // r是L的尾指针
    scanf("%d", &x);
    while (x != -1) {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL; // 设置新节点的next指针为NULL
        r->next = s; // 将新节点插入到尾指针r的后面
        r = s; // 更新尾指针r的指向
        scanf("%d", &x);
    }
    return L;
}

//0929review: 70/100
LinkList List_tail_insert_3(LinkList &L){
    int x;
    LNode *r, *s;
    L= (LinkList)malloc(sizeof(LNode));
    r=L;
    scanf("%d", &x);
    while(x!=-1){
        *s = (LNode)malloc(sizeof(LNode));
        *r = (LNode)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return L;
}

//0930review: 90/100
LinkList List_tail_insert_4(LinkList &L){
    LNode *r, *s;
    L = (LinkList *)malloc(sizeof(LNode));
    r=L;
    int x;
    scanf("%d",&x);
    while(x!=-1){
        s=(LNode)malloc(sizeof(LNode));
        r=(LNode)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    return L;
}
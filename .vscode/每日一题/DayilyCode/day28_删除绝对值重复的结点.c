//TODO: 【2015统考真题】用单链表保存m个整数，结点的结构为[data][link]，且 |data|<=n (n正整数)
//设计一个时问复杂度尽可能高效的算法，对于链表中data的绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点。
// 若给定的单链表L如下: L->21->-15->-15->-7->15^ 删除节点后的L为: L->21->-15->-7^
// 算法思想💭：（以空间换时间）申请一个大小为n+1的辅助空间（标记数组），初始化为0，第一次出现，保留（将标记从0->1)否则删掉结点。
void Fun(LinkList &L, int n){
    LNode *p = L->link, *pre = L;
    int *C = (int*)malloc(sizeof(int)*(n+1)); // 申请数组并初始化为全0
    for(int i = 0; i < n+1; i++){
        C[i] = 0;
    }
    while(p != nullptr){
        int m = p->data > 0 ? p->data : -(p->data);
        if(C[m] == 0){
            C[m] = 1; // 保留
            pre = p;
            p = p->link;
        }
        else{ // 若标记为1（已出现）
            pre->link = p->link; // 删除
            LNode *temp = p;
            p = p->link;
            free(temp);
        }
    }
    free(C);
}
// 1013 review: 90/100
LinkList Fun_2(LinkList &L, int n) {
    LNode *p = L->next, *pre = L;
    int *a = (int*)malloc((n+1)*sizeof(int));
    for(int i = 0; i <= n; i++) {
        a[i] = 0;
    }
    while(p != NULL) {
        int temp = abs(p->data);
        if(a[temp] == 0) {
            a[temp] = 1;
        } else if(a[temp] == 1) {
            pre->next = p->next;
            free(p);
        }
        pre = pre->next;
        p = pre->next;
    }
    return L;
}
// TODO: 给定一个单链表，编写算法找出两个单链表的公共结点。
// 算法思想: 
// 如何寻找公共结点?同时到达表尾。
//     如何同时到达表尾?
//         ①链表等长:同步移动
//         ②链表不等长:长表先走K步[k即两表长之差], 再一起开始走
//     如何判断两条链表有公共结点? p=q
LNode* Search_Common_1(Linklist A, Linklist B) {
    LNode* p = A->next;
    LNode* q = B->next;
    int lenA = 0, lenB = 0;
    // 计算两条链表的长度
    while (p != NULL) {
        lenA++;
        p = p->next;
    }
    while (q != NULL) {
        lenB++;
        q = q->next;
    }
    
    p = A->next;
    q = B->next;
    int diff = abs(lenA - lenB);
    if (lenA > lenB) {
        while (diff > 0) {
            p = p->next;
            diff--;
        }
    } else {
        while (diff > 0) {
            q = q->next;
            diff--;
        }
    }
    
    while (p != NULL && q != NULL) {
        if (p == q) {
            return p;
        }
        p = p->next;
        q = q->next;
    }
    
    return NULL;
}
// 1005 review: 80/100
LNode* Search_Common_2(LinkList A, LinkList B){
    int len_A = 0, len_B = 0;
    LNode* pa = A->next, *pb = B->next;
    while(pa != NULL){
        pa = pa->next;
        len_A++;
    }
    while(pb != NULL){
        pb = pb->next;
        len_B++;
    }
    int diff = (len_A > len_B ? (len_A - len_B) : (len_B - len_A));
    pa = A->next;
    pb = B->next;
    while(diff > 0){
        int da = diff, db = diff;
        if (len_A > len_B){
            while(da > 0){
                pa = pa->next;
                da--;
            }
        }
        if(len_A < len_B){
            while(db > 0){
                pb = pb->next;
                db--;
            }
        }
        while(pa != NULL && pb != NULL){
            if(pa == pb){
                return pa;
            }
            pa = pa->next;
            pb = pb->next;
        }
    }
    return NULL;
}
// TODO: 假定采用带头结点的单链表保存两个单词有相同的后缀时，可享受相同的后缀存储空问，
// 例如，“loading”“being”的存储映像如下图。设str1和str2分别指向两个单词的单链表的头结点，
// 请设计一个时间上尽可能高效的算法，找出由strl和str2所指向两个链表共同后缀的起始位置
// 算法思想💭:1.求出str1与str2的长度m与n 2.将较长的链表移动k=|str1-str2| 3.反复将pq指针后移直到pq指向同一指针(p=q即为共同后缀)
LNode* Search_Common_1(LinkList str1, LinkList str2){
    m=len(str1);
    n=len(str2);
    for(p=str1->next, m>n, n--){
        p=p->next;
    }
    for(q=str2->next, m<n, n--){
        q=q->next;
    }
    while(p!=NULL && p!=q){
        p=p->next;
        q=q->next;
    }
}
int len(SNode *head){
    LNode *p=head->next;
    int len=0;
    while(p!=NULL){
        p=p->next;
        len++;
    }
    return len;
}
// 1012 review: 90/100
LNode* Search_Common_2(LinkList str1, LinkList str2){
    int len_1 = len(str1), len_2 = len(str2);
    int len = abs(len_1 - len_2);
    LNode *p1 = str1->next, *p2 = str2->next;
    while (len > 0) {
        if (len_1 > len_2) {
            p1 = p1->next;
        } else {
            p2 = p2->next;
        }
        len--;
    }
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
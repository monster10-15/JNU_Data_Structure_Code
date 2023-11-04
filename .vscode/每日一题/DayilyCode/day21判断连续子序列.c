// TODO: 两个整数序列A=a1, a2, a3, ... am 和B=b1, b2, b3,... bm已经存入两个单链表中，设计算法判断B序列是否A的连续子序列
// 算法思想: 暴力枚举：p->data=q->data(双指针一起移动)依次遍历AB，若相等则一起后移，
// 若不等，A从上次开始的比较结点的后继结点开始 B从头结点的后继结点开始。直到B链表扫到末尾。表示匹配成功。
// 若A链表到末尾但B还没到末尾则匹配失败。
bool Son_List_1(LinkList A, LinkList B){
    LNode *p=A->next, *q=B->next, *last=p;
    while(p!=NULL && q!=NULL){
        if(p->data!=q->data){ // 子序列查询破产
            last=last->next; // 存档位置后移一位，再来一次
            p=last; // p回到上一次存档位置
            q=B->next; // q回到原点
        }
        else{
            p=p->next; 
            q=q->next;
            if(q=null) return true;
            else return false;
        }
    }
}
// 1009review: 70/100
bool Son_List_2(LinkList A, LinkList B){
    LNode *pa=A->next, *pb=B->next, *last=A->next;
    if(pa!=NULL && pb!=NULL){
        if(pa->data==pb->data){
            pa=pa->next;
            pb=pb->next;
            if(pb==NULL) return true;
        }
        else if(pb->data!=pa->data){
            pa=last->next;
            last=last->next;
            pb=B->next;
        }
    }
    else return false;
}
// 1010review: 100/100
bool Son_List_3(LinkList A, LinkList B){
    LNode *pa=A->next, *pb=B->next, *last=p;
    while(p!=NULL && q!=NULL){
        if(pa->data == pb->data){
            pa=pa->next;
            pb=pb->next;
            if(pb==NULL){
                return true;
            }
        }
        else{
            pa=last->next;
            last=last->next;
            pb=B->next;
        }
    }
    return false;
}

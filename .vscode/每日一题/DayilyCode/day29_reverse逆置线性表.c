// TODO: 【2019统考真题】设线性表L= (a1，a2，a3，.…，an-2，an-1，an） 采用带头结点的单链表保存，链表中的结点定义如下：
// 请设计一个空间复杂度为O(1) 且时间上尽可能高效的算法，重新排列L中的各結点，得到线性表L1= (a1, an, a2, an-1, a3, an-2,...)
typedef struct node
{
    int data;
    struct node *next
}NODE;
// 算法思想: 找中间结点，后半段逆置，再依次插入到前半段
// 【1】如何找到中间结点？
// 法1⃣️第一次遍历确定链表长度，第二次遍历走len/2步
// 法2⃣️双指针法：间隔保持一个倍数。p向后移a步，q后移2a步。当q到达表尾，p所在位置即为表中。
// 【2】如何合并链表？
// 法1: 都采用尾插法（尾插留尾针）
// 法2: 直接插入在要求的位置
void Change_list_1(Node *h){
    Node *p=h, *q=h, *r, *s;
    // 找中间结点
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
        if(q->next!=null){
            q=q->next;
        }
        q=q->next;
        p->next=null;
    }
    // 逆置
    while(q!=null){
        r=q->next;
        q=q->next;
        p->next=q;
        q=r;
    }
    s=h->next;
    q=p->next;
    p->next=null;
    // 合并
    while(q!=null){
        r=q->next;// 防断链
        q->next=s->next;// 类头插法
        s->next=q;
        s=q->next;// 更改s的位置
        q=r;// 防止断链
    }
}
// 1013 review 70/100
void Change_list_2(Node *L){
    LNode *p=L->next, *mid;
    // 第一步: 找到中间结点
    int count=len(L)/2-1;
    while(count>0){
        p=p->next; // 此时p指向中间结点了
        count--;
    }
    mid=p; // 标记一下中间结点
    // 第二步: 后半段逆置(头插法)
    LNode *q=p->next, *temp;
    while(q->next!=null){
        temp=q->next;
        q->next=temp->next;
        temp->next=p->next;
        p->next=temp;
        q=p->next;
    }
    // 第三步: 尾插到前半段
    p=L->next;
    while(mid!=null){
        temp=mid;
        temp->next=p->next;
        p->next=temp;
        // 尾插完之后，p和mid向后移动一位
        p=p->next;
        mid=mid->next;
    }
}
int len(LinkList *L){
    LNode *p=L->next;
    int n=0;
    while(p!=null){
        p=p->next;
        n++;
    }
    return n;
}

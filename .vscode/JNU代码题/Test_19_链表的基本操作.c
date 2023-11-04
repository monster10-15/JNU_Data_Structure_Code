//TODO: 设有一个由正整数组成的无序单链表，试编写算法实现下列功能
//TODO: （1）找出最小值结点，并输出该数值；
//TODO: （2）若该最小值是奇数，则将其与直接后继结点的数值交换；如该最小值是偶数，则将其直接后继结点删除。
void Fun(LinkList &L){
    LinkNode *p=L->next, *minp=p, *temp;
    int min=p->data;
    while(p!=NULL){
        if(p->data<min){
            min=p->data;
            minp=p;
        }
        p=p->next;
    }
    printf("最小值是：%d\n", min);
    while(minp->next != NULL){
        if(min%2==0){
            temp=minp->next;
            minp->next=temp->next;
            free(temp);
        }
        else{
            minp->data=minp->next->data;
            minp->next->data=min;
        }
    }
}

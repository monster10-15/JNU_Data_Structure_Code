// TODO: 利用结点的右指针将一个二叉树的叶子结点从左向右链接成一个单链表(head指向第一个，tail指向最后一个)
void LinkLeaf(BiTree p, BiTree *head, BiTree *tail){
    if (p) {
        if (p->lchild == NULL && p->rchild == NULL) {
            if (*head == NULL) {
                *head = p;
                *tail = p;
            } else {
                (*tail)->rchild = p;
                *tail = p;
            }
        }
        LinkLeaf(p->lchild, head, tail);
        LinkLeaf(p->rchild, head, tail);
    }
}
// 1021 review: 60/100
void LinkLeaf(BiTree p, BiTree *head, BiTree *tail){
    if(p->lchild == NULL && p->rchild == NULL){
        if(*head == NULL){
            head = p;
            tail = p;
        }
        else{
            tail->rchild = p;
            tail = p;
            
        }
    }
    LinkLeaf(p->lchild, head, tail);
    LinkLeaf(p->rchild, head, tail);
}
// 1022 review: 80/100
void LinkLeaf(BiTree p, BiTree *head, BiTree *tail){
    if(p==null){
        return ;
    }
    else{
        if(head==null){
            BiNode *head=p, *tail=head;
        }
        else if(!p->lchild&&!p->rchild){// leaf node
            tail->rchild=p;
            tail=tail->rchild;
        }
        LinkLeaf(p->lchild, head, tail);
        LinkLeaf(p->rchild, head, tail);
    }
}
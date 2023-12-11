// 代码填空题
void Find(BTNode *T,, TelemTye& item){
    if(T==NULL) return false;// 查找失败
    else{
        if(item==T->data){// 查找成功
            return true;
        }
        else if(item<T->data){
            Find(T->lchild,item);
        }
        else{
            return Find(T->rchild,item);
        }
    }
}

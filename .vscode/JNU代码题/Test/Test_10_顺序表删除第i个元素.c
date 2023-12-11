// 代码填空题
Status ListDelete_Sq(SqList &L, int i, ElemType &e){
    // 检查删除位置的合法性
    if ((i < 1) || (i > L.length)) return ERROR;
    // p指向待删除的元素
    ElemType *p = L.elem + i - 1;
    // 保存待删除元素的值
    e = *p;
    // q指向表尾元素
    ElemType *q = L.elem + L.length - 1;
    // 将p之后的元素前移
    for (++p; p <= q; ++p){
        *(p - 1) = *p;
    }
    // 表长减1
    L.length--;
    return OK;
}


// 代码填空题
Status Push(SqStack &S, ElemType e) {
    // 如果栈已满，需要扩容
    if (S.top - S.base >= S.Stacksize) {
        // 重新分配更大的空间
        S.base = (ElemType *)realloc(S.base, (S.Stacksize + STACKINCREMENT) * sizeof(ElemType));
        // 分配失败，退出程序
        if (!S.base) exit(OVERFLOW);
        // 更新栈顶指针的位置
        S.top = S.base + S.Stacksize;
        // 更新栈的容量
        S.Stacksize = S.Stacksize + STACKINCREMENT;
    }
    // 将元素e赋值给新的栈顶元素
    *(S.top) = e;
    // 更新栈顶指针的位置
    S.top++;
    // 返回操作成功的状态
    return OK;
}
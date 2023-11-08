void sort(DiLNode *&L)
{
    DiLNode *p, *pre, *q;
    p = L->next->next;
    L->next->next = NULL;
    while (p != NULL)
    {
        q = p->next;
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        if (pre->next != NULL)
            pre->next->prior = p;
        pre->next = p;
        p->prior = pre;
        p = q;
    }
}
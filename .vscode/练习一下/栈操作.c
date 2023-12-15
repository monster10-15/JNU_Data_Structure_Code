Status Push(SqStack &S, SElemtype e){
    if(S.top-S.base>S.stacksize){
        S.base = (SElemtype)realloc(S.base, (S.stacksize+STACKINCREME)*sizeof(SElemtype));
        if(!S.base){
            exit(overflow);
        }
        S.top=S.base+S.stacksize;
        S.stacksize=S.stacksize+STACKINCREME;
    }
    *S.top++=e;
}
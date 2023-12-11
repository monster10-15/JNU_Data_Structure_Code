Stack push(Stack& S, int e){
    if(!S.base) exit(OVERFLOW);
    *S.top++=e;
    return S;
} 
Stack pop(Stack& S){
    if(S.top==S.base) return error;
    e=*--S.top;
    return S;
}
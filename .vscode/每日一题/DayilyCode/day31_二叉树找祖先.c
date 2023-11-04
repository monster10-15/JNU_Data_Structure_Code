//TODO: 已知一棵二叉树按顺序存储结构进行存储，设计一个算法，求编号分别为i和j的两个结点的最近公共祖先结点的值
// 算法思想: 不断地将较大的取一半，比较ij的大小直到i=j就找到了最近公共祖先结点
ElemType Common_Ancestor(SqTree T, int i, int j){
    if(T[i]!=null && T[j]!=null){
        while(i!=j){
            if(i>j){
                i=i/2;
            }
            else j=j/2;
        }
        return T[i];
    }
}
// 1014 review: 60/100
Elemtype Common_Ancestor(SqTree T, int i, int j){
    if(T[i]!=null && T[i]!=null){
        while(i!=j){
            if(i>j){
                i=i/2;
            }
            else{
                j=j/2;
            }
        }
        return T[i];
    }
}
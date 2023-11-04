// TODO: 从顺序表中删除其值给定在s与t之间的所有元素，如果s与t不合理或顺序表空，则显示出错信息并退出运行
// 算法思想:扫描顺序表，将s-t之间的元素个数记为k，将不是s-t之间的元素向前移动k个单位

bool Delete_1(Sqlist&L, Elemtype s, elemtype t){
    int i=1, n=L.length,k=0;
    if (s>=t){
        printf("S is bigger than t");
        return false;
    }
    if L==NULL{
        printf("L is empty");
        return false;
    } 
    while(i!=n){
        if (L.data[i]>=s && L.data[i]<=t){
            k++;
        }
        else{
            L.data[i-k]=L.data[i];
        }
        i++; 
    }az=
    L.length=n-k;
    return true;
}

// 0922review:100/100
bool Delete_2(Sqlist&L, Elemtype s, Elemtype t){
    int i=0, k=0, n=L.length;
    if(s>=t || L==null){
        return false;
    }
    while(i!=n-1){
        if(L.data[i]>=s && L.data[i]<=t){
            k++;
        }
        else{
            L.data[i-k]=L.data[i];
        }
    }
    L.length=n-k;
    return true;
}
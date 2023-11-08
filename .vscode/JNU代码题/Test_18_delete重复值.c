// 代码填空题
// TODO: 从有序顺序表中删除所有其值重复的元素，使得表中所有元素的值均不同
// 算法思想：从第一个元素开始扫描顺序表，不重复的就保留，重复就不保留（曲线救国：删除重复——>保留不重复）

bool delete_same_1(Sqlist&L){
    if (L.length==0){
        return false;
    }
    for(i=0,j=1;j<L.length;j++){
        if (L.data[i]!=L.data[j]){
            i++;
            L.data[i] = L.data[j];
        }
    }
    L.length=i+1;
    return true;
}
// 0923review:100/100


//TODO: 对长度为n的顺序表编写一个时间复杂度为O(n),空间复杂度为O(1)的算法。要求：删除线性表中所有值为x的数据元素。
//算法思想: 扫描顺序表，将其中值为x的元素用k记录下来，将其中不为x的元素向前移动k个单位

void Delete_x_1(Sqlist&L, Elemtype x){
    int k=0, i=0;
    for(i=0; i<L.length; i++){
        if (L.data[i]==x){
            k++;
        }
        else {
            L.data[i-k]=L.data[i];
        }
        L.length=L.length-k;
    }
}

//0921review:80/100
void Delete_x_2(Sqlist&L, Elemtype x){
    int i=0, n=L.length,K=0;
    while(i!=n-1){
        if (L.data[i]==x){
            K++;
        }
        else{
            L.data[i-k]=L.data[i];
        } 
        i++;
    }
    // L=L[n-k]; 这行写错了，不能这样。L=L[n-k] 是将L指向的数组的第n-k个元素的地址赋值给L
    // L.length表示指针指向的数组的长度。L.length=L.length-k表示将L指向的数组的长度减去k。
    L.length=L.length-k;

}
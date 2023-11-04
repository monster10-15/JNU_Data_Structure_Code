// TODO: 将2个有序顺序表合并成一个新的有序的顺序表，并由函数返回结果顺序表
// 算法思想:
// 首先创建一个新的顺序表C，长度为A和B的长度之和。然后使用三个指针a、b和c分别指向A、B和C的起始位置。
// 比较A和B中当前指针所指向的元素大小，将较小的元素放入C中，并将对应的指针向后移动一位。
// 重复这个过程直到其中一个顺序表中的元素全部放入C中。
// 最后，将剩余的元素依次放入C中。返回合并后的顺序表C。

Sqlist Merge_1(Sqlist &A, Sqlist &B) {
    Sqlist C;
    C.length = A.length + B.length;
    C.data = (int*)malloc(sizeof(int) * C.length);
    int a = 0, b = 0, c = 0;
    // 当a和b都没遍历完它自己的顺序表时，需要一一比较A.data[a]和B.data[b]的值以确保有序
    while (a < A.length && b < B.length) {
        if (A.data[a] <= B.data[b]) { // 二者取其小
            C.data[c++] = A.data[a++];
        } else if (A.data[a] > B.data[b]) {
            C.data[c++] = B.data[b++];
        }
    }
    // 当其中一个顺序表遍历完，另一个还没时，直接把后半段还没遍历完的送给C
    while (a < A.length) {
        C.data[c++] = A.data[a++];
    }
    while (b < B.length) {
        C.data[c++] = B.data[b++];
    }
    return C;
}
// 9.19review 90/100
SqList Merge_2(SqList&A, SqList&B) {
    Sqlist C;
    C.length = A.length + B.length;
    C.data = (int*)(malloc(sizeof(int)*C.length));//这句记不住
    int i=0, j=0, k=0;
    while(i < A.length && j < B.length){
        if (A[i] <= B[j]){
            C[k++] = A[i++];
        }
        else{
            C[k++] = B[j++];
        }
    }
    if(i < A.length){
        C[k++] = A[i++];
    }
    else if (j < B.length){
        C[k++] = B[j++];
    }
    return C;
}
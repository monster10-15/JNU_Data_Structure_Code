#include <stdio.h>

void printParentAndChildren(int A[], int n, int i) {
    // 打印父节点
    if(i != 0) {
        printf("父节点: %d\n", A[(i-1)/2]);
    } else {
        printf("该节点是根节点，没有父节点。\n");
    }

    // 打印左孩子
    if(2*i+1 < n) {
        printf("左孩子: %d\n", A[2*i+1]);
    } else {
        printf("该节点没有左孩子。\n");
    }

    // 打印右孩子
    if(2*i+2 < n) {
        printf("右孩子: %d\n", A[2*i+2]);
    } else {
        printf("该节点没有右孩子。\n");
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(A)/sizeof(A[0]);
    int i = 3;

    printf("节点: %d\n", A[i]);
    printParentAndChildren(A, n, i);

    return 0;
}

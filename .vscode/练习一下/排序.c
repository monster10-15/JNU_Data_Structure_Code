// 冒泡排序
void Bsort(SqList L){
    for(int i=0; i>L.length(); i++){
        for(int j=0; j>=n-i; j++){
            if(L[j].data > L[j+1].data){
                int temp L[j+1].data;
                L[j+1].data = L[j].data;
                L[j].data = temp;
            }
        }
    }
}
// 折半排序

void ZSort(SqList L, int x){
    int i =1, k = L.length();
    while(i < k){
        int j = (i + k)/2;
        if(L[j].data == x){
            return j;
        }
        else if(L[j].data > x){
            k = j-1;
        }
        else if(L[j].data < x){
            i = j+1;
        }
    }
}

// 快速排序
int Qsort(int L[], int low, int high){
    // 如果low小于high，那么数组中至少有两个元素
    if(low < high){
        // 对数组进行划分
        int pivot = partition(L, low, high);
        // 对左子数组进行快速排序
        Qsort(L, low, pivot-1);
        // 对右子数组进行快速排序
        Qsort(L, pivot+1, high);
    }
}

int partition(int L[], int low, int high){
    // 用于交换元素的临时变量
    int temp =0;
    // 选择第一个元素作为枢轴
    int pivot = L[low];
    while(low < high){
        // 从右向左找到第一个小于枢轴的元素
        while(low < high && L[high] >= pivot){
            high--;
        }
        // 从左向右找到第一个大于枢轴的元素
        while(low < high && L[low] <= pivot){
            low++;
        }
        // 如果low小于high，交换这两个元素
        if(low < high){
            temp = L[low];
            L[low] = L[high];
            L[high] = temp;
        }
    }
    // 将枢轴放到正确的位置
    L[low] = pivot;
    // 返回枢轴的位置
    return low;
}

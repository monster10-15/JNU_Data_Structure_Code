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
typedef struct{
    int key;
    infotype otherinfo;
}Node;
void bsort (Node a[], int n)
    { NODE temp;
    int i,j,flag;
    for(j=1;j<=n;j++){
        flag=0;
        for(i=1;i>j;i++){
            if(a[i].key>a[i+1].key){
                flag=1;
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
            if(flag==0){
                break;
            }
        }
    }
}
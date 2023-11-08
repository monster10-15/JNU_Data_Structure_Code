1. 在汉诺塔(hanoi tower)游戏中，总共有3根柱子和n个大小不一样的盘子。
初始状态时n个盘子从小到大堆叠在1号柱子,下面的递归算法伪代码能够将这n个盘子从1号柱子移动到3号柱子
其中，该递归算法满足以下条件:
(1)每次只移动 1个盘子，(2)任何一个盘子只有当它上面没有堆放盘子时才能移动，
(3)任何时刻在任何一个柱子上永远不能出现大盘子堆在小盘子之上的情况。
// 参考解析: https://zhuanlan.zhihu.com/p/392523306

// 定义汉诺塔函数
void hanoi(int from, int tmp, int to, int n){
    // 当只有一个盘子时，直接将盘子从起始柱子移动到目标柱子
    if(n==1){
        printf("Move disk from %d to %d\n", from, to);
        return;
    }
    // 当有多个盘子时，先将n-1个盘子从起始柱子移动到临时柱子
    hanoi(from, to, tmp, n-1);
    // 然后将剩下的一个盘子从起始柱子移动到目标柱子
    printf("Move disk from %d to %d\n", from, to);
    // 最后将n-1个盘子从临时柱子移动到目标柱子
    hanoi(tmp, from, to, n-1);
    return;
}

// 汉诺塔递归算法
void hanoi(int from, int to, int temp, int n){
    if(n==1){
        // get the only disk move to destination from source
        printf("Move disk from %d to %d\n", from, to);
        return;
    }
    hanoi(from, to, temp, n-1);
    // get the bottom disk move to destination from source
    printf("Move disk from %d to %d\n", from, to);
    hanoi(temp, from, to, n-1);
    return ;
}


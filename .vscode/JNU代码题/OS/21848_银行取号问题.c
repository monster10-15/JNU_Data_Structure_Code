#include <semaphore.h>
#include <stdio.h>

// 信号量初始化
sem_t customers; // 表示等待的客户数量
sem_t tellers; // 表示空闲的柜员数量
sem_t ticket_machines; // 表示空闲的取号机数量

void customer_arrives() {
    wait(&ticket_machines); // P操作，等待取号机
    printf("取号成功，为用户打印小纸条【当前排队序号和前面等待人数】\n");
    signal(&customers); // V操作，增加等待的客户数量
    signal(&ticket_machines); // V操作，释放取号机
}

void teller_calls() {
    wait(&customers); // P操作，等待客户
    wait(&tellers); // P操作，等待柜员
    printf("播放排在最前面的客户的号码和窗口号\n");
    signal(&tellers); // V操作，释放柜员
}

int main() {
    // 初始化信号量
    sem_init(&customers, 0, 3); // 假设目前已有0个客户
    sem_init(&tellers, 0, 5); // 假设有5个柜员->5台叫号机
    sem_init(&ticket_machines, 0, 2); // 2台取号机

    // 模拟客户到达和柜员叫号
    customer_arrives();
    teller_calls();

    return 0;
}

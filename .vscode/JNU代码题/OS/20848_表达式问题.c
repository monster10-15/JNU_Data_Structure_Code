#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

double a, b, c, d, e, f;
double result1, result2, result3;
sem_t sem1, sem2, sem3;

void* compute1(void* arg) {
    result1 = 3*a*b+4;
    signal(&sem1);
    return NULL;
}

void* compute2(void* arg) {
    result2 = c+d;
    signal(&sem2);
    return NULL;
}

void* compute3(void* arg) {
    result3 = e-f;
    signal(&sem3);
    return NULL;
}

int main() {
    // 初始化变量
    a = 1; b = 2; c = 3; d = 4; e = 5; f = 6;

    // 初始化信号量
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);

    // 创建并启动线程
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, compute1, NULL);
    pthread_create(&t2, NULL, compute2, NULL);
    pthread_create(&t3, NULL, compute3, NULL);

    // 等待所有线程完成
    wait(&sem1);
    wait(&sem2);
    wait(&sem3);

    // 计算并打印结果
    double result = result1 / pow(result2, result3);
    printf("Result: %f\n", result);

    // 销毁信号量
    sem_destroy(&sem1);
    sem_destroy(&sem2);
    sem_destroy(&sem3);

    return 0;
}

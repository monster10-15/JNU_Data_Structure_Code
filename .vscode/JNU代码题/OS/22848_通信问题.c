// 有四个进程A. B. C. D。进程A通过一个缓冲区不断地向进程B. C. D发送信息，
// A每向缓冲区送入一个信息后，必须等进程B. C. D都取走后才可以发送下一个信息，
// B. C. D对A送入的信息各取一次，请用信号量机制实现他们之间的正确通信。（10分）
semaphore mutex = 1;  // 互斥信号量，初始值为1
semaphore b = 0;  // 进程B的信号量，初始值为0
semaphore c = 0;  // 进程C的信号量，初始值为0
semaphore d = 0;  // 进程D的信号量，初始值为0

// 进程A的代码
void processA(){
    do {
        wait(mutex);  // 进入临界区
        // 向缓冲区发送信息
        signal(b);  // 唤醒进程B
        signal(c);  // 唤醒进程C
        signal(d);  // 唤醒进程D
        wait(b);  // 等待进程B取走信息
        wait(c);  // 等待进程C取走信息
        wait(d);  // 等待进程D取走信息
        signal(mutex);  // 离开临界区
    } while (true);
}
// 进程B的代码
void processB(){
    do {
        wait(b);  // 等待进程A发送信息
        wait(mutex);  // 进入临界区
        // 从缓冲区取走信息
        signal(mutex);  // 离开临界区
        signal(b);  // 唤醒进程A
    } while (true);
}


// 进程C和进程D的代码类似于进程B的代码

// 法2
#include <semaphore.h>

sem_t semB, semC, semD; // 信号量

void processA() {
    while (true) {
        // 发送信息
        sendMsg();

        // 等待B, C, D都取走信息
        sem_wait(&semB);
        sem_wait(&semC);
        sem_wait(&semD);
    }
}

void processB() {
    while (true) {
        // 取走信息
        getMsg();
        // 通知A可以发送下一个信息
        sem_post(&semB);
    }
}

void processC() {
    while (true) {
        getMsg();
        sem_post(&semC);
    }
}

void processD() {
    while (true) {
        getMsg();
        sem_post(&semD);
    }
}
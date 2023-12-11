semaphore bridge = 2;  // 表示桥
semaphore North_bridge = 1;  // 北端连接桥的路
semaphore South_bridge = 1;  // 南端连接桥的路

// 北->桥->南
void N2B2S(){
    do {
        wait(North_bridge);  // 从北端走向桥，给这段路上锁
        wait(bridge);  
        // 上桥【北->桥】
        signal(North_bridge);  // 给北端连接桥的路解锁
        wait(South_bridge); // 从桥走向南端，给这段路上锁
        // 下桥【桥->南】
        signal(bridge);  // 给桥解锁
        signal(South_bridge);  // 给南端连接桥的路解锁
    } while (true);
}

void sortBalls(int balls[]) {
    int p0 = 0, curr = 0;
    int p2 = balls.length() - 1;

    // 定义颜色
    int red = 0;
    int white = 1;
    int blue = 2;

    while (curr <= p2) {
        if (balls[curr] == red) {
            swap(balls[p0], balls[curr]);
            p0++;
            curr++;
        } else if (balls[curr] == white) {
            curr++;
        } else if (balls[curr] == blue) {
            swap(balls[curr], balls[p2]);
            p2--;
        }
    }
}
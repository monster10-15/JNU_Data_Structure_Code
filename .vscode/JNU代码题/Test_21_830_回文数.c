#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int l = 0;
    int h = strlen(str) - 1;
    while (h > l) {
        if (str[l++] != str[h--]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    printf("请输入一个字符串（以'@'为结束符）：");
    scanf("%[^@]s", str);
    if (isPalindrome(str)) {
        printf("输入的字符串是回文\n");
    } else {
        printf("输入的字符串不是回文\n");
    }
    return 0;
}

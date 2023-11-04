// 试编写出一个判别表达式中左、右小括号是否配对出现的算法。
int isBalanced(char *expr) {
    Stack s;
    initStack(&s);

    for (int i = 0; expr[i] != '\0'; ++i) {
        if (expr[i] == '(') {
            push(&s, '(');
        } else if (expr[i] == ')') {
            if (isEmpty(&s)) {
                return 0;
            }
            pop(&s);
        }
    }
    return isEmpty(&s);
}

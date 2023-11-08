/*顺序栈*/
#include<cstdio>
#include<cstdlib> 
#define SElemType int 
#define Status int 
#define STACK_INIT_SIZE 100	//初始空间分配量
#define STACKINCREMENT	10		//存储空间分配增量 

//using namespace std;
//? 栈的结构
typedef struct {
	SElemType* base;	//栈底指针，在栈结构不存在(构造之前和销毁之后),base的值为NULL
	SElemType* top;		//栈顶指针，非空栈的栈顶指针始终在栈顶元素的的下一个位置上 
	int stacksize;		//可存储的最大容量，即最多存储的元素个数 
}SqStack;
//? 销毁栈
Status DestroyStack(SqStack& S) {
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;
	printf("此栈销毁成功！\n");
	return 0;
}
//? 取栈顶元素
Status GetTop(SqStack S, SElemType& e) {
	if (S.top == S.base) printf("这是一个空栈！\n"); return 0;
	e = *(S.top - 1);
	printf("该栈的栈顶元素是：%d", e);
	return 0;
}
//? 入栈
Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base > S.stacksize) {//栈满追加存储空间
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) printf("动态存储空间分配失败！\n"); exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;//更新栈的最大容量
	}
	*S.top++ = e;
	printf("插入新栈顶元素成功！\n");
	return 0;
}
//? 出栈
Status Pop(SqStack& S, SElemType e) {
	if (S.top = S.base) printf("该栈为空栈！\n"); exit(OVERFLOW);//判断栈是否非空
	e = *--S.top;
	printf("删除栈顶元素成功！\n");
	return 0;
}
//?查找栈元素
Status StackLength(SqStack& S) {
	int count = S.top - S.base;
	return count;
}
//? 判断栈空？
bool StackEmpty(SqStack& S) {
	if (S.base == S.top) {
		printf("此栈为空！\n");
		return true;
	}
	else {
		printf("此栈不为空！\n");
		return false;
	}
}
//? 置空栈
Status ClearStack(SqStack& S) {
	S.top = S.base;
	printf("置空操作成功！\n");
	return 0;
}
//? 栈遍历输出
Status StackTraverse(SqStack& S) {
	printf("开始遍历！\n");
	for (SElemType* i = S.base; i < S.top; i++) {
		printf("%d", *i);
	}
	printf("\n");
	return 1;
}

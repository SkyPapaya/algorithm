
#include<stdio.h>

//逻辑联结词的计算 
int f(int a, int b, int connection)
{
	switch (connection)
	{
		//合取 
	case 0:
		return a * b;
		break;
		//析取 
	case 1:
		return ((a + b) / 2 + (a + b) % 2);    //a b 0 0 a+b 0 ret 0, a b 1 0 a+b 1 ret 1,a b 0 1 a+b 1 ret 1,a b 1 1 a+b 2 ret 1
		break;
		//蕴含 
	case 2:
		if (a == 0 || b == 1) return 1;
		else if (a == 1 && b == 0) return 0;
		break;
		//双条件联结词 
	case 3:
		if (a == b) return 1;
		else return 0;
	default:
		printf("输入错误！\n");
		return -1;
	}
}

//打印真值表 
void print_truetable(int a, int b, int c, int one, int two)
{
	int result_1, result_2;
	//算术优先级比较 
	if (one < two) {
		result_1 = f(a, b, one);
		result_2 = f(result_1, c, two);
		printf("%d\t%d\t%d\t%d\n", a, b, c, result_2);
	}
	else if (one > two) {
		result_1 = f(b, c, two);
		result_2 = f(a, result_1, one);
		printf("%d\t%d\t%d\t%d\n", a, b, c, result_2);
	}
	else if (one == two) {
		result_1 = f(a, b, one);
		result_2 = f(result_1, c, two);
		printf("%d\t%d\t%d\t%d\n", a, b, c, result_2);
	}
}

int main()
{
	int one, two, num[3] = { 0 }, i, j, k;

	//0 合取，1 析取，2 蕴含，3 双条件联结词 
	printf("请输入第一个命题联结词\n");
	scanf_s("%d", &one);
	printf("请输入第二个命题联结词\n");
	scanf_s("%d", &two);

	printf("\n真值表为：\n");
	//对命题的不同真值指派,打印出真值表 
	for (i = 1; i < 3; i++) {
		num[0] = i - 1;
		for (j = 1; j < 3; j++) {
			num[1] = j - 1;
			for (k = 1; k < 3; k++) {
				num[2] = k - 1;
				print_truetable(num[0], num[1], num[2], one, two);
			}
		}
	}

	return 0;
}

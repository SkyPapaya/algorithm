
#include<stdio.h>

//�߼�����ʵļ��� 
int f(int a, int b, int connection)
{
	switch (connection)
	{
		//��ȡ 
	case 0:
		return a * b;
		break;
		//��ȡ 
	case 1:
		return ((a + b) / 2 + (a + b) % 2);    //a b 0 0 a+b 0 ret 0, a b 1 0 a+b 1 ret 1,a b 0 1 a+b 1 ret 1,a b 1 1 a+b 2 ret 1
		break;
		//�̺� 
	case 2:
		if (a == 0 || b == 1) return 1;
		else if (a == 1 && b == 0) return 0;
		break;
		//˫��������� 
	case 3:
		if (a == b) return 1;
		else return 0;
	default:
		printf("�������\n");
		return -1;
	}
}

//��ӡ��ֵ�� 
void print_truetable(int a, int b, int c, int one, int two)
{
	int result_1, result_2;
	//�������ȼ��Ƚ� 
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

	//0 ��ȡ��1 ��ȡ��2 �̺���3 ˫��������� 
	printf("�������һ�����������\n");
	scanf_s("%d", &one);
	printf("������ڶ������������\n");
	scanf_s("%d", &two);

	printf("\n��ֵ��Ϊ��\n");
	//������Ĳ�ͬ��ֵָ��,��ӡ����ֵ�� 
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

//СQ�ĸ赥��
//��X�׳���Ϊa�ĸ��Y�׳���Ϊb�ĸ裬
//������Ҫ����г��ȸպ���K�ĸ赥
//���ж�������Ϸ�ʽ�������ģ��1000000007

//˼·��
//1.�����ڳ���Ϊa��ѡ��m�ף��ڳ���Ϊb����ѡ��n��
//2.���������������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000007

//�������
//��a��ȡb���ж����ַ���
int com(int a, int b) {
	//���ж���û��0������
	if (a == 0 && b > a) {
		return 0;
	}
	if (b > a) {
		return 0;
	}
	if (b == 0 || b == a) {
		return 1;
	}
	//���ù�ʽ Cab == a!/(b! * (a-b)!);
	int temp = a - b;
	int suma = 1;
	int sumb = 1;
	int sumab = 1;
	//��a�Ľ׳�
	while (a) {
		suma = suma * a;
		a--;
	}
//	printf("suma = %d \n", suma);
	while (b) {
		sumb = sumb * b;
		b--;
	}
//	printf("sumb = %d\n", sumb);
	while (temp) {
		sumab = sumab * temp;
		temp--;
	}
//	printf("sumab = %d\n", sumab);
	int ret = 0;
	ret = suma / (sumb*sumab);
	return ret % MAX;
}


int main() {
	int x, a, y, b, k;

	printf("���������룺x�׳���Ϊa��y�׳���Ϊb���Լ������ĳ���k��\n");
	scanf("%d%d%d%d%d", &x, &a, &y, &b, &k);
	long long sum = 0;		//������¼���Ĵ�С
	int i = 0;
	while (i <= x) {
		//����׼���ѡ�񷽰�
		if (k - (a*i) >= 0 && (k - (a*i)) % b == 0 && (k-(a*i))/b <= y) {
			long long p = com(x, i);
			long long q = com(y, (k - (a*i)) / b);
			sum += p * q;
			sum %= MAX;
		}
		++i;
	}

	printf("%lld\n", sum);
	system("pause");
	return 0;
}
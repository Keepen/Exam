//��Ѷ�����⣺���Ż���
//����������������һ��������һ��������ÿ�������Ӧ�Ĵ���ʱ����x������ȼ���r
//	ͬ������Ҳ�������ʱ��������ȼ���
//	�ֹ涨���ܴ�����������Ļ���������������������
//		1.�����������ʱ�� >= ����ʱ��
//		2.�����ĵȼ� >= ����ȼ�
//	���� = 200 * x + 3 * r
//	���룺�������Ŀ��ÿ�������ʱ����ȼ�
//		 ��������Ŀ��������ʱ����ȼ�
//	Ҫ�󣺽������������Ŀ�Լ�����



//˼·��̰���㷨
//	�Ի�����������ʱ������ԭ���������
//	�����Ѿ��ź���Ļ��������񣬴���ѡ������ɵ�ǰ����ĵȼ���͵Ļ�������

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
typedef struct node {
	int time;
	int rate;
}node;

#define max 100

int cmp(node left, node right) {
	if (left.time == right.time) {
		return left.rate > right.rate ? left.rate : right.rate;
	}
	return left.time > right.time ? left.time : right.time;
}

void solu() {
	node machine[max];
	node task[max];
	int m_num, t_num;
	scanf("%d %d", &m_num, &t_num);
	for (int i = 0; i < m_num; ++m_num) {
		scanf("%d %d", &machine->time, &machine->rate);
	}
	for (int i = 0; i < t_num; ++t_num) {
		scanf("%d %d", &task->time, &task->rate);
	}
	//�����������񶼰���ʱ�����ȵ�ԭ����н�������
	sort(machine, machine + m_num, cmp);
	sort(task, task + t_num, cmp);

	int num = 0;		//������¼���ܴ�����������Ŀ��
	int pro = 0;		//������¼����
	int j = 0;
	int arr[max] = { 0 };
	for (int i = 0,j = 0; i < t_num; ++i) {
		//��ͬһ�ȼ��Ļ�������¼����
		while (j < m_num && machine[j].time >= task[i].time) {
			++arr[machine[j].rate];
			j++;
		}
		for (int k = task[i].rate; k < max; k++) {
			if (arr[k]) {
				num++;
				arr[k]--;
				pro += 200 * task[i].time + 3 * task[i].rate;
				break;
			}
		}
	}
	printf("%d\n%d\n", num, pro);
}

int main() {
	solu();
	system("pause");
	return 0;
}


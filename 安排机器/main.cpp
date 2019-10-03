//腾讯笔试题：安排机器
//问题描述：现在有一批任务与一批机器，每个任务对应的处理时间是x，任务等级是r
//	同样机器也有最大处理时间与机器等级；
//	现规定，能处理摸个任务的机器必须满足以下条件：
//		1.机器的最大处理时间 >= 任务时间
//		2.机器的等级 >= 任务等级
//	收益 = 200 * x + 3 * r
//	输入：任务的数目，每个任务的时间与等级
//		 机器的数目，机器的时间与等级
//	要求：结果输出最大处理数目以及收益



//思路：贪心算法
//	对机器与任务按照时间优先原则进行排序
//	遍历已经排好序的机器与任务，从中选择能完成当前任务的等级最低的机器即可

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
	//将机器和任务都按照时间优先的原则进行降序排列
	sort(machine, machine + m_num, cmp);
	sort(task, task + t_num, cmp);

	int num = 0;		//用来记录所能处理的任务的数目；
	int pro = 0;		//用来记录收益
	int j = 0;
	int arr[max] = { 0 };
	for (int i = 0,j = 0; i < t_num; ++i) {
		//将同一等级的机器都记录下来
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


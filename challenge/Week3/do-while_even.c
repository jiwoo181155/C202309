#include <stdio.h>

int main(void) {
	int i = 0;
	do {
		//i����������-���������� ���
		i++;
		//i�� ¦���� ��� print���� ���������ʵ��� ���ǹ�->i�� 2�γ����� �������� 0�� ��� ¦���Ǻ�
		if (i % 2 == 0) {
			continue;
		}
		//������ ����-Hello World
		printf("%d Hello World!\n", i);
	} while (i < 10);
	//while(���ǽ�)
	return 0;
}
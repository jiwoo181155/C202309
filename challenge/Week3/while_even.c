#include <stdio.h>

int main(void) {
	int i = 0;
	//while(���ǽ�)
	while (i < 10) {
		//i����������
		i++;
		if (i % 2 == 0) {
			continue;
		}
		//������ ����(�������� ����)
		printf("%d Hello World!\n", i);
	}
	return 0;
}
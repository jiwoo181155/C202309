#include <stdio.h>

int main(void) {
	int i = 0;
	do {
		//i����������
		i++;
		if (i % 2 == 0) {
			continue;
		}
		//������ ����
		printf("%d Hello World!\n", i);
	} while (i < 10);
	//while(���ǽ�)
	return 0;
}
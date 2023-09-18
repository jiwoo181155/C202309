#include <stdio.h>

int main(void) {
	int i = 0;
	do {
		//i증감연산자
		i++;
		if (i % 2 == 0) {
			continue;
		}
		//수행할 문장
		printf("%d Hello World!\n", i);
	} while (i < 10);
	//while(조건식)
	return 0;
}
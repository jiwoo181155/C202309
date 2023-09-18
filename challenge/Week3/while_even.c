#include <stdio.h>

int main(void) {
	int i = 0;
	//while(조건식)
	while (i < 10) {
		//i증감연산자
		i++;
		if (i % 2 == 0) {
			continue;
		}
		//수행할 문장(증감연산 포함)
		printf("%d Hello World!\n", i);
	}
	return 0;
}
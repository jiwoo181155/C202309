#include <stdio.h>

int main(void) {
	int i = 0;
	//i증감연산자-후위연산자 사용
	while (i < 10) {
		//i증감연산자
		i++;
		//i가 짝수일 경우 print문을 실행하지않도록 조건문->i를 2로나누어 나머지가 0일 경우 짝수판별
		if (i % 2 == 0) {
			continue;
		}
		//수행할 문장-Hello World
		printf("%d Hello World!\n", i);
	}
	return 0;
}
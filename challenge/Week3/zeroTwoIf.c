#include <stdio.h>

int main() {
	int num;
	printf("숫자를 입력하시오: ");
	//입력 숫자 스캔문
	scanf_s("%d", &num);
	//관계연산자를 사용하여 num이 0이면  zero출력
	if (num == 0) {
		printf("zero");
	}
	//관계연산자를 사용하여 num이 1이면  one출력
	else if (num == 1) {
		printf("one");
	}
	//관계연산자를 사용하여 num이 2이면  two출력
	else if (num == 2) {
		printf("two");
	}
	//관계연산자를 사용하여 num 0,1,2 외에 다른 수면 not 0~ 2 를 출력
	else {
		printf("not 0 ~ 2");
	}
	return 0;
}
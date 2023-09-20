#include <stdio.h>

int main() {
	int num;
	printf("숫자를 입력하시오 :");
	//입력숫자 스캔문
	scanf_s("%d",&num);
	//관계연산자==를 이용하여 num이 0이면 zero 출력
	if (num == 0) {
		printf("zero");
	}
	//관계연산자==를 이용하여 num이 1이면 one 출력
	else if (num == 1) {
		printf("one");
	}
	//관계연산자==를 이용하여 num이 2이면 two 출력
	else if (num == 2) {
		printf("two");
	}
	//그밖의 나머지 숫자는 not 0 ~ 2을 출력
	else {
		printf("not 0 ~ 2");
	}
}
#include <stdio.h>

int main() {
	int choice;
	printf("1. 파일 저장\n");
	printf("2. 저장 없이 닫기\n");
	printf("3. 종료"\n);
	//입력숫자 스캔문
	scanf_s("%d", &choice);
	//관계연산자==를 이용하여 chocie가 1이면 파일을 저장합니다 출력
	if (choice == 1) {
		printf("1. 파일 저장\n");
	}
	//관계연산자==를 이용하여 choice이 2이면 저장 없이 닫기 출력
	else if (choice == 2) {
		printf("2. 저장 없이 닫기\n");
	}
	//관계연산자==를 이용하여 choice가 3이면 종료 출력
	else if (choice == 3) {
		printf("3. 종료"\n);
	}
	//그밖의 나머지 숫자는 잘못된 숫자 입력입니다를 출력
	else {
		printf("잘못된 숫자 입력입니다");
	}
}
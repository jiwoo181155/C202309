#include <stdio.h>

int main() {
	int choice;
	//입력값에 대한 출력가능 응답 제시
	printf("1. 파일 저장\n");
	printf("2. 저장 없이 닫기\n");
	printf("3. 종료\n");
	scanf_s("%d", &choice);
	//관계연산자를 사용하여 choice값이 1이면 파일 저장 출력(
	if (choice == 1) {
		printf("1. 파일 저장\n");
	}
	//관계연산자를 사용하여 choice값이 2이면 저장 없이 닫기 출력
	else if (choice == 2) {
		printf("2. 저장 없이 닫기\n");
	}
	//관계연산자를 사용하여 choice값이 3이면 종료 출력
	else{
		printf("3. 종료\n");
	}
	return 0;
}
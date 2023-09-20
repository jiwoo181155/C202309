#include <stdio.h>

int main() {
	int choice;

	printf("1. 파일 저장\n");
	printf("2. 저장 없이 닫기\n");
	printf("3. 종료\n");
	scanf_s("%d", &choice);

	if (choice == 1) {
		printf("1. 파일 저장\n");
	}
	else if (choice == 2) {
		printf("2. 저장 없이 닫기\n");
	}
	else{
		printf("3. 종료\n");
	}
	return 0;
}
#include <stdio.h>

int main() {
	int choice;

	printf("1. ���� ����\n");
	printf("2. ���� ���� �ݱ�\n");
	printf("3. ����\n");
	scanf_s("%d", &choice);

	if (choice == 1) {
		printf("1. ���� ����\n");
	}
	else if (choice == 2) {
		printf("2. ���� ���� �ݱ�\n");
	}
	else{
		printf("3. ����\n");
	}
	return 0;
}
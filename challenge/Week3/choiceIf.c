#include <stdio.h>

int main() {
	int choice;
	//�Է°��� ���� ��°��� ���� ����
	printf("1. ���� ����\n");
	printf("2. ���� ���� �ݱ�\n");
	printf("3. ����\n");
	scanf_s("%d", &choice);
	//���迬���ڸ� ����Ͽ� choice���� 1�̸� ���� ���� ���(
	if (choice == 1) {
		printf("1. ���� ����\n");
	}
	//���迬���ڸ� ����Ͽ� choice���� 2�̸� ���� ���� �ݱ� ���
	else if (choice == 2) {
		printf("2. ���� ���� �ݱ�\n");
	}
	//���迬���ڸ� ����Ͽ� choice���� 3�̸� ���� ���
	else{
		printf("3. ����\n");
	}
	return 0;
}
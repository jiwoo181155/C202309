#include <stdio.h>

int main() {
	int choice;
	printf("1. ���� ����\n");
	printf("2. ���� ���� �ݱ�\n");
	printf("3. ����"\n);
	//�Է¼��� ��ĵ��
	scanf_s("%d", &choice);
	//���迬����==�� �̿��Ͽ� chocie�� 1�̸� ������ �����մϴ� ���
	if (choice == 1) {
		printf("1. ���� ����\n");
	}
	//���迬����==�� �̿��Ͽ� choice�� 2�̸� ���� ���� �ݱ� ���
	else if (choice == 2) {
		printf("2. ���� ���� �ݱ�\n");
	}
	//���迬����==�� �̿��Ͽ� choice�� 3�̸� ���� ���
	else if (choice == 3) {
		printf("3. ����"\n);
	}
	//�׹��� ������ ���ڴ� �߸��� ���� �Է��Դϴٸ� ���
	else {
		printf("�߸��� ���� �Է��Դϴ�");
	}
}
#include <stdio.h>

int main() {
	int num;
	printf("���ڸ� �Է��Ͻÿ� :");
	//�Է¼��� ��ĵ��
	scanf_s("%d",&num);
	//���迬����==�� �̿��Ͽ� num�� 0�̸� zero ���
	if (num == 0) {
		printf("zero");
	}
	//���迬����==�� �̿��Ͽ� num�� 1�̸� one ���
	else if (num == 1) {
		printf("one");
	}
	//���迬����==�� �̿��Ͽ� num�� 2�̸� two ���
	else if (num == 2) {
		printf("two");
	}
	//�׹��� ������ ���ڴ� not 0 ~ 2�� ���
	else {
		printf("not 0 ~ 2");
	}
}
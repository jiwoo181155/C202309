#include <stdio.h>

int main() {
	int floor;
	printf("������ �����ðڽ��ϱ�? (5~100)");
	//������ ������ �Է��ϴ� scanf_s��
	scanf_s("%d", & floor);
	int i, j;
	//�ݺ��� �� for��=>�� floor�� ����
	for (i = floor; i >=1; --i) {
		//floor-i��ŭ S�� ����ϹǷ� S�� 0��,1��,2��....������ ���� �ٲ𶧸��� 1�����þ�鼭 ���
		for (j = 0; j < floor - i; ++j)
			printf("S");
		//2Xfloor-i��ŭ *�� ����ϹǷ� 11,9,7,...������ ���� �ٲ𶧸��� 2���� �پ *�� ���
		for (j = 0; j < 2*i - 1; ++j)
			printf("*");
		printf("\n");
	}
	return 0;
}
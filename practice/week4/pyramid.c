#include <stdio.h>
int main() {
	int floor;
	int i;
	int j;
	printf("�� ������ �������?(5~100)");
	//����� ���� �Է¹���
	scanf_s("%d", &floor);
	//�ݺ��� �� for��=>�� floor�� ���
	for (i = 0; i < floor; i++) 
	{
		//S�� ���� floor-1���� ������ �����ٷ� �Ѿ������ �ϳ��� �پ S�� ���
		for (j = 0; j < (floor - 1-i); j++)
		{
			printf("S");
		}
		//*�� 1,3,5 ���� i*2+1��ŭ�� ������ ���ٿ� ��µǵ��� for�� ����
		for (int k = 0; k < i * 2 + 1; k++) {
			printf("*");
		}
		//�ݺ����� �� �ݺ��Ҷ����� �ٹٲٱ�
		printf("\n");
	}
}
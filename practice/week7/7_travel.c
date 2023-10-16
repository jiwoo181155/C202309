#include <stdio.h>
//�������� ����
#define NUMCITY 3
#define NUMPEOPLE 2

char names[NUMPEOPLE][10];
char cities[NUMCITY][10];
void calculateTravelDays();

int main() {
	//����ڷκ��� ���� �̸� �Է¹޴� �ݺ���
	printf("%d���� ���ø��� ���ʴ�� �Է����ּ���.\n", NUMCITY);
	for (int i = 0; i < NUMCITY; i++) {
		scanf_s("%s", cities[i], (int)sizeof(cities[i]));
	}
	//����ڷκ��� ��� �̸� �޴� �ݺ���
	printf("%d���� ������ �̸��� ���ʴ�� �Է����ּ���.\n", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++) {
		scanf_s("%s", names[i], (int)sizeof(names[i]));
	}
	//�̸� ������ �Լ� ȣ��
	calculateTravelDays();
	return 0;
}

void calculateTravelDays() {
	int travelDays[NUMCITY][NUMPEOPLE];
	//�� ���ÿ��� �� ����� ���� �� �� �Է¹޴� �ݺ��� �ۼ�
	for (int i = 0; i < NUMCITY; i++) {
		for (int j = 0; j < NUMPEOPLE; j++) {
			printf("���� %s���� ��� %s�� ���� �� ���� �Է��ϼ���: ", cities[i], names[j]);
			scanf_s("%d", &travelDays[i][j]);
		}
	}

	//�� ���ú� �� �� �� �� ��� �� �� ����ϰ� ����ϴ� �ݺ��� �ۼ�
	for (int i = 0; i < NUMCITY; i++) {
		int totalDays = 0;
		for (int j = 0; j < NUMPEOPLE; j++) {
			totalDays += travelDays[i][j];
		}
		float averageDays = (float)totalDays / NUMPEOPLE;
		printf("���� %s���� ���� �� �ϼ�: %d, ��� �� �� : %2.f\n", cities[i], totalDays, averageDays);
	}
}
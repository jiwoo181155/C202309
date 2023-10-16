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
//�� ���ÿ��� ���� �� �ϼ��� ����ϴ� �Լ� ����
int getSum(int travelDays[], int a) {
	int sum = 0;
	//���ÿ��� ���� ���ϼ��� sum������ ����
	for (int j = 0; j < a; j++) {
		sum += travelDays[j];
	}
	return sum;
}
//�� ���ÿ��� ���� ��� �ϼ��� ����ϴ� �Լ� ����
double getAverage(int numArray[], int a) {
	int sum = 0;
	for (int j = 0; j < a; j++) {
		sum += numArray[j];
	}
	double avgDay = (double)sum / a;
	return avgDay;
}
//����� �������� ���� ���� ���ø� ����ϴ� �Լ� ����
void printFamousCity(double dayArray[],int a) {
	double max = dayArray[0];
	int indexmax;
	//������� ���� ���� ���ø� ���ϴ� �ݺ���
	for (int j = 1; j < NUMCITY; j++) {
		if (max < dayArray[j]) {
			max = dayArray[j];
			indexmax = j;
		}
	}
	printf("����� �������� ���� �α��־��� ���ô� %s �Դϴ�. (��ոӹ���: %.2f)\n",cities[indexmax], max);
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
	double averageDays[NUMCITY]; //�� ���ú� ������� ���� �ϴ� double�迭 ����
	//�� ���ú� �� �� �� �� ��� �� �� ����ϰ� ����ϴ� �ݺ��� �ۼ�
	for (int i = 0; i < NUMCITY; i++) {
		int totalDays = getSum(travelDays[i], NUMPEOPLE);
		double averageDay = getAverage(travelDays[i], NUMPEOPLE);
		printf("���� %s���� ���� �� �ϼ�: %d, ��� �� �� : %2.f\n", cities[i], totalDays, averageDay);
		averageDays[i] = averageDay;
	}
	printFamousCity(averageDays, NUMCITY);
}
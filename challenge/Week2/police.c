#include <stdio.h> //stdio.h ������

int main(void) {
	int age;
	float weight;
	float height;
	char name[256];
	char crime[256];
	printf("�̸�?");
	scanf_s("%s", name, sizeof(name));
	printf("����?");
	scanf_s("%d", &age);
	printf("������?");
	scanf_s("%f", &weight);
	printf("Ű?");
	scanf_s("%f", &height);
	printf("����?");
	scanf_s("%s", crime, sizeof(crime));
	printf("----����������----");
	printf("�̸�: %s\n", name);
	printf("����: %d\n", age);
	printf("������: %f\n", weight);
	printf("Ű: %f\n", height);
	printf("�˸�: %s\n", crime);
	return 0;
}

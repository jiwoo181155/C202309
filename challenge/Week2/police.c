#include <stdio.h>  //�����Ϸ��� ���̺귯������ stdio.h ��������� ã�Ƽ� ���Խ�Ų��

//main�Լ� ����
int main(void) {
	int age; //age���� ����
	float weight;  //weight ���� ����
	float height;   //height ���� ����
	char name[256];  //ũ�Ⱑ 256�� ���ڿ� �迭 name ����
	char crime[256]; //ũ�Ⱑ 256�� ���ڿ� �迭 crime ����
	printf("�̸�?");  
	scanf_s("%s", name, sizeof(name));  //scanf_s������ �Է¹��� �ܾ name�迭�� ����
	printf("����?"); 
	scanf_s("%d", &age);  //scanf_s������ �Է¹��� ���ڸ� int�� ����age�� ����
	printf("������?");
	scanf_s("%f", &weight);  //scanf_s������ �Է¹��� ���ڸ� float�� ����weight�� ����
	printf("Ű?");
	scanf_s("%f", &height); //scanf_s������ �Է¹��� ���ڸ� float�� ����height�� ����
	printf("����?");
	scanf_s("%s", crime, sizeof(crime)); //scanf_s������ �Է¹��� �ܾ �迭 crime�� ����
	printf("----����������----");  //������ �Է¹޾� ������ ������ �ѹ��� ����ؼ� �����ش�.
	printf("�̸�: %s\n", name);
	printf("����: %d\n", age);
	printf("������: %f\n", weight);
	printf("Ű: %f\n", height);
	printf("�˸�: %s\n", crime);
	return 0;
}

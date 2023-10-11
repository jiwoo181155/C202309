#include <stdio.h>
#define STUDENTS 5 //�������� STUDENTS ����

//classifyStudents��� ������ ABCDF�� �з��ϴ� �Լ� ����
void classifyStudents(int scores[], char targetGrade) {
	printf("�л� ���� �з�:\n");
	char grade = ' ';
	//i�� 0~4(STUDENTS�� �������� 5)���� �ݺ��Ǵ� �ݺ��� ����
	for (int i = 0; i < STUDENTS; i++) {
		if (scores[i] >= 90) {
			grade = 'A'; //socre�迭�� i��° ������ 90�� �̻��̸� grade�� A�� �ȴ�
		}
		else if (scores[i] >= 80) {
			grade = 'B';//socre�迭�� i��° ������ 80�� �̻��̸� grade�� B�� �ȴ�
		}
		else if (scores[i] >= 70) {
			grade = 'C';//socre�迭�� i��° ������ 70�� �̻��̸� grade�� C�� �ȴ�
		}
		else if (scores[i] >= 60) {
			grade = 'D';//socre�迭�� i��° ������ 60�� �̻��̸� grade�� D�� �ȴ�
		}
		else {
			grade = 'F'; //score�迭�� i��° ������ �׿��� 60�� �̸��� ������ ��� grade�� F�� �ȴ�
		}
		if (targetGrade == grade) {
			printf("%d �л��� %c ������ �޾ҽ��ϴ�.", i + 1, targetGrade);
		}
	}
}

int main() {
	//���̰� 5�� score�迭 ����
	int scores[STUDENTS];
	//�л��� ������ �Է��ؼ� socre�迭�� �����ϴ� �ݺ���
	for (int i = 0; i < STUDENTS; i++) {
		printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
		scanf_s("%d", &scores[i]);
	}
	char ch = getchar(); //���͸� ����� ���� ���� �ӽ� ���� ����
	char target;
	printf("Ư�� ���� (A, B, C, D, F)�� �Է��Ͻÿ�");
	scanf_s("%c", &target, 1);

	classifyStudents(scores, target);
}
#include <stdio.h>
#define STUDENTS 5
#define SUBJECTS 3
#define CHARNUM 20

char subjectNames[SUBJECTS][CHARNUM] = { "����", "�߰����", "�⸻���" };
char studentNames[STUDENTS][CHARNUM] = { "" }; // �л� �̸��� ����� �迭
double studentScores[STUDENTS][SUBJECTS] = { 0.0 }; // �л��� ���� �� ������ ������ ����� �迭

//�л����� ���� ����� �л����� ���ؼ� ����ϴ� �Լ� ����
void printStudentResults(double studentScores[][SUBJECTS], char studentNames[][CHARNUM]) {
	for (int i = 0; i < STUDENTS; i++) {
		double student_sum = 0.0; //������������ �����ϴ� sum������ �ʱ�ȭ
		// �л����� �������� ���� ���ϴ� �ݺ���
		for (int j = 0; j < SUBJECTS; j++) {
			student_sum += studentScores[i][j];
		}
		//�л��� �������� ����� ����ϴ� ��¹�
		printf("\t%s�� ��� ����: %.2lf\n", studentNames[i], student_sum / SUBJECTS);
	}

}

//���񺰷� �л��� ������ ����� ���ϴ� �Լ� ����
void printSubjectResults(double studentsScores[][SUBJECTS], char subjectNames[][CHARNUM]) {
	double AvgScore[SUBJECTS] = { 0.0 };
	for (int j = 0; j < SUBJECTS; j++) {
		double subject_sum = 0.0;
		//���񺰷� ������ ���� ���ϴ� �ݺ���
		for (int i = 0; i < STUDENTS; i++) {
			subject_sum += studentScores[i][j];
		}
		//���� ���� ���Ѵ�
		AvgScore[j] = subject_sum / STUDENTS;
		//���񺰷� �л��� ������ ����� ���
		printf("\t%s�� ��� ������ %.2lf �Դϴ�.\n", subjectNames[j], AvgScore[j]);
	}
}

int main() {

	printf("�л� %d���� �̸��� �Է��� �����մϴ�. \n", STUDENTS);
	// TODO 1.1: �л� �̸��� �Է¹޴� �ڵ� ��� �ۼ�
	for (int i = 0; i < STUDENTS; i++) {
		printf("\t%d��° �л��� �̸��� �Է��ϼ���: ", i + 1);
		scanf_s("%s", studentNames[i], (int)sizeof(studentNames[i]));
	}

	// �Էµ� �л� �̸��� �� ����Ǿ����� Ȯ���ϴ� �ڵ� ���
	printf("�л� �̸��� ��� �ԷµǾ����ϴ�. \n");
	printf("�Էµ� �л� �̸��� ������ �����ϴ�. \n");
	for (int i = 0; i < STUDENTS; i++) {
		printf("%s", studentNames[i]);
		if (i != STUDENTS - 1) {
			printf(", ");
		}
	}
	printf("\n");
	printf("--------------------\n");
	printf("�� �л��� %s, %s, %s ������ ���ʴ�� �Է����ּ���. (���� ����)\n ", subjectNames[0], subjectNames[1], subjectNames[2]);


	// TODO 1.2: �л����� ���� �� ������ �Է¹޴� �ڵ� ��� �ۼ�
	for (int i = 0; i < STUDENTS; i++) {
		printf("\t%s�� ����: ", studentNames[i]);
		scanf_s("%lf %lf %lf", &studentScores[i][0], &studentScores[i][1], &studentScores[i][2]);
	}


	printf("�л����� ���� ������ ��� �Է� �Ǿ����ϴ�.\n");
	printf("--------------------\n");
	printf("�л� �� ������ ������ �����ϴ� \n");

	//�л����� ��������� ���ϴ� �Լ� ȣ��
	printStudentResults(studentScores, studentNames);

	printf("--------------------\n");
	printf("���� �� ��� ������ �Ʒ��� �����ϴ�. \n");

	//���񺰷� �л��� ������ ����� ���ϴ� �Լ� ȣ��
	printSubjectResults(studentScores, subjectNames);

	printf("���α׷��� �����մϴ�. ");
	return 0;
}
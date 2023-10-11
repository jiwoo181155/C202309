#include <stdio.h>
#define STUDENTS 5 //�������� STUDENTS ����

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
			printf("%d �л��� %c ������ �޾ҽ��ϴ�.\n", i + 1, targetGrade);
		}
	}
}

//���� ������ ���ϴ� �Լ�sumSocres����
int sumScores(int scores[]) {
	int sum = 0; //sum�� 0���� �ʱ�ȭ
	for (int i = 0; i < STUDENTS; i++) {
		sum += scores[i];//sum�� score�迭 ���� ���ʴ�� ����
	}
	return sum;
}

//������ ����� ���ϴ� averageScores�Լ� ����
double averageScores(int scores[]) {
	double avg; //double�� avg ���� ����
	int sum = 0;
	for (int i = 0; i < STUDENTS; i++) {
		sum += scores[i];
	}
	avg = (double)sum / (sizeof(scores) / sizeof(int)); //(sizeof(scores) / sizeof(int)������ �迭�� ���� �� ������ �� ������ ���Ѵ��� ������ ����� ��� ���ϱ�
	return avg;
}

//�л����� ���� ������ ����ϴ� printRanks�Լ� ����
void printRanks(int scores[]) {
	int rank[STUDENTS];
	int cnt; //socre�迭�� i��° ������ ū���� ����� ���ϴ� ����
	for (int i = 0; i < STUDENTS; i++) {
		cnt = 0; //�ݺ��� �� ����Ŭ���� 0���� �ʱ�ȭ
		for (int j = 0; j < STUDENTS; j++) {
			if (scores[i] < scores[j]) {
				cnt++;
			}
		}
		rank[i] = cnt + 1;
	}
	//���� ������ �������� ����ϴ� �ݺ���
	for (int i = 0; i < STUDENTS; i++) {
		printf("%d �л��� ������ %d �Դϴ�.\n", i+1,rank[i]);
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

	int sum = sumScores(scores); //���� ������ ���ϴ� sumScores�Լ� ȣ��
	double average = averageScores(scores); //���� ����� ���ϴ� averageScores�Լ� ȣ��
	printf("�л��� ������ �� ���� %d�̰� ��� ���� %lf�Դϴ�.\n", sum, average);

	printRanks(scores); //�л����� ������ ����ϴ� printRanks�Լ� ȣ��

	return 0;
}
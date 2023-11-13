#include <stdio.h>
#define STUDENTS 5  // �������� STUDENTS�� 5�� ����

//�迭�� �����͸� �Ű������� �޴� sumScores�Լ� ����
int sumScores(int* scores) {
  int sum = 0;
  //�ݺ����� �̿��Ͽ� socres�迭���� ���ڸ� ��� ���Ѵ�
  for (int i = 0; i < STUDENTS; i++) {
    sum += scores[i];
  }
  return sum;
}

//�迭�� �����͸� �Ű������� �޴� averageScores�Լ� ����
//scores �迭�� ��հ��� ���ϴ� �Լ�
double averageScores(int* scores) { 
    int sum = sumScores(scores);
    double average = (double)sum / (double)STUDENTS;
    return average;
}

//scores ������ ������ ����(rank)�� �Ű� ����ϴ� �Լ�
//�迭�� �����͸� �Ű������� �޴� printRanks�Լ� ����
void printRanks(int* scores) {
    int ranks[STUDENTS]; //scores�迭���� ������ ������ �Ű��� rank�迭
    for (int i = 0; i < STUDENTS; i++) {
        ranks[i] = 1; 
        for (int j = 0; j < STUDENTS; j++) {
            if (scores[j] > scores[i]) {
                ranks[i]++; //�ڽź��� ū ���� �����Ұ�� �ʱ� ���� 1���ٰ� 1�� ���ؼ� ���� ����
            }
        }
        printf("%d �л��� ������ %d �Դϴ�. \n", i, ranks[i]);
    }
}

// �迭�� �����͸� �Ű������� �޴� classifyStudents�Լ� ����
void classifyStudents(int* scores, char targetGrade) {
    printf("�л� ���� �з�:\n");
    char grade = ' ';
    // i�� 0~4(STUDENTS�� �������� 5)���� �ݺ��Ǵ� �ݺ��� ����
    for (int i = 0; i < STUDENTS; i++) {
        if (scores[i] >= 90) {
            grade =
                'A';  // socre�迭�� i��° ������ 90�� �̻��̸� grade�� A�� �ȴ�
        } else if (scores[i] >= 80) {
            grade =
                'B';  // socre�迭�� i��° ������ 80�� �̻��̸� grade�� B�� �ȴ�
        } else if (scores[i] >= 70) {
            grade =
                'C';  // socre�迭�� i��° ������ 70�� �̻��̸� grade�� C�� �ȴ�
        } else if (scores[i] >= 60) {
            grade =
                'D';  // socre�迭�� i��° ������ 60�� �̻��̸� grade�� D�� �ȴ�
        } else {
            grade = 'F';  // score�迭�� i��° ������ �׿��� 60�� �̸��� ������
                          // ��� grade�� F�� �ȴ�
        }
        if (targetGrade == grade) {
            printf("%d �л��� %c ������ �޾ҽ��ϴ�.", i + 1, targetGrade);
        }
    }
}

int main() {
    int scores[STUDENTS];

    for (int i = 0; i < STUDENTS; i++) {
        printf("�л� %d�� ������ �Է��ϼ���.: ", i + 1);
        scanf_s("%d", &scores[i]);
    }

    char ch = getchar(); //���۸� �ʱ�ȭ���ִ� getchar�Լ�

    char target;
    printf("Ư�� ����(A, B, C, D, F)�� �Է��Ͻÿ�: ");
    scanf_s("%c", &target, 1 ); 

    classifyStudents(scores, target); //������ �з����ִ� classifyStudents�Լ� ȣ��
    
    int sum = sumScores(scores);
    double average = averageScores(scores);
    printf("�л��� ������ �� ���� %d �̰�, ��� ���� %lf�Դϴ�.\n", sum, average);

    printRanks(scores);

    return 0;

}
#include <stdio.h>
#include <stdlib.h>

// �л� ������ �����ϴ� ����ü ����
struct Student {
  char name[50]; //�̸��� ���� �迭
  int score; //������ ���� ����
};

// �迭�� �����͸� �Ű������� �޴� sumScores�Լ� ����
int sumScores(struct Student* students, int studentCount) {
  int sum = 0;
  // �ݺ����� �̿��Ͽ� socres�迭���� ���ڸ� ��� ���Ѵ�
  for (int i = 0; i < studentCount; i++) {
    sum += students[i].score;
  }
  return sum;
}

// �迭�� �����͸� �Ű������� �޴� averageScores�Լ� ����
// scores �迭�� ��հ��� ���ϴ� �Լ�
double averageScores(struct Student* students, int studentCount) {
  int sum = sumScores(students, studentCount);
  double average = (double)sum / (double)studentCount; //double�� average�� �˸°� ���� double�� ������ ���
  return average;
}

// students ����ü �迭�� �Ű������� �޴� printRanks�Լ� ����
// students �迭�� ������ ����(rank)�� �Ű� ����ϴ� �Լ�
void printRanks(struct Student* students, int studentCount) {
  int* ranks = (int*)malloc(studentCount * sizeof(int));  // students �迭���� ������ ������ �Ű��� rank�迭
  if (ranks == NULL) {
    printf("�޸� �Ҵ� ����\n");
    return;
  }

  //�л����� ���� ũ�⿡ ���� ����(rank)�� �ο� (��������)
  for (int i = 0; i < studentCount; i++) {
    ranks[i] = 1;
    for (int j = 0; j < studentCount; j++) {
      if (students[j].score > students[i].score) {
        ranks[i]++;  // �ڽź��� ū ���� �����Ұ�� �ʱ� ���� 1���ٰ� 1�� ���ؼ� ���� ����
                     
      }
    }
    printf("%s �л��� ������ %d �Դϴ�.\n", students[i].name, ranks[i]);
  }

  free(ranks);  // �������� �Ҵ��� �޸� ����
}

// students ����ü �迭�� �Ű������� �޴� classifyStudents �Լ� ����
void classifyStudents(struct Student* students, int studentCount,char targetGrade) {
  printf("�л� ���� �з�:\n");
  char grade = ' ';
  // i�� 0���� studentCount-1���� �ݺ��Ǵ� �ݺ��� ����
  //�л��� ���������� A~F���� �����ο�
  for (int i = 0; i < studentCount; i++) {
    if (students[i].score >= 90) {
      grade = 'A';  // score�迭�� i��° ������ 90�� �̻��̸� grade�� A�� �ȴ�
    } else if (students[i].score >= 80) {
      grade = 'B';  // score�迭�� i��° ������ 80�� �̻��̸� grade�� B�� �ȴ�
    } else if (students[i].score >= 70) {
      grade = 'C';  // score�迭�� i��° ������ 70�� �̻��̸� grade�� C�� �ȴ�
    } else if (students[i].score >= 60) {
      grade = 'D';  // score�迭�� i��° ������ 60�� �̻��̸� grade�� D�� �ȴ�
    } else {
      grade = 'F';  // score�迭�� i��° ������ �׿��� 60�� �̸��� ������ ���
                    // grade�� F�� �ȴ�
    }
    if (targetGrade == grade) {
      printf("%s �л��� %c ������ �޾ҽ��ϴ�.\n", students[i].name,
             targetGrade);
    }
  }
}

int main() {
  int studentCount; //����ڰ� �Է��ϴ� �л� ���� �����ϴ� ����

  // ����ڷκ��� �л� �� �Է� �ޱ�
  printf("�л� ���� �Է��ϼ���: ");
  scanf_s("%d", &studentCount);

  // �������� �л� ����ü �迭 �Ҵ�
  struct Student* students = (struct Student*)malloc(studentCount * sizeof(struct Student));

  // �л� ���� �Է� �ޱ�
  for (int i = 0; i < studentCount; ++i) {
    printf("�л� %d�� �̸��� �Է��ϼ���: ", i + 1);
    scanf_s("%s", students[i].name, (int)sizeof(students[i].name));
    printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
    scanf_s("%d", &students[i].score);
  }


  char targetGrade; //����ڰ� �Է��ϴ� Ư�� ������ ���� ���ڸ� �����ϴ� ����
  printf("Ư�� ����(A, B, C, D, F)�� �Է��ϼ���: ");
  scanf_s(" %c", &targetGrade);  // ���� �Է� �� ������ �����Ͽ� �Է¹޵��� ����

  classifyStudents(students, studentCount,targetGrade);  // ����ڰ� �Է��� ������ ���� �л� ���

  int sum = sumScores(students, studentCount); //sum������ �����ϰ� �л��� ������ ������ sumScore�Լ��� �̿��Ͽ� ���� ������ �ʱ�ȭ
  double average = averageScores(students, studentCount); //double�� average������ �����ϰ� averageScores�Լ��� �̿��Ͽ� ���� ������� ������ �ʱ�ȭ
  printf("�л��� ������ �� ���� %d �̰�, ��� ���� %lf�Դϴ�.\n", sum, average);

  printRanks(students, studentCount); //�л����� ������ ���

  // �������� �Ҵ��� �޸� ����
  free(students);

  return 0;
}
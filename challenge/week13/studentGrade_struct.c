#include <stdio.h>
#include <stdlib.h>

// 학생 정보를 저장하는 구조체 정의
struct Student {
  char name[50]; //이름이 들어가는 배열
  int score; //점수가 들어가는 변수
};

// 배열의 포인터를 매개변수로 받는 sumScores함수 선언
int sumScores(struct Student* students, int studentCount) {
  int sum = 0;
  // 반복문을 이용하여 socres배열안의 숫자를 모두 더한다
  for (int i = 0; i < studentCount; i++) {
    sum += students[i].score;
  }
  return sum;
}

// 배열의 포인터를 매개변수로 받는 averageScores함수 선언
// scores 배열의 평균값을 구하는 함수
double averageScores(struct Student* students, int studentCount) {
  int sum = sumScores(students, studentCount);
  double average = (double)sum / (double)studentCount; //double형 average에 알맞게 각각 double형 변수로 계산
  return average;
}

// students 구조체 배열을 매개변수로 받는 printRanks함수 선언
// students 배열의 점수를 순위(rank)를 매겨 출력하는 함수
void printRanks(struct Student* students, int studentCount) {
  int* ranks = (int*)malloc(studentCount * sizeof(int));  // students 배열안의 점수에 순위를 매겨줄 rank배열
  if (ranks == NULL) {
    printf("메모리 할당 오류\n");
    return;
  }

  //학생들의 점수 크기에 따른 순위(rank)를 부여 (내림차순)
  for (int i = 0; i < studentCount; i++) {
    ranks[i] = 1;
    for (int j = 0; j < studentCount; j++) {
      if (students[j].score > students[i].score) {
        ranks[i]++;  // 자신보다 큰 수가 존재할경우 초기 순위 1에다가 1씩 더해서 순위 결정
                     
      }
    }
    printf("%s 학생의 순위는 %d 입니다.\n", students[i].name, ranks[i]);
  }

  free(ranks);  // 동적으로 할당한 메모리 해제
}

// students 구조체 배열을 매개변수로 받는 classifyStudents 함수 선언
void classifyStudents(struct Student* students, int studentCount,char targetGrade) {
  printf("학생 성적 분류:\n");
  char grade = ' ';
  // i가 0부터 studentCount-1까지 반복되는 반복문 설정
  //학생의 점수에따라 A~F까지 학점부여
  for (int i = 0; i < studentCount; i++) {
    if (students[i].score >= 90) {
      grade = 'A';  // score배열의 i번째 점수가 90점 이상이면 grade는 A가 된다
    } else if (students[i].score >= 80) {
      grade = 'B';  // score배열의 i번째 점수가 80점 이상이면 grade는 B가 된다
    } else if (students[i].score >= 70) {
      grade = 'C';  // score배열의 i번째 점수가 70점 이상이면 grade는 C가 된다
    } else if (students[i].score >= 60) {
      grade = 'D';  // score배열의 i번째 점수가 60점 이상이면 grade는 D가 된다
    } else {
      grade = 'F';  // score배열의 i번째 점수가 그외의 60점 미만의 점수일 경우
                    // grade는 F가 된다
    }
    if (targetGrade == grade) {
      printf("%s 학생은 %c 점수를 받았습니다.\n", students[i].name,
             targetGrade);
    }
  }
}

int main() {
  int studentCount; //사용자가 입력하는 학생 수를 저장하는 변수

  // 사용자로부터 학생 수 입력 받기
  printf("학생 수를 입력하세요: ");
  scanf_s("%d", &studentCount);

  // 동적으로 학생 구조체 배열 할당
  struct Student* students = (struct Student*)malloc(studentCount * sizeof(struct Student));

  // 학생 정보 입력 받기
  for (int i = 0; i < studentCount; ++i) {
    printf("학생 %d의 이름을 입력하세요: ", i + 1);
    scanf_s("%s", students[i].name, (int)sizeof(students[i].name));
    printf("학생 %d의 성적을 입력하세요: ", i + 1);
    scanf_s("%d", &students[i].score);
  }


  char targetGrade; //사용자가 입력하는 특정 학점에 대한 문자를 저장하는 변수
  printf("특정 학점(A, B, C, D, F)을 입력하세요: ");
  scanf_s(" %c", &targetGrade);  // 학점 입력 시 공백을 포함하여 입력받도록 수정

  classifyStudents(students, studentCount,targetGrade);  // 사용자가 입력한 학점을 가진 학생 출력

  int sum = sumScores(students, studentCount); //sum변수를 선언하고 학생들 점수의 총점을 sumScore함수를 이용하여 구한 값으로 초기화
  double average = averageScores(students, studentCount); //double혀 average변수를 선언하고 averageScores함수를 이용하여 구한 평균점수 값으로 초기화
  printf("학생들 성적의 총 합은 %d 이고, 평균 값은 %lf입니다.\n", sum, average);

  printRanks(students, studentCount); //학생들의 순위를 출력

  // 동적으로 할당한 메모리 해제
  free(students);

  return 0;
}
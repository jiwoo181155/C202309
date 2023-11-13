#include <stdio.h>
#define STUDENTS 5  // 전역변수 STUDENTS를 5로 선언

//배열의 포인터를 매개변수로 받는 sumScores함수 선언
int sumScores(int* scores) {
  int sum = 0;
  //반복문을 이용하여 socres배열안의 숫자를 모두 더한다
  for (int i = 0; i < STUDENTS; i++) {
    sum += scores[i];
  }
  return sum;
}

//배열의 포인터를 매개변수로 받는 averageScores함수 선언
//scores 배열의 평균값을 구하는 함수
double averageScores(int* scores) { 
    int sum = sumScores(scores);
    double average = (double)sum / (double)STUDENTS;
    return average;
}

//scores 변수의 점수를 순위(rank)를 매겨 출력하는 함수
//배열의 포인터를 매개변수로 받는 printRanks함수 선언
void printRanks(int* scores) {
    int ranks[STUDENTS]; //scores배열안의 점수에 순위를 매겨줄 rank배열
    for (int i = 0; i < STUDENTS; i++) {
        ranks[i] = 1; 
        for (int j = 0; j < STUDENTS; j++) {
            if (scores[j] > scores[i]) {
                ranks[i]++; //자신보다 큰 수가 존재할경우 초기 순위 1에다가 1씩 더해서 순위 결정
            }
        }
        printf("%d 학생의 순위는 %d 입니다. \n", i, ranks[i]);
    }
}

// 배열의 포인터를 매개변수로 받는 classifyStudents함수 선언
void classifyStudents(int* scores, char targetGrade) {
    printf("학생 성적 분류:\n");
    char grade = ' ';
    // i가 0~4(STUDENTS는 전역변수 5)까지 반복되는 반복문 설정
    for (int i = 0; i < STUDENTS; i++) {
        if (scores[i] >= 90) {
            grade =
                'A';  // socre배열의 i번째 점수가 90점 이상이면 grade는 A가 된다
        } else if (scores[i] >= 80) {
            grade =
                'B';  // socre배열의 i번째 점수가 80점 이상이면 grade는 B가 된다
        } else if (scores[i] >= 70) {
            grade =
                'C';  // socre배열의 i번째 점수가 70점 이상이면 grade는 C가 된다
        } else if (scores[i] >= 60) {
            grade =
                'D';  // socre배열의 i번째 점수가 60점 이상이면 grade는 D가 된다
        } else {
            grade = 'F';  // score배열의 i번째 점수가 그외의 60점 미만의 점수일
                          // 경우 grade는 F가 된다
        }
        if (targetGrade == grade) {
            printf("%d 학생은 %c 점수를 받았습니다.", i + 1, targetGrade);
        }
    }
}

int main() {
    int scores[STUDENTS];

    for (int i = 0; i < STUDENTS; i++) {
        printf("학생 %d의 성적을 입력하세요.: ", i + 1);
        scanf_s("%d", &scores[i]);
    }

    char ch = getchar(); //버퍼를 초기화해주는 getchar함수

    char target;
    printf("특정 점수(A, B, C, D, F)를 입력하시오: ");
    scanf_s("%c", &target, 1 ); 

    classifyStudents(scores, target); //성적을 분류해주는 classifyStudents함수 호출
    
    int sum = sumScores(scores);
    double average = averageScores(scores);
    printf("학생들 점수의 총 합은 %d 이고, 평균 값은 %lf입니다.\n", sum, average);

    printRanks(scores);

    return 0;

}
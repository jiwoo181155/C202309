#include <stdio.h>
#define STUDENTS 5
#define SUBJECTS 3
#define CHARNUM 20

char subjectNames[SUBJECTS][CHARNUM] = { "퀴즈", "중간고사", "기말고사" };
char studentNames[STUDENTS][CHARNUM] = { "" }; // 학생 이름이 저장될 배열
double studentScores[STUDENTS][SUBJECTS] = { 0.0 }; // 학생의 시험 별 성적이 점수가 저장될 배열

//학생들의 점수 평균을 학생별로 구해서 출력하는 함수 정의
void printStudentResults(double studentScores[][SUBJECTS], char studentNames[][CHARNUM]) {
	for (int i = 0; i < STUDENTS; i++) {
		double student_sum = 0.0; //시험점수합을 저장하는 sum변수를 초기화
		// 학생별로 시험점수 합을 구하는 반복문
		for (int j = 0; j < SUBJECTS; j++) {
			student_sum += studentScores[i][j];
		}
		//학생별 시험점수 평균을 출력하는 출력문
		printf("\t%s의 평균 점수: %.2lf\n", studentNames[i], student_sum / SUBJECTS);
	}

}

//과목별로 학생들 점수의 평균을 구하는 함수 정의
void printSubjectResults(double studentsScores[][SUBJECTS], char subjectNames[][CHARNUM]) {
	double AvgScore[SUBJECTS] = { 0.0 };
	for (int j = 0; j < SUBJECTS; j++) {
		double subject_sum = 0.0;
		//과목별로 점수의 합을 구하는 반복문
		for (int i = 0; i < STUDENTS; i++) {
			subject_sum += studentScores[i][j];
		}
		//과목별 평군을 구한다
		AvgScore[j] = subject_sum / STUDENTS;
		//과목별로 학생들 점수의 평균을 출력
		printf("\t%s의 평균 점수는 %.2lf 입니다.\n", subjectNames[j], AvgScore[j]);
	}
}

int main() {

	printf("학생 %d명의 이름의 입력을 시작합니다. \n", STUDENTS);
	// TODO 1.1: 학생 이름을 입력받는 코드 블록 작성
	for (int i = 0; i < STUDENTS; i++) {
		printf("\t%d번째 학생의 이름을 입력하세요: ", i + 1);
		scanf_s("%s", studentNames[i], (int)sizeof(studentNames[i]));
	}

	// 입력된 학생 이름이 잘 저장되었는지 확인하는 코드 블록
	printf("학생 이름이 모두 입력되었습니다. \n");
	printf("입력된 학생 이름은 다음과 같습니다. \n");
	for (int i = 0; i < STUDENTS; i++) {
		printf("%s", studentNames[i]);
		if (i != STUDENTS - 1) {
			printf(", ");
		}
	}
	printf("\n");
	printf("--------------------\n");
	printf("각 학생의 %s, %s, %s 점수를 차례대로 입력해주세요. (띄어쓰기 구분)\n ", subjectNames[0], subjectNames[1], subjectNames[2]);


	// TODO 1.2: 학생들의 시험 별 점수를 입력받는 코드 블록 작성
	for (int i = 0; i < STUDENTS; i++) {
		printf("\t%s의 성적: ", studentNames[i]);
		scanf_s("%lf %lf %lf", &studentScores[i][0], &studentScores[i][1], &studentScores[i][2]);
	}


	printf("학생들의 시험 점수가 모두 입력 되었습니다.\n");
	printf("--------------------\n");
	printf("학생 별 성적은 다음과 같습니다 \n");

	//학생들의 평균점수를 구하는 함수 호출
	printStudentResults(studentScores, studentNames);

	printf("--------------------\n");
	printf("과목 별 평균 점수는 아래와 같습니다. \n");

	//과목별로 학생들 점수의 평균을 구하는 함수 호출
	printSubjectResults(studentScores, subjectNames);

	printf("프로그램을 종료합니다. ");
	return 0;
}
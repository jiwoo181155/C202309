#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

int main() {
	char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // 할 일 목록을 저장하기 위한 2차원 배열을 먼저 선언하고 시작
	int taskCount = 0; // 할 일의 수를 저장하기 위한 변수를 먼저 선언하고 시작

	printf("TODO 리스트 시작! \n"); //TODO리스트 프로그램 시작 문구 출력

	while (1) {
		int choice = -1; // 사용자 입력 메뉴를 저장하기 위한 변수 choice

		// 사용자에게 메뉴를 출력하는 printf문과 메뉴를 입력받는 scanf_s문 작성
		printf("------------------\n");
		printf("메뉴를 입력해주세요.\n");;
		printf("1. 할 일 추가\n2. 할 일 삭제\n3. 목록 보기\n4. 종료\n5.할 일 수정\n");
		printf("현재 할 일 수 = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		int terminate = 0; // 종료를 위한 변수 terminate를 0으로 초기화
		int delIndex = -1;  // 할 일 삭제를 위해 index를 저장하는 delIndex 변수를 -1로 초기화
		int changeIndex = -1; // 할 일 수정을 위한 index 저장 변수 changeIndex를 -1로 초기화
		char ch; //  할 일 수정시 버퍼를 받기 위한 문자 변수 ch를 선언

		// 입력에 따른 기능 수행을하는 switch조건문
		switch (choice) {
		case 1:
			printf("할 일을 입력하세요 (공백 없이 입력하세요): ");
			//할일을 2차원 배열 tasks에 입력받는 scanf_s문
			scanf_s("%s", tasks[taskCount], (int)sizeof(tasks[taskCount])); 
			printf("할 일 ""%s""가 저장되었습니다\n\n", tasks[taskCount]);
			//할 일 목록이 추가되었으므로 할 일 갯수를 저장하는
			//taskCount변수에 1을 더한다.
			taskCount++;
			break;
		case 2:
			// 할 일 삭제하는 코드 블록 
			printf("삭제할 할 일의 번호를 입력해주세요. (1부터 시작):");
			scanf_s("%d", &delIndex); //삭제할 할일의 인덱스를 입력받는 scanf_s문

			//만약 입력한 삭제할 일의 번호가 저장된 할 일의 갯수인 
			//taskCount보다 크면 삭제범위가 벗어났음을 알려주는 조건문 작성
			if (delIndex > taskCount || delIndex <= 0) {
				printf("삭제 범위가 벗어났습니다.\n");
			}
			else {
				printf("%d. %s : 할 일을 삭제합니다.\n", delIndex, tasks[delIndex - 1]);

				// 배열에 문자 배열인 문자열의 대입이 불가능하므로 
				//문자열 복사 함수strcpy_s를 이용해서 삭제
				strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");

				// 앞에서 할 일 삭제 후 뒤에 있는 할 일을 앞으로 옮겨서 빈 칸 채우기
				for (int i = delIndex; i < taskCount + 1; i++) {
					strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
				}
				taskCount -= 1;
			}
			break;
		case 3:
			printf("할 일 목록\n"); 
			//반복문을 통해 tasks배열을 전부 출력
			for (int i = 0; i < taskCount; i++) {
				printf("%d. %s \n", i + 1, tasks[i]);
			}
			printf("\n");
			break;
		case 4:
			//종료를 위한 변수 terminate에 1을 입력하여 
			//뒤에 나오는 조건문을 이용하여 프로그램 종료
			terminate = 1; 
			break;
		case 5:
			printf("수정할 할 일의 번호를 입력해주세요. (1부터 시작): ");
			scanf_s("%d", &changeIndex);  //수정할 할 일의 인덱스를 입력받음
			//입력된 버퍼를 getchar()를 이용해 ch에 저장하는 방식으로 
			//다음 코드가 작동하는데 방해되지 않도록함
			ch = getchar(); 
			printf("수정할 내용을 입력해주세요 : ");
			//수정할 내용을 입력받는 scanf_s문
			scanf_s("%s", tasks[changeIndex - 1], (int)sizeof(tasks[taskCount])); 
			printf("할일이 수정되었습니다.");
			printf("\n");
			break;

		default:
			//앞서 정의된 1~5번의 숫자를 제외한 다른 숫자가 입력되면 
			//잘못 입력했음을 알려주는 문구
			printf("잘못된 선택입니다. 다시 선택하세요.\n"); 
		}

		//terminate변수에 1이 입력되면 프로그램을 종료시키는 조건문
		if (terminate == 1) {
			printf("종료를 선택하셨습니다. 프로그램을 종료합니다.\n"); 
			break;
		}

		// TODO: 할 일이 다 찼는지 체크하는 코드=>다 차면 프로그램 종료
		//저장된 할 일의 개수를 의미하는 taskCount가 최대 입력가능 할 일 개수인
		//MAX_TASKS와 같아지면 프로그램을 탈출하는 break문 작동해서 프로그램 종료
		if (taskCount == MAX_TASKS) {
			printf("할일이 다 찼습니다.\n");
			break;
		}
	}
}
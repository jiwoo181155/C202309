#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // �� �� ����� �����ϱ� ���� 2���� �迭 tasks�� ���� �����ϰ� ����
                                          //���Ŀ� ������ �Լ��鿡 tasks �迭�� ����ϱ� ����
int taskCount = 0; // �� ���� ���� �����ϱ� ���� ������ ���� �����ϰ� ����

//������ �Է¹޾Ƽ� tasks 2���� �迭�� �Է��ϴ� �Լ�
void addTask(char tasks[]) {
	printf("�� ���� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
	scanf_s("%s", tasks, (int)sizeof(tasks)); //������ 2���� �迭 tasks�� �Է¹޴� scanf_s��
	printf("�� �� ""%s""�� ����Ǿ����ϴ�\n\n", tasks);
}

//tasks2�����迭�� �Է¹��� �� ���� �����ϴ� �Լ�
void delTask(int delIndex, int taskCount) {
	printf("%d. %s : �� ���� �����մϴ�.\n", delIndex, tasks[delIndex - 1]);

	// �迭�� ���� �迭�� ���ڿ��� ������ �Ұ����ϹǷ� ���ڿ� ���� �Լ�strcpy_s�� �̿��ؼ� ����
	strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");

	// �տ��� �� �� ���� �� �ڿ� �ִ� �� ���� ������ �Űܼ� �� ĭ ä���
	for (int i = delIndex; i < taskCount + 1; i++) {
		strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
	}
}

//tasks 2���� �迭�� ����� �� �� ����� ������ִ� �Լ� ����
void printTask(int taskCount) {
	//�ݺ����� ���� tasks�迭�� ���� ���
	for (int i = 0; i < taskCount; i++) {
		printf("%d. %s \n", i + 1, tasks[i]);
	}
	printf("\n");
}

int main() {
	printf("TODO ����Ʈ ����! \n");
	//while�ݺ����� 1�� �־ ���� �ݺ��� �ǽ�
	while (1) {
		int choice = -1; // ����� �Է� �޴��� �����ϱ� ���� ����

		// ����ڿ��� �޴��� ����ϴ� printf���� �޴��� �Է¹޴� scanf_s�� �ۼ�
		printf("------------------\n");
		printf("�޴��� �Է����ּ���.\n");;
		printf("1. �� �� �߰�\n2. �� �� ����\n3. ��� ����\n4. ����\n5.�� �� ����\n");
		printf("���� �� �� �� = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		int terminate = 0; // ���Ḧ ���� ���� terminate�� 0���� �ʱ�ȭ
		int delIndex = -1;  // �� �� ������ ���� index�� �����ϴ� delIndex ������ -1�� �ʱ�ȭ
		int changeIndex = -1; // �� �� ������ ���� index ���� ���� changeIndex�� -1�� �ʱ�ȭ
		char ch; // �� �� ������ ���۸� �ޱ� ���� ���� ���� ch�� ����

		// �Է¿� ���� ��� �������ϴ� switch���ǹ�
		switch (choice) {
		case 1:
			addTask(tasks[taskCount]); //������ �߰��ϴ� addTask�Լ� ȣ��
			taskCount++;  //taskCount�� 1���߰��Ͽ� ��� ���� ����� �ԷµǾ����� ī��Ʈ
			break;
		case 2:
			// �� �� �����ϴ� �ڵ� ��� 
			printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����):");
			scanf_s("%d", &delIndex);
			//���� �Է��� ������ ���� ��ȣ�� ����� �� ���� ������ taskCount���� ũ�� ���������� ������� �˷��ִ� ���ǹ� �ۼ�
			if (delIndex > taskCount || delIndex <= 0) {
				printf("���� ������ ������ϴ�.\n");
			}
			else {
				delTask(delIndex, taskCount); //����� �ʾ����� ������ �����ϴ� �Լ��� ȣ���Ͽ� ����
				taskCount -= 1; //������ �ϳ� �����Ǿ����Ƿ� taskCount�� 1 ����
			}
			break;
		case 3:
			printf("�� �� ���\n");
			printTask(taskCount); //�Էµ� �� �� ����� ���� �����ִ� printTask�Լ� ȣ��
			break;
		case 4:
			terminate = 1; //���Ḧ ���� ���� terminate�� 1�� �Է��Ͽ� �ڿ� ������ ���ǹ��� �̿��Ͽ� ���α׷� ����
			break;
		case 5:
			printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����): ");
			scanf_s("%d", &changeIndex); //������ �� ���� �ε����� �Է¹���
			ch = getchar(); //�Էµ� ���۸� getchar()�� �̿��� ch�� �����ϴ� ������� ���� �ڵ尡 �۵��ϴµ� ���ص��� �ʵ�����
			printf("������ ������ �Է����ּ��� : ");
			scanf_s("%s", tasks[changeIndex - 1], (int)sizeof(tasks[taskCount])); //������ ������ �Է¹޴� scanf_s��
			printf("������ �����Ǿ����ϴ�.");
			printf("\n");
			break;

		default:
			printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n"); //�ռ� ���ǵ� 1~5���� ���ڸ� ������ �ٸ� ���ڰ� �ԷµǸ� �߸� �Է������� �˷��ִ� ����
		}
		
		//terminate������ 1�� �ԷµǸ� ���α׷��� �����Ű�� ���ǹ�
		if (terminate == 1) {
			printf("���Ḧ �����ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
			break;
		}

		// TODO: �� ���� �� á���� üũ�ϴ� �ڵ�=>�� ���� ���α׷� ����
		//����� �� ���� ������ �ǹ��ϴ� taskCount�� �ִ� �Է°��� �� �� ������
		//MAX_TASKS�� �������� ���α׷��� Ż���ϴ� break�� �۵��ؼ� ���α׷� ����
		if (taskCount == MAX_TASKS) {
			printf("������ �� á���ϴ�.\n"); //
			break;
		}
	}
}
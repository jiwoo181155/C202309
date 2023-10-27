#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

int main() {
	char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // �� �� ����� �����ϱ� ���� 2���� �迭�� ���� �����ϰ� ����
	int taskCount = 0; // �� ���� ���� �����ϱ� ���� ������ ���� �����ϰ� ����

	printf("TODO ����Ʈ ����! \n"); //TODO����Ʈ ���α׷� ���� ���� ���

	while (1) {
		int choice = -1; // ����� �Է� �޴��� �����ϱ� ���� ���� choice

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
		char ch; //  �� �� ������ ���۸� �ޱ� ���� ���� ���� ch�� ����

		// �Է¿� ���� ��� �������ϴ� switch���ǹ�
		switch (choice) {
		case 1:
			printf("�� ���� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
			//������ 2���� �迭 tasks�� �Է¹޴� scanf_s��
			scanf_s("%s", tasks[taskCount], (int)sizeof(tasks[taskCount])); 
			printf("�� �� ""%s""�� ����Ǿ����ϴ�\n\n", tasks[taskCount]);
			//�� �� ����� �߰��Ǿ����Ƿ� �� �� ������ �����ϴ�
			//taskCount������ 1�� ���Ѵ�.
			taskCount++;
			break;
		case 2:
			// �� �� �����ϴ� �ڵ� ��� 
			printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����):");
			scanf_s("%d", &delIndex); //������ ������ �ε����� �Է¹޴� scanf_s��

			//���� �Է��� ������ ���� ��ȣ�� ����� �� ���� ������ 
			//taskCount���� ũ�� ���������� ������� �˷��ִ� ���ǹ� �ۼ�
			if (delIndex > taskCount || delIndex <= 0) {
				printf("���� ������ ������ϴ�.\n");
			}
			else {
				printf("%d. %s : �� ���� �����մϴ�.\n", delIndex, tasks[delIndex - 1]);

				// �迭�� ���� �迭�� ���ڿ��� ������ �Ұ����ϹǷ� 
				//���ڿ� ���� �Լ�strcpy_s�� �̿��ؼ� ����
				strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");

				// �տ��� �� �� ���� �� �ڿ� �ִ� �� ���� ������ �Űܼ� �� ĭ ä���
				for (int i = delIndex; i < taskCount + 1; i++) {
					strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
				}
				taskCount -= 1;
			}
			break;
		case 3:
			printf("�� �� ���\n"); 
			//�ݺ����� ���� tasks�迭�� ���� ���
			for (int i = 0; i < taskCount; i++) {
				printf("%d. %s \n", i + 1, tasks[i]);
			}
			printf("\n");
			break;
		case 4:
			//���Ḧ ���� ���� terminate�� 1�� �Է��Ͽ� 
			//�ڿ� ������ ���ǹ��� �̿��Ͽ� ���α׷� ����
			terminate = 1; 
			break;
		case 5:
			printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����): ");
			scanf_s("%d", &changeIndex);  //������ �� ���� �ε����� �Է¹���
			//�Էµ� ���۸� getchar()�� �̿��� ch�� �����ϴ� ������� 
			//���� �ڵ尡 �۵��ϴµ� ���ص��� �ʵ�����
			ch = getchar(); 
			printf("������ ������ �Է����ּ��� : ");
			//������ ������ �Է¹޴� scanf_s��
			scanf_s("%s", tasks[changeIndex - 1], (int)sizeof(tasks[taskCount])); 
			printf("������ �����Ǿ����ϴ�.");
			printf("\n");
			break;

		default:
			//�ռ� ���ǵ� 1~5���� ���ڸ� ������ �ٸ� ���ڰ� �ԷµǸ� 
			//�߸� �Է������� �˷��ִ� ����
			printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n"); 
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
			printf("������ �� á���ϴ�.\n");
			break;
		}
	}
}
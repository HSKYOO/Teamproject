#include <stdio.h>
#include <string.h>

struct List{
    char name[50]; // �̸�
    int num_people; // �ο���
    char phone[20]; // ��ȭ��ȣ
    int price; // ����
    int check; // ���� �Ϸ� ���� (0: �̰���, 1: ���� �Ϸ�)
    char time[30]; // �ð���
    char notes[100]; // �߰� ����
};

struct List list[100]; // ���� ������ ������ �迭
int numRe = 0; // ���� ���� ���� ����

void delete() {

    char name[50];
    char phone[50];
    printf("������ �������� �̸��� �Է��ϼ���.");
    scanf("%s", name);
    printf("������ �������� ��ȭ��ȣ�� �Է��ϼ���.");
    scanf("%s", phone);

//char* name, char* phone

    int i, j;
    for (i = 0; i < numRe; i++) {
        // �̸��� ��ȭ��ȣ�� ��ġ�ϴ� ���� ������ ã��
        if (strcmp(list[i].name, name) == 0 && strcmp(list[i].phone, phone) == 0) {
            
            for (j = i; j < numRe - 1; j++) {  // �����ϰ� �迭 ����
                list[j] = list[j+1];
            }
            numRe--;
            printf("���� ������ �����Ǿ����ϴ�.\n");
            return;
        }
    }
    printf("��ġ�ϴ� ���� ������ �����ϴ�.\n");
}
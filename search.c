#include "CRUD.h"
#include "setting.h"

void search(int mm, int dd, char guestName[]) {
    // ��¥ �ε��� ���
    int m = mm-1;
    int d =dd-1;
    int found = 0; // �� ���� ã�Ҵ��� ���θ� ��Ÿ���� ����

    
        printf("��¥: %d�� %d��\n", mm,dd);
        printf("�˻� ���:\n");

        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 12; j++) {
                if (dates[m][d].tables[i].customer[j].full == 1 && strcmp(dates[m][d].tables[i].customer[j].name, guestName) == 0) {
                     printf("���̺� ��ȣ: %d, �մ� �̸�: %s, �մ� ��ȭ��ȣ: %d,  ���ҿ���: %d, ������ ����: %d��\n",
                       i, dates[m][d].tables[i].customer[j].name, dates[m][d].tables[i].customer[j].phoneNum,
                       dates[m][d].tables[i].customer[j].isPaid,
                       dates[m][d].tables[i].customer[j].price);
                       found = 1; // �� ������ ã������ ǥ��
                       break;
                }
            }
        }
    if (!found) {
        printf("�ش� �մ��� ������ ã�� �� �����ϴ�.\n");
    }
}
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setting.h>

// struct CUSTOMER{
//     char name[SIZE];
//     int people;
//     int phoneNum;
//     int price;
//     int isPaid;
//     char time[SIZE];
//     char Menu[SIZE];
//     char extra[SIZE];
// };

// ���� ���� �Լ�
void saveList(struct List list[], int count) {
    FILE *fp;
    fp = fopen("reservation_list.txt", "w"); // ���� ����

    if (fp == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    // ���Ͽ� ���� ���� ����
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %s %d %d %s %s\n", list[i].name, list[i].num_people, list[i].phone, list[i].price, list[i].check, list[i].time, list[i].notes);
    }

    fclose(fp); // ���� �ݱ�
}

// ���� ��� �Լ�
void printList() {
    FILE *fp;
  //  struct Reservation list[MAX_LIST_SIZE];
    int count = 0;

    fp = fopen("reservation_list.txt", "r"); // ���� ����

    if (fp == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    // ���Ͽ��� ���� ���� �о����
    while (fscanf(fp, "%s %d %s %d %d %s %[^\n]"), list[count]->name, &list[count].num_people, list[count].phone, &list[count].price, &list[count].check, list[count].time, list[count].notes) != EOF) {
        count++;
    }

    fclose(fp); // ���� �ݱ�

    // ���� ���� ���
    printf("=============================================================\n");
    printf("��ȣ\t�̸�\t�ο���\t��ȭ��ȣ\t����\t���� �Ϸ�\t�ð���\t�߰� ����\n");
    printf("=============================================================\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%s\t%d\t%s\t%s\t%s\n", i + 1, list[i]->name, list[i].num_people, list[i].phone, list[i].price, list[i].check == 1 ? "O" : "X", list[i].time, list[i].notes);
    }
    printf("=============================================================\n");
}
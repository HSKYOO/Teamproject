// #include <stdio.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <setting.h>


// // ���� ���� �Լ�
// void saveList(day *day) {
//     char filename[100];
//     printf("������ ������ �̸��� �Է��ϼ���: ");
//     scanf("%s", filename);

//     FILE *fp;
//     fp = fopen(filename, "w"); // ����ڰ� �Է��� ���� �̸����� ���� ����

//     if (fp == NULL) {
//         printf("������ �� �� �����ϴ�.\n");
//         return;
//     }


//     // ���Ͽ� ���� ���� ����
//     for(int i=0; i<16; i++){
//         for(int j=0; j<12; i++){
//         printf("%s %d %d %d %d\n", day[mm-1][dd-1]->table[i]->customer[j]->name, day[mm-1][dd-1]->table[i]->customer[j]->people, day[mm-1][dd-1]->table[i]->customer[j]->phoneNum, day[mm-1][dd-1]->table[i]->customer[j]->price,day[mm-1][dd-1]->table[i]->customer[j]->isPaid);
//         }
//     }

//     fclose(fp); // ���� �ݱ�
// }

// // ���� ��� �Լ�
// void printList() {
//     FILE *fp;
//   //  struct Reservation list[MAX_LIST_SIZE];
//     int countt = 0;

//     fp = fopen("reservation_list.txt", "r"); // ���� ����

//     if (fp == NULL) {
//         printf("������ �� �� �����ϴ�.\n");
//         return;
//     }

//     // ���Ͽ��� ���� ���� �о����
//     while (fscanf(fp, "%s %d %s %d %d %s %[^\n]"), list[countt]->name, &list[countt].num_people, list[countt].phone, &list[count].price, &list[count].check, list[count].time, list[count].notes) != EOF) {
//         count++;
//     }

//     fclose(fp); // ���� �ݱ�

//     // ���� ���� ���
//     printf("=============================================================\n");
//     printf("��ȣ\t�̸�\t�ο���\t��ȭ��ȣ\t����\t���� �Ϸ�\t�ð���\t�߰� ����\n");
//     printf("=============================================================\n");
//     for (int i = 0; i < count; i++) {
//         printf("%d\t%s\t%d\t%s\t%d\t%s\t%s\t%s\n", i + 1, list[i]->name, list[i].num_people, list[i].phone, list[i].price, list[i].check == 1 ? "O" : "X", list[i].time, list[i].notes);
//     }
//     printf("=============================================================\n");
// }
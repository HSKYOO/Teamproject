#include "CRUD.h"
#include <string.h>


void listSeat(day *day) {

    int dd; // ��
    int mm; // ��

    printf("��¥�� �Է��ϼ���");
    scanf("%d %d", &mm, &dd);

    int m = mm-1;
    int d = dd-1;

    for(int i = 0; i < 16; i++) {
        printf("�¼� ��ȣ: %d\n", i + 1);
        printf("------------------------\n");

        for(int j=0; j<12; j++){
        if(day[m][d]->table[i]->customer[j]->people == 0) continue; // �ش� ���̺� �ο����� 0�̸� ���� ���� ������ ���

        if(day[m][d]->table[i]->customer[j]->phoneNum == day[m][d]->table[i]->customer[j-1]->phoneNum) continue; // �� �ð��� ���� �� ������ ��� ������ continue
        
            printf("�� ����:\n");
            printf("�̸�: %s\n", day[m][d]->table[i]->customer[j]->name);
            printf("�ο� ��: %d\n", day[m][d]->table[i]->customer[j]->people);
            printf("��ȭ��ȣ: %d\n", day[m][d]->table[i]->customer[j]->phoneNum);
            printf("����: %d\n", day[m][d]->table[i]->customer[j]->price);
            printf("���� ����: %d\n", day[m][d]->table[i]->customer[j]->isPaid);
            printf("���� �ð�: %s\n", day[m][d]->table[i]->customer[j]->time);
            printf("�޴�: %s\n", day[m][d]->table[i]->customer[j]->Menu);
            printf("�߰� ��û����: %s\n", day[m][d]->table[i]->customer[j]->extra);
            printf("------------------------\n");
        }
    }
}
void addSeat(day *day, bunsik *menu){

    int dd; // ��
    int mm; // ��

    printf("��¥�� �Է��ϼ���");
    scanf("%d %d", &mm, &dd);

    int m = mm-1;
    int d = dd-1;

    // �̹� ������ �� �� ���̸� return
    if(day[m][d]-> full) {
        printf("%d�� %d���� �����Ͻ� �� �����ϴ�.", mm,dd);
        return;
    }

    int seatNum;
    //�¼� �Է�
    printf("���� �¼� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &seatNum);

    // //�̹� ������ �� �� �¼��̸� return
    // if(day[m][d]->table[seatNum-1]->s_index != 0) {
    //     printf("���� �� �� ���� �¼��Դϴ�.\n");
    //     return;
    // }


///////////////////////////////���� ������ �ð� �����ֱ�!

    int clock; //���� ���� �ð�
    int during; //��ð� ���� �Ұ���
    printf("������ �ð��� �����ϼ���: ");
    scanf("%d", &clock);
    printf("��ð� ���� �Ͻ� �ǰ���?");
    scanf("%d", &during);


    char name[50];

    printf("�� ������ �Է��ϼ���.\n");
    printf("----------------------\n");
    printf("�̸� : ");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    getchar();
    strcpy(day[m][d]->table[seatNum-1]->customer[clock-1]->name, name);
    printf("�ο� �� : ");
    scanf("%d", &day[m][d]->table[seatNum-1]->customer[clock-1]->people);
    getchar();
    printf("��ȭ��ȣ : ");
    scanf("%d", &day[m][d]->table[seatNum-1]->customer[clock-1]->phoneNum);
    printf("���� ����(1: ���� �Ϸ�, 0: ������) : ");
    scanf("%d", &day[m][d]->table[seatNum-1]->customer[clock-1]->isPaid);
    /////////////////////////////////////////////

     printf("�޴��� �Է��ϼ���:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s: %d��\n", menu[i]->foodName, menu[i]->foodPrice);
    }

    printf("�޴� ��ȣ�� �����ϼ���: ");
    int menuNum;
    scanf("%d", &menuNum);
    if (menuNum < 1 || menuNum > 4) {
        printf("�߸��� �޴� ��ȣ�Դϴ�.\n");
        return;
    }

    strcpy(day[m][d]->table[seatNum-1]->customer[clock-1]->Menu, menu[menuNum - 1]->foodName);

    day[m][d]->table[seatNum-1]->customer[clock-1]->price = menu[menuNum - 1]->foodPrice * day[m][d]->table[seatNum-1]->customer[clock-1]->people;

    ///////////////////////////////////////////
    printf("�߰� ��û������ �Է��ϼ��� : ");
    scanf("%s", day[m][d]->table[seatNum-1]->customer[clock-1]->extra);


//������ ��� �ð��� 1�� ǥ����.
    int k = clock-1;
    for(int i=0; i<during; i++){
        day[m][d]->table[seatNum-1]->customer[k]->nop = 1;
        k++;
    }

// �ش� ���� ���̺� ������ �� ���� ���̺� ����ü�� �ִ� s_index�� 1�� ���� �� �̻� ������ �� �� ������ �Ѵ�.
int p = 0;
for(int i=0; i<12; i++){
    if(day[m][d]->table[seatNum-1]->customer[i]->nop == 1) p++;
}
if(p==12) day[m][d]->table[seatNum-1]->s_index =1;

   
// �Ϸ� ǥ��
    printf("������ �Ϸ�Ǿ����ϴ�.\n");
}


void updateSeat(day *day) {

    int dd; // ��
    int mm; // ��

    printf("��¥�� �����Ͻü���(��/��): ");
    scanf("%d %d", &mm, &dd);

    int m = mm-1;
    int d = dd-1;


    int seatNum, choice, addedTime, timeDiff;
    printf("������ �¼� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &seatNum);

    
    if (day[m][d]->table[seatNum-1]->s_index== 0) {
        printf("��� ���� �¼��� �ƴմϴ�.\n");
        return;
    }

    int t = seatNum-1;

    
    int now;
    printf("���� ���� ��ȭ��ȣ�� �Է��ϼ���.");
    scanf("%d", &now);
    
    printf("[1] �� ���� ����\n[2] �޴� ����\n[3] �ð� �߰�/���\n");
    printf("���ϴ� �۾��� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &choice);

            char name1[50];
            int people1;
            int phoneNum1;
            int price1;
            int isPaid1;

    switch (choice) {
        case 1:

          
            for(int i=0; i<12; i++) {
                
            }
            printf("������ �� ������ �Է��ϼ���.\n");
            printf("�̸� : ");
            scanf("%s", name1);
            printf("�ο� �� : ");
            scanf("%d", &people1);
            printf("��ȭ��ȣ : ");
            scanf("%d", &phoneNum1);
            printf("���� : ");
            scanf("%d", &price1);
            printf("���� ����(1: ���� �Ϸ�, 0: ������) : ");
            scanf("%d", &isPaid1);

            for(int i=0; i<12; i++) {
                if(day[m][d]->table[t]->customer[i]->phoneNum == now){
                    strcpy(day[m][d]->table[t]->customer[i]->name, name1);
                    day[m][d]->table[t]->customer[i]->people = people1;
                    day[m][d]->table[t]->customer[i]->phoneNum = phoneNum1;
                    day[m][d]->table[t]->customer[i]->price =price1;
                    day[m][d]->table[t]->customer[i]-> isPaid =isPaid1;
                }
            }
            break;
        case 2:

            // for(int i=0; i<12; i++) {
            //     if(day[m][d]->table[t]->customer[i]->phoneNum == now){
            //         strcpy(day[m][d]->table[t]->customer[i]->name, name);
            //         day[m][d]->table[t]->customer[i]->people = people;
            //         day[m][d]->table[t]->customer[i]->phoneNum = phoneNum;
            //         day[m][d]->table[t]->customer[i]->price =price;
            //         day[m][d]->table[t]->customer[i]-> isPaid =isPaid;
            //     }
            // }
            // printf("������ �޴��� �Է��ϼ��� : ");
            // scanf("%s", cust[t]->Menu);
            // printf("�߰� ��û������ �Է��ϼ��� : ");
            // scanf("%s", cust[t]->extra);
            break;
        case 3:
            printf("������ �ð��� �Է��ϼ���(����: �ð�) : ");
            scanf("%d", &timeDiff);
          //  table[t]->time += timeDiff;
            if (timeDiff > 0) {
                printf("%d�ð��� �߰��Ǿ����ϴ�.\n", timeDiff);
            } else if (timeDiff < 0) {
                printf("%d�ð��� ��ҵǾ����ϴ�.\n", -timeDiff);
            } else {
                printf("�ð� ������ �����ϴ�.\n");
            }
            break;
        default:
            printf("�߸��� �Է��Դϴ�.\n");
            break;
    }
}


void deleteSeat(day *day){
     int dd;
    int mm;

    printf("��¥�� �Է��ϼ��� : ");
    scanf("%d %d", &mm, &dd);

    int seatNum;
    printf("������ �¼� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &seatNum);

    if (day[mm-1][dd-1]->table[seatNum-1]->s_index == 0) {
        printf("�ش� �¼��� �̹� ����ֽ��ϴ�.\n");
        return;
    }

    for (int i = 0; i < 12; i++) {
        if (day[mm-1][dd-1]->table[seatNum-1]->customer[i] != NULL) {
            day[mm-1][dd-1]->table[seatNum-1]->customer[i] = NULL;
        }
    }

    day[mm-1][dd-1]->table[seatNum-1]->s_index = 0;
    printf("%d�� �¼��� �����Ǿ����ϴ�.\n", seatNum);

}



void UpdateMenu(bunsik *menu){
    strcpy(menu[0]->foodName, "ChickenSkewer");
    menu[0]->foodPrice = 4000;
    menu[0]->count = 0;

    strcpy(menu[1]->foodName, "Ramen");
    menu[1]->foodPrice = 8500;
    menu[1]->count = 0;

    strcpy(menu[2]->foodName, "Gimbob");
    menu[2]->foodPrice = 3000;
    menu[2]->count = 0;

    strcpy(menu[3]->foodName, "Tteokbokki");
    menu[3]->foodPrice = 7000;
    menu[3]->count = 0;
}
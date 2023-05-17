#include "CRUD.h"

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
void addSeat(day *day){

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

    //�̹� ������ �� �� �¼��̸� return
    if(day[m][d]->table[seatNum-1]->s_index != 0) {
        printf("���� �� �� ���� �¼��Դϴ�.\n");
        return;
    }


///////////////////////////////���� ������ �ð� �����ֱ�!

    int clock; //���� ���� �ð�
    int during; //��ð� ���� �Ұ���
    printf("������ �ð��� �����ϼ���: ");
    scanf("%d", &clock);
    printf("��ð� ���� �Ͻ� �ǰ���?");
    scanf("%d", &during);



    printf("�� ������ �Է��ϼ���.\n");
    printf("----------------------\n");
    printf("�̸� : ");
    scanf("%s", day[m][d]->table[seatNum-1]->customer[clock-1]->name);
    printf("�ο� �� : ");
    scanf("%d", &day[m][d]->table[seatNum-1]->customer[clock-1]->people);
    printf("��ȭ��ȣ : ");
    scanf("%d", &day[m][d]->table[seatNum-1]->customer[clock-1]->phoneNum);
    printf("���� : ");
    scanf("%d", &day[m][d]->table[seatNum-1]->customer[clock-1]->price);
    printf("���� ����(1: ���� �Ϸ�, 0: ������) : ");
    scanf("%d", &day[m][d]->table[seatNum-1]->customer[clock-1]->isPaid);
    printf("�޴��� �Է��ϼ��� : ");
    scanf("%s", day[m][d]->table[seatNum-1]->customer[clock-1]->Menu);
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
    
    printf("[1] �� ���� ����\n[2] �޴� ����\n[3] �ð� �߰�/���\n");
    printf("���ϴ� �۾��� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("������ �� ������ �Է��ϼ���.\n");
            printf("�̸� : ");
            scanf("%s", cust[t]->name);
            printf("�ο� �� : ");
            scanf("%d", &cust[t]->people);
            printf("��ȭ��ȣ : ");
            scanf("%d", &cust[t]->phoneNum);
            printf("���� : ");
            scanf("%d", &cust[t]->price);
            printf("���� ����(1: ���� �Ϸ�, 0: ������) : ");
            scanf("%d", &cust[t]->isPaid);
            break;
        case 2:
            printf("������ �޴��� �Է��ϼ��� : ");
            scanf("%s", cust[t]->Menu);
            printf("�߰� ��û������ �Է��ϼ��� : ");
            scanf("%s", cust[t]->extra);
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

void addOrder(tableForm *table){

}
void deleteSeat(tableForm *table){
    int seatNum;
    printf("������ �¼� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &seatNum);

    if (table[seatNum-1]->s_index == 0) {
        printf("�ش� �¼��� �̹� ����ֽ��ϴ�.\n");
        return;
    }

    table[seatNum-1]->s_index = 0;
    printf("%d�� �¼��� �����Ǿ����ϴ�.\n", seatNum);
}

#include "CRUD.h"

void listSeat(tableForm *table){
    printf("�߰����ּ���\n");
}
void addSeat(tableForm *table){
    int seatNum;
    //�¼� �Է�
    printf("�߰��� �¼� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &seatNum);

    //�̹� ������� �¼��̸� ǥ��
    if(table->s_index[seatNum-1] != 0) {
        printf("�̹� ������� �¼��Դϴ�.\n");
        return;
    }
    //�¼� �߰�
    table->s_index[seatNum-1] = 1;
    //�ð� �߰�(�߰��ؾߵ�!)
    //(�ð� �߰� �ڵ�)

    // �Ϸ� ǥ��
    printf("%d�� �¼��� �߰��Ǿ����ϴ�.\n", seatNum);
}
void updateSeat(tableForm *table, customer *cust) {
    int seatNum, choice, addedTime, timeDiff;
    printf("������ �¼� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &seatNum);

    if (table->s_index[seatNum - 1] == 0) {
        printf("��� ���� �¼��� �ƴմϴ�.\n");
        return;
    }

    printf("[1] �� ���� ����\n[2] �޴� ����\n[3] �ð� �߰�/���\n");
    printf("���ϴ� �۾��� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("������ �� ������ �Է��ϼ���.\n");
            printf("�̸� : ");
            scanf("%s", cust->name);
            printf("�ο� �� : ");
            scanf("%d", &cust->people);
            printf("��ȭ��ȣ : ");
            scanf("%d", &cust->phoneNum);
            printf("���� : ");
            scanf("%d", &cust->price);
            printf("���� ����(1: ���� �Ϸ�, 0: ������) : ");
            scanf("%d", &cust->isPaid);
            break;
        case 2:
            printf("������ �޴��� �Է��ϼ��� : ");
            scanf("%s", cust->Menu);
            printf("�߰� ��û������ �Է��ϼ��� : ");
            scanf("%s", cust->extra);
            break;
        case 3:
            printf("������ �ð��� �Է��ϼ���(����: �ð�) : ");
            scanf("%d", &timeDiff);
            table->time += timeDiff;
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

    if (table->s_index[seatNum-1] == 0) {
        printf("�ش� �¼��� �̹� ����ֽ��ϴ�.\n");
        return;
    }

    table->s_index[seatNum-1] = 0;
    printf("%d�� �¼��� �����Ǿ����ϴ�.\n", seatNum);
}

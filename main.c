#include "CRUD.h"

void showMenu();

int main(){
    tableForm table = {0};
    customer client = {0};
    int selc;
    
    label:
    while(1){
        showMenu();
        printf("���� => ");
        scanf("%d", &selc);

        switch(selc){
            //���� ��Ȳ
            case 1:
                listSeat(&table);
                break;
            //���� �߰�
            case 2:
                addSeat(&table);
                break;
            //���� ����
            case 3:
                updateSeat(&table, &client);
                break;
            //���� ����
            case 4: 
                deleteSeat(&table);
                break;
            //���� �ҷ�����(from txt file)
            case 5:

                break;
            //����� �� ���� ��ȸ
            case 6:

                break;
            //����� Ȯ��
            case 7:

                break;
            //�������� Ȯ��
            case 8:

                break;
            //�޾���¥ ����
            case 9:

                break;
            case 10:
                break;

            default:
                printf("�߸��� ��ȣ�� �Է��ϼ̽��ϴ�.");
                break;
        }
    }
    return 0;
}

//�޴�â 
void showMenu(){
    printf("����������������������������������������\n");
    printf("��       �޴�       ��\n");
    printf("����������������������������������������\n");
    printf("�� 1. ���� ��Ȳ     ��\n");
    printf("�� 2. ���� �߰�     ��\n");
    printf("�� 3. ���� ����     ��\n");
    printf("�� 4. ���� ����     ��\n");
    printf("�� 5. ���� �ҷ����� ��\n");
    printf("�� 6. �� ���� ��ȸ��\n");
    printf("�� 7. ����� Ȯ�� ��\n");
    printf("�� 8. �������� Ȯ�� ��\n");
    printf("�� 9. �޾���¥ ���� ��\n");
    printf("����������������������������������������\n");
}

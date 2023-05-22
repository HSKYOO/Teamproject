#include "setting.h"

void initialize_queue(my_queue *queue) {
    queue->front = 0;
    queue->rear = -1;
}

void insert_q(my_queue *queue, Customer x) {
    if ((queue->rear + 1) % Q_SIZE == queue->front) {
        printf("[�߰� ����] ��� ����� �� ���ֽ��ϴ�\n");
        return;
    }

    queue->rear = (queue->rear + 1) % Q_SIZE;
    queue->q[queue->rear] = x;
    x.isQueued++;
}

void delete_q(my_queue *queue) {
    if (queue->front == (queue->rear + 1) % Q_SIZE) {
        printf("[���� ����] ��� ����� ����ֽ��ϴ�\n");
        return -1;
    }
}

bool queue_full(my_queue *queue) {
    return (queue->rear + 1) % Q_SIZE == queue->front;
}

bool queue_empty(my_queue *queue) {
    return queue->front == (queue->rear + 1) % Q_SIZE;
}

void showQueue(my_queue *queue){
    int count;
    int month;
    printf("��ȸ �ϰ���� ���� �Է��ϼ���: ");
    scanf("%d",&month);

    //��Ⱑ �����ϴ� ��¥�� ���̺� �մ��� ã��(��¥�� ����ϱ� ���ؼ�)
    
    for(int i = 0; i < 31; i++){
        if(dates[month-1][i].isQueued > 0){
            //[��¥]
            printf("[%d�� %d��]\n",month,i+1);
        }
        for(int j = 0; j < MAX_TABLES; j++){
            for(int n = 0; n < MAX_CUSTOMERS; n++){
                if(dates[month][i].tables[j].customer[n].isQueued > 0){
                    //[�ð�] [���̺� No] [�̸�] ���
                    printf("[%s] [%d] [%s]",dates[month][i].tables[j].customer[n].orderedTime,dates[month][i].tables[j].customer[n].tableNum,dates[month][i].tables[j].customer[n].name);
                }
            }
        }
    }
        
    
    
    
}



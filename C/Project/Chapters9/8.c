#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct List //һ����������
{
    int data;
    struct List *next;
};

int main()
{
    struct List *Add_List(struct List * head);
    void Print_List(struct List * head, int i);
    void Change_one_node(struct List * head);
    void Insert_one_node(struct List * head);
    void Delete_one_node(struct List * head);

    struct List *head = NULL;
    char c;
    int i = 0, num = 0;

    while (num != 6)
    {
        printf("1. ��ӽڵ�\n");
        printf("2. ��ʾ��ǰ����\n");
        printf("3. �޸Ľڵ�����\n");
        printf("4. ����һ���ڵ�\n");
        printf("5. ɾ��һ���ڵ�\n");
        printf("6. �˳�\n");
        scanf("%d", &num);

        system("cls");
        switch (num)
        {
        case 1: //����һ������
            printf("��ӽڵ�? (Y or N)\n");
            scanf(" %c", &c);
            while ((c == 'Y') || (c == 'y'))
            {
                head = Add_List(head);
                printf("������ӽڵ�? (Y or N)\n");
                scanf(" %c", &c);
                i++;
            }
            printf("������%d ���ڵ�\n\n", i);
            break;
        case 2: //��ʾ��ǰ����
            if (i == 0)
            {
                printf("��ǰ����Ϊ��");
                break;
            }
            Print_List(head, i);
            break;
        case 3: //�޸Ľڵ�����
            if (i == 0)
            {
                printf("��ǰ����Ϊ��");
                break;
            }
            Print_List(head, i);
            Change_one_node(head);
            break;
        case 4: //����ڵ�

        case 5: //ɾ���ڵ�
            if (i == 0)
            {
                printf("��ǰ����Ϊ��");
                break;
            }
            Print_List(head, i);
            Delete_one_node(head);
            i--;
            break;
        default:
            break;
        }
    }

    return 0;
}

struct List *Add_List(struct List *head)
{
    struct List *pNew = NULL, *p1 = head;
    int data;

    pNew = (struct List *)malloc(sizeof(struct List)); //����ռ�
    if (pNew == NULL)
    {
        printf("���񲻶Ծ�Ѽ������ʧ��Ѽ");
        exit(0);
    }

    if (head == NULL) //�ж��ǲ��ǿ�����
    { 
        head = pNew;
    }
    else
    {
        while (p1->next != NULL) //ʹp1�ƶ�������β��
        {
            p1 = p1->next;
        }
        p1->next = pNew;   //ʹ��һ���ڵ��ָ���½ڵ�
    }
    printf("Plz Input data: ");
    scanf("%d", &data);
    printf("\n");
    pNew->data = data;
    pNew->next = NULL;
    return head;
}

void Print_List(struct List *head, int i)
{
    struct List *p = head;
    int j = 1;

    printf("��ǰ������%d���ڵ㣬�ֱ�Ϊ: \n", i);
    while (p != NULL)
    {
        printf("�ڵ�%dΪ: ", i);
        j++;
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("\n");
}

void Change_one_node(struct List *head)
{
    struct List *p = head;
    int i = 0, j;

    printf("����Ҫ�ı��ĸ��ڵ㣿 ");
    scanf("%d", &j);
    while (i < j && p != NULL) //ʹpָ��Ҫ�޸ĵĽڵ�
    {
        p = p->next;
        i++;
    }

    if (p != NULL)
    {
        printf("�������޸�֮���ֵ:\n");
        scanf("%d", &p->data);
    }
    else
    {
        printf("�ڵ㲻���ڣ�\n");
    }
}

void Insert_one_node(struct List * head)
{

}

void Delete_one_node(struct List *head)
{
    struct List *p = head, *pr = head;
    int a = 0, n = 0;

    printf("����ɾ���Ǹ��ڵ�? ");
    scanf("%d", &n);
    while ((a < n) && (p != NULL))
    {
        pr = p;
        p = p->next;
        a++;
    }
    if (p != NULL)
    {
        pr->next = p->next;
        free(p);
        printf("ɾ�����\n");
    }
    else
    {
        printf("�ڵ㲻���ڣ�\n");
    }
}
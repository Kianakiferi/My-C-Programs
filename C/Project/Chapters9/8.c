#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct List //一个简易链表
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
        printf("1. 添加节点\n");
        printf("2. 显示当前链表\n");
        printf("3. 修改节点数据\n");
        printf("4. 插入一个节点\n");
        printf("5. 删除一个节点\n");
        printf("6. 退出\n");
        scanf("%d", &num);

        system("cls");
        switch (num)
        {
        case 1: //创建一个链表
            printf("添加节点? (Y or N)\n");
            scanf(" %c", &c);
            while ((c == 'Y') || (c == 'y'))
            {
                head = Add_List(head);
                printf("继续添加节点? (Y or N)\n");
                scanf(" %c", &c);
                i++;
            }
            printf("创建了%d 个节点\n\n", i);
            break;
        case 2: //显示当前链表
            if (i == 0)
            {
                printf("当前链表为空");
                break;
            }
            Print_List(head, i);
            break;
        case 3: //修改节点数据
            if (i == 0)
            {
                printf("当前链表为空");
                break;
            }
            Print_List(head, i);
            Change_one_node(head);
            break;
        case 4: //插入节点

        case 5: //删除节点
            if (i == 0)
            {
                printf("当前链表为空");
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

    pNew = (struct List *)malloc(sizeof(struct List)); //分配空间
    if (pNew == NULL)
    {
        printf("好像不对劲鸭，创建失败鸭");
        exit(0);
    }

    if (head == NULL) //判断是不是空链表
    { 
        head = pNew;
    }
    else
    {
        while (p1->next != NULL) //使p1移动到链表尾部
        {
            p1 = p1->next;
        }
        p1->next = pNew;   //使上一个节点的指向新节点
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

    printf("当前链表有%d个节点，分别为: \n", i);
    while (p != NULL)
    {
        printf("节点%d为: ", i);
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

    printf("你想要改变哪个节点？ ");
    scanf("%d", &j);
    while (i < j && p != NULL) //使p指向要修改的节点
    {
        p = p->next;
        i++;
    }

    if (p != NULL)
    {
        printf("请输入修改之后的值:\n");
        scanf("%d", &p->data);
    }
    else
    {
        printf("节点不存在！\n");
    }
}

void Insert_one_node(struct List * head)
{

}

void Delete_one_node(struct List *head)
{
    struct List *p = head, *pr = head;
    int a = 0, n = 0;

    printf("你想删除那个节点? ");
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
        printf("删除完毕\n");
    }
    else
    {
        printf("节点不存在！\n");
    }
}
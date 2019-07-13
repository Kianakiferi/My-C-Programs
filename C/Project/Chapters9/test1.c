#include <stdio.h>
#include <stdlib.h>
struct link *AppendNode(struct link *head);
void DisplayNode(struct link *head);
void DeleteMemory(struct link *head);
//����ṹ��
struct link
{
	int data;		   //����������
	struct link *next; //����ָ����
};
int main()
{
	int i = 0; //����i����¼�����Ľڵ���
	char c;
	struct link *head = NULL; //����ͷָ�룬��ʼ��ΪNULL
	printf("DO you wang to append a new node(Y or N)?");
	scanf(" %c", &c);
	while (c == 'Y' || c == 'y')
	{							 //���ȷ��������ӽ��
		head = AppendNode(head); //ͨ�������������ĵ�ַ��AppendNode�������ص��������ͷָ��
								 //���Ը���ͷָ��ָ��ĵ�ַ����ȡ�����б��������
		DisplayNode(head);		 //����ͷָ���ӡ����
		printf("DO you want to append a new node(Y or N)?");
		scanf(" %c", &c);
		i++;
	}
	printf("%d new nodes hava been appended!\n", i);
	DeleteMemory(head); //�ͷ�ռ�õ��ڴ�
}
struct link *AppendNode(struct link *head)
{									   //���������ڵ㺯��
	struct link *p = NULL, *pr = head; //����pָ�룬��ʼ��ΪNULL������prָ�룬ͨ��prָ������ָ����ֵ
	int data;
	p = (struct link *)malloc(sizeof(struct link)); //Ϊָ��p�����ڴ�ռ䣬�����������Ϊp���´����Ľڵ�
	if (p == NULL)
	{ //��������ڴ�ʧ�ܣ����˳�����
		printf("NO enough momery to allocate!\n");
		exit(0);
	}
	if (head == NULL)
	{			  //���ͷָ��ΪNULL,˵�����������ǿձ�
		head = p; //ʹheadָ��ָ��p�ĵ�ַ(p�Ѿ�ͨ��malloc�������ڴ棬�����е�ַ��
	}
	else
	{   //��ʱ�����Ѿ���ͷ�ڵ� ����һ��ִ����AppendNode����
		//ע���������ǵڶ�����ӽڵ�
		//��Ϊ��һ�����ͷ�ڵ�ʱ��pr = head����ͷָ��һ��ָ��ͷ�ڵ�ĵ�ַ
		while (pr->next != NULL)
		{				   //��prָ��ĵ�ַ������ʱ��p��ָ����ΪNULL(��p����β�ڵ�)
			pr = pr->next; //ʹprָ��ͷ�ڵ��ָ����
		}
		pr->next = p; //ʹpr��ָ����ָ���¼��ڵ�ĵ�ַ����ʱ��nextָ������ͷ�ڵ��ָ����
	}
	printf("Input node data:");
	scanf("%d", &data);
	p->data = data; //��p��������ֵ
	p->next = NULL; //����ӵĽڵ�λ�ڱ�β����������ָ����ΪNULL
	return head;	//����head�ĵ�ַ
}
void DisplayNode(struct link *head)
{						   //�����������ӡ����
	struct link *p = head; // ����pָ��ʹ��ָ��ͷ�ڵ�
	int j = 1;			   //����j��¼���ǵڼ�����ֵ
	while (p != NULL)
	{ //��Ϊp = p->next,����ֱ��β�ڵ��ӡ����
		printf("%5d%10d\n", j, p->data);
		p = p->next; //��Ϊ�ڵ��Ѿ������ɹ�������p��ָ����ͷ�ڵ�ָ����һ���ڵ�(ÿһ���ڵ��ָ����ָ������һ���ڵ�)
		j++;
	}
}
void DeleteMemory(struct link *head)
{									   //�ͷ���Դ����
	struct link *p = head, *pr = NULL; //����pָ��ָ��ͷ�ڵ�
	while (p != NULL)
	{				 //��p��ָ����ΪNULL
		pr = p;		 //��ÿһ���ڵ�ĵ�ַ��ֵ��prָ��
		p = p->next; //ʹpָ����һ���ڵ�
		free(pr);	//�ͷŴ�ʱprָ��ڵ���ڴ�
	}
}

void deleteNode(struct Stu *head, int n)
{ //ɾ��n���Ľڵ�
	struct Stu *p = head, *pr = head;
	int i = 0;
	while (i < n && p != NULL)
	{				 //����ָ���ڵ㣬��ʱpָ��ָ���ڵ㣬prָ����һ�ڵ�
		pr = p;		 //��p�ĵ�ַ��ֵ��pr
		p = p->next; //pָ����һ�ڵ�
		i++;
	}
	if (p != NULL)
	{ //��p��Ϊ��ʱ����p����ָ��β�ڵ�֮��Ľڵ�
		pr->next = p->next;
		free(p);
	}
	else
	{
		printf("�ڵ㲻���ڣ�\n");
	}
}
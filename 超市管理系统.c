#include<string.h>
#include<windows.h>
#include<conio.h>
#include <stdlib.h>
#include<stdio.h>
#include<malloc.h>
#define N "/t��Ʒ���ƣ�%-12s   ��Ʒ���:%-3d   �۸�:%-5d   �������ڣ�%-5d   �����ڣ�%-5d\n"

FILE* fp;

struct Users {
	char name[20];
	char code[10];
}customer;
typedef struct shopcart
{
	char name[20];
	int price;
	struct shopcart* next;
}shopcart;

typedef struct shangpin
{
	char name[20];
	int number;
	int price;
	int shengchanriqi;
	int baozhiqi;
	struct shangpin* next;
}shangpin;
void xiugai();
void tianjia();
void output(shangpin* head);
//void output_shopcart(shopcart* head);
shangpin* shuchu();
//shopcart* shuchu_2();
shangpin* creatnode();
//void creat_shopcart();
void deletes();
//shopcart* delete_shopcart(shopcart* head);
void chaxun();
void baobiao();
//int calculate(shopcart* head);
void yincode(char megc[]);
void login();
void customers();
void mmmm();
void manager();
void registers();
int managermenu();
//int shopcart_menu();
int customermenu();
void loginface();


//��ʾ������Ʒ��Ϣ 
void output(shangpin* head)
{
	shangpin* p;
	p = head;
	while (p != NULL)
	{
		printf(N, p->name, p->number, p->price, p->shengchanriqi, p->baozhiqi);
		p = p->next;
	}

}
//��ʾ���ﳵ��Ʒ 
//void output_shopcart(shopcart *head)
//{
//	shopcart *p;
//	if (head!=NULL)
//	{
//		p=head;
//		while(p!=NULL)
//		{
//			printf("%s          %d",p->name,p->price);
//			p=p->next;
//		}
//	}
//}
//���ﳵ�ļ������Ʒ
//shopcart *shuchu_2()
//{
//	shopcart *head,*p1,*p2;
//	FILE*f3,*f4;
//	char ch;
//	f3=fopen("��Ʒ��Ϣ.txt","r");
//	f4=fopen("��Ʒ��Ϣ.txt","r");
//	head=(shopcart *)malloc(sizeof(shopcart));
//	head->next=NULL;
//	p1=head;
//	ch=fgetc(f4);
//	if(ch==EOF){
//		return NULL;
//	}
//	while(!feof(f3))
//	{
//		p2=(shopcart*)malloc(sizeof(shopcart));
//		fscanf(f3,"%s %d\n",&p1->name,&p1->price);
//		p1->next =p2;
//		p1=p2;
//	} 
//	
//	p1->next =NULL;
//	fclose(f3);
//	return head;
//	
//}  
//�ļ�������Ʒ
void shuru(shangpin* head)
{
	shangpin* p;
	p = head;
	FILE* fp;
	fp = fopen("��Ʒ��Ϣ.txt", "wt");
	if ((fp = fopen("��Ʒ��Ϣ.txt", "wt")) == NULL)
	{
		printf("\t\t\t�޷����ļ�");
		getch();
		exit(0);
	}
	for (p = head; p != NULL; p = p->next)
	{
		fprintf(fp, "%s %d %d %d %d\n", p->name, p->number, p->price, p->shengchanriqi, p->baozhiqi);
	}
	fclose(fp);
}
//�ļ������Ʒ

shangpin* shuchu()
{
	shangpin* head, * p1, * p2;
	FILE* f1, * f2;
	char ch;
	f1 = fopen("��Ʒ��Ϣ.txt", "r");
	f2 = fopen("��Ʒ��Ϣ.txt", "r");
	head = (shangpin*)malloc(sizeof(shangpin));
	head->next = NULL;
	p1 = head;
	ch = fgetc(f2);
	if (ch == EOF) {
		return NULL;
	}
	while (!feof(f1))
	{
		p2 = (shangpin*)malloc(sizeof(shangpin));
		fscanf(f1, "%s %d %d %d %d\n", &p2->name, &p2->number, &p2->price, &p2->shengchanriqi, &p2->baozhiqi);
		p1->next = p2;
		p1 = p2;
	}

	p1->next = NULL;
	fclose(f1);
	return head;

}
//�����Ʒ��Ϣ 
shangpin* creatnode()
{
	shangpin* head;
	shangpin* p1;
	shangpin* p2;
	char ch;
	int n = 0;
	head = NULL;
	p1 = (shangpin*)malloc(sizeof(shangpin));
	p2 = (shangpin*)malloc(sizeof(shangpin));
	while (1)
	{
		printf("�Ƿ������Ʒ����ظ�Y/N:\n");
		rewind(stdin);
		scanf("%c", &ch);
		if (ch == 'N')
		{
			break;
		}

		printf("��������Ʒ���ƣ�\n");
		scanf("%s", &p1->name);
		printf("��������Ʒ��ţ�\n");
		scanf("%d", &p1->number);
		printf("��������Ʒ�۸�\n");
		scanf("%d", &p1->price);
		printf("��������Ʒ�������ڣ�\n");
		scanf("%d", &p1->shengchanriqi);
		printf("��������Ʒ�����ڣ�\n");
		scanf("%d", &p1->baozhiqi);
		n++;
		if (n == 1)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (shangpin*)malloc(sizeof(shangpin));
	}
	p2->next = NULL;
	return head;
}
//��ӹ��ﳵ��Ʒ
//void creat_shopcart()
//{
//	shopcart *p1,*p2,*head;
//	char ch;
//	int n=0;
//	head=NULL;
//	p1=(shopcart*)malloc(sizeof(shopcart));
//	p2=(shopcart*)malloc(sizeof(shopcart));
//	while(1)
//	{
//		printf("�Ƿ������Ʒ����ظ�Y/N:\n");
//		rewind(stdin); 
//		scanf("%c",&ch);
//		if(ch=='N')
//		{
//			break;
//		}
//		
//		printf("��������Ʒ���ƣ�\n");
//		scanf("%s",&p1->name);
//		printf("��������Ʒ��ţ�\n");
//		scanf("%f",&p1->price);
//		n++;
//		if(n==1)
//		{
//			head=p1;
//		}
//		else
//		{
//			p2->next-p1;
//		}
//		p2=p1;
//		p1=(shopcart*)malloc(sizeof(shopcart));
//	}
//	p2->next=NULL;
//	
//	
//} 
//�����Ʒ��Ϣ
void tianjia()
{
	shangpin* p, * head, * t;
	char n;
	int num, k = -1;
	head = shuchu();
	output(head->next);
	printf("\t\t\t�����������Ʒ�Ĵ���");
	scanf("%d", &num);
	for (p = head; p != NULL; p = p->next) {
		k++;
		if (k == num - 1) {
			t = (shangpin*)malloc(sizeof(shangpin));
			printf("\t\t\t������Ʒ���ƣ�");
			scanf("%s", &t->name);
			printf("\t\t\t������Ʒ��ţ�");
			scanf("%d", &t->number);
			printf("\t\t\t������Ʒ�۸�");
			scanf("%d",&t->price);
			printf("\t\t\t������Ʒ�������ڣ�");
			scanf("%d", &t->shengchanriqi);
			printf("\t\t\t������Ʒ�����ڣ�");
			scanf("%d", &t->baozhiqi);
			t->next = p->next;
			p->next = t;
			break;
		}
	}
	printf("\t\t\t��ӳɹ���\n");
	shuru(head->next);
	output(head->next);
}
//ɾ����Ʒ��Ϣ
void deletes()
{
	shangpin* p1, * p2, * t;
	shangpin* p;
	p = shuchu();
	char name[20];
	int n;
	int num;
	int flag = 0;
	printf("��ѡ��ɾ����ʽ��\n");
	printf("1 ������Ʒ��Ž���ɾ��\n2 ������Ʒ���ƽ���ɾ��\n");
	scanf("%d",&n);
	switch (n)
	{
	case 1:
		printf("��Ʒ��Ϣ���£�\n");
		output(p->next);
		printf("������Ҫɾ����Ʒ�ı�ţ�\n");
		scanf("%d", &num);
		for (t = p; t != NULL; t = t->next)
		{
			if (t->next->number == num)
			{
				printf("��Ʒ��Ϣ���£�\n");
				printf(N, t->next->name, t->next->number, t->next->price, t->next->shengchanriqi, t->next->baozhiqi);
				flag = 1;
				t->next=t->next->next;
				printf("ɾ���ɹ�����\n");
				break;
			}
		}
		if (flag == 0)
		{
			printf("\t\t\tδ���ҵ���Ʒ��Ϣ��");
		}
		
		shuru(p->next);
		output(p->next);
		break;
	case 2:
		printf("��Ʒ��Ϣ���£�\n");
		output(p->next);
		printf("������Ҫɾ����Ʒ�����ƣ�\n");
		scanf("%s", name);
		for (t = p; t != NULL; t->next)
		{
			if (strcmp(t->next->name, name) == 0)
			{
				printf("��Ʒ��Ϣ���£�\n");
				printf(N, t->next->name, t->next->number, t->next->price, t->next->shengchanriqi, t->next->baozhiqi);
				flag = 1;
				t->next=t->next->next;
				free(t);
				printf("ɾ���ɹ�����\n");
				break;

			}
		}
		if (flag == 0)
		{
			printf("\t\t\tδ���ҵ���Ʒ��Ϣ��");
		}
		shuru(p->next);
		output(p->next);

	

	}

}
//ɾ�����ﳵ��Ʒ
//shopcart* delete_shopcart(shopcart *head)
//{
//	shopcart *p1,*p2,*t;
//	p1=head;
//	char name[20];
//	int n;
//	int num;
//	int flag=0;
//	printf("��Ʒ��Ϣ���£�\n");
//	output(head);
//	printf("������Ҫɾ����Ʒ�����ƣ�\n");
//	scanf("%s",name);
//	for(t=p1;t!=NULL;t->next)
//	{
//		if(strcmp(t->name,name)==0)
//		{
//			printf("��Ʒ��Ϣ���£�\n");
//			printf("%s  %.2f",t->name,t->price);
//			p1->next=t;
//			p1->next=t->next;
//			free(t);
//			printf("ɾ���ɹ�����\n");
//			break; 
//					
//			}
//		}
//	if(flag==0)
//	{
//		printf("\t\t\tδ���ҵ���Ʒ��Ϣ��");
//	}
//	return head; 
//}
//
//
// 
//��ѯָ����Ʒ����Ϣ 
void chaxun()
{

	shangpin* p1, * p2, * t;
	p1 = shuchu();
	p1=p1->next;
	char name[20];
	int flag = 0;
	int num;
	int ch;
	printf("�������ѯ��ʽ��\n");
	printf("1 ���ձ�Ų�ѯ\n2 ������Ʒ���Ʋ�ѯ\n");
	scanf("%d", &ch);
	switch (ch)
	{
		case 1:
			printf("��������Ʒ��ţ�\n");
			scanf("%d", &num);
			for (t =p1; t != NULL; t=t->next)
			{
				if (t->number == num)
				{
					printf("��Ʒ��Ϣ���£�\n");
					printf(N, t->name, t->number, t->price, t->shengchanriqi, t->baozhiqi);
					flag = 1;
					break;
				}		
			}
			if (flag == 0)
			{
				printf("\t\t\t\tδ���ҵ���Ʒ��Ϣ��");
			}
			break;
		case 2:
			printf("��������Ʒ���ƣ�\n");
			scanf("%s", name);
			for (t =p1; t != NULL; t=t->next)
			{
				if (strcmp(t->name, name) == 0)
				{
					printf("��Ʒ��Ϣ���£�\n");
					printf(N, t->name, t->number, t->price, t->shengchanriqi, t->baozhiqi);
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				printf("\t\t\t\tδ���ҵ���Ʒ��Ϣ��");
			}
			break;
	}

}
//�޸���Ʒ��Ϣ
void xiugai()
{
	shangpin* h, * t, * p;
	int ch, j, flag = 0;
	char choice;
	char name[20];
	h = shuchu();
	h=h->next;
	printf("\t\t\t��������Ʒ���ƣ�");
	scanf("%s", name);
	for (t = h; t != NULL; t = t->next)
	{
		if (strcmp(t->name, name) == 0)
		{
			printf(N, t->name, t->number, t->price, t->shengchanriqi, t->baozhiqi);
			flag = 1;
			while (1)
			{
				printf("\t\t\tȷ���޸���Ʒ��Ϣ�𣿣�Y/N����");
				rewind(stdin);
				scanf("%c", &choice);
				if (choice == 'N')
				{
					break;
				}
				else
				{
					printf("\t\t\t������������Ʒ���ƣ�");
					scanf("%s", t->name);
					printf("\t\t\t������������Ʒ��ţ�");
					scanf("%d", &t->number);
					printf("\t\t\t������������Ʒ�۸�");
					scanf("%d", &t->price);
					printf("\t\t\t�����������������ڣ�");
					scanf("%d", &t->shengchanriqi);
					printf("\t\t\t���������뱣���ڣ�");
					scanf("%d", &t->baozhiqi);
					printf("\t\t\t�޸�������£�\n");
					printf(N, t->name, t->number, t->price, t->shengchanriqi, t->baozhiqi);

				}

			}
		}
		if (flag == 0)
		{
			printf("\t\t\tδ���ҵ���Ʒ��Ϣ��");
		}
		p = h;
		shuru(p);
		break;
	}

}
//��ӡ��Ʒ��Ϣ����
void baobiao()
{
	shangpin* p, * head;
	head = shuchu();
	head = head->next;
	printf("\t����Ʒͳ�ƺ����ɱ�������:\n");
	printf("\t\t\t------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t|                                                                                                                                        |\n");
	printf("\t\t\t| **%15s%15s%15s%15s%15s  ** |\n", "��Ʒ����", "��Ʒ���", "��Ʒ�۸�", "��Ʒ��������", "��Ʒ������");
	for (p = head; p != NULL; p = p->next)
	{
		printf("\t\t\t| **%15s%15d%15d%15d%15d  ** |\n", p->name, p->number, p->price, p->shengchanriqi, p->baozhiqi);
	}
	printf("\t\t\t|                                                                                                                                        |\n");
	printf("\t\t\t------------------------------------------------------------------------------------------------------------------------------------------\n");

}
//���� 
//int calculate(shopcart *head)
//{
//	int sum=0;
//	shopcart *p;
//	for(p=head;p!=NULL;p->next)
//	{
//		sum=sum+p->price;
//	}
//	return sum;
//}
//	

//�ܳ� 
void yincode(char megc[])
{
	int i = 0;
	while (i < 50) {
		megc[i] = getch();
		if (megc[i] == '\r') {
			break;
		}
		else if (megc[i] == '\b') {
			i = i - 1;
			printf("\b \b");
		}
		else {
			i = i + 1;
			printf("*");
		}
	}
	megc[i] = '\0';
}
//�û���¼ 
void login()
{
	char name[20];
	char code[20];
	int n;
	printf("�û���¼��\n");
	printf("�������û�����\n");
	scanf("%s", name);
	strcat(name, ".txt");
	fp = fopen(name, "r");
	if (fp == NULL) {
		printf("�û������ڣ���ע�᣺\n");
		printf("1 ע��\n2 ���µ�¼\n3 �˳�\n");
		n = getch();
		if (n == 1) {
			registers();
		}
		else if (n == 2) {
			login();
		}
		else {
			exit(0);
		}
	}
	do {
		printf("���������룺\n");
		yincode(code);
		fscanf(fp, "%s", customer.code);
		if (strcmp(customer.code, code) != 0) {
			printf("\n�������\n");
			fflush(stdin);
		}
		else {
			break;
		}
	} while (1);
}
//�˿ͽ����½��ע�� 
void customers()
{
	char n;
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t��ӭ����customer����ϵͳ1.0��\n");
    printf("\n\n\n\t\t\t\t\t\t��ѡ��\n");
    printf("\t\t\t\t\t\t\t1 �û���¼\n\t\t\t\t\t\t\t2 �û�ע��\n\t\t\t\t\t\t\t3 ������һ��\n");
    n=getch();
    if(n=='1'){
    	login();
    }
    else if(n=='2'){
    	system("CLS");
        registers();
 	}
    else{
  		system("CLS");
  		loginface() ; 
 	}
}

void mmmm()
{
	shangpin* p, * head, * p2;
	char ch;
	int a,b,c,d,e,f,g,h,i;
	while (1)
	{
		switch (managermenu())
		{
		case 1:
			system("CLS");
			fflush(stdin);
			printf("\t\tϵͳ����Ʒ��Ϣ���£�\n");
			p = shuchu();
			if (p == NULL) {
				printf("\t\t\tϵͳ������Ϣ��\n");
				printf("\t\t��Ҫ¼����Ʒ��Ϣ�𣿣�Y/N��");
				scanf("%c", &ch);
				if (ch == 'Y') {
					head = creatnode();
					shuru(head);
					output(head);
				}
			}
			else
			{
				p2 = p->next;
				output(p2);
			}
			printf("\t\t������ص��ײ˵�\n");
			a=getch();
			break;
		case 2:
			system("CLS");
			deletes();
			printf("\t\t\t��������ص��ײ˵�\n");
			b=getch();
			break;
		case 3:
			system("CLS");
			chaxun();
			printf("\t\t\t��������ص��ײ˵�\n");
			c=getch();
			break;
		case 4:
			system("CLS");
			xiugai();
			printf("\t\t\t��������ص��ײ˵�\n");
			d=getch();

			break;
		case 5:
			system("CLS");
			tianjia();
			printf("\t\t\t��������ص��ײ˵�\n");
			e=getch();
			break;
		case 6:
			system("CLS");
			baobiao();
			printf("\t\t\t��������ص��ײ˵�\n");
			f=getch();
			break;
		case 0:
			system("CLS");
			loginface();
			break;
			
		}
	}

}

//����Ա��¼ 
void manager()
{
	char code[20] = "123456";
	char n[20];
	int i = 0;
	do {
		printf("���������룺\n");
		yincode(n);
		if (strcmp(code, n) == 0) {
			printf("������ȷ����\n");
			i = 1;
			break;
		}
		else {
			printf("������󣡣�\n");
			break;
		}
	} while (1);
	if (i == 1) {
		mmmm();
	}
	else {
		loginface();
	}
}
//�û�ע�� 
void registers()
{
	char code[20], filename[20];

	while (1) {
		printf("\n�û�ע�᣺\n");
		printf("�������û�����");
		scanf("%s", customer.name);
		strcat(customer.name, ".txt");
		fp = fopen(customer.name, "r+");
		if (fp != NULL) {
			printf("\n�û��Ѵ��ڣ�\n");
			fclose(fp);
			login();
			break;
		}
		printf("\n���������룺\n");
		yincode(customer.code);
		printf("\nȷ�����룺\n");
		yincode(code);
		while (strcmp(customer.code, code) != 0) {
			printf("\n\t\t\t\t\t���벻һ�£����������룺\n");
			printf("\t\t\t\t\t���������룺");
			yincode(customer.code);
			printf("\n\t\t\t\t\tȷ�����룺");
			yincode(code);
		}
		fp = fopen(customer.name, "wt");
		if (fp == NULL) {
			printf("\n\t\t\t\t\tע��ʧ�ܣ�\n");
			exit(0);
		}
		else {
			system("cls");
			printf("\n\n\n\n\n\t\t\t\t\tע��ɹ���\n");
			fprintf(fp, "%s", customer.code);
			fclose(fp);
			Sleep(1);
			system("cls");
			customers();
			break;
		}
	}
	fclose(fp);
}
//����Ա���ܲ˵� 
int managermenu()
{
	char n;
	do
	{
		system("CLS");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t***********��ӭ�������managerϵͳ***********\n");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t||  1 �鿴ϵͳ����Ʒ��Ϣ                   ||\n");
		printf("\t\t\t\t||  2 �¼�ָ����Ʒ��Ϣ                     ||\n");
		printf("\t\t\t\t||  3 ��ѯָ����Ʒ��Ϣ                     ||\n");
		printf("\t\t\t\t||  4 �޸�ָ����Ʒ��Ϣ                     ||\n");
		printf("\t\t\t\t||  5 �����Ʒ                             ||\n");
		printf("\t\t\t\t||  6 ��Ʒ��Ϣ����                         ||\n");
		printf("\t\t\t\t||  0 �˳�                                 ||\n");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t��ѡ��1~6��");
		n = getch();
	} while (n < '0' || n>'6');
	return n - 48;

}
//���ﳵ���ܲ˵� 
//int shopcart_menu()
//{
//	char n;
//	printf("*********************************************************\n");
//	printf("1 ɾ�����ﳵ��Ʒ\n2 �ڹ��ﳵ�����Ʒ\n3 ��ʾ���ﳵ��Ʒ\n4 �˳�\n");
//	printf("��ѡ������Ҫ���ܵ����֣�\n");
//	n=getch();
//	return n-48;
//}
//�˿͹��ܲ˵� 
int customermenu()
{
	char n;
	do
	{
		system("CLS");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t***********��ӭ�������customerϵͳ**********\n");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t||  1 ���ﳵ                               ||\n");
		printf("\t\t\t\t||  2 ����                                 ||\n");
		printf("\t\t\t\t||  0 �˳�                                 ||\n");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t��ѡ��1~2��");
		n = getch();
	} while (n < '0' || n>'2');
	return n - 48;
}
//��¼���� 
void loginface()
{
	char n;
	printf("\n");
	printf("��ѡ����������ֱ�ʾ�����ݣ�\n");
	printf("1 ����Ա\n2 �˿�\n3 �˳�ϵͳ\n");
	printf("**************************************************************************\n");
	n = getch();
	if (n == '1') {
		manager();
	}
	else if (n == '2') {
		customers();
	}
	else {

		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t��лʹ��,ף��������죡");
		printf("\n\n\n\n");
		exit(-1);
	}
}
int main()
{
	system("color 70");
	loginface();
	return 0;
}

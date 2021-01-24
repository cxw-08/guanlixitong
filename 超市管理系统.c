#include<string.h>
#include<windows.h>
#include<conio.h>
#include <stdlib.h>
#include<stdio.h>
#include<malloc.h>
#define N "/t商品名称：%-12s   商品编号:%-3d   价格:%-5d   生产日期：%-5d   保质期：%-5d\n"

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


//显示所有商品信息 
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
//显示购物车商品 
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
//购物车文件输出商品
//shopcart *shuchu_2()
//{
//	shopcart *head,*p1,*p2;
//	FILE*f3,*f4;
//	char ch;
//	f3=fopen("商品信息.txt","r");
//	f4=fopen("商品信息.txt","r");
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
//文件输入商品
void shuru(shangpin* head)
{
	shangpin* p;
	p = head;
	FILE* fp;
	fp = fopen("商品信息.txt", "wt");
	if ((fp = fopen("商品信息.txt", "wt")) == NULL)
	{
		printf("\t\t\t无法打开文件");
		getch();
		exit(0);
	}
	for (p = head; p != NULL; p = p->next)
	{
		fprintf(fp, "%s %d %d %d %d\n", p->name, p->number, p->price, p->shengchanriqi, p->baozhiqi);
	}
	fclose(fp);
}
//文件输出商品

shangpin* shuchu()
{
	shangpin* head, * p1, * p2;
	FILE* f1, * f2;
	char ch;
	f1 = fopen("商品信息.txt", "r");
	f2 = fopen("商品信息.txt", "r");
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
//添加商品信息 
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
		printf("是否添加商品，请回复Y/N:\n");
		rewind(stdin);
		scanf("%c", &ch);
		if (ch == 'N')
		{
			break;
		}

		printf("请输入商品名称：\n");
		scanf("%s", &p1->name);
		printf("请输入商品编号：\n");
		scanf("%d", &p1->number);
		printf("请输入商品价格：\n");
		scanf("%d", &p1->price);
		printf("请输入商品生产日期：\n");
		scanf("%d", &p1->shengchanriqi);
		printf("请输入商品保质期：\n");
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
//添加购物车商品
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
//		printf("是否添加商品，请回复Y/N:\n");
//		rewind(stdin); 
//		scanf("%c",&ch);
//		if(ch=='N')
//		{
//			break;
//		}
//		
//		printf("请输入商品名称：\n");
//		scanf("%s",&p1->name);
//		printf("请输入商品编号：\n");
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
//添加商品信息
void tianjia()
{
	shangpin* p, * head, * t;
	char n;
	int num, k = -1;
	head = shuchu();
	output(head->next);
	printf("\t\t\t请输入添加商品的次序：");
	scanf("%d", &num);
	for (p = head; p != NULL; p = p->next) {
		k++;
		if (k == num - 1) {
			t = (shangpin*)malloc(sizeof(shangpin));
			printf("\t\t\t输入商品名称：");
			scanf("%s", &t->name);
			printf("\t\t\t输入商品编号：");
			scanf("%d", &t->number);
			printf("\t\t\t输入商品价格：");
			scanf("%d",&t->price);
			printf("\t\t\t输入商品生产日期：");
			scanf("%d", &t->shengchanriqi);
			printf("\t\t\t输入商品保质期：");
			scanf("%d", &t->baozhiqi);
			t->next = p->next;
			p->next = t;
			break;
		}
	}
	printf("\t\t\t添加成功！\n");
	shuru(head->next);
	output(head->next);
}
//删除商品信息
void deletes()
{
	shangpin* p1, * p2, * t;
	shangpin* p;
	p = shuchu();
	char name[20];
	int n;
	int num;
	int flag = 0;
	printf("请选择删除方式：\n");
	printf("1 按照商品编号进行删除\n2 按照商品名称进行删除\n");
	scanf("%d",&n);
	switch (n)
	{
	case 1:
		printf("商品信息如下：\n");
		output(p->next);
		printf("请输入要删除商品的编号：\n");
		scanf("%d", &num);
		for (t = p; t != NULL; t = t->next)
		{
			if (t->next->number == num)
			{
				printf("商品信息如下：\n");
				printf(N, t->next->name, t->next->number, t->next->price, t->next->shengchanriqi, t->next->baozhiqi);
				flag = 1;
				t->next=t->next->next;
				printf("删除成功！！\n");
				break;
			}
		}
		if (flag == 0)
		{
			printf("\t\t\t未查找到商品信息！");
		}
		
		shuru(p->next);
		output(p->next);
		break;
	case 2:
		printf("商品信息如下：\n");
		output(p->next);
		printf("请输入要删除商品的名称：\n");
		scanf("%s", name);
		for (t = p; t != NULL; t->next)
		{
			if (strcmp(t->next->name, name) == 0)
			{
				printf("商品信息如下：\n");
				printf(N, t->next->name, t->next->number, t->next->price, t->next->shengchanriqi, t->next->baozhiqi);
				flag = 1;
				t->next=t->next->next;
				free(t);
				printf("删除成功！！\n");
				break;

			}
		}
		if (flag == 0)
		{
			printf("\t\t\t未查找到商品信息！");
		}
		shuru(p->next);
		output(p->next);

	

	}

}
//删除购物车商品
//shopcart* delete_shopcart(shopcart *head)
//{
//	shopcart *p1,*p2,*t;
//	p1=head;
//	char name[20];
//	int n;
//	int num;
//	int flag=0;
//	printf("商品信息如下：\n");
//	output(head);
//	printf("请输入要删除商品的名称：\n");
//	scanf("%s",name);
//	for(t=p1;t!=NULL;t->next)
//	{
//		if(strcmp(t->name,name)==0)
//		{
//			printf("商品信息如下：\n");
//			printf("%s  %.2f",t->name,t->price);
//			p1->next=t;
//			p1->next=t->next;
//			free(t);
//			printf("删除成功！！\n");
//			break; 
//					
//			}
//		}
//	if(flag==0)
//	{
//		printf("\t\t\t未查找到商品信息！");
//	}
//	return head; 
//}
//
//
// 
//查询指定商品的信息 
void chaxun()
{

	shangpin* p1, * p2, * t;
	p1 = shuchu();
	p1=p1->next;
	char name[20];
	int flag = 0;
	int num;
	int ch;
	printf("请输入查询方式：\n");
	printf("1 按照编号查询\n2 按照商品名称查询\n");
	scanf("%d", &ch);
	switch (ch)
	{
		case 1:
			printf("请输入商品编号：\n");
			scanf("%d", &num);
			for (t =p1; t != NULL; t=t->next)
			{
				if (t->number == num)
				{
					printf("商品信息如下：\n");
					printf(N, t->name, t->number, t->price, t->shengchanriqi, t->baozhiqi);
					flag = 1;
					break;
				}		
			}
			if (flag == 0)
			{
				printf("\t\t\t\t未查找到商品信息！");
			}
			break;
		case 2:
			printf("请输入商品名称：\n");
			scanf("%s", name);
			for (t =p1; t != NULL; t=t->next)
			{
				if (strcmp(t->name, name) == 0)
				{
					printf("商品信息如下：\n");
					printf(N, t->name, t->number, t->price, t->shengchanriqi, t->baozhiqi);
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				printf("\t\t\t\t未查找到商品信息！");
			}
			break;
	}

}
//修改商品信息
void xiugai()
{
	shangpin* h, * t, * p;
	int ch, j, flag = 0;
	char choice;
	char name[20];
	h = shuchu();
	h=h->next;
	printf("\t\t\t请输入商品名称：");
	scanf("%s", name);
	for (t = h; t != NULL; t = t->next)
	{
		if (strcmp(t->name, name) == 0)
		{
			printf(N, t->name, t->number, t->price, t->shengchanriqi, t->baozhiqi);
			flag = 1;
			while (1)
			{
				printf("\t\t\t确定修改商品信息吗？（Y/N）：");
				rewind(stdin);
				scanf("%c", &choice);
				if (choice == 'N')
				{
					break;
				}
				else
				{
					printf("\t\t\t请重新输入商品名称：");
					scanf("%s", t->name);
					printf("\t\t\t请重新输入商品编号：");
					scanf("%d", &t->number);
					printf("\t\t\t请重新输入商品价格：");
					scanf("%d", &t->price);
					printf("\t\t\t请重新输入生产日期：");
					scanf("%d", &t->shengchanriqi);
					printf("\t\t\t请重新输入保质期：");
					scanf("%d", &t->baozhiqi);
					printf("\t\t\t修改情况如下：\n");
					printf(N, t->name, t->number, t->price, t->shengchanriqi, t->baozhiqi);

				}

			}
		}
		if (flag == 0)
		{
			printf("\t\t\t未查找到商品信息！");
		}
		p = h;
		shuru(p);
		break;
	}

}
//打印商品信息报表
void baobiao()
{
	shangpin* p, * head;
	head = shuchu();
	head = head->next;
	printf("\t对商品统计后生成报表如下:\n");
	printf("\t\t\t------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t|                                                                                                                                        |\n");
	printf("\t\t\t| **%15s%15s%15s%15s%15s  ** |\n", "商品名称", "商品编号", "商品价格", "商品生产日期", "商品保质期");
	for (p = head; p != NULL; p = p->next)
	{
		printf("\t\t\t| **%15s%15d%15d%15d%15d  ** |\n", p->name, p->number, p->price, p->shengchanriqi, p->baozhiqi);
	}
	printf("\t\t\t|                                                                                                                                        |\n");
	printf("\t\t\t------------------------------------------------------------------------------------------------------------------------------------------\n");

}
//结算 
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

//密匙 
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
//用户登录 
void login()
{
	char name[20];
	char code[20];
	int n;
	printf("用户登录：\n");
	printf("请输入用户名：\n");
	scanf("%s", name);
	strcat(name, ".txt");
	fp = fopen(name, "r");
	if (fp == NULL) {
		printf("用户不存在，请注册：\n");
		printf("1 注册\n2 重新登录\n3 退出\n");
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
		printf("请输入密码：\n");
		yincode(code);
		fscanf(fp, "%s", customer.code);
		if (strcmp(customer.code, code) != 0) {
			printf("\n密码错误！\n");
			fflush(stdin);
		}
		else {
			break;
		}
	} while (1);
}
//顾客界面登陆或注册 
void customers()
{
	char n;
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t欢迎进入customer管理系统1.0！\n");
    printf("\n\n\n\t\t\t\t\t\t请选择：\n");
    printf("\t\t\t\t\t\t\t1 用户登录\n\t\t\t\t\t\t\t2 用户注册\n\t\t\t\t\t\t\t3 返回上一层\n");
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
			printf("\t\t系统内商品信息如下：\n");
			p = shuchu();
			if (p == NULL) {
				printf("\t\t\t系统内无信息！\n");
				printf("\t\t需要录入商品信息吗？（Y/N）");
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
			printf("\t\t按任意回到首菜单\n");
			a=getch();
			break;
		case 2:
			system("CLS");
			deletes();
			printf("\t\t\t按任意键回到首菜单\n");
			b=getch();
			break;
		case 3:
			system("CLS");
			chaxun();
			printf("\t\t\t按任意键回到首菜单\n");
			c=getch();
			break;
		case 4:
			system("CLS");
			xiugai();
			printf("\t\t\t按任意键回到首菜单\n");
			d=getch();

			break;
		case 5:
			system("CLS");
			tianjia();
			printf("\t\t\t按任意键回到首菜单\n");
			e=getch();
			break;
		case 6:
			system("CLS");
			baobiao();
			printf("\t\t\t按任意键回到首菜单\n");
			f=getch();
			break;
		case 0:
			system("CLS");
			loginface();
			break;
			
		}
	}

}

//管理员登录 
void manager()
{
	char code[20] = "123456";
	char n[20];
	int i = 0;
	do {
		printf("请输入密码：\n");
		yincode(n);
		if (strcmp(code, n) == 0) {
			printf("密码正确！！\n");
			i = 1;
			break;
		}
		else {
			printf("密码错误！！\n");
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
//用户注册 
void registers()
{
	char code[20], filename[20];

	while (1) {
		printf("\n用户注册：\n");
		printf("请输入用户名：");
		scanf("%s", customer.name);
		strcat(customer.name, ".txt");
		fp = fopen(customer.name, "r+");
		if (fp != NULL) {
			printf("\n用户已存在！\n");
			fclose(fp);
			login();
			break;
		}
		printf("\n请输入密码：\n");
		yincode(customer.code);
		printf("\n确认密码：\n");
		yincode(code);
		while (strcmp(customer.code, code) != 0) {
			printf("\n\t\t\t\t\t密码不一致，请重新输入：\n");
			printf("\t\t\t\t\t请输入密码：");
			yincode(customer.code);
			printf("\n\t\t\t\t\t确认密码：");
			yincode(code);
		}
		fp = fopen(customer.name, "wt");
		if (fp == NULL) {
			printf("\n\t\t\t\t\t注册失败！\n");
			exit(0);
		}
		else {
			system("cls");
			printf("\n\n\n\n\n\t\t\t\t\t注册成功！\n");
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
//管理员功能菜单 
int managermenu()
{
	char n;
	do
	{
		system("CLS");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t***********欢迎进入管理manager系统***********\n");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t||  1 查看系统内商品信息                   ||\n");
		printf("\t\t\t\t||  2 下架指定商品信息                     ||\n");
		printf("\t\t\t\t||  3 查询指定商品信息                     ||\n");
		printf("\t\t\t\t||  4 修改指定商品信息                     ||\n");
		printf("\t\t\t\t||  5 添加商品                             ||\n");
		printf("\t\t\t\t||  6 商品信息报表                         ||\n");
		printf("\t\t\t\t||  0 退出                                 ||\n");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t请选择1~6：");
		n = getch();
	} while (n < '0' || n>'6');
	return n - 48;

}
//购物车功能菜单 
//int shopcart_menu()
//{
//	char n;
//	printf("*********************************************************\n");
//	printf("1 删除购物车商品\n2 在购物车添加商品\n3 显示购物车商品\n4 退出\n");
//	printf("请选择你想要功能的数字：\n");
//	n=getch();
//	return n-48;
//}
//顾客功能菜单 
int customermenu()
{
	char n;
	do
	{
		system("CLS");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t***********欢迎进入管理customer系统**********\n");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t||  1 购物车                               ||\n");
		printf("\t\t\t\t||  2 结算                                 ||\n");
		printf("\t\t\t\t||  0 退出                                 ||\n");
		printf("\t\t\t\t*********************************************\n");
		printf("\t\t\t\t请选择1~2：");
		n = getch();
	} while (n < '0' || n>'2');
	return n - 48;
}
//登录界面 
void loginface()
{
	char n;
	printf("\n");
	printf("请选择下面的数字表示你的身份：\n");
	printf("1 管理员\n2 顾客\n3 退出系统\n");
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
		printf("\t\t\t\t\t感谢使用,祝您生活愉快！");
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

/**********************************咖啡厅管理系统********************************************
		文件名称:	1.c
		文件描述:	链表 + 文件 简易的咖啡厅管理系统
		编译环境：	VC6.0
		最后修改：	<2020年05月16日><新增统计功能><Yang>
		功    能：	查找 显示 修改 删除 存档 客人信息
		说    明：	存档在C:\\student_file.txt
	
***********************************************************************************************/ 
#include<stdio.h>
#include<iostream>
#include<string>

#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
using namespace std;
/*********************************宏定义*****************************************/
#define N 100				//结构体中数组的大小
/*********************************函数声明***************************************/
void save_file();	
void Delay();
/*********************************咖啡声明***************************************/		
//抽象类，咖啡

class coffee

{

public:

	virtual float dabei_cost() = 0;

	virtual float zhongbei_cost() = 0;

	virtual float xiaobei_cost() = 0;

};



//具体类，浓缩咖啡

class black_coffee :public coffee

{

public:

	virtual float dabei_cost() //大杯价格

	{

		return 15.0;

	}



	virtual float zhongbei_cost()//中杯价格

	{

		return 10.0;

	}



	virtual float xiaobei_cost()//小杯价格

	{

		return 5.0;

	}

};



//具体类，美式咖啡

class white_coffee :public coffee

{

public:

	virtual float dabei_cost()//大杯价格

	{

		return 18.0;

	}



	virtual float zhongbei_cost()//中杯价格

	{

		return 14.0;

	}



	virtual float xiaobei_cost()//小杯价格

	{

		return 10.0;

	}

};



//具体类，玛奇朵咖啡

class flavored_coffee :public coffee

{

public:

	virtual float dabei_cost()//大杯价格

	{

		return 20.0;

	}



	virtual float zhongbei_cost()//中杯价格

	{

		return 15.0;

	}



	virtual float xiaobei_cost()//小杯价格

	{

		return 10.0;

	}

};



//具体类，卡布奇诺咖啡

class caffelatte :public coffee

{

public:

	virtual float dabei_cost()//大杯价格

	{

		return 25.0;

	}



	virtual float zhongbei_cost()//中杯价格

	{

		return 20.0;

	}



	virtual float xiaobei_cost()//小杯价格

	{

		return 15.0;

	}

};



//装饰者类，给咖啡加入若干种调味品

class Add_Condiment :public coffee

{

public:

	void Decorate(coffee* cof)

	{

		this->cof = cof;

	}

public:

	virtual float dabei_cost()

	{

		return (cof->dabei_cost());

	}

	virtual float zhongbei_cost()

	{

		return(cof->zhongbei_cost());

	}

	virtual float xiaobei_cost()

	{

		return(cof->xiaobei_cost());

	}

protected:

	coffee* cof;

};



//给咖啡加牛奶

class has_milk :public Add_Condiment

{

public:

	float with_milk()

	{

		return 1.0;

	}

public:

	virtual float dabei_cost()

	{

		return(with_milk() + (Add_Condiment::dabei_cost()));

	}



	virtual float zhongbei_cost()

	{

		return(with_milk() + (Add_Condiment::zhongbei_cost()));

	}

	virtual float xiaobei_cost()

	{

		return(with_milk() + (Add_Condiment::xiaobei_cost()));

	}

};



//给咖啡加糖

class has_sugar :public Add_Condiment

{

public:

	float with_sugar()

	{

		return 0.5;

	}

public:

	virtual float dabei_cost()

	{

		return(with_sugar() + (Add_Condiment::dabei_cost()));

	}



	virtual float zhongbei_cost()

	{

		return(with_sugar() + (Add_Condiment::zhongbei_cost()));

	}



	virtual float xiaobei_cost()

	{

		return(with_sugar() + (Add_Condiment::xiaobei_cost()));

	}

};



//给咖啡加奶油

class has_cream :public Add_Condiment

{

public:

	float with_cream()

	{

		return 3.0;

	}

public:

	virtual float dabei_cost()

	{

		return(with_cream() + (Add_Condiment::dabei_cost()));

	}

	virtual float zhongbei_cost()

	{

		return(with_cream() + (Add_Condiment::zhongbei_cost()));

	}

	virtual float xiaobei_cost()

	{

		return(with_cream() + (Add_Condiment::xiaobei_cost()));

	}

};

/*********************************自定义数据类型*********************************/
typedef struct stu
{
	char num[N];			//座位号
	char name[N];			//姓名
	char xiaofei[N];		//消费额 

	struct stu* pnext;

}STU;
/*********************************全局变量定义*********************************/
STU* pStu = NULL;			//表头
STU* pCurrent = NULL;		//当前顾客（已经存在）
STU* pNew=NULL;				//当前顾客（待输入）
char KEY[7];				//服务密码
/*********************************子函数定义***********************************/
//登陆验证	
void InCheck()							
{	
	int InputLimit= 0;
	char keynumber[7]="0";
	int i = 0;

	srand((unsigned)time(NULL));		//生成随机验证码
	for(i=0;i<6;i++)
	{
		KEY[i] = rand() % 10  + 48; 
	}
	KEY[6] = '\0';

	system("cls");
	system("color 3e");

	printf("\n\n\t┌================================================┑\n");
	printf("\n\n");
	printf("\t\t\t欢迎使用咖啡厅管理系统\n");
	printf("\t\t\t\t\n");
	printf("\t\t\t\t\n");
	printf("\t\t\t\t\n");
	printf("\t\t\t请输入验证码登陆此系统\n");
	printf("\t\t\t<验证码是%s>\n",KEY);
	printf("\t\t\t \n");
	printf("\t\t\t如果3次输入均不正确，将退出系统\n");

	printf("\n\n\t┕================================================┚\n");
	
	
	scanf("%s",keynumber);
	while(strcmp(keynumber,KEY)!=0)
	{	InputLimit++;
		if(InputLimit==3)
		{	printf("\t您输入错误的次数已经到达%d次,您将退出系统",InputLimit);
			Delay();
			exit(0);
		}
		printf("\n\t\t您的输入有误!请重新输入\n");
		scanf("%s",keynumber);
	}

	system("cls");
	
}
//检查信息合法性:输入的都是数字字符吗？
char InformationCheck(const char *str)			
{
	int L = 0;
	int i = 0;
	int PointCount=0;
	int NumCount = 0;


	L = strlen(str);
	for(i=0;i<L;i++)
	{	if(str[i]=='.')
			PointCount++;
		if((str[i]<'0'||str[i]>'9')&&str[i]!='.')
		{	printf("\t您输入不合法，请重新输入\n");
			return 1;
		}

	}
	if(PointCount>1)
	{	printf("\t您输入不合法，请重新输入\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
//输入的信息容错后期处理[在InformationCheck,确保没有重大错误之后]
void InformationDebug(char *str)	
{
	int L = 0;
	char PointFlag=0;
	int IntCount = 0;
	int FloatCount = 0;			//小数部分
	int i = 0;	
	int PositionOfPoint = 0;	//小数点所在的下标
	int ZeroPre = 0;			//无用的0的个数
	char NotZeroStartFlag=0;	//字符串中开始出现了第一个1-9的数字字符

	L= strlen(str);

	for(i=0;i<L;i++)
	{	if(str[i]>='1'&&str[i]<='9')
			NotZeroStartFlag=1;

		if(str[i]=='.')
		{	
			PointFlag = 1;
			PositionOfPoint = i;
		}
		else if(!PointFlag)
			IntCount++;
		else
			FloatCount++;

		if((PointFlag==0)&&(NotZeroStartFlag==0)&&(str[i]=='0')&&(str[i+1]!='.'))	//多余的'0'
			ZeroPre++;
	}

	if(IntCount==0)								//没有整数部分?
	{
		for(i=L;i>0;i--)
		{
			str[i]=str[i-1];
		}
		str[0] = '0';
		str[L+1] = '\0';
		PositionOfPoint++;
	}
	if(FloatCount==0&&PointFlag == 1)			//有小数点却没有小数部分？
	{
		str[PositionOfPoint+1] = '0';
		str[PositionOfPoint+2] = '\0';
	}
	if(ZeroPre>0)
	{
		strcpy(str,str+ZeroPre);
	}
	if(!NotZeroStartFlag)						//字符串中从来没有出现过1 -9 字符
	{
		strcpy(str,"0");
	}
}
//检查信息合法性:有没有输入的座位号已经存在？
char NumCheck(const char *str)			
{
	STU * View = NULL;
	int L = 0;
	int i = 0;

	View = pStu->pnext;


	while(View!=NULL)
	{
		if(strcmp(str,View->num)==0)
		{	printf("\t您输入的座位号已经存在，请重新输入\n");
			return 1;
		}
		View=View->pnext;
	}
										//输入的学号是在0 -9 之内的字符吗
	L = strlen(str);
	for(i=0;i<L;i++)
	{	
		if(str[i]<'0'||str[i]>'9')
		{	printf("\t您输入的字符应在'0'-'9'之间输入，请重新输入\n");
			return 1;
		}
	}

	return 0;


}
//信息数字检查，,只检查字符串里面是不是只有 '0' - '9' 字符
void NumberCheck(char *str,char *Display)
{
	while(NumCheck(str))
	{
		printf("\t%s:",Display);
		scanf("%s",str);

	}
}
//信息过安检，不仅仅检查字符串里面是不是有除了'0' - '9'和'.'以外的字符，还进行消除冗余的'0'的操作
void SecureCheck(char *str,char *DisPlay)
{
		while(InformationCheck(str))
	{
		
		printf("\t%s:",DisPlay);
		scanf("%s",str);
	}
	InformationDebug(str);
}

void diandan()

{

	cout << "                                欢迎光临本店!                                   " << endl;

	cout << "*******************************请选择咖啡系列********************************" << endl;

	cout << "  ▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏" << endl;

	cout << "  ▕  1.浓缩系列     2.美式系列     3.玛奇朵系列       4.卡布奇诺系列     ▏" << endl;

	cout << "  ▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏" << endl;

	int choie;

	cout << "                         请输入数字选择对应的咖啡系列：";

	cin >> choie;

	switch (choie)

	{

	case 1:

	{

		cout << "  ▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏" << endl;

		cout << "  ▕                浓缩咖啡系列有以下种类，请选择：                      ▏" << endl;

		cout << "  ▕ 1.浓缩咖啡（纯）  2.浓缩咖啡+牛奶   3.浓缩咖啡+糖    4.浓缩咖啡+奶油 ▏" << endl;

		cout << "  ▕ 5.浓缩咖啡+牛奶+糖    6.浓缩咖啡+牛奶+奶油     7.浓缩咖啡+糖+奶油    ▏" << endl;

		cout << "  ▕ 8.浓缩咖啡+牛奶+糖+奶油                                              ▏" << endl;

		cout << "  ▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏" << endl;

		cout << "                       请输入数字选择您想要的咖啡:";

		int a;

		cin >> a;

		switch (a)

		{

		case 1:

			cout << "                           请选择浓缩咖啡的型号：" << endl;

			cout << "                           1.大杯  2.中杯   3.小杯" << endl;

			cout << "                           请输入对应的数字选择您想要的型号：";

			int a1;

			cin >> a1;

			switch (a1)

			{

			case 1:

			{

				coffee* c1 = new black_coffee;

				cout << endl << "                         请付" << c1->dabei_cost() << "元！" << "谢谢！" << endl;

				delete c1; break;

			}

			case 2:

			{

				coffee* c2 = new black_coffee;

				cout << endl << "                         请付" << c2->zhongbei_cost() << "元！" << "谢谢！" << endl;

				delete c2; break;

			}

			case 3:

			{

				coffee* c3 = new black_coffee;

				cout << endl << "                        请付" << c3->xiaobei_cost() << "元！" << "谢谢！" << endl;

				delete c3; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 2:

			cout << "                         请选择浓缩咖啡+牛奶的型号：" << endl;

			cout << "                         1.大杯  2.中杯   3.小杯" << endl;

			cout << "                         请输入对应的数字选择您想要的型号：";

			int a2;

			cin >> a2;

			switch (a2)

			{

			case 1:

			{

				coffee* b1 = new black_coffee;

				Add_Condiment* b2 = new has_milk;

				b2->Decorate(b1);

				cout << endl << "                         请付" << b2->dabei_cost() << "元!" << "谢谢！" << endl;

				delete b1; delete b2; break;

			}

			case 2:

			{

				coffee* b3 = new black_coffee;

				Add_Condiment* b4 = new has_milk;

				b4->Decorate(b3);

				cout << endl << "                         请付" << b4->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete b3; delete b4; break;

			}

			case 3:

			{

				coffee* b5 = new black_coffee;

				Add_Condiment* b6 = new has_milk;

				b6->Decorate(b5);

				cout << endl << "                        请付" << b6->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete b5; delete b6; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 3:

			cout << "                         请选择浓缩咖啡+糖的型号：" << endl;

			cout << "                         1.大杯  2.中杯   3.小杯" << endl;

			cout << "                         请输入对应的数字选择您想要的型号：";

			int a3;

			cin >> a3;

			switch (a3)

			{

			case 1:

			{

				coffee* d1 = new black_coffee;

				Add_Condiment* d2 = new has_sugar;

				d2->Decorate(d1);

				cout << endl << "                      请付" << d2->dabei_cost() << "元！" << "谢谢！" << endl;

				delete d1; delete d2; break;

			}

			case 2:

			{

				coffee* d3 = new black_coffee;

				Add_Condiment* d4 = new has_sugar;

				d4->Decorate(d3);

				cout << endl << "                     请付" << d4->zhongbei_cost() << "元！" << "谢谢！" << endl;

				delete d3; delete d4; break;

			}

			case 3:

			{

				coffee* d5 = new black_coffee;

				Add_Condiment* d6 = new has_sugar;

				d6->Decorate(d5);

				cout << endl << "                     请付" << d6->xiaobei_cost() << "元！" << "谢谢！" << endl;

				delete d5; delete d6; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 4:

			cout << "                        请选择浓缩咖啡+奶油的型号：" << endl;

			cout << "                        1.大杯  2.中杯   3.小杯" << endl;

			cout << "                        请输入对应的数字选择您想要的型号：";

			int a4;

			cin >> a4;

			switch (a4)

			{

			case 1:

			{

				coffee* e1 = new black_coffee;

				Add_Condiment* e2 = new has_cream;

				e2->Decorate(e1);

				cout << endl << "                    请付" << e2->dabei_cost() << "元" << "谢谢！" << endl;

				delete e1; delete e2; break;

			}

			case 2:

			{

				coffee* e3 = new black_coffee;

				Add_Condiment* e4 = new has_cream;

				e4->Decorate(e3);

				cout << endl << "                   请付" << e4->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete e3; delete e4; break;

			}

			case 3:

			{

				coffee* e5 = new black_coffee;

				Add_Condiment* e6 = new has_cream;

				e6->Decorate(e5);

				cout << endl << "                  请付" << e6->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete e5; delete e6; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 5:

			cout << "                    请选择浓缩咖啡+牛奶+糖的型号：" << endl;

			cout << "                    1.大杯  2.中杯   3.小杯" << endl;

			cout << "                    请输入对应的数字选择您想要的型号：";

			int a5;

			cin >> a5;

			switch (a5)

			{

			case 1:

			{

				coffee* f1 = new black_coffee;

				Add_Condiment* f2 = new  has_milk;

				Add_Condiment* f3 = new has_sugar;

				f2->Decorate(f1);

				f3->Decorate(f2);

				cout << endl << "                   请付" << f3->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete f1; delete f2; delete f3; break;

			}

			case 2:

			{

				coffee* f4 = new black_coffee;

				Add_Condiment* f5 = new  has_milk;

				Add_Condiment* f6 = new has_sugar;

				f5->Decorate(f4);

				f6->Decorate(f5);

				cout << endl << "                   请付" << f6->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete f4; delete f5; delete f6; break;

			}

			case 3:

			{

				coffee* f7 = new black_coffee;

				Add_Condiment* f8 = new  has_milk;

				Add_Condiment* f9 = new has_sugar;

				f8->Decorate(f7);

				f9->Decorate(f8);

				cout << endl << "                   请付" << f9->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete f7; delete f8; delete f9; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 6:

			cout << "                  请选择浓缩咖啡+牛奶+奶油的型号：" << endl;

			cout << "                  1.大杯  2.中杯   3.小杯" << endl;

			cout << "                  请输入对应的数字选择您想要的型号：";

			int a6;

			cin >> a6;

			switch (a6)

			{

			case 1:

			{

				coffee* g1 = new black_coffee;

				Add_Condiment* g2 = new has_milk;

				Add_Condiment* g3 = new has_cream;

				g2->Decorate(g1);

				g3->Decorate(g2);

				cout << endl << "                   请付" << g3->dabei_cost() << "元" << "谢谢！" << endl;

				delete g1; delete g2; delete g3; break;

			}

			case 2:

			{

				coffee* g4 = new black_coffee;

				Add_Condiment* g5 = new has_milk;

				Add_Condiment* g6 = new has_cream;

				g5->Decorate(g4);

				g6->Decorate(g5);

				cout << endl << "                   请付" << g6->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete g4; delete g5; delete g6; break;

			}

			case 3:

			{

				coffee* g7 = new black_coffee;

				Add_Condiment* g8 = new has_milk;

				Add_Condiment* g9 = new has_cream;

				g8->Decorate(g7);

				g9->Decorate(g8);

				cout << endl << "                   请付" << g9->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete g7; delete g8; delete g9; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 7:

			cout << "                 请选择浓缩咖啡+糖+奶油的型号：" << endl;

			cout << "                 1.大杯  2.中杯   3.小杯" << endl;

			cout << "                 请输入对应的数字选择您想要的型号：";

			int a7;

			cin >> a7;

			switch (a7)

			{

			case 1:

			{

				coffee* h1 = new black_coffee;

				Add_Condiment* h2 = new has_sugar;

				Add_Condiment* h3 = new has_cream;

				h2->Decorate(h1);

				h3->Decorate(h2);

				cout << endl << "                   请付" << h3->dabei_cost() << "元" << "谢谢！" << endl;

				delete h1; delete h2; delete h3; break;

			}

			case 2:

			{

				coffee* h4 = new black_coffee;

				Add_Condiment* h5 = new has_sugar;

				Add_Condiment* h6 = new has_cream;

				h5->Decorate(h4);

				h6->Decorate(h5);

				cout << endl << "                    请付" << h6->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete h4; delete h5; delete h6; break;

			}

			case 3:

			{

				coffee* h7 = new black_coffee;

				Add_Condiment* h8 = new has_sugar;

				Add_Condiment* h9 = new has_cream;

				h8->Decorate(h7);

				h9->Decorate(h8);

				cout << endl << "                    请付" << h9->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete h7; delete h8; delete h9; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 8:

			cout << "                请选择浓缩咖啡+牛奶+糖+奶油的型号：" << endl;

			cout << "                1.大杯  2.中杯   3.小杯" << endl;

			cout << "                请输入对应的数字选择您想要的型号：";

			int a8;

			cin >> a8;

			switch (a8)

			{

			case 1:

			{

				coffee* i1 = new black_coffee;

				Add_Condiment* i2 = new has_milk;

				Add_Condiment* i3 = new has_sugar;

				Add_Condiment* i4 = new has_cream;

				i2->Decorate(i1);

				i3->Decorate(i2);

				i4->Decorate(i3);

				cout << endl << "                      请付" << i4->dabei_cost() << "元" << "谢谢！" << endl;

				delete i1; delete i2; delete i3; delete i4; break;

			}

			case 2:

			{

				coffee* i5 = new black_coffee;

				Add_Condiment* i6 = new has_milk;

				Add_Condiment* i7 = new has_sugar;

				Add_Condiment* i8 = new has_cream;

				i6->Decorate(i5);

				i7->Decorate(i6);

				i8->Decorate(i7);

				cout << endl << "                     请付" << i8->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete i5; delete i6; delete i7; delete i8; break;

			}

			case 3:

			{

				coffee* i9 = new black_coffee;

				Add_Condiment* i10 = new has_milk;

				Add_Condiment* i11 = new has_sugar;

				Add_Condiment* i12 = new has_cream;

				i10->Decorate(i9);

				i11->Decorate(i10);

				i12->Decorate(i11);

				cout << endl << "                    请付" << i12->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete i9; delete i10; delete i11; delete i12; break;

			}

			default:printf("输入有误！\n");

			}break;

		default:printf("输入有误！\n");

		}

	}break;

	case 2:

	{

		cout << "  ▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏" << endl;

		cout << "  ▕                  美式咖啡系列有以下种类，请选择：                    ▏" << endl;

		cout << "  ▕ 1.美式咖啡（纯）   2.美式咖啡+牛奶    3.美式咖啡+糖  4.美式咖啡+奶油 ▏" << endl;

		cout << "  ▕ 5.美式咖啡+牛奶+糖    6.美式咖啡+牛奶+奶油      7.美式咖啡+糖+奶油   ▏" << endl;

		cout << "  ▕ 8.美式咖啡+牛奶+糖+奶油                                              ▏" << endl;

		cout << "  ▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏" << endl;

		cout << "                       请输入数字选择您想要的咖啡:";

		int b;

		cin >> b;

		switch (b)

		{

		case 1:

			cout << "                   请选择美式咖啡的型号：" << endl;

			cout << "                   1.大杯  2.中杯   3.小杯" << endl;

			cout << "                   请输入对应的数字选择您想要的型号：";

			int a1;

			cin >> a1;

			switch (a1)

			{

			case 1:

			{

				coffee* c1 = new white_coffee;

				cout << endl << "                    请付" << c1->dabei_cost() << "元！" << "谢谢！" << endl;

				delete c1; break;

			}

			case 2:

			{

				coffee* c2 = new white_coffee;

				cout << endl << "                    请付" << c2->zhongbei_cost() << "元！" << "谢谢！" << endl;

				delete c2; break;

			}

			case 3:

			{

				coffee* c3 = new white_coffee;

				cout << endl << "                    请付" << c3->xiaobei_cost() << "元！" << "谢谢！" << endl;

				delete c3; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 2:

			cout << "                 请选择美式咖啡+牛奶的型号：" << endl;

			cout << "                 1.大杯  2.中杯   3.小杯" << endl;

			cout << "                 请输入对应的数字选择您想要的型号：";

			int a2;

			cin >> a2;

			switch (a2)

			{

			case 1:

			{

				coffee* b1 = new white_coffee;

				Add_Condiment* b2 = new has_milk;

				b2->Decorate(b1);

				cout << endl << "                     请付" << b2->dabei_cost() << "元!" << "谢谢！" << endl;

				delete b1; delete b2; break;

			}

			case 2:

			{

				coffee* b3 = new white_coffee;

				Add_Condiment* b4 = new has_milk;

				b4->Decorate(b3);

				cout << endl << "                    请付" << b4->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete b3; delete b4; break;

			}

			case 3:

			{

				coffee* b5 = new white_coffee;

				Add_Condiment* b6 = new has_milk;

				b6->Decorate(b5);

				cout << endl << "                    请付" << b6->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete b5; delete b6; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 3:

			cout << "               请选择美式咖啡+糖的型号：" << endl;

			cout << "               1.大杯  2.中杯   3.小杯" << endl;

			cout << "               请输入对应的数字选择您想要的型号：";

			int a3;

			cin >> a3;

			switch (a3)

			{

			case 1:

			{

				coffee* d1 = new white_coffee;

				Add_Condiment* d2 = new has_sugar;

				d2->Decorate(d1);

				cout << endl << "                    请付" << d2->dabei_cost() << "元！" << "谢谢！" << endl;

				delete d1; delete d2; break;

			}

			case 2:

			{

				coffee* d3 = new white_coffee;

				Add_Condiment* d4 = new has_sugar;

				d4->Decorate(d3);

				cout << endl << "                    请付" << d4->zhongbei_cost() << "元！" << "谢谢！" << endl;

				delete d3; delete d4; break;

			}

			case 3:

			{

				coffee* d5 = new white_coffee;

				Add_Condiment* d6 = new has_sugar;

				d6->Decorate(d5);

				cout << endl << "                  请付" << d6->xiaobei_cost() << "元！" << "谢谢！" << endl;

				delete d5; delete d6; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 4:

			cout << "              请选择美式咖啡+奶油的型号：" << endl;

			cout << "              1.大杯  2.中杯   3.小杯" << endl;

			cout << "              请输入对应的数字选择您想要的型号：";

			int a4;

			cin >> a4;

			switch (a4)

			{

			case 1:

			{

				coffee* e1 = new white_coffee;

				Add_Condiment* e2 = new has_cream;

				e2->Decorate(e1);

				cout << endl << "                 请付" << e2->dabei_cost() << "元" << "谢谢！" << endl;

				delete e1; delete e2; break;

			}

			case 2:

			{

				coffee* e3 = new white_coffee;

				Add_Condiment* e4 = new has_cream;

				e4->Decorate(e3);

				cout << endl << "                 请付" << e4->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete e3; delete e4; break;

			}

			case 3:

			{

				coffee* e5 = new white_coffee;

				Add_Condiment* e6 = new has_cream;

				e6->Decorate(e5);

				cout << endl << "                 请付" << e6->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete e5; delete e6; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 5:

			cout << "            请选择美式咖啡+牛奶+糖的型号：" << endl;

			cout << "            1.大杯  2.中杯   3.小杯" << endl;

			cout << "            请输入对应的数字选择您想要的型号：";

			int a5;

			cin >> a5;

			switch (a5)

			{

			case 1:

			{

				coffee* f1 = new white_coffee;

				Add_Condiment* f2 = new  has_milk;

				Add_Condiment* f3 = new has_sugar;

				f2->Decorate(f1);

				f3->Decorate(f2);

				cout << endl << "                  请付" << f3->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete f1; delete f2; delete f3; break;

			}

			case 2:

			{

				coffee* f4 = new white_coffee;

				Add_Condiment* f5 = new  has_milk;

				Add_Condiment* f6 = new has_sugar;

				f5->Decorate(f4);

				f6->Decorate(f5);

				cout << endl << "                  请付" << f6->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete f4; delete f5; delete f6; break;

			}

			case 3:

			{

				coffee* f7 = new white_coffee;

				Add_Condiment* f8 = new  has_milk;

				Add_Condiment* f9 = new has_sugar;

				f8->Decorate(f7);

				f9->Decorate(f8);

				cout << endl << "                  请付" << f9->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete f7; delete f8; delete f9; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 6:

			cout << "            请选择美式咖啡+牛奶+奶油的型号：" << endl;

			cout << "            1.大杯  2.中杯   3.小杯" << endl;

			cout << "            请输入对应的数字选择您想要的型号：";

			int a6;

			cin >> a6;

			switch (a6)

			{

			case 1:

			{

				coffee* g1 = new white_coffee;

				Add_Condiment* g2 = new has_milk;

				Add_Condiment* g3 = new has_cream;

				g2->Decorate(g1);

				g3->Decorate(g2);

				cout << endl << "                    请付" << g3->dabei_cost() << "元" << "谢谢！" << endl;

				delete g1; delete g2; delete g3; break;

			}

			case 2:

			{

				coffee* g4 = new white_coffee;

				Add_Condiment* g5 = new has_milk;

				Add_Condiment* g6 = new has_cream;

				g5->Decorate(g4);

				g6->Decorate(g5);

				cout << endl << "                   请付" << g6->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete g4; delete g5; delete g6; break;

			}

			case 3:

			{

				coffee* g7 = new white_coffee;

				Add_Condiment* g8 = new has_milk;

				Add_Condiment* g9 = new has_cream;

				g8->Decorate(g7);

				g9->Decorate(g8);

				cout << endl << "                   请付" << g9->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete g7; delete g8; delete g9; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 7:

			cout << "           请选择美式咖啡+糖+奶油的型号：" << endl;

			cout << "           1.大杯  2.中杯   3.小杯" << endl;

			cout << "           请输入对应的数字选择您想要的型号：";

			int a7;

			cin >> a7;

			switch (a7)

			{

			case 1:

			{

				coffee* h1 = new white_coffee;

				Add_Condiment* h2 = new has_sugar;

				Add_Condiment* h3 = new has_cream;

				h2->Decorate(h1);

				h3->Decorate(h2);

				cout << endl << "                       请付" << h3->dabei_cost() << "元" << "谢谢！" << endl;

				delete h1; delete h2; delete h3; break;

			}

			case 2:

			{

				coffee* h4 = new white_coffee;

				Add_Condiment* h5 = new has_sugar;

				Add_Condiment* h6 = new has_cream;

				h5->Decorate(h4);

				h6->Decorate(h5);

				cout << endl << "                       请付" << h6->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete h4; delete h5; delete h6; break;

			}

			case 3:

			{

				coffee* h7 = new white_coffee;

				Add_Condiment* h8 = new has_sugar;

				Add_Condiment* h9 = new has_cream;

				h8->Decorate(h7);

				h9->Decorate(h8);

				cout << endl << "                       请付" << h9->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete h7; delete h8; delete h9; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 8:

			cout << "         请选择美式咖啡+牛奶+糖+奶油的型号：" << endl;

			cout << "         1.大杯  2.中杯   3.小杯" << endl;

			cout << "         请输入对应的数字选择您想要的型号：";

			int a8;

			cin >> a8;

			switch (a8)

			{

			case 1:

			{

				coffee* i1 = new white_coffee;

				Add_Condiment* i2 = new has_milk;

				Add_Condiment* i3 = new has_sugar;

				Add_Condiment* i4 = new has_cream;

				i2->Decorate(i1);

				i3->Decorate(i2);

				i4->Decorate(i3);

				cout << endl << "                        请付" << i4->dabei_cost() << "元" << "谢谢！" << endl;

				delete i1; delete i2; delete i3; delete i4; break;

			}

			case 2:

			{

				coffee* i5 = new white_coffee;

				Add_Condiment* i6 = new has_milk;

				Add_Condiment* i7 = new has_sugar;

				Add_Condiment* i8 = new has_cream;

				i6->Decorate(i5);

				i7->Decorate(i6);

				i8->Decorate(i7);

				cout << endl << "                        请付" << i8->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete i5; delete i6; delete i7; delete i8; break;

			}

			case 3:

			{

				coffee* i9 = new white_coffee;

				Add_Condiment* i10 = new has_milk;

				Add_Condiment* i11 = new has_sugar;

				Add_Condiment* i12 = new has_cream;

				i10->Decorate(i9);

				i11->Decorate(i10);

				i12->Decorate(i11);

				cout << endl << "                        请付" << i12->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete i9; delete i10; delete i11; delete i12; break;

			}

			default:printf("输入有误！\n");

			}break;

		default:printf("输入有误！\n");

		}

	}break;

	case 3:

	{

		cout << "  ▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏" << endl;

		cout << "  ▕                  玛奇朵系列有以下种类，请选择：                      ▏" << endl;

		cout << "  ▕ 1.玛奇朵（纯）     2.玛奇朵+牛奶        3.玛奇朵+糖                  ▏" << endl;

		cout << "  ▕ 4.玛奇朵+奶油      5.玛奇朵+牛奶+糖     6.玛奇朵+牛奶+奶油           ▏" << endl;

		cout << "  ▕ 7.玛奇朵+糖+奶油   8.玛奇朵+牛奶+糖+奶油                             ▏" << endl;

		cout << "  ▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏" << endl;

		cout << "                       请输入数字选择您想要的咖啡:";

		int b;

		cin >> b;

		switch (b)

		{

		case 1:

			cout << "                  请选择玛奇朵的型号：" << endl;

			cout << "                  1.大杯  2.中杯   3.小杯" << endl;

			cout << "                  请输入对应的数字选择您想要的型号：";

			int a1;

			cin >> a1;

			switch (a1)

			{

			case 1:

			{

				coffee* c1 = new flavored_coffee;

				cout << endl << "                      请付" << c1->dabei_cost() << "元！" << "谢谢！" << endl;

				delete c1; break;

			}

			case 2:

			{

				coffee* c2 = new flavored_coffee;

				cout << endl << "                      请付" << c2->zhongbei_cost() << "元！" << "谢谢！" << endl;

				delete c2; break;

			}

			case 3:

			{

				coffee* c3 = new flavored_coffee;

				cout << endl << "                       请付" << c3->xiaobei_cost() << "元！" << "谢谢！" << endl;

				delete c3; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 2:

			cout << "                 请选择玛奇朵+牛奶的型号：" << endl;

			cout << "                 1.大杯  2.中杯   3.小杯" << endl;

			cout << "                 请输入对应的数字选择您想要的型号：";

			int a2;

			cin >> a2;

			switch (a2)

			{

			case 1:

			{

				coffee* b1 = new flavored_coffee;

				Add_Condiment* b2 = new has_milk;

				b2->Decorate(b1);

				cout << endl << "                        请付" << b2->dabei_cost() << "元!" << "谢谢！" << endl;

				delete b1; delete b2; break;

			}

			case 2:

			{

				coffee* b3 = new flavored_coffee;

				Add_Condiment* b4 = new has_milk;

				b4->Decorate(b3);

				cout << endl << "                       请付" << b4->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete b3; delete b4; break;

			}

			case 3:

			{

				coffee* b5 = new flavored_coffee;

				Add_Condiment* b6 = new has_milk;

				b6->Decorate(b5);

				cout << endl << "                      请付" << b6->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete b5; delete b6; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 3:

			cout << "                  请选择玛奇朵+糖的型号：" << endl;

			cout << "                  1.大杯  2.中杯   3.小杯" << endl;

			cout << "                  请输入对应的数字选择您想要的型号：";

			int a3;

			cin >> a3;

			switch (a3)

			{

			case 1:

			{

				coffee* d1 = new flavored_coffee;

				Add_Condiment* d2 = new has_sugar;

				d2->Decorate(d1);

				cout << endl << "                      请付" << d2->dabei_cost() << "元！" << "谢谢！" << endl;

				delete d1; delete d2; break;

			}

			case 2:

			{

				coffee* d3 = new flavored_coffee;

				Add_Condiment* d4 = new has_sugar;

				d4->Decorate(d3);

				cout << endl << "                     请付" << d4->zhongbei_cost() << "元！" << "谢谢！" << endl;

				delete d3; delete d4; break;

			}

			case 3:

			{

				coffee* d5 = new flavored_coffee;

				Add_Condiment* d6 = new has_sugar;

				d6->Decorate(d5);

				cout << endl << "                    请付" << d6->xiaobei_cost() << "元！" << "谢谢！" << endl;

				delete d5; delete d6; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 4:

			cout << "                请选择玛奇朵+奶油的型号：" << endl;

			cout << "                1.大杯  2.中杯   3.小杯" << endl;

			cout << "                请输入对应的数字选择您想要的型号：";

			int a4;

			cin >> a4;

			switch (a4)

			{

			case 1:

			{

				coffee* e1 = new flavored_coffee;

				Add_Condiment* e2 = new has_cream;

				e2->Decorate(e1);

				cout << endl << "                     请付" << e2->dabei_cost() << "元" << "谢谢！" << endl;

				delete e1; delete e2; break;

			}

			case 2:

			{

				coffee* e3 = new flavored_coffee;

				Add_Condiment* e4 = new has_cream;

				e4->Decorate(e3);

				cout << endl << "                    请付" << e4->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete e3; delete e4; break;

			}

			case 3:

			{

				coffee* e5 = new flavored_coffee;

				Add_Condiment* e6 = new has_cream;

				e6->Decorate(e5);

				cout << endl << "                   请付" << e6->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete e5; delete e6; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 5:

			cout << "               请选择玛奇朵+牛奶+糖的型号：" << endl;

			cout << "               1.大杯  2.中杯   3.小杯" << endl;

			cout << "               请输入对应的数字选择您想要的型号：";

			int a5;

			cin >> a5;

			switch (a5)

			{

			case 1:

			{

				coffee* f1 = new flavored_coffee;

				Add_Condiment* f2 = new  has_milk;

				Add_Condiment* f3 = new has_sugar;

				f2->Decorate(f1);

				f3->Decorate(f2);

				cout << endl << "                     请付" << f3->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete f1; delete f2; delete f3; break;

			}

			case 2:

			{

				coffee* f4 = new flavored_coffee;

				Add_Condiment* f5 = new  has_milk;

				Add_Condiment* f6 = new has_sugar;

				f5->Decorate(f4);

				f6->Decorate(f5);

				cout << endl << "                     请付" << f6->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete f4; delete f5; delete f6; break;

			}

			case 3:

			{

				coffee* f7 = new flavored_coffee;

				Add_Condiment* f8 = new  has_milk;

				Add_Condiment* f9 = new has_sugar;

				f8->Decorate(f7);

				f9->Decorate(f8);

				cout << endl << "                     请付" << f9->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete f7; delete f8; delete f9; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 6:

			cout << "                请选择玛奇朵+牛奶+奶油的型号：" << endl;

			cout << "                1.大杯  2.中杯   3.小杯" << endl;

			cout << "                请输入对应的数字选择您想要的型号：";

			int a6;

			cin >> a6;

			switch (a6)

			{

			case 1:

			{

				coffee* g1 = new flavored_coffee;

				Add_Condiment* g2 = new has_milk;

				Add_Condiment* g3 = new has_cream;

				g2->Decorate(g1);

				g3->Decorate(g2);

				cout << endl << "                     请付" << g3->dabei_cost() << "元" << "谢谢！" << endl;

				delete g1; delete g2; delete g3; break;

			}

			case 2:

			{

				coffee* g4 = new flavored_coffee;

				Add_Condiment* g5 = new has_milk;

				Add_Condiment* g6 = new has_cream;

				g5->Decorate(g4);

				g6->Decorate(g5);

				cout << endl << "                     请付" << g6->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete g4; delete g5; delete g6; break;

			}

			case 3:

			{

				coffee* g7 = new flavored_coffee;

				Add_Condiment* g8 = new has_milk;

				Add_Condiment* g9 = new has_cream;

				g8->Decorate(g7);

				g9->Decorate(g8);

				cout << endl << "                     请付" << g9->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete g7; delete g8; delete g9; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 7:

			cout << "                请选择玛奇朵+糖+奶油的型号：" << endl;

			cout << "                1.大杯  2.中杯   3.小杯" << endl;

			cout << "                请输入对应的数字选择您想要的型号：";

			int a7;

			cin >> a7;

			switch (a7)

			{

			case 1:

			{

				coffee* h1 = new flavored_coffee;

				Add_Condiment* h2 = new has_sugar;

				Add_Condiment* h3 = new has_cream;

				h2->Decorate(h1);

				h3->Decorate(h2);

				cout << endl << "                      请付" << h3->dabei_cost() << "元" << "谢谢！" << endl;

				delete h1; delete h2; delete h3; break;

			}

			case 2:

			{

				coffee* h4 = new flavored_coffee;

				Add_Condiment* h5 = new has_sugar;

				Add_Condiment* h6 = new has_cream;

				h5->Decorate(h4);

				h6->Decorate(h5);

				cout << endl << "                      请付" << h6->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete h4; delete h5; delete h6; break;

			}

			case 3:

			{

				coffee* h7 = new flavored_coffee;

				Add_Condiment* h8 = new has_sugar;

				Add_Condiment* h9 = new has_cream;

				h8->Decorate(h7);

				h9->Decorate(h8);

				cout << endl << "                     请付" << h9->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete h7; delete h8; delete h9; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 8:

			cout << "              请选择玛奇朵+牛奶+糖+奶油的型号：" << endl;

			cout << "              1.大杯  2.中杯   3.小杯" << endl;

			cout << "              请输入对应的数字选择您想要的型号：";

			int a8;

			cin >> a8;

			switch (a8)

			{

			case 1:

			{

				coffee* i1 = new flavored_coffee;

				Add_Condiment* i2 = new has_milk;

				Add_Condiment* i3 = new has_sugar;

				Add_Condiment* i4 = new has_cream;

				i2->Decorate(i1);

				i3->Decorate(i2);

				i4->Decorate(i3);

				cout << endl << "                    请付" << i4->dabei_cost() << "元" << "谢谢！" << endl;

				delete i1; delete i2; delete i3; delete i4; break;

			}

			case 2:

			{

				coffee* i5 = new flavored_coffee;

				Add_Condiment* i6 = new has_milk;

				Add_Condiment* i7 = new has_sugar;

				Add_Condiment* i8 = new has_cream;

				i6->Decorate(i5);

				i7->Decorate(i6);

				i8->Decorate(i7);

				cout << endl << "                   请付" << i8->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete i5; delete i6; delete i7; delete i8; break;

			}

			case 3:

			{

				coffee* i9 = new flavored_coffee;

				Add_Condiment* i10 = new has_milk;

				Add_Condiment* i11 = new has_sugar;

				Add_Condiment* i12 = new has_cream;

				i10->Decorate(i9);

				i11->Decorate(i10);

				i12->Decorate(i11);

				cout << endl << "                  请付" << i12->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete i9; delete i10; delete i11; delete i12; break;

			}

			default:printf("输入有误！\n");

			}break;

		default:printf("输入有误！\n");

		}

	}break;

	case 4:

	{

		cout << "  ▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏" << endl;

		cout << "  ▕                  卡布奇诺系列有以下种类，请选择：                    ▏" << endl;

		cout << "  ▕ 1.卡布奇诺（纯）     2.卡布奇诺+牛奶        3.卡布奇诺+糖            ▏" << endl;

		cout << "  ▕ 4.卡布奇诺+奶油      5.卡布奇诺+牛奶+糖     6.卡布奇诺+牛奶+奶油     ▏" << endl;

		cout << "  ▕ 7.卡布奇诺+糖+奶油   8.卡布奇诺+牛奶+糖+奶油                         ▏" << endl;

		cout << "  ▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏" << endl;

		cout << "                       请输入数字选择您想要的咖啡:";

		int b;

		cin >> b;

		switch (b)

		{

		case 1:

			cout << "                  请选择卡布奇诺的型号：" << endl;

			cout << "                  1.大杯  2.中杯   3.小杯" << endl;

			cout << "                  请输入对应的数字选择您想要的型号：";

			int a1;

			cin >> a1;

			switch (a1)

			{

			case 1:

			{

				coffee* c1 = new caffelatte;

				cout << endl << "                    请付" << c1->dabei_cost() << "元！" << "谢谢！" << endl;

				delete c1; break;

			}

			case 2:

			{

				coffee* c2 = new caffelatte;

				cout << endl << "                    请付" << c2->zhongbei_cost() << "元！" << "谢谢！" << endl;

				delete c2; break;

			}

			case 3:

			{

				coffee* c3 = new caffelatte;

				cout << endl << "                    请付" << c3->xiaobei_cost() << "元！" << "谢谢！" << endl;

				delete c3; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 2:

			cout << "                请选择卡布奇诺+牛奶的型号：" << endl;

			cout << "                1.大杯  2.中杯   3.小杯" << endl;

			cout << "                请输入对应的数字选择您想要的型号：";

			int a2;

			cin >> a2;

			switch (a2)

			{

			case 1:

			{

				coffee* b1 = new caffelatte;

				Add_Condiment* b2 = new has_milk;

				b2->Decorate(b1);

				cout << endl << "                   请付" << b2->dabei_cost() << "元!" << "谢谢！" << endl;

				delete b1; delete b2; break;

			}

			case 2:

			{

				coffee* b3 = new caffelatte;

				Add_Condiment* b4 = new has_milk;

				b4->Decorate(b3);

				cout << endl << "                   请付" << b4->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete b3; delete b4; break;

			}

			case 3:

			{

				coffee* b5 = new caffelatte;

				Add_Condiment* b6 = new has_milk;

				b6->Decorate(b5);

				cout << endl << "                  请付" << b6->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete b5; delete b6; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 3:

			cout << "              请选择卡布奇诺+糖的型号：" << endl;

			cout << "              1.大杯  2.中杯   3.小杯" << endl;

			cout << "              请输入对应的数字选择您想要的型号：";

			int a3;

			cin >> a3;

			switch (a3)

			{

			case 1:

			{

				coffee* d1 = new caffelatte;

				Add_Condiment* d2 = new has_sugar;

				d2->Decorate(d1);

				cout << endl << "                 请付" << d2->dabei_cost() << "元！" << "谢谢！" << endl;

				delete d1; delete d2; break;

			}

			case 2:

			{

				coffee* d3 = new caffelatte;

				Add_Condiment* d4 = new has_sugar;

				d4->Decorate(d3);

				cout << endl << "                 请付" << d4->zhongbei_cost() << "元！" << "谢谢！" << endl;

				delete d3; delete d4; break;

			}

			case 3:

			{

				coffee* d5 = new caffelatte;

				Add_Condiment* d6 = new has_sugar;

				d6->Decorate(d5);

				cout << endl << "                 请付" << d6->xiaobei_cost() << "元！" << "谢谢！" << endl;

				delete d5; delete d6; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 4:

			cout << "            请选择卡布奇诺+奶油的型号：" << endl;

			cout << "            1.大杯  2.中杯   3.小杯" << endl;

			cout << "            请输入对应的数字选择您想要的型号：";

			int a4;

			cin >> a4;

			switch (a4)

			{

			case 1:

			{

				coffee* e1 = new caffelatte;

				Add_Condiment* e2 = new has_cream;

				e2->Decorate(e1);

				cout << endl << "                 请付" << e2->dabei_cost() << "元" << "谢谢！" << endl;

				delete e1; delete e2; break;

			}

			case 2:

			{

				coffee* e3 = new caffelatte;

				Add_Condiment* e4 = new has_cream;

				e4->Decorate(e3);

				cout << endl << "                  请付" << e4->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete e3; delete e4; break;

			}

			case 3:

			{

				coffee* e5 = new caffelatte;

				Add_Condiment* e6 = new has_cream;

				e6->Decorate(e5);

				cout << endl << "                  请付" << e6->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete e5; delete e6; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 5:

			cout << "            请选择卡布奇诺+牛奶+糖的型号：" << endl;

			cout << "            1.大杯  2.中杯   3.小杯" << endl;

			cout << "            请输入对应的数字选择您想要的型号：";

			int a5;

			cin >> a5;

			switch (a5)

			{

			case 1:

			{

				coffee* f1 = new caffelatte;

				Add_Condiment* f2 = new  has_milk;

				Add_Condiment* f3 = new has_sugar;

				f2->Decorate(f1);

				f3->Decorate(f2);

				cout << endl << "                    请付" << f3->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete f1; delete f2; delete f3; break;

			}

			case 2:

			{

				coffee* f4 = new caffelatte;

				Add_Condiment* f5 = new  has_milk;

				Add_Condiment* f6 = new has_sugar;

				f5->Decorate(f4);

				f6->Decorate(f5);

				cout << endl << "                   请付" << f6->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete f4; delete f5; delete f6; break;

			}

			case 3:

			{

				coffee* f7 = new caffelatte;

				Add_Condiment* f8 = new  has_milk;

				Add_Condiment* f9 = new has_sugar;

				f8->Decorate(f7);

				f9->Decorate(f8);

				cout << endl << "                   请付" << f9->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete f7; delete f8; delete f9; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 6:

			cout << "           请选择卡布奇诺+牛奶+奶油的型号：" << endl;

			cout << "           1.大杯  2.中杯   3.小杯" << endl;

			cout << "           请输入对应的数字选择您想要的型号：";

			int a6;

			cin >> a6;

			switch (a6)

			{

			case 1:

			{

				coffee* g1 = new caffelatte;

				Add_Condiment* g2 = new has_milk;

				Add_Condiment* g3 = new has_cream;

				g2->Decorate(g1);

				g3->Decorate(g2);

				cout << endl << "                    请付" << g3->dabei_cost() << "元" << "谢谢！" << endl;

				delete g1; delete g2; delete g3; break;

			}

			case 2:

			{

				coffee* g4 = new caffelatte;

				Add_Condiment* g5 = new has_milk;

				Add_Condiment* g6 = new has_cream;

				g5->Decorate(g4);

				g6->Decorate(g5);

				cout << endl << "                    请付" << g6->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete g4; delete g5; delete g6; break;

			}

			case 3:

			{

				coffee* g7 = new caffelatte;

				Add_Condiment* g8 = new has_milk;

				Add_Condiment* g9 = new has_cream;

				g8->Decorate(g7);

				g9->Decorate(g8);

				cout << endl << "                    请付" << g9->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete g7; delete g8; delete g9; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 7:

			cout << "           请选择卡布奇诺+糖+奶油的型号：" << endl;

			cout << "           1.大杯  2.中杯   3.小杯" << endl;

			cout << "           请输入对应的数字选择您想要的型号：";

			int a7;

			cin >> a7;

			switch (a7)

			{

			case 1:

			{

				coffee* h1 = new caffelatte;

				Add_Condiment* h2 = new has_sugar;

				Add_Condiment* h3 = new has_cream;

				h2->Decorate(h1);

				h3->Decorate(h2);

				cout << endl << "                    请付" << h3->dabei_cost() << "元" << "谢谢！" << endl;

				delete h1; delete h2; delete h3; break;

			}

			case 2:

			{

				coffee* h4 = new caffelatte;

				Add_Condiment* h5 = new has_sugar;

				Add_Condiment* h6 = new has_cream;

				h5->Decorate(h4);

				h6->Decorate(h5);

				cout << endl << "                    请付" << h6->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete h4; delete h5; delete h6; break;

			}

			case 3:

			{

				coffee* h7 = new caffelatte;

				Add_Condiment* h8 = new has_sugar;

				Add_Condiment* h9 = new has_cream;

				h8->Decorate(h7);

				h9->Decorate(h8);

				cout << endl << "                    请付" << h9->xiaobei_cost() << "元" << "谢谢！" << endl;

				delete h7; delete h8; delete h9; break;

			}

			default:printf("输入有误！\n");

			}break;

		case 8:

			cout << "           请选择卡布奇诺+牛奶+糖+奶油的型号：" << endl;

			cout << "           1.大杯  2.中杯   3.小杯" << endl;

			cout << "           请输入对应的数字选择您想要的型号：";

			int a8;

			cin >> a8;

			switch (a8)

			{

			case 1:

			{

				coffee* i1 = new caffelatte;

				Add_Condiment* i2 = new has_milk;

				Add_Condiment* i3 = new has_sugar;

				Add_Condiment* i4 = new has_cream;

				i2->Decorate(i1);

				i3->Decorate(i2);

				i4->Decorate(i3);

				cout << endl << "                    请付" << i4->dabei_cost() << "元" << "谢谢！" << endl;

				delete i1; delete i2; delete i3; delete i4; break;

			}

			case 2:

			{

				coffee* i5 = new caffelatte;

				Add_Condiment* i6 = new has_milk;

				Add_Condiment* i7 = new has_sugar;

				Add_Condiment* i8 = new has_cream;

				i6->Decorate(i5);

				i7->Decorate(i6);

				i8->Decorate(i7);

				cout << endl << "                     请付" << i8->zhongbei_cost() << "元" << "谢谢！" << endl;

				delete i5; delete i6; delete i7; delete i8; break;

			}

			case 3:

			{

				coffee* i9 = new caffelatte;

				Add_Condiment* i10 = new has_milk;

				Add_Condiment* i11 = new has_sugar;

				Add_Condiment* i12 = new has_cream;

				i10->Decorate(i9);

				i11->Decorate(i10);

				i12->Decorate(i11);

				cout << endl << "                     请付" << i12->xiaobei_cost() << "元" << "谢谢！" << endl;
				delete i9; delete i10; delete i11; delete i12; break;
			}
			default:printf("输入有误！\n");
			}break;
		default:printf("输入有误！\n");
		}
	}break;
	default:printf("输入有误！\n");
	}
	system("pause");
}
//增加客人信息
void AddInformation()								
{	
	int placed=0;
	STU* vIew = NULL;

	system("cls");

	placed=0;
	pNew = (STU *)malloc(sizeof(STU));			
	pNew->pnext = NULL;
	printf("\t请输入要增加的客人信息:\n");

	printf("\t座位号:");
	scanf("%s",pNew->num);
	//信息检查
	NumberCheck(pNew->num,"座位号");


	printf("\t姓名:");
	scanf("%s",pNew->name);
	
	
	printf("\t消费额:");
	scanf("%s",pNew->xiaofei);
	//信息检查
	SecureCheck(pNew->xiaofei,"消费额");

	vIew = (STU *)malloc(sizeof(STU));
	
	if(pStu->pnext==NULL)
		pStu->pnext=pNew;
	else								//查找最佳位置进行升序插入节点, 维护学号升序顺序的插入
	{	
		vIew->pnext=pStu;
		while(vIew->pnext->pnext!=NULL)
		{
			if(strcmp(vIew->pnext->num , pNew->num)<=0 && strcmp(vIew->pnext->pnext->num ,pNew->num)>=0)
			{	
			
				pNew->pnext = vIew->pnext->pnext;
				vIew->pnext->pnext = pNew;
				placed=1;				//表示已经放置
				break;
				
			}
			vIew->pnext = vIew->pnext->pnext;
		}
		if(placed==0)
			vIew->pnext->pnext = pNew;	//没有找到合适的节点，把pNew挂在链表最后面
		
	}
	
	free(vIew);
	vIew=NULL;
	
}
//显示信息
void ShowInformation()					
{
	STU* vIew = NULL;

	system("cls");
	printf("\n\t┍====================显示信息====================┑\n");
	
	
	vIew = (STU *)malloc(sizeof(STU));

	vIew->pnext=pStu->pnext;
	if(vIew->pnext==NULL)
	{
		printf("\n\t\t当前系统内没有客人信息");
	}
	else
	{
		while(vIew->pnext!=NULL)
		{
		printf("\t座位号:%s\n",vIew->pnext->num);
		printf("\t姓名:%s\n",vIew->pnext->name);
		printf("\t消费额:%s\n",vIew->pnext->xiaofei);
		printf("\n\t...................................................\n");
		vIew->pnext=vIew->pnext->pnext;
		}
	}
	free(vIew);
	vIew=NULL;

	printf("\n\t┕====================显示信息完毕================┙\n");

}

//查找信息
void Search()						
{
	char serach[N];
	int flag=0;
	char choice='0';
	STU* vIew = NULL;

	system("cls");
									//选择查找的根据[座位号/姓名]
	printf("\n\t输入指令\t 1、按照座位号查找 \t2、按照姓名查找\n");
	choice = getch();

	if(choice=='1')
		printf("\t请输入要查找的客人的座位号:\n");
	else if(choice=='2')
		printf("\t请输入要查找的客人的姓名:\n");
	else
		printf("\t您的指令输入有误！已经退出查找\n");

	if(choice=='1'||choice=='2')	//如果指令是正确的
	{
		scanf("%s",serach);

	
		vIew = (STU *)malloc(sizeof(STU));

		vIew->pnext=pStu->pnext;
		while(vIew->pnext!=NULL)
		{
			if((strcmp(vIew->pnext->num,serach)==0&&choice == '1')||(strcmp(vIew->pnext->name,serach)==0&&choice == '2'))
			{flag=1;
			printf("\t座位号:%s\n",vIew->pnext->num);
			printf("\t姓名:%s\n",vIew->pnext->name);
			printf("\t消费额:%s\n",vIew->pnext->xiaofei);
			printf("\n\t...................................................\n");
			}
		vIew->pnext=vIew->pnext->pnext;
		}
		free(vIew);
		vIew=NULL;

		if(!flag)
		printf("\n!!!!!!!!!!!!!!!!!!!!对不起，查无此人!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}

}
//删除信息
void Delete()							
{	
	STU *temp;
	char num_serach[N];
	int flag=0;
	STU* vIew = NULL;

	system("cls");

	temp=(STU *)malloc(sizeof(STU));
	
	
	printf("\n\t请输入要删除的客人的座位号:\n");
	scanf("%s",num_serach);



	vIew = (STU *)malloc(sizeof(STU));
	
	vIew->pnext=pStu;
	while(vIew->pnext->pnext!=NULL)
	{
		if(strcmp(vIew->pnext->pnext->num,num_serach)==0)		//匹配到了座位号
		{
		flag=1;
		printf("\n\n\t待删除的客人信息为:\n");
		printf("\t座位号:%s\n",vIew->pnext->pnext->num);
		printf("\t姓名:%s\n",vIew->pnext->pnext->name);
		printf("\t消费额:%s\n",vIew->pnext->pnext->xiaofei);
		
		temp ->pnext=vIew->pnext->pnext;						//temp->next保存将要删除的节点的地址
		vIew->pnext->pnext=vIew->pnext->pnext->pnext;			//绕过将要删除的节点

		free(temp->pnext);										//释放已经被绕过的节点，节省空间
		
		printf("\n\t待删除的客人信息已经删除\n");			
		printf("\n\t...................................................\n");
		break;													//删除一个节点之后，跳出循环体
		}
		vIew->pnext=vIew->pnext->pnext;
	}

	free(vIew);
	vIew=NULL;
	free(temp);
	temp=NULL;

	if(!flag)
	printf("\n!!!!!!!!!!!!!!!!!!!!对不起，查无此人!!!!!!!!!!!!!!!!!!!!!!!!!\n");

}
//修改信息
void Modify()								
{	
	char num_serach[N];
	int flag=0;
	STU* vIew = NULL;
	
	system("cls");
	
	printf("\n\t请输入要修改的客人的座位号的消费额:\n");
	scanf("%s",num_serach);

	
	vIew = (STU *)malloc(sizeof(STU));

	vIew->pnext=pStu->pnext;
	while(vIew->pnext!=NULL)
	{
		if(strcmp(vIew->pnext->num,num_serach)==0)
		{
			flag=1;
		printf("\t座位号:%s\n",vIew->pnext->num);
		printf("\t姓名:%s\n",vIew->pnext->name);
		printf("\t消费额:%s\n",vIew->pnext->xiaofei);
		printf("\t修改成:\n");
		//新信息的输入
		printf("\t消费额:\n");
		scanf("%s",vIew->pnext->xiaofei);
		//信息检查
		SecureCheck(vIew->pnext->xiaofei,"消费额");

		//信息检查
		
		//AddInformation();	//原则上不修改座位号和姓名；但如果要；可以直接用AddInformation()函数
							//去代替新信息的输入
		printf("\n\t...................................................\n");
		}
		vIew->pnext=vIew->pnext->pnext;
	}
	free(vIew);
	vIew=NULL;

	if(!flag)
	printf("\n!!!!!!!!!!!!!!!!!!!!对不起，查无此人!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	
}
//数据统计
void Statistical()
{
	double sumprice = 0;
	double sumprices= 0;
	int    Number   = 0;
	int    Over18   = 0;
	int    Below15  = 0;   
	STU *View = NULL;
	View = pStu->pnext;
	
	system("cls");

	printf("\t进行数据统计:\n");
	while(View!=NULL)
	{	
		sumprice =  atof(View->xiaofei);
		if(atof(View->xiaofei)<15)
		{
			Below15++;
		}
		if(atof(View->xiaofei)>=18)
		{
			Over18++;
		}
			if(atof(View->xiaofei)>0)
		{
			sumprices = atof(View->xiaofei)+sumprices;
		}

		Number++;
		
		View = View->pnext;
		
	}
	printf("\n\t客人的总人数是:%d",Number);

	if(Number!=0)
		printf("\n\t客人们的平均消费是:%.2f",sumprices/Number);
	else
		printf("\n\t客人们的平均消费是:0");

	printf("\n\t客人总消费额是:%.2f",sumprices);
	printf("\n\t存在消费不足15元的客人的人数是:%d",Below15);
	printf("\n\t存在消费超过18元的客人的人数是:%d",Over18);
}
//保存信息
void save_file()								
{	
	FILE *file=NULL;
	STU* vIew = NULL;


	file = fopen("C:\\student_file.txt","w+");
	if(file==NULL)
		printf("文件打开失败!\n");
	
	vIew = (STU *)malloc(sizeof(STU));

	vIew->pnext=pStu->pnext;
	while(vIew->pnext!=NULL)
	{
	fputs(vIew->pnext->num,file);
	fputc(0x20,file);
	fputs(vIew->pnext->name,file);
	fputc(0x20,file);
	fputs(vIew->pnext->xiaofei,file);
	fputc(0x20,file);
	vIew->pnext=vIew->pnext->pnext;
	}
	free(vIew);
	vIew=NULL;	
	
	fputs("END_OF_FILE",file);
	fputc(0x20,file);

	fclose(file);
}
//从文件读入信息
void read_file()								
{	
	int i=0;

	
	FILE *file=NULL;
	file = fopen("C:\\student_file.txt","r");

	if(file==NULL)
	{
		save_file();
		file = fopen("C:\\student_file.txt","r");
	}

	rewind(file);

	pCurrent ->pnext =pStu;
		
	while(1)
	{	pNew = (STU *)malloc(sizeof(STU));
		pNew->pnext = NULL;


		fscanf(file,"%s",pNew->num);
		if(strcmp(pNew->num,"END_OF_FILE")==0)	break;

		fscanf(file,"%s",pNew->name);
		fscanf(file,"%s",pNew->xiaofei);
		
		pCurrent->pnext->pnext=pNew;			
		pCurrent->pnext = pCurrent->pnext->pnext;
		//pCurrent->pnext指向现在存在的节点
	
	}
	fclose(file);

}
//短暂延时效果
void Delay()															
{
	int i = 0;
	int j = 0;

	for(i=50000;i>0;i--)
		for(j=5000;j>0;j--)
			;
}
//系统初始化
void init()		
{
	pStu = (STU *)malloc(sizeof(STU));					//创建头节点
	pStu->pnext  =NULL;
	strcpy(pStu->num, "0");
	strcpy(pStu->name, " ");

	pCurrent = (STU *)malloc(sizeof(STU));
	pCurrent ->pnext =NULL;

	read_file();

}
//欢迎使用
void Welcome()									
{	system("cls");
	
	printf("\n\n\t┌================================================┑\n");
	printf("\n\n");
	printf("\t\t★★★欢迎来到腾龍咖啡厅管理系统★★★\n\n\n");
	printf("\t\t\t1.请尊贵的顾客点单\n");
	printf("\t\t\t2.查看顾客信息\n");
	printf("\t\t\t3.增加顾客信息\n");
	printf("\t\t\t4.查找顾客信息\n");
	printf("\t\t\t5.修改顾客信息\n");
	printf("\t\t\t6.删除顾客信息\n");
	printf("\t\t\t7.营业额统计\n");
	printf("\t\t\t8.退出系统\n");
	printf("\n\n\t┕================================================┚\n");
}
/************************************主函数************************************/
int main()
{
	char choice  = 0;
	char AddYorN = 0;

	init();
	InCheck();
	Welcome();
//	MessageBox(0, "", 0);

															//命令解释
	
	while(choice!='8')
	{	
		printf("\n>>");										//输入命令
		choice=getch();
		printf("%c",choice);

		switch(choice)
		{
			case '1':diandan();		
				break;
			case '2':ShowInformation();		
				break;
			case '3':	do
						{
							AddInformation();	save_file();
							printf("输入N可以退出增加信息.任意键继续输入\n");AddYorN=getch();printf("%c",AddYorN);
						}while(AddYorN!='N');
				break;	
			case '4':Search();
				break;	
			case '5':Modify();	save_file();	
				break;
			case '6':Delete();	save_file();
				break;
			case '7':Statistical();
				break;
			case '8':
				break;
			default:printf("\t\t任意键返回主菜单\n");getch();Welcome();
			
		}
}
	
    system("cls");
	system("color 81");
	printf("\n\t\t感谢您的使用，再见!\n");
	Delay();

	
	save_file();
	return 0;

}



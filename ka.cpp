/**********************************����������ϵͳ********************************************
		�ļ�����:	1.c
		�ļ�����:	���� + �ļ� ���׵Ŀ���������ϵͳ
		���뻷����	VC6.0
		����޸ģ�	<2020��05��16��><����ͳ�ƹ���><Yang>
		��    �ܣ�	���� ��ʾ �޸� ɾ�� �浵 ������Ϣ
		˵    ����	�浵��C:\\student_file.txt
	
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
/*********************************�궨��*****************************************/
#define N 100				//�ṹ��������Ĵ�С
/*********************************��������***************************************/
void save_file();	
void Delay();
/*********************************��������***************************************/		
//�����࣬����

class coffee

{

public:

	virtual float dabei_cost() = 0;

	virtual float zhongbei_cost() = 0;

	virtual float xiaobei_cost() = 0;

};



//�����࣬Ũ������

class black_coffee :public coffee

{

public:

	virtual float dabei_cost() //�󱭼۸�

	{

		return 15.0;

	}



	virtual float zhongbei_cost()//�б��۸�

	{

		return 10.0;

	}



	virtual float xiaobei_cost()//С���۸�

	{

		return 5.0;

	}

};



//�����࣬��ʽ����

class white_coffee :public coffee

{

public:

	virtual float dabei_cost()//�󱭼۸�

	{

		return 18.0;

	}



	virtual float zhongbei_cost()//�б��۸�

	{

		return 14.0;

	}



	virtual float xiaobei_cost()//С���۸�

	{

		return 10.0;

	}

};



//�����࣬����俧��

class flavored_coffee :public coffee

{

public:

	virtual float dabei_cost()//�󱭼۸�

	{

		return 20.0;

	}



	virtual float zhongbei_cost()//�б��۸�

	{

		return 15.0;

	}



	virtual float xiaobei_cost()//С���۸�

	{

		return 10.0;

	}

};



//�����࣬������ŵ����

class caffelatte :public coffee

{

public:

	virtual float dabei_cost()//�󱭼۸�

	{

		return 25.0;

	}



	virtual float zhongbei_cost()//�б��۸�

	{

		return 20.0;

	}



	virtual float xiaobei_cost()//С���۸�

	{

		return 15.0;

	}

};



//װ�����࣬�����ȼ��������ֵ�ζƷ

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



//�����ȼ�ţ��

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



//�����ȼ���

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



//�����ȼ�����

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

/*********************************�Զ�����������*********************************/
typedef struct stu
{
	char num[N];			//��λ��
	char name[N];			//����
	char xiaofei[N];		//���Ѷ� 

	struct stu* pnext;

}STU;
/*********************************ȫ�ֱ�������*********************************/
STU* pStu = NULL;			//��ͷ
STU* pCurrent = NULL;		//��ǰ�˿ͣ��Ѿ����ڣ�
STU* pNew=NULL;				//��ǰ�˿ͣ������룩
char KEY[7];				//��������
/*********************************�Ӻ�������***********************************/
//��½��֤	
void InCheck()							
{	
	int InputLimit= 0;
	char keynumber[7]="0";
	int i = 0;

	srand((unsigned)time(NULL));		//���������֤��
	for(i=0;i<6;i++)
	{
		KEY[i] = rand() % 10  + 48; 
	}
	KEY[6] = '\0';

	system("cls");
	system("color 3e");

	printf("\n\n\t��================================================��\n");
	printf("\n\n");
	printf("\t\t\t��ӭʹ�ÿ���������ϵͳ\n");
	printf("\t\t\t\t\n");
	printf("\t\t\t\t\n");
	printf("\t\t\t\t\n");
	printf("\t\t\t��������֤���½��ϵͳ\n");
	printf("\t\t\t<��֤����%s>\n",KEY);
	printf("\t\t\t \n");
	printf("\t\t\t���3�����������ȷ�����˳�ϵͳ\n");

	printf("\n\n\t��================================================��\n");
	
	
	scanf("%s",keynumber);
	while(strcmp(keynumber,KEY)!=0)
	{	InputLimit++;
		if(InputLimit==3)
		{	printf("\t���������Ĵ����Ѿ�����%d��,�����˳�ϵͳ",InputLimit);
			Delay();
			exit(0);
		}
		printf("\n\t\t������������!����������\n");
		scanf("%s",keynumber);
	}

	system("cls");
	
}
//�����Ϣ�Ϸ���:����Ķ��������ַ���
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
		{	printf("\t�����벻�Ϸ�������������\n");
			return 1;
		}

	}
	if(PointCount>1)
	{	printf("\t�����벻�Ϸ�������������\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
//�������Ϣ�ݴ���ڴ���[��InformationCheck,ȷ��û���ش����֮��]
void InformationDebug(char *str)	
{
	int L = 0;
	char PointFlag=0;
	int IntCount = 0;
	int FloatCount = 0;			//С������
	int i = 0;	
	int PositionOfPoint = 0;	//С�������ڵ��±�
	int ZeroPre = 0;			//���õ�0�ĸ���
	char NotZeroStartFlag=0;	//�ַ����п�ʼ�����˵�һ��1-9�������ַ�

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

		if((PointFlag==0)&&(NotZeroStartFlag==0)&&(str[i]=='0')&&(str[i+1]!='.'))	//�����'0'
			ZeroPre++;
	}

	if(IntCount==0)								//û����������?
	{
		for(i=L;i>0;i--)
		{
			str[i]=str[i-1];
		}
		str[0] = '0';
		str[L+1] = '\0';
		PositionOfPoint++;
	}
	if(FloatCount==0&&PointFlag == 1)			//��С����ȴû��С�����֣�
	{
		str[PositionOfPoint+1] = '0';
		str[PositionOfPoint+2] = '\0';
	}
	if(ZeroPre>0)
	{
		strcpy(str,str+ZeroPre);
	}
	if(!NotZeroStartFlag)						//�ַ����д���û�г��ֹ�1 -9 �ַ�
	{
		strcpy(str,"0");
	}
}
//�����Ϣ�Ϸ���:��û���������λ���Ѿ����ڣ�
char NumCheck(const char *str)			
{
	STU * View = NULL;
	int L = 0;
	int i = 0;

	View = pStu->pnext;


	while(View!=NULL)
	{
		if(strcmp(str,View->num)==0)
		{	printf("\t���������λ���Ѿ����ڣ�����������\n");
			return 1;
		}
		View=View->pnext;
	}
										//�����ѧ������0 -9 ֮�ڵ��ַ���
	L = strlen(str);
	for(i=0;i<L;i++)
	{	
		if(str[i]<'0'||str[i]>'9')
		{	printf("\t��������ַ�Ӧ��'0'-'9'֮�����룬����������\n");
			return 1;
		}
	}

	return 0;


}
//��Ϣ���ּ�飬,ֻ����ַ��������ǲ���ֻ�� '0' - '9' �ַ�
void NumberCheck(char *str,char *Display)
{
	while(NumCheck(str))
	{
		printf("\t%s:",Display);
		scanf("%s",str);

	}
}
//��Ϣ�����죬����������ַ��������ǲ����г���'0' - '9'��'.'������ַ������������������'0'�Ĳ���
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

	cout << "                                ��ӭ���ٱ���!                                   " << endl;

	cout << "*******************************��ѡ�񿧷�ϵ��********************************" << endl;

	cout << "  ��������������������������������������������������������������������������" << endl;

	cout << "  ��  1.Ũ��ϵ��     2.��ʽϵ��     3.�����ϵ��       4.������ŵϵ��     ��" << endl;

	cout << "  ���x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x��" << endl;

	int choie;

	cout << "                         ����������ѡ���Ӧ�Ŀ���ϵ�У�";

	cin >> choie;

	switch (choie)

	{

	case 1:

	{

		cout << "  ��������������������������������������������������������������������������" << endl;

		cout << "  ��                Ũ������ϵ�����������࣬��ѡ��                      ��" << endl;

		cout << "  �� 1.Ũ�����ȣ�����  2.Ũ������+ţ��   3.Ũ������+��    4.Ũ������+���� ��" << endl;

		cout << "  �� 5.Ũ������+ţ��+��    6.Ũ������+ţ��+����     7.Ũ������+��+����    ��" << endl;

		cout << "  �� 8.Ũ������+ţ��+��+����                                              ��" << endl;

		cout << "  ���x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x��" << endl;

		cout << "                       ����������ѡ������Ҫ�Ŀ���:";

		int a;

		cin >> a;

		switch (a)

		{

		case 1:

			cout << "                           ��ѡ��Ũ�����ȵ��ͺţ�" << endl;

			cout << "                           1.��  2.�б�   3.С��" << endl;

			cout << "                           �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a1;

			cin >> a1;

			switch (a1)

			{

			case 1:

			{

				coffee* c1 = new black_coffee;

				cout << endl << "                         �븶" << c1->dabei_cost() << "Ԫ��" << "лл��" << endl;

				delete c1; break;

			}

			case 2:

			{

				coffee* c2 = new black_coffee;

				cout << endl << "                         �븶" << c2->zhongbei_cost() << "Ԫ��" << "лл��" << endl;

				delete c2; break;

			}

			case 3:

			{

				coffee* c3 = new black_coffee;

				cout << endl << "                        �븶" << c3->xiaobei_cost() << "Ԫ��" << "лл��" << endl;

				delete c3; break;

			}

			default:printf("��������\n");

			}break;

		case 2:

			cout << "                         ��ѡ��Ũ������+ţ�̵��ͺţ�" << endl;

			cout << "                         1.��  2.�б�   3.С��" << endl;

			cout << "                         �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a2;

			cin >> a2;

			switch (a2)

			{

			case 1:

			{

				coffee* b1 = new black_coffee;

				Add_Condiment* b2 = new has_milk;

				b2->Decorate(b1);

				cout << endl << "                         �븶" << b2->dabei_cost() << "Ԫ!" << "лл��" << endl;

				delete b1; delete b2; break;

			}

			case 2:

			{

				coffee* b3 = new black_coffee;

				Add_Condiment* b4 = new has_milk;

				b4->Decorate(b3);

				cout << endl << "                         �븶" << b4->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete b3; delete b4; break;

			}

			case 3:

			{

				coffee* b5 = new black_coffee;

				Add_Condiment* b6 = new has_milk;

				b6->Decorate(b5);

				cout << endl << "                        �븶" << b6->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete b5; delete b6; break;

			}

			default:printf("��������\n");

			}break;

		case 3:

			cout << "                         ��ѡ��Ũ������+�ǵ��ͺţ�" << endl;

			cout << "                         1.��  2.�б�   3.С��" << endl;

			cout << "                         �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a3;

			cin >> a3;

			switch (a3)

			{

			case 1:

			{

				coffee* d1 = new black_coffee;

				Add_Condiment* d2 = new has_sugar;

				d2->Decorate(d1);

				cout << endl << "                      �븶" << d2->dabei_cost() << "Ԫ��" << "лл��" << endl;

				delete d1; delete d2; break;

			}

			case 2:

			{

				coffee* d3 = new black_coffee;

				Add_Condiment* d4 = new has_sugar;

				d4->Decorate(d3);

				cout << endl << "                     �븶" << d4->zhongbei_cost() << "Ԫ��" << "лл��" << endl;

				delete d3; delete d4; break;

			}

			case 3:

			{

				coffee* d5 = new black_coffee;

				Add_Condiment* d6 = new has_sugar;

				d6->Decorate(d5);

				cout << endl << "                     �븶" << d6->xiaobei_cost() << "Ԫ��" << "лл��" << endl;

				delete d5; delete d6; break;

			}

			default:printf("��������\n");

			}break;

		case 4:

			cout << "                        ��ѡ��Ũ������+���͵��ͺţ�" << endl;

			cout << "                        1.��  2.�б�   3.С��" << endl;

			cout << "                        �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a4;

			cin >> a4;

			switch (a4)

			{

			case 1:

			{

				coffee* e1 = new black_coffee;

				Add_Condiment* e2 = new has_cream;

				e2->Decorate(e1);

				cout << endl << "                    �븶" << e2->dabei_cost() << "Ԫ" << "лл��" << endl;

				delete e1; delete e2; break;

			}

			case 2:

			{

				coffee* e3 = new black_coffee;

				Add_Condiment* e4 = new has_cream;

				e4->Decorate(e3);

				cout << endl << "                   �븶" << e4->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete e3; delete e4; break;

			}

			case 3:

			{

				coffee* e5 = new black_coffee;

				Add_Condiment* e6 = new has_cream;

				e6->Decorate(e5);

				cout << endl << "                  �븶" << e6->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete e5; delete e6; break;

			}

			default:printf("��������\n");

			}break;

		case 5:

			cout << "                    ��ѡ��Ũ������+ţ��+�ǵ��ͺţ�" << endl;

			cout << "                    1.��  2.�б�   3.С��" << endl;

			cout << "                    �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                   �븶" << f3->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete f1; delete f2; delete f3; break;

			}

			case 2:

			{

				coffee* f4 = new black_coffee;

				Add_Condiment* f5 = new  has_milk;

				Add_Condiment* f6 = new has_sugar;

				f5->Decorate(f4);

				f6->Decorate(f5);

				cout << endl << "                   �븶" << f6->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete f4; delete f5; delete f6; break;

			}

			case 3:

			{

				coffee* f7 = new black_coffee;

				Add_Condiment* f8 = new  has_milk;

				Add_Condiment* f9 = new has_sugar;

				f8->Decorate(f7);

				f9->Decorate(f8);

				cout << endl << "                   �븶" << f9->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete f7; delete f8; delete f9; break;

			}

			default:printf("��������\n");

			}break;

		case 6:

			cout << "                  ��ѡ��Ũ������+ţ��+���͵��ͺţ�" << endl;

			cout << "                  1.��  2.�б�   3.С��" << endl;

			cout << "                  �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                   �븶" << g3->dabei_cost() << "Ԫ" << "лл��" << endl;

				delete g1; delete g2; delete g3; break;

			}

			case 2:

			{

				coffee* g4 = new black_coffee;

				Add_Condiment* g5 = new has_milk;

				Add_Condiment* g6 = new has_cream;

				g5->Decorate(g4);

				g6->Decorate(g5);

				cout << endl << "                   �븶" << g6->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete g4; delete g5; delete g6; break;

			}

			case 3:

			{

				coffee* g7 = new black_coffee;

				Add_Condiment* g8 = new has_milk;

				Add_Condiment* g9 = new has_cream;

				g8->Decorate(g7);

				g9->Decorate(g8);

				cout << endl << "                   �븶" << g9->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete g7; delete g8; delete g9; break;

			}

			default:printf("��������\n");

			}break;

		case 7:

			cout << "                 ��ѡ��Ũ������+��+���͵��ͺţ�" << endl;

			cout << "                 1.��  2.�б�   3.С��" << endl;

			cout << "                 �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                   �븶" << h3->dabei_cost() << "Ԫ" << "лл��" << endl;

				delete h1; delete h2; delete h3; break;

			}

			case 2:

			{

				coffee* h4 = new black_coffee;

				Add_Condiment* h5 = new has_sugar;

				Add_Condiment* h6 = new has_cream;

				h5->Decorate(h4);

				h6->Decorate(h5);

				cout << endl << "                    �븶" << h6->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete h4; delete h5; delete h6; break;

			}

			case 3:

			{

				coffee* h7 = new black_coffee;

				Add_Condiment* h8 = new has_sugar;

				Add_Condiment* h9 = new has_cream;

				h8->Decorate(h7);

				h9->Decorate(h8);

				cout << endl << "                    �븶" << h9->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete h7; delete h8; delete h9; break;

			}

			default:printf("��������\n");

			}break;

		case 8:

			cout << "                ��ѡ��Ũ������+ţ��+��+���͵��ͺţ�" << endl;

			cout << "                1.��  2.�б�   3.С��" << endl;

			cout << "                �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                      �븶" << i4->dabei_cost() << "Ԫ" << "лл��" << endl;

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

				cout << endl << "                     �븶" << i8->zhongbei_cost() << "Ԫ" << "лл��" << endl;

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

				cout << endl << "                    �븶" << i12->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete i9; delete i10; delete i11; delete i12; break;

			}

			default:printf("��������\n");

			}break;

		default:printf("��������\n");

		}

	}break;

	case 2:

	{

		cout << "  ��������������������������������������������������������������������������" << endl;

		cout << "  ��                  ��ʽ����ϵ�����������࣬��ѡ��                    ��" << endl;

		cout << "  �� 1.��ʽ���ȣ�����   2.��ʽ����+ţ��    3.��ʽ����+��  4.��ʽ����+���� ��" << endl;

		cout << "  �� 5.��ʽ����+ţ��+��    6.��ʽ����+ţ��+����      7.��ʽ����+��+����   ��" << endl;

		cout << "  �� 8.��ʽ����+ţ��+��+����                                              ��" << endl;

		cout << "  ���x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x��" << endl;

		cout << "                       ����������ѡ������Ҫ�Ŀ���:";

		int b;

		cin >> b;

		switch (b)

		{

		case 1:

			cout << "                   ��ѡ����ʽ���ȵ��ͺţ�" << endl;

			cout << "                   1.��  2.�б�   3.С��" << endl;

			cout << "                   �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a1;

			cin >> a1;

			switch (a1)

			{

			case 1:

			{

				coffee* c1 = new white_coffee;

				cout << endl << "                    �븶" << c1->dabei_cost() << "Ԫ��" << "лл��" << endl;

				delete c1; break;

			}

			case 2:

			{

				coffee* c2 = new white_coffee;

				cout << endl << "                    �븶" << c2->zhongbei_cost() << "Ԫ��" << "лл��" << endl;

				delete c2; break;

			}

			case 3:

			{

				coffee* c3 = new white_coffee;

				cout << endl << "                    �븶" << c3->xiaobei_cost() << "Ԫ��" << "лл��" << endl;

				delete c3; break;

			}

			default:printf("��������\n");

			}break;

		case 2:

			cout << "                 ��ѡ����ʽ����+ţ�̵��ͺţ�" << endl;

			cout << "                 1.��  2.�б�   3.С��" << endl;

			cout << "                 �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a2;

			cin >> a2;

			switch (a2)

			{

			case 1:

			{

				coffee* b1 = new white_coffee;

				Add_Condiment* b2 = new has_milk;

				b2->Decorate(b1);

				cout << endl << "                     �븶" << b2->dabei_cost() << "Ԫ!" << "лл��" << endl;

				delete b1; delete b2; break;

			}

			case 2:

			{

				coffee* b3 = new white_coffee;

				Add_Condiment* b4 = new has_milk;

				b4->Decorate(b3);

				cout << endl << "                    �븶" << b4->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete b3; delete b4; break;

			}

			case 3:

			{

				coffee* b5 = new white_coffee;

				Add_Condiment* b6 = new has_milk;

				b6->Decorate(b5);

				cout << endl << "                    �븶" << b6->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete b5; delete b6; break;

			}

			default:printf("��������\n");

			}break;

		case 3:

			cout << "               ��ѡ����ʽ����+�ǵ��ͺţ�" << endl;

			cout << "               1.��  2.�б�   3.С��" << endl;

			cout << "               �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a3;

			cin >> a3;

			switch (a3)

			{

			case 1:

			{

				coffee* d1 = new white_coffee;

				Add_Condiment* d2 = new has_sugar;

				d2->Decorate(d1);

				cout << endl << "                    �븶" << d2->dabei_cost() << "Ԫ��" << "лл��" << endl;

				delete d1; delete d2; break;

			}

			case 2:

			{

				coffee* d3 = new white_coffee;

				Add_Condiment* d4 = new has_sugar;

				d4->Decorate(d3);

				cout << endl << "                    �븶" << d4->zhongbei_cost() << "Ԫ��" << "лл��" << endl;

				delete d3; delete d4; break;

			}

			case 3:

			{

				coffee* d5 = new white_coffee;

				Add_Condiment* d6 = new has_sugar;

				d6->Decorate(d5);

				cout << endl << "                  �븶" << d6->xiaobei_cost() << "Ԫ��" << "лл��" << endl;

				delete d5; delete d6; break;

			}

			default:printf("��������\n");

			}break;

		case 4:

			cout << "              ��ѡ����ʽ����+���͵��ͺţ�" << endl;

			cout << "              1.��  2.�б�   3.С��" << endl;

			cout << "              �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a4;

			cin >> a4;

			switch (a4)

			{

			case 1:

			{

				coffee* e1 = new white_coffee;

				Add_Condiment* e2 = new has_cream;

				e2->Decorate(e1);

				cout << endl << "                 �븶" << e2->dabei_cost() << "Ԫ" << "лл��" << endl;

				delete e1; delete e2; break;

			}

			case 2:

			{

				coffee* e3 = new white_coffee;

				Add_Condiment* e4 = new has_cream;

				e4->Decorate(e3);

				cout << endl << "                 �븶" << e4->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete e3; delete e4; break;

			}

			case 3:

			{

				coffee* e5 = new white_coffee;

				Add_Condiment* e6 = new has_cream;

				e6->Decorate(e5);

				cout << endl << "                 �븶" << e6->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete e5; delete e6; break;

			}

			default:printf("��������\n");

			}break;

		case 5:

			cout << "            ��ѡ����ʽ����+ţ��+�ǵ��ͺţ�" << endl;

			cout << "            1.��  2.�б�   3.С��" << endl;

			cout << "            �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                  �븶" << f3->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete f1; delete f2; delete f3; break;

			}

			case 2:

			{

				coffee* f4 = new white_coffee;

				Add_Condiment* f5 = new  has_milk;

				Add_Condiment* f6 = new has_sugar;

				f5->Decorate(f4);

				f6->Decorate(f5);

				cout << endl << "                  �븶" << f6->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete f4; delete f5; delete f6; break;

			}

			case 3:

			{

				coffee* f7 = new white_coffee;

				Add_Condiment* f8 = new  has_milk;

				Add_Condiment* f9 = new has_sugar;

				f8->Decorate(f7);

				f9->Decorate(f8);

				cout << endl << "                  �븶" << f9->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete f7; delete f8; delete f9; break;

			}

			default:printf("��������\n");

			}break;

		case 6:

			cout << "            ��ѡ����ʽ����+ţ��+���͵��ͺţ�" << endl;

			cout << "            1.��  2.�б�   3.С��" << endl;

			cout << "            �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                    �븶" << g3->dabei_cost() << "Ԫ" << "лл��" << endl;

				delete g1; delete g2; delete g3; break;

			}

			case 2:

			{

				coffee* g4 = new white_coffee;

				Add_Condiment* g5 = new has_milk;

				Add_Condiment* g6 = new has_cream;

				g5->Decorate(g4);

				g6->Decorate(g5);

				cout << endl << "                   �븶" << g6->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete g4; delete g5; delete g6; break;

			}

			case 3:

			{

				coffee* g7 = new white_coffee;

				Add_Condiment* g8 = new has_milk;

				Add_Condiment* g9 = new has_cream;

				g8->Decorate(g7);

				g9->Decorate(g8);

				cout << endl << "                   �븶" << g9->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete g7; delete g8; delete g9; break;

			}

			default:printf("��������\n");

			}break;

		case 7:

			cout << "           ��ѡ����ʽ����+��+���͵��ͺţ�" << endl;

			cout << "           1.��  2.�б�   3.С��" << endl;

			cout << "           �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                       �븶" << h3->dabei_cost() << "Ԫ" << "лл��" << endl;

				delete h1; delete h2; delete h3; break;

			}

			case 2:

			{

				coffee* h4 = new white_coffee;

				Add_Condiment* h5 = new has_sugar;

				Add_Condiment* h6 = new has_cream;

				h5->Decorate(h4);

				h6->Decorate(h5);

				cout << endl << "                       �븶" << h6->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete h4; delete h5; delete h6; break;

			}

			case 3:

			{

				coffee* h7 = new white_coffee;

				Add_Condiment* h8 = new has_sugar;

				Add_Condiment* h9 = new has_cream;

				h8->Decorate(h7);

				h9->Decorate(h8);

				cout << endl << "                       �븶" << h9->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete h7; delete h8; delete h9; break;

			}

			default:printf("��������\n");

			}break;

		case 8:

			cout << "         ��ѡ����ʽ����+ţ��+��+���͵��ͺţ�" << endl;

			cout << "         1.��  2.�б�   3.С��" << endl;

			cout << "         �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                        �븶" << i4->dabei_cost() << "Ԫ" << "лл��" << endl;

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

				cout << endl << "                        �븶" << i8->zhongbei_cost() << "Ԫ" << "лл��" << endl;

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

				cout << endl << "                        �븶" << i12->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete i9; delete i10; delete i11; delete i12; break;

			}

			default:printf("��������\n");

			}break;

		default:printf("��������\n");

		}

	}break;

	case 3:

	{

		cout << "  ��������������������������������������������������������������������������" << endl;

		cout << "  ��                  �����ϵ�����������࣬��ѡ��                      ��" << endl;

		cout << "  �� 1.����䣨����     2.�����+ţ��        3.�����+��                  ��" << endl;

		cout << "  �� 4.�����+����      5.�����+ţ��+��     6.�����+ţ��+����           ��" << endl;

		cout << "  �� 7.�����+��+����   8.�����+ţ��+��+����                             ��" << endl;

		cout << "  ���x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x��" << endl;

		cout << "                       ����������ѡ������Ҫ�Ŀ���:";

		int b;

		cin >> b;

		switch (b)

		{

		case 1:

			cout << "                  ��ѡ���������ͺţ�" << endl;

			cout << "                  1.��  2.�б�   3.С��" << endl;

			cout << "                  �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a1;

			cin >> a1;

			switch (a1)

			{

			case 1:

			{

				coffee* c1 = new flavored_coffee;

				cout << endl << "                      �븶" << c1->dabei_cost() << "Ԫ��" << "лл��" << endl;

				delete c1; break;

			}

			case 2:

			{

				coffee* c2 = new flavored_coffee;

				cout << endl << "                      �븶" << c2->zhongbei_cost() << "Ԫ��" << "лл��" << endl;

				delete c2; break;

			}

			case 3:

			{

				coffee* c3 = new flavored_coffee;

				cout << endl << "                       �븶" << c3->xiaobei_cost() << "Ԫ��" << "лл��" << endl;

				delete c3; break;

			}

			default:printf("��������\n");

			}break;

		case 2:

			cout << "                 ��ѡ�������+ţ�̵��ͺţ�" << endl;

			cout << "                 1.��  2.�б�   3.С��" << endl;

			cout << "                 �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a2;

			cin >> a2;

			switch (a2)

			{

			case 1:

			{

				coffee* b1 = new flavored_coffee;

				Add_Condiment* b2 = new has_milk;

				b2->Decorate(b1);

				cout << endl << "                        �븶" << b2->dabei_cost() << "Ԫ!" << "лл��" << endl;

				delete b1; delete b2; break;

			}

			case 2:

			{

				coffee* b3 = new flavored_coffee;

				Add_Condiment* b4 = new has_milk;

				b4->Decorate(b3);

				cout << endl << "                       �븶" << b4->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete b3; delete b4; break;

			}

			case 3:

			{

				coffee* b5 = new flavored_coffee;

				Add_Condiment* b6 = new has_milk;

				b6->Decorate(b5);

				cout << endl << "                      �븶" << b6->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete b5; delete b6; break;

			}

			default:printf("��������\n");

			}break;

		case 3:

			cout << "                  ��ѡ�������+�ǵ��ͺţ�" << endl;

			cout << "                  1.��  2.�б�   3.С��" << endl;

			cout << "                  �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a3;

			cin >> a3;

			switch (a3)

			{

			case 1:

			{

				coffee* d1 = new flavored_coffee;

				Add_Condiment* d2 = new has_sugar;

				d2->Decorate(d1);

				cout << endl << "                      �븶" << d2->dabei_cost() << "Ԫ��" << "лл��" << endl;

				delete d1; delete d2; break;

			}

			case 2:

			{

				coffee* d3 = new flavored_coffee;

				Add_Condiment* d4 = new has_sugar;

				d4->Decorate(d3);

				cout << endl << "                     �븶" << d4->zhongbei_cost() << "Ԫ��" << "лл��" << endl;

				delete d3; delete d4; break;

			}

			case 3:

			{

				coffee* d5 = new flavored_coffee;

				Add_Condiment* d6 = new has_sugar;

				d6->Decorate(d5);

				cout << endl << "                    �븶" << d6->xiaobei_cost() << "Ԫ��" << "лл��" << endl;

				delete d5; delete d6; break;

			}

			default:printf("��������\n");

			}break;

		case 4:

			cout << "                ��ѡ�������+���͵��ͺţ�" << endl;

			cout << "                1.��  2.�б�   3.С��" << endl;

			cout << "                �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a4;

			cin >> a4;

			switch (a4)

			{

			case 1:

			{

				coffee* e1 = new flavored_coffee;

				Add_Condiment* e2 = new has_cream;

				e2->Decorate(e1);

				cout << endl << "                     �븶" << e2->dabei_cost() << "Ԫ" << "лл��" << endl;

				delete e1; delete e2; break;

			}

			case 2:

			{

				coffee* e3 = new flavored_coffee;

				Add_Condiment* e4 = new has_cream;

				e4->Decorate(e3);

				cout << endl << "                    �븶" << e4->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete e3; delete e4; break;

			}

			case 3:

			{

				coffee* e5 = new flavored_coffee;

				Add_Condiment* e6 = new has_cream;

				e6->Decorate(e5);

				cout << endl << "                   �븶" << e6->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete e5; delete e6; break;

			}

			default:printf("��������\n");

			}break;

		case 5:

			cout << "               ��ѡ�������+ţ��+�ǵ��ͺţ�" << endl;

			cout << "               1.��  2.�б�   3.С��" << endl;

			cout << "               �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                     �븶" << f3->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete f1; delete f2; delete f3; break;

			}

			case 2:

			{

				coffee* f4 = new flavored_coffee;

				Add_Condiment* f5 = new  has_milk;

				Add_Condiment* f6 = new has_sugar;

				f5->Decorate(f4);

				f6->Decorate(f5);

				cout << endl << "                     �븶" << f6->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete f4; delete f5; delete f6; break;

			}

			case 3:

			{

				coffee* f7 = new flavored_coffee;

				Add_Condiment* f8 = new  has_milk;

				Add_Condiment* f9 = new has_sugar;

				f8->Decorate(f7);

				f9->Decorate(f8);

				cout << endl << "                     �븶" << f9->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete f7; delete f8; delete f9; break;

			}

			default:printf("��������\n");

			}break;

		case 6:

			cout << "                ��ѡ�������+ţ��+���͵��ͺţ�" << endl;

			cout << "                1.��  2.�б�   3.С��" << endl;

			cout << "                �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                     �븶" << g3->dabei_cost() << "Ԫ" << "лл��" << endl;

				delete g1; delete g2; delete g3; break;

			}

			case 2:

			{

				coffee* g4 = new flavored_coffee;

				Add_Condiment* g5 = new has_milk;

				Add_Condiment* g6 = new has_cream;

				g5->Decorate(g4);

				g6->Decorate(g5);

				cout << endl << "                     �븶" << g6->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete g4; delete g5; delete g6; break;

			}

			case 3:

			{

				coffee* g7 = new flavored_coffee;

				Add_Condiment* g8 = new has_milk;

				Add_Condiment* g9 = new has_cream;

				g8->Decorate(g7);

				g9->Decorate(g8);

				cout << endl << "                     �븶" << g9->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete g7; delete g8; delete g9; break;

			}

			default:printf("��������\n");

			}break;

		case 7:

			cout << "                ��ѡ�������+��+���͵��ͺţ�" << endl;

			cout << "                1.��  2.�б�   3.С��" << endl;

			cout << "                �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                      �븶" << h3->dabei_cost() << "Ԫ" << "лл��" << endl;

				delete h1; delete h2; delete h3; break;

			}

			case 2:

			{

				coffee* h4 = new flavored_coffee;

				Add_Condiment* h5 = new has_sugar;

				Add_Condiment* h6 = new has_cream;

				h5->Decorate(h4);

				h6->Decorate(h5);

				cout << endl << "                      �븶" << h6->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete h4; delete h5; delete h6; break;

			}

			case 3:

			{

				coffee* h7 = new flavored_coffee;

				Add_Condiment* h8 = new has_sugar;

				Add_Condiment* h9 = new has_cream;

				h8->Decorate(h7);

				h9->Decorate(h8);

				cout << endl << "                     �븶" << h9->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete h7; delete h8; delete h9; break;

			}

			default:printf("��������\n");

			}break;

		case 8:

			cout << "              ��ѡ�������+ţ��+��+���͵��ͺţ�" << endl;

			cout << "              1.��  2.�б�   3.С��" << endl;

			cout << "              �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                    �븶" << i4->dabei_cost() << "Ԫ" << "лл��" << endl;

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

				cout << endl << "                   �븶" << i8->zhongbei_cost() << "Ԫ" << "лл��" << endl;

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

				cout << endl << "                  �븶" << i12->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete i9; delete i10; delete i11; delete i12; break;

			}

			default:printf("��������\n");

			}break;

		default:printf("��������\n");

		}

	}break;

	case 4:

	{

		cout << "  ��������������������������������������������������������������������������" << endl;

		cout << "  ��                  ������ŵϵ�����������࣬��ѡ��                    ��" << endl;

		cout << "  �� 1.������ŵ������     2.������ŵ+ţ��        3.������ŵ+��            ��" << endl;

		cout << "  �� 4.������ŵ+����      5.������ŵ+ţ��+��     6.������ŵ+ţ��+����     ��" << endl;

		cout << "  �� 7.������ŵ+��+����   8.������ŵ+ţ��+��+����                         ��" << endl;

		cout << "  ���x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x��" << endl;

		cout << "                       ����������ѡ������Ҫ�Ŀ���:";

		int b;

		cin >> b;

		switch (b)

		{

		case 1:

			cout << "                  ��ѡ�񿨲���ŵ���ͺţ�" << endl;

			cout << "                  1.��  2.�б�   3.С��" << endl;

			cout << "                  �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a1;

			cin >> a1;

			switch (a1)

			{

			case 1:

			{

				coffee* c1 = new caffelatte;

				cout << endl << "                    �븶" << c1->dabei_cost() << "Ԫ��" << "лл��" << endl;

				delete c1; break;

			}

			case 2:

			{

				coffee* c2 = new caffelatte;

				cout << endl << "                    �븶" << c2->zhongbei_cost() << "Ԫ��" << "лл��" << endl;

				delete c2; break;

			}

			case 3:

			{

				coffee* c3 = new caffelatte;

				cout << endl << "                    �븶" << c3->xiaobei_cost() << "Ԫ��" << "лл��" << endl;

				delete c3; break;

			}

			default:printf("��������\n");

			}break;

		case 2:

			cout << "                ��ѡ�񿨲���ŵ+ţ�̵��ͺţ�" << endl;

			cout << "                1.��  2.�б�   3.С��" << endl;

			cout << "                �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a2;

			cin >> a2;

			switch (a2)

			{

			case 1:

			{

				coffee* b1 = new caffelatte;

				Add_Condiment* b2 = new has_milk;

				b2->Decorate(b1);

				cout << endl << "                   �븶" << b2->dabei_cost() << "Ԫ!" << "лл��" << endl;

				delete b1; delete b2; break;

			}

			case 2:

			{

				coffee* b3 = new caffelatte;

				Add_Condiment* b4 = new has_milk;

				b4->Decorate(b3);

				cout << endl << "                   �븶" << b4->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete b3; delete b4; break;

			}

			case 3:

			{

				coffee* b5 = new caffelatte;

				Add_Condiment* b6 = new has_milk;

				b6->Decorate(b5);

				cout << endl << "                  �븶" << b6->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete b5; delete b6; break;

			}

			default:printf("��������\n");

			}break;

		case 3:

			cout << "              ��ѡ�񿨲���ŵ+�ǵ��ͺţ�" << endl;

			cout << "              1.��  2.�б�   3.С��" << endl;

			cout << "              �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a3;

			cin >> a3;

			switch (a3)

			{

			case 1:

			{

				coffee* d1 = new caffelatte;

				Add_Condiment* d2 = new has_sugar;

				d2->Decorate(d1);

				cout << endl << "                 �븶" << d2->dabei_cost() << "Ԫ��" << "лл��" << endl;

				delete d1; delete d2; break;

			}

			case 2:

			{

				coffee* d3 = new caffelatte;

				Add_Condiment* d4 = new has_sugar;

				d4->Decorate(d3);

				cout << endl << "                 �븶" << d4->zhongbei_cost() << "Ԫ��" << "лл��" << endl;

				delete d3; delete d4; break;

			}

			case 3:

			{

				coffee* d5 = new caffelatte;

				Add_Condiment* d6 = new has_sugar;

				d6->Decorate(d5);

				cout << endl << "                 �븶" << d6->xiaobei_cost() << "Ԫ��" << "лл��" << endl;

				delete d5; delete d6; break;

			}

			default:printf("��������\n");

			}break;

		case 4:

			cout << "            ��ѡ�񿨲���ŵ+���͵��ͺţ�" << endl;

			cout << "            1.��  2.�б�   3.С��" << endl;

			cout << "            �������Ӧ������ѡ������Ҫ���ͺţ�";

			int a4;

			cin >> a4;

			switch (a4)

			{

			case 1:

			{

				coffee* e1 = new caffelatte;

				Add_Condiment* e2 = new has_cream;

				e2->Decorate(e1);

				cout << endl << "                 �븶" << e2->dabei_cost() << "Ԫ" << "лл��" << endl;

				delete e1; delete e2; break;

			}

			case 2:

			{

				coffee* e3 = new caffelatte;

				Add_Condiment* e4 = new has_cream;

				e4->Decorate(e3);

				cout << endl << "                  �븶" << e4->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete e3; delete e4; break;

			}

			case 3:

			{

				coffee* e5 = new caffelatte;

				Add_Condiment* e6 = new has_cream;

				e6->Decorate(e5);

				cout << endl << "                  �븶" << e6->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete e5; delete e6; break;

			}

			default:printf("��������\n");

			}break;

		case 5:

			cout << "            ��ѡ�񿨲���ŵ+ţ��+�ǵ��ͺţ�" << endl;

			cout << "            1.��  2.�б�   3.С��" << endl;

			cout << "            �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                    �븶" << f3->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete f1; delete f2; delete f3; break;

			}

			case 2:

			{

				coffee* f4 = new caffelatte;

				Add_Condiment* f5 = new  has_milk;

				Add_Condiment* f6 = new has_sugar;

				f5->Decorate(f4);

				f6->Decorate(f5);

				cout << endl << "                   �븶" << f6->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete f4; delete f5; delete f6; break;

			}

			case 3:

			{

				coffee* f7 = new caffelatte;

				Add_Condiment* f8 = new  has_milk;

				Add_Condiment* f9 = new has_sugar;

				f8->Decorate(f7);

				f9->Decorate(f8);

				cout << endl << "                   �븶" << f9->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete f7; delete f8; delete f9; break;

			}

			default:printf("��������\n");

			}break;

		case 6:

			cout << "           ��ѡ�񿨲���ŵ+ţ��+���͵��ͺţ�" << endl;

			cout << "           1.��  2.�б�   3.С��" << endl;

			cout << "           �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                    �븶" << g3->dabei_cost() << "Ԫ" << "лл��" << endl;

				delete g1; delete g2; delete g3; break;

			}

			case 2:

			{

				coffee* g4 = new caffelatte;

				Add_Condiment* g5 = new has_milk;

				Add_Condiment* g6 = new has_cream;

				g5->Decorate(g4);

				g6->Decorate(g5);

				cout << endl << "                    �븶" << g6->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete g4; delete g5; delete g6; break;

			}

			case 3:

			{

				coffee* g7 = new caffelatte;

				Add_Condiment* g8 = new has_milk;

				Add_Condiment* g9 = new has_cream;

				g8->Decorate(g7);

				g9->Decorate(g8);

				cout << endl << "                    �븶" << g9->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete g7; delete g8; delete g9; break;

			}

			default:printf("��������\n");

			}break;

		case 7:

			cout << "           ��ѡ�񿨲���ŵ+��+���͵��ͺţ�" << endl;

			cout << "           1.��  2.�б�   3.С��" << endl;

			cout << "           �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                    �븶" << h3->dabei_cost() << "Ԫ" << "лл��" << endl;

				delete h1; delete h2; delete h3; break;

			}

			case 2:

			{

				coffee* h4 = new caffelatte;

				Add_Condiment* h5 = new has_sugar;

				Add_Condiment* h6 = new has_cream;

				h5->Decorate(h4);

				h6->Decorate(h5);

				cout << endl << "                    �븶" << h6->zhongbei_cost() << "Ԫ" << "лл��" << endl;

				delete h4; delete h5; delete h6; break;

			}

			case 3:

			{

				coffee* h7 = new caffelatte;

				Add_Condiment* h8 = new has_sugar;

				Add_Condiment* h9 = new has_cream;

				h8->Decorate(h7);

				h9->Decorate(h8);

				cout << endl << "                    �븶" << h9->xiaobei_cost() << "Ԫ" << "лл��" << endl;

				delete h7; delete h8; delete h9; break;

			}

			default:printf("��������\n");

			}break;

		case 8:

			cout << "           ��ѡ�񿨲���ŵ+ţ��+��+���͵��ͺţ�" << endl;

			cout << "           1.��  2.�б�   3.С��" << endl;

			cout << "           �������Ӧ������ѡ������Ҫ���ͺţ�";

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

				cout << endl << "                    �븶" << i4->dabei_cost() << "Ԫ" << "лл��" << endl;

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

				cout << endl << "                     �븶" << i8->zhongbei_cost() << "Ԫ" << "лл��" << endl;

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

				cout << endl << "                     �븶" << i12->xiaobei_cost() << "Ԫ" << "лл��" << endl;
				delete i9; delete i10; delete i11; delete i12; break;
			}
			default:printf("��������\n");
			}break;
		default:printf("��������\n");
		}
	}break;
	default:printf("��������\n");
	}
	system("pause");
}
//���ӿ�����Ϣ
void AddInformation()								
{	
	int placed=0;
	STU* vIew = NULL;

	system("cls");

	placed=0;
	pNew = (STU *)malloc(sizeof(STU));			
	pNew->pnext = NULL;
	printf("\t������Ҫ���ӵĿ�����Ϣ:\n");

	printf("\t��λ��:");
	scanf("%s",pNew->num);
	//��Ϣ���
	NumberCheck(pNew->num,"��λ��");


	printf("\t����:");
	scanf("%s",pNew->name);
	
	
	printf("\t���Ѷ�:");
	scanf("%s",pNew->xiaofei);
	//��Ϣ���
	SecureCheck(pNew->xiaofei,"���Ѷ�");

	vIew = (STU *)malloc(sizeof(STU));
	
	if(pStu->pnext==NULL)
		pStu->pnext=pNew;
	else								//�������λ�ý����������ڵ�, ά��ѧ������˳��Ĳ���
	{	
		vIew->pnext=pStu;
		while(vIew->pnext->pnext!=NULL)
		{
			if(strcmp(vIew->pnext->num , pNew->num)<=0 && strcmp(vIew->pnext->pnext->num ,pNew->num)>=0)
			{	
			
				pNew->pnext = vIew->pnext->pnext;
				vIew->pnext->pnext = pNew;
				placed=1;				//��ʾ�Ѿ�����
				break;
				
			}
			vIew->pnext = vIew->pnext->pnext;
		}
		if(placed==0)
			vIew->pnext->pnext = pNew;	//û���ҵ����ʵĽڵ㣬��pNew�������������
		
	}
	
	free(vIew);
	vIew=NULL;
	
}
//��ʾ��Ϣ
void ShowInformation()					
{
	STU* vIew = NULL;

	system("cls");
	printf("\n\t��====================��ʾ��Ϣ====================��\n");
	
	
	vIew = (STU *)malloc(sizeof(STU));

	vIew->pnext=pStu->pnext;
	if(vIew->pnext==NULL)
	{
		printf("\n\t\t��ǰϵͳ��û�п�����Ϣ");
	}
	else
	{
		while(vIew->pnext!=NULL)
		{
		printf("\t��λ��:%s\n",vIew->pnext->num);
		printf("\t����:%s\n",vIew->pnext->name);
		printf("\t���Ѷ�:%s\n",vIew->pnext->xiaofei);
		printf("\n\t...................................................\n");
		vIew->pnext=vIew->pnext->pnext;
		}
	}
	free(vIew);
	vIew=NULL;

	printf("\n\t��====================��ʾ��Ϣ���================��\n");

}

//������Ϣ
void Search()						
{
	char serach[N];
	int flag=0;
	char choice='0';
	STU* vIew = NULL;

	system("cls");
									//ѡ����ҵĸ���[��λ��/����]
	printf("\n\t����ָ��\t 1��������λ�Ų��� \t2��������������\n");
	choice = getch();

	if(choice=='1')
		printf("\t������Ҫ���ҵĿ��˵���λ��:\n");
	else if(choice=='2')
		printf("\t������Ҫ���ҵĿ��˵�����:\n");
	else
		printf("\t����ָ�����������Ѿ��˳�����\n");

	if(choice=='1'||choice=='2')	//���ָ������ȷ��
	{
		scanf("%s",serach);

	
		vIew = (STU *)malloc(sizeof(STU));

		vIew->pnext=pStu->pnext;
		while(vIew->pnext!=NULL)
		{
			if((strcmp(vIew->pnext->num,serach)==0&&choice == '1')||(strcmp(vIew->pnext->name,serach)==0&&choice == '2'))
			{flag=1;
			printf("\t��λ��:%s\n",vIew->pnext->num);
			printf("\t����:%s\n",vIew->pnext->name);
			printf("\t���Ѷ�:%s\n",vIew->pnext->xiaofei);
			printf("\n\t...................................................\n");
			}
		vIew->pnext=vIew->pnext->pnext;
		}
		free(vIew);
		vIew=NULL;

		if(!flag)
		printf("\n!!!!!!!!!!!!!!!!!!!!�Բ��𣬲��޴���!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}

}
//ɾ����Ϣ
void Delete()							
{	
	STU *temp;
	char num_serach[N];
	int flag=0;
	STU* vIew = NULL;

	system("cls");

	temp=(STU *)malloc(sizeof(STU));
	
	
	printf("\n\t������Ҫɾ���Ŀ��˵���λ��:\n");
	scanf("%s",num_serach);



	vIew = (STU *)malloc(sizeof(STU));
	
	vIew->pnext=pStu;
	while(vIew->pnext->pnext!=NULL)
	{
		if(strcmp(vIew->pnext->pnext->num,num_serach)==0)		//ƥ�䵽����λ��
		{
		flag=1;
		printf("\n\n\t��ɾ���Ŀ�����ϢΪ:\n");
		printf("\t��λ��:%s\n",vIew->pnext->pnext->num);
		printf("\t����:%s\n",vIew->pnext->pnext->name);
		printf("\t���Ѷ�:%s\n",vIew->pnext->pnext->xiaofei);
		
		temp ->pnext=vIew->pnext->pnext;						//temp->next���潫Ҫɾ���Ľڵ�ĵ�ַ
		vIew->pnext->pnext=vIew->pnext->pnext->pnext;			//�ƹ���Ҫɾ���Ľڵ�

		free(temp->pnext);										//�ͷ��Ѿ����ƹ��Ľڵ㣬��ʡ�ռ�
		
		printf("\n\t��ɾ���Ŀ�����Ϣ�Ѿ�ɾ��\n");			
		printf("\n\t...................................................\n");
		break;													//ɾ��һ���ڵ�֮������ѭ����
		}
		vIew->pnext=vIew->pnext->pnext;
	}

	free(vIew);
	vIew=NULL;
	free(temp);
	temp=NULL;

	if(!flag)
	printf("\n!!!!!!!!!!!!!!!!!!!!�Բ��𣬲��޴���!!!!!!!!!!!!!!!!!!!!!!!!!\n");

}
//�޸���Ϣ
void Modify()								
{	
	char num_serach[N];
	int flag=0;
	STU* vIew = NULL;
	
	system("cls");
	
	printf("\n\t������Ҫ�޸ĵĿ��˵���λ�ŵ����Ѷ�:\n");
	scanf("%s",num_serach);

	
	vIew = (STU *)malloc(sizeof(STU));

	vIew->pnext=pStu->pnext;
	while(vIew->pnext!=NULL)
	{
		if(strcmp(vIew->pnext->num,num_serach)==0)
		{
			flag=1;
		printf("\t��λ��:%s\n",vIew->pnext->num);
		printf("\t����:%s\n",vIew->pnext->name);
		printf("\t���Ѷ�:%s\n",vIew->pnext->xiaofei);
		printf("\t�޸ĳ�:\n");
		//����Ϣ������
		printf("\t���Ѷ�:\n");
		scanf("%s",vIew->pnext->xiaofei);
		//��Ϣ���
		SecureCheck(vIew->pnext->xiaofei,"���Ѷ�");

		//��Ϣ���
		
		//AddInformation();	//ԭ���ϲ��޸���λ�ź������������Ҫ������ֱ����AddInformation()����
							//ȥ��������Ϣ������
		printf("\n\t...................................................\n");
		}
		vIew->pnext=vIew->pnext->pnext;
	}
	free(vIew);
	vIew=NULL;

	if(!flag)
	printf("\n!!!!!!!!!!!!!!!!!!!!�Բ��𣬲��޴���!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	
}
//����ͳ��
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

	printf("\t��������ͳ��:\n");
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
	printf("\n\t���˵���������:%d",Number);

	if(Number!=0)
		printf("\n\t�����ǵ�ƽ��������:%.2f",sumprices/Number);
	else
		printf("\n\t�����ǵ�ƽ��������:0");

	printf("\n\t���������Ѷ���:%.2f",sumprices);
	printf("\n\t�������Ѳ���15Ԫ�Ŀ��˵�������:%d",Below15);
	printf("\n\t�������ѳ���18Ԫ�Ŀ��˵�������:%d",Over18);
}
//������Ϣ
void save_file()								
{	
	FILE *file=NULL;
	STU* vIew = NULL;


	file = fopen("C:\\student_file.txt","w+");
	if(file==NULL)
		printf("�ļ���ʧ��!\n");
	
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
//���ļ�������Ϣ
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
		//pCurrent->pnextָ�����ڴ��ڵĽڵ�
	
	}
	fclose(file);

}
//������ʱЧ��
void Delay()															
{
	int i = 0;
	int j = 0;

	for(i=50000;i>0;i--)
		for(j=5000;j>0;j--)
			;
}
//ϵͳ��ʼ��
void init()		
{
	pStu = (STU *)malloc(sizeof(STU));					//����ͷ�ڵ�
	pStu->pnext  =NULL;
	strcpy(pStu->num, "0");
	strcpy(pStu->name, " ");

	pCurrent = (STU *)malloc(sizeof(STU));
	pCurrent ->pnext =NULL;

	read_file();

}
//��ӭʹ��
void Welcome()									
{	system("cls");
	
	printf("\n\n\t��================================================��\n");
	printf("\n\n");
	printf("\t\t���ﻶӭ������������������ϵͳ����\n\n\n");
	printf("\t\t\t1.�����Ĺ˿͵㵥\n");
	printf("\t\t\t2.�鿴�˿���Ϣ\n");
	printf("\t\t\t3.���ӹ˿���Ϣ\n");
	printf("\t\t\t4.���ҹ˿���Ϣ\n");
	printf("\t\t\t5.�޸Ĺ˿���Ϣ\n");
	printf("\t\t\t6.ɾ���˿���Ϣ\n");
	printf("\t\t\t7.Ӫҵ��ͳ��\n");
	printf("\t\t\t8.�˳�ϵͳ\n");
	printf("\n\n\t��================================================��\n");
}
/************************************������************************************/
int main()
{
	char choice  = 0;
	char AddYorN = 0;

	init();
	InCheck();
	Welcome();
//	MessageBox(0, "", 0);

															//�������
	
	while(choice!='8')
	{	
		printf("\n>>");										//��������
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
							printf("����N�����˳�������Ϣ.�������������\n");AddYorN=getch();printf("%c",AddYorN);
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
			default:printf("\t\t������������˵�\n");getch();Welcome();
			
		}
}
	
    system("cls");
	system("color 81");
	printf("\n\t\t��л����ʹ�ã��ټ�!\n");
	Delay();

	
	save_file();
	return 0;

}



#pragma warning (disable : 4996)
#pragma once
#include "English.h"
#include "Korean.h"
#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
#define MAX 40
using namespace std;

void ShowTopMenu()
{
	cout << "==================================================================\n";
	cout << "\t\t\t���ܾ� ���߱� ����" << endl;
	cout << "\t\t���� �ܾ�� �� ���� �ѱ� �ܾ �Է�" << endl;
	cout << "==================================================================\n";
	
}
//void InputEng(Englishi<string> *_eng)
//{
//	Englishi<string> eng;
//	string input;
//	cout << endl;
//	cout << "\t\t\t���� �ܾ �Է��� �ּ���: ";
//	getline(cin, input);
//	eng.Add(input);
//
//	cout << endl;
//}
//void InputKor(Korean <string> *_kor, string _input)
//{
//	Korean <string> kor;
//	string input;
//	cout << endl;
//	cout << "\t\t\t�ܾ��� ���� �Է��� �ּ��� : ";
//	getline(cin,input);	
//	kor.Add(_input);
//	cout << endl;
//}
void CheckOverlap(English<string> &_eng, Korean <string> &_kor)
{


}
void SelectMenu()
{	
	cout << "\t\t1. �ܾ� �Է� �ϱ� 2. ����Ǯ�� 3. �ܾ��" << endl << endl;
}
void main()
{
	English<string> Eng;
	Korean<string> Kor;
	int nCheckIndex = 0;
	int nInput_Flag;
	int nScore = 5;
	int nTotalScore = 0;
	int nQcount = 0;
	int inputNullCheck = 0;
	string strinput = "";
	char pInput[MAX] = { 0, };

	int enloopcheck = 1;
	int korloopcheck = 1;
	ShowTopMenu();


	while (1)
	{
		system("cls");
		ShowTopMenu();
		SelectMenu();

		cout << "��ȣ�� �Է��� �ּ��� :";
		cin >> nInput_Flag;

		enloopcheck = 1;
		korloopcheck = 1;
		if (nInput_Flag == 1)
		{
			system("cls");
			ShowTopMenu();
			
			while (enloopcheck == 1)
			{
				cout << "\t\t\t���� �ܾ �Է��� �ּ���: ";
				scanf("%s", pInput);
				//cin.get();
				//cin.getline(pInput, MAX);

				inputNullCheck++;
				if (pInput[inputNullCheck] == '\0')
				{
					int k;
					for (k = inputNullCheck; k < MAX; k++ )
					{
						pInput[k] = '\0';
					}
					inputNullCheck = 0;
				}

				strinput = pInput;

				if (Eng.GetDataForIndex(0).empty())
				{
					Eng.Add(strinput);
					enloopcheck = 0;
				}
				else if (!Eng.GetDataForIndex(0).empty())
				{
					for (int i = 0; i< Eng.Size(); i++)
					{
						if (Eng.GetDataForIndex(i) == strinput)
						{
							cout << "\n�̹� �ִ� �ܾ� �Դϴ�. �ٽ� �Է��� �ּ���." << endl << endl;							
							system("PAUSE");
							break;
						}
						else if(Eng.GetDataForIndex(i) != strinput)
						{
							Eng.Add(pInput);
							enloopcheck = 0;
							break;
						}
					}
					continue;
				}
			}
			

			while (korloopcheck == 1)
			{
				cout << "\n\t\t\t�ܾ��� ���� �Է��� �ּ���: ";
				scanf("%s", pInput);

				inputNullCheck++;
				if (pInput[inputNullCheck] == '\0')
				{
					int k;
					for (k = inputNullCheck; k < MAX; k++)
					{
						pInput[k] = '\0';
					}
					inputNullCheck = 0;
				}
				strinput = pInput;

				if (Kor.GetDataForIndex(0).empty())
				{
					Kor.Add(strinput);
					korloopcheck = 0;
				}
				else if (!Kor.GetDataForIndex(0).empty())
				{
					for (int i = 0; i < Kor.Size(); i++)
					{
						if (Kor.GetDataForIndex(i) == strinput)
						{
							cout << "\n�̹� �ִ� �ܾ� �Դϴ�. �ٽ� �Է��� �ּ���." << endl << endl;							
							system("PAUSE");
							break;
						}
						else if (Kor.GetDataForIndex(i) != strinput)
						{
							Kor.Add(strinput);
							korloopcheck = 0;
							break;
						}
					}
					continue;
				}
			}
			
			

			cout << endl;
		}
		else if (nInput_Flag == 2)
		{
			cout << "\n\t\t\t���� Ǯ�̸� ���� �մϴ�." << endl << endl;
			cout << "�� " << Eng.Size() << "���� Ǯ�� �����մϴ�. �� ������ Ǫ�ðڽ��ϱ�??";
			cin >> nInput_Flag;
			cout << nInput_Flag << "���� �������ϴ�. " << endl << endl;

			for (int i = 0; i<= nInput_Flag; i++)
			{
				cout << Eng.GetDataForIndex(i) << "�� ���� ??" << endl;
				cout << "�� : ";
				cin.getline(pInput, MAX, '\n');
				
				if (Kor.GetDataForIndex(i).compare(pInput) == 0)
				{
					cout << "���� �Դϴ�!" << nScore <<"�� ȹ��!"<< endl;					
				}
				else
				{
					cout << "���� �Դϴ�!" << endl;
				}
			}
			cout << "�� ���ھ�� " << nTotalScore << "�� �Դϴ�. " << endl << endl;
			system("PAUSE");

		}
		else if (nInput_Flag == 3)
		{
			system("cls");
			ShowTopMenu();
			cout << endl;
			for ( int i = 0; i < Eng.Size(); i++ )
			{
				cout << i + 1<< ". "  << Eng.GetDataForIndex(i) << "\t" << Kor.GetDataForIndex(i) << endl;
			}
			cout << endl;
			system("PAUSE");
		}
		
	}
}


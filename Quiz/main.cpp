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
	cout << "\t\t\t영단어 맞추기 게임" << endl;
	cout << "\t\t영어 단어와 그 뜻인 한글 단어를 입력" << endl;
	cout << "==================================================================\n";
	
}
//void InputEng(Englishi<string> *_eng)
//{
//	Englishi<string> eng;
//	string input;
//	cout << endl;
//	cout << "\t\t\t영어 단어를 입력해 주세요: ";
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
//	cout << "\t\t\t단어의 뜻을 입력해 주세요 : ";
//	getline(cin,input);	
//	kor.Add(_input);
//	cout << endl;
//}
void CheckOverlap(English<string> &_eng, Korean <string> &_kor)
{


}
void SelectMenu()
{	
	cout << "\t\t1. 단어 입력 하기 2. 문제풀기 3. 단어보기" << endl << endl;
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

		cout << "번호를 입력해 주세요 :";
		cin >> nInput_Flag;

		enloopcheck = 1;
		korloopcheck = 1;
		if (nInput_Flag == 1)
		{
			system("cls");
			ShowTopMenu();
			
			while (enloopcheck == 1)
			{
				cout << "\t\t\t영어 단어를 입력해 주세요: ";
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
							cout << "\n이미 있는 단어 입니다. 다시 입력해 주세요." << endl << endl;							
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
				cout << "\n\t\t\t단어의 뜻을 입력해 주세요: ";
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
							cout << "\n이미 있는 단어 입니다. 다시 입력해 주세요." << endl << endl;							
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
			cout << "\n\t\t\t문제 풀이를 시작 합니다." << endl << endl;
			cout << "총 " << Eng.Size() << "문제 풀기 가능합니다. 몇 문제를 푸시겠습니까??";
			cin >> nInput_Flag;
			cout << nInput_Flag << "개의 문제갑니다. " << endl << endl;

			for (int i = 0; i<= nInput_Flag; i++)
			{
				cout << Eng.GetDataForIndex(i) << "의 뜻은 ??" << endl;
				cout << "답 : ";
				cin.getline(pInput, MAX, '\n');
				
				if (Kor.GetDataForIndex(i).compare(pInput) == 0)
				{
					cout << "정답 입니다!" << nScore <<"점 획득!"<< endl;					
				}
				else
				{
					cout << "오답 입니다!" << endl;
				}
			}
			cout << "총 스코어는 " << nTotalScore << "점 입니다. " << endl << endl;
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


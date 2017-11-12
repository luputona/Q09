#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<string>
#include<Windows.h>
#include<time.h>

#define ITEM_MAX 50
using namespace std;



void ShowTopMenu1()
{
	cout << "==================================================================\n";
	cout << "\t\t\t영단어 맞추기 게임" << endl;
	cout << "\t\t영어 단어와 그 뜻인 한글 단어를 입력" << endl;
	cout << "==================================================================\n";

}
void SelectMenu1()
{
	cout << "\t\t1. 단어 입력 하기 2. 문제풀기 3. 단어보기" << endl << endl;
}
void main()
{
	
	string strInput;
	vector<string> vKorDB;
	vector<string> vEngDB;

	vector<string>::iterator iter;
	vector<string>::iterator awsCheckIter;

	int awsCheck[ITEM_MAX] = { 0, };
	int enloopcheck = 1;
	int korloopcheck = 1;
	int nFlag = 0;
	int nScore = 5;
	int nTotal = 0;
	int nItem = 0;
	int nQcount = 0;
	int nAwscount = 0;

	ShowTopMenu1();	
		
	while (1)
	{
		system("cls");
		ShowTopMenu1();
		SelectMenu1();

		cout << "번호를 입력해 주세요 :";
		cin >> nFlag;

		enloopcheck = 1;
		korloopcheck = 1;

		if (nFlag == 1)
		{
			cin.ignore(256, '\n');
			system("cls");
			ShowTopMenu1();

			while (enloopcheck == 1)
			{
				cout << "\t\t\t영어 단어를 입력해 주세요: ";
				getline(cin, strInput, '\n');
				
				iter = find(vEngDB.begin(), vEngDB.end(), strInput);

				if (vEngDB.empty() || iter == vEngDB.end())
				{					
					vEngDB.push_back(strInput);
					cout << endl;
					enloopcheck = 0;
				}
				else if(iter != vEngDB.end())
				{
					cout << "\n이미 있는 단어 입니다. 다시 입력해 주세요." << endl << endl;
					system("PAUSE");
					cout << endl;
					continue;
				}				
			}
			while (korloopcheck == 1)
			{
				cout << "\t\t\t단어의 뜻을 입력해 주세요: ";
				getline(cin, strInput, '\n');

				iter = find(vKorDB.begin(), vKorDB.end(), strInput);

				if (vKorDB.empty() || iter == vKorDB.end())
				{					
					vKorDB.push_back(strInput);
					cout << endl;
					korloopcheck = 0;
				}
				else if (iter != vKorDB.end())
				{
					cout << "\n이미 있는 단어 입니다. 다시 입력해 주세요." << endl << endl;
					system("PAUSE");
					cout << endl;
					continue;
				}
			}
			//system("PAUSE");

		}
		else if (nFlag ==2)
		{
			
			cout << "\n\t\t\t문제 풀이를 시작 합니다." << endl << endl;
			cout << "총 " << vEngDB.size() << "문제 풀기 가능합니다. 몇 문제를 푸시겠습니까??";
			cin >> nQcount;
			cout << nQcount << "개의 문제갑니다. " << endl << endl;

			cin.ignore(256,'\n');
			int tempQ = nQcount;
			while (nQcount != 0)
			{
				srand(time(NULL));
				nItem = rand() % vEngDB.size();
				
				if (awsCheck[nItem] == 0)
				{
					awsCheck[nItem] = 1;
				}
				else if(awsCheck[nItem] != 0)
				{
					continue;
				}
				
				cout << vEngDB[nItem] << "의 뜻은 ??  " << endl;
				cout << "답 : ";				
				getline(cin, strInput, '\n');

				if (vKorDB[nItem] == strInput)
				{
					cout << "정답 입니다!" << nScore << "점 획득!" << endl << endl;
					nTotal = nTotal + nScore;
					nAwscount++;
				}
				else if(vKorDB[nItem] != strInput)
				{
					cout << "오답 입니다!" << endl << endl;
				}				
				nQcount--;
			}
			if (nQcount == 0)
			{
				cout << tempQ << "문제중 " << nAwscount << "문제를 맞추셨습니다.  총 스코어 " << nTotal << "점 입니다.\n\n";
			}
			
			system("PAUSE");
		}
		else if (nFlag ==3)
		{
			system("cls");
			ShowTopMenu1();
			cout << endl;
			for (int i = 0; i < vEngDB.size(); i++)
			{
				cout << i + 1 << ". " << vEngDB[i] << " , " << vKorDB[i] << endl;
			}		
			system("PAUSE");		
		}

	}



}
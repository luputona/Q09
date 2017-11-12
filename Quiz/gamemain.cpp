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
	cout << "\t\t\t���ܾ� ���߱� ����" << endl;
	cout << "\t\t���� �ܾ�� �� ���� �ѱ� �ܾ �Է�" << endl;
	cout << "==================================================================\n";

}
void SelectMenu1()
{
	cout << "\t\t1. �ܾ� �Է� �ϱ� 2. ����Ǯ�� 3. �ܾ��" << endl << endl;
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

		cout << "��ȣ�� �Է��� �ּ��� :";
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
				cout << "\t\t\t���� �ܾ �Է��� �ּ���: ";
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
					cout << "\n�̹� �ִ� �ܾ� �Դϴ�. �ٽ� �Է��� �ּ���." << endl << endl;
					system("PAUSE");
					cout << endl;
					continue;
				}				
			}
			while (korloopcheck == 1)
			{
				cout << "\t\t\t�ܾ��� ���� �Է��� �ּ���: ";
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
					cout << "\n�̹� �ִ� �ܾ� �Դϴ�. �ٽ� �Է��� �ּ���." << endl << endl;
					system("PAUSE");
					cout << endl;
					continue;
				}
			}
			//system("PAUSE");

		}
		else if (nFlag ==2)
		{
			
			cout << "\n\t\t\t���� Ǯ�̸� ���� �մϴ�." << endl << endl;
			cout << "�� " << vEngDB.size() << "���� Ǯ�� �����մϴ�. �� ������ Ǫ�ðڽ��ϱ�??";
			cin >> nQcount;
			cout << nQcount << "���� �������ϴ�. " << endl << endl;

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
				
				cout << vEngDB[nItem] << "�� ���� ??  " << endl;
				cout << "�� : ";				
				getline(cin, strInput, '\n');

				if (vKorDB[nItem] == strInput)
				{
					cout << "���� �Դϴ�!" << nScore << "�� ȹ��!" << endl << endl;
					nTotal = nTotal + nScore;
					nAwscount++;
				}
				else if(vKorDB[nItem] != strInput)
				{
					cout << "���� �Դϴ�!" << endl << endl;
				}				
				nQcount--;
			}
			if (nQcount == 0)
			{
				cout << tempQ << "������ " << nAwscount << "������ ���߼̽��ϴ�.  �� ���ھ� " << nTotal << "�� �Դϴ�.\n\n";
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
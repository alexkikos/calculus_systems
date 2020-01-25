#include "ShowFromFileConsole.h"

void ShowFromFileConsole::SetFileName(string s)
{
	if (s.length() > 0) file_name = s;
	else cout << "\nCheck input";
}

string ShowFromFileConsole::GetFIleName() const
{
	return file_name;
}

vector<string> ShowFromFileConsole::GetStrings() const
{
	return file_strings;
}

void ShowFromFileConsole::Display()
{
	LoadFroFileToArray();
	for (int i = 0; i < file_strings.size(); i++)
	{
		
		cout << file_strings[i] << endl;
	}
}

void ShowFromFileConsole::LoadFroFileToArray()
{
	char buff[2048];
	ifstream load(file_name);
	if (load.is_open())
	{
		while (!load.eof())
		{
			load.getline((char*)buff, 2048);
			file_strings.push_back(buff);//������ � ����� ������ � �������, ����� ����� ���� �������� �� � ������������� ������� ��� ��������� ���������	
		}

	}
	else cout << "\nCant find file!";
	load.close();
}





////////////////////////ASCIII/////////////////////////////////////

void ShowFromFileConsoleAsCii::Display()
{
	LoadFroFileToArray();
	for (int i = 0; i < mynumbers.size(); i++)
	{
		if (mynumbers[i] == 0) {
			cout << endl; continue; //0 - end of string
		}
		cout << mynumbers[i];

	}

}

void ShowFromFileConsoleAsCii::LoadFroFileToArray()
{
	ShowFromFileConsole::LoadFroFileToArray();//��������� ��� ���� ������ � ������ �������� ������ files_strings
	for (int i = 0; i < file_strings.size(); i++)//������ � ������ �����
	{
		string s = file_strings[i];//����� ������ ������
		for (int c = 0; c < s.length() + 1; c++)//�������� ����������� � ������ �������� � ��������� ������ ����
		{
			mynumbers.push_back(((int)s[c]));//������ ������� �������� � ����� ���������� � ���� ������ ������, � ���������� ���� ����� ������������� ������ �� ����
		}

	}
}


////////////////////BINARY
void ShowFromFileConsoleToBinary::LoadFroFileToArray()
{
	vector<int> s;//������ ������ � ������� ���� ���������� ����� ��������
	ShowFromFileConsoleAsCii::LoadFroFileToArray();//��������� ��� ���� ������ � ������ ������� ������ ���� ������, ������� ������������
	for (int i = 0; i < mynumbers.size(); i++)
	{
		int number = mynumbers[i];
		int sum = 0;
		int count = 0;
		while (number != 0)
		{
			sum += number%2  * (pow(10,count++));
			number /= 2;
		}	
		s.push_back(sum);
	}
	mynumbers.clear();//���� �������������� �������� � ���� ���
	mynumbers = s;//�������� ������� ������� ����������� ���������� ����� ��������
}






///////////////////////������������
void ShowFromFileConsole_x8::LoadFroFileToArray()
{
	vector<int> my;
	ShowFromFileConsoleAsCii::LoadFroFileToArray();//��������� ��� ���� ������ � ������
	for (int i = 0; i < mynumbers.size(); i++)
	{
		int number = mynumbers[i];
		int sum = 0;
		int count = 0;
		while (number != 0)
		{
			sum += number % 8 * (pow(10, count++));
			number /= 8;
		}

		my.push_back(sum);
	}
	mynumbers.clear();
	mynumbers = my;
}





void ShowFromFileConsoleTo_x16::LoadFroFileToArray()
{
	vector<string> my;
	ShowFromFileConsoleAsCii::LoadFroFileToArray();//��������� ��� ���� ������ � ������ � �������� �� � ������� ��������
	for (int i = 0; i < mynumbers.size(); i++)//���������� ������ �������
	{
		int number = mynumbers[i];
		string sum1;
		do
		{	
			if (number%16 >= 10 and number%16 <= 15)
			{
				if (number % 16 == 10) { sum1 += "A"; }
				else
					if (number % 16 == 11) { sum1 += "B"; }
					else
						if (number % 16 == 12) { sum1 += "C"; }
						else
							if (number % 16 == 13) { sum1 += "D"; }
							else
								if (number % 16 == 14) { sum1 += "E"; }
								else
									if (number % 16 == 15) { sum1 += "F"; }
					
				number /= 16;
			}
			else
			{	
	
				sum1 += to_string(number%16);
				number /= 16;
			}

		}while (number != 0);
		for (int b = 0; b < sum1.length()/2; b++)
		{
			swap(sum1[b], sum1[sum1.length() -1 -b]);
		}
		my.push_back(sum1);//������ ������ �� ��������� ������
	}
	file_strings.clear();
	file_strings = my;
}

void ShowFromFileConsoleTo_x16::Display()
{
	LoadFroFileToArray();
	for (int i = 0; i < file_strings.size(); i++)
	{	
		cout << file_strings[i];
	}
}


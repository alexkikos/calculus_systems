#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


//����� ��������� ���������� �� ����� � �������� � ������ ��������, ��� ��������� ������, ������� ������ ����� � �������
class ShowFromFileConsole
{
protected:
	string file_name;//�������� ��� �����
	vector<string> file_strings;//����� ����������� ������
	virtual void LoadFroFileToArray();//������ ����� ��������������, � ����� ������ � ����
public:
	void SetFileName(string s);
	string GetFIleName() const;
	vector<string> GetStrings() const; //������ �� �����, �� ��� ���������� �������� �� ����� ����������
	virtual void Display();
	explicit ShowFromFileConsole(string filename)
	{		
		this->file_name = filename;
	}
	virtual ~ShowFromFileConsole() {
		file_strings.clear();

	};

};



//����� ������������ ������ ������ ������ � ��� ���� ��� � ��������� ����������� � ������� �������, ��� ��������� ����������
class ShowFromFileConsoleAsCii :
	public ShowFromFileConsole
{
protected:
	vector<int> mynumbers;//������ ����� ���� � ������� ������� ���� ���� ������(���) ������� ������� ������, � ���������� �� ����� ������� ������ ����� ������������� ��� ����������� � ������ �������
	virtual void LoadFroFileToArray() override;//����� ��� �������������� � ������ ������� ����������
public:
	virtual void Display() override; //� ���������� ������������� ���� ����� ����� ����� � ����
	explicit ShowFromFileConsoleAsCii(string file) : ShowFromFileConsole(file) {  };//����������������� �� 1 �������
	virtual ~ShowFromFileConsoleAsCii() { mynumbers.clear(); };
};



//� ������ ������ ���������������� �������� ������ � ������, � ������ ����������� � �������� ���, ������� ����������� ������ 1 �����, ��� ��������� ������������� �� ������������ ������������� �� ������ ����

class ShowFromFileConsoleToBinary : public ShowFromFileConsoleAsCii
{
	virtual void LoadFroFileToArray() override;
public:
	explicit ShowFromFileConsoleToBinary(string file): ShowFromFileConsoleAsCii(file) {  };
	virtual ~ShowFromFileConsoleToBinary() {};
};




class ShowFromFileConsole_x8: public ShowFromFileConsoleAsCii
{
	virtual void LoadFroFileToArray() override;
public:
	explicit ShowFromFileConsole_x8(string file) : ShowFromFileConsoleAsCii(file) {  };
	virtual ~ShowFromFileConsole_x8() {};
};



class ShowFromFileConsoleTo_x16: public ShowFromFileConsoleAsCii
{
	virtual void LoadFroFileToArray() override;
public:
	virtual void Display() override;
	explicit ShowFromFileConsoleTo_x16(string file) :ShowFromFileConsoleAsCii(file) {  };
	virtual ~ShowFromFileConsoleTo_x16() {};
};


#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


//метод считывает информацию из файла и помещает в массив стрингов, для подальшей работы, выводит только текст в консоль
class ShowFromFileConsole
{
protected:
	string file_name;//сохраняю имя файла
	vector<string> file_strings;//храню загруженные строки
	virtual void LoadFroFileToArray();//данный метод обрабатывающий, и будет разный у всех
public:
	void SetFileName(string s);
	string GetFIleName() const;
	vector<string> GetStrings() const; //сеттор не делаю, тк все информация грузится из файла изначально
	virtual void Display();
	explicit ShowFromFileConsole(string filename)
	{		
		this->file_name = filename;
	}
	virtual ~ShowFromFileConsole() {
		file_strings.clear();

	};

};



//метод конвертирует каждый символ строки в его аски код и результат сохраняется в массиве интовом, для подальших вычислений
class ShowFromFileConsoleAsCii :
	public ShowFromFileConsole
{
protected:
	vector<int> mynumbers;//создал новое поле в котором хранить буду аски номера(инт) каждого символа строки, в дальнейшем из этого массива данные будут подтягиваться для конвертаций в другие системы
	virtual void LoadFroFileToArray() override;//метод для преобразований в разные системы исчеслений
public:
	virtual void Display() override; //в дальнейших наследованиях этот метод будет общий у всех
	explicit ShowFromFileConsoleAsCii(string file) : ShowFromFileConsole(file) {  };//проиницилизировал на 1 елемент
	virtual ~ShowFromFileConsoleAsCii() { mynumbers.clear(); };
};



//в данном методе переоприделяется загрузка данных в массив, а именно конвертация в бинарный вид, поэтому переделываю только 1 метод, все остальное подтягивается из виртуального унаследования из класса выше

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


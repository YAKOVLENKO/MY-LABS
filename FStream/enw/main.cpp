#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "Addings.h"

void writeToFile(const std::string & filename)
{
	// fstream - это класс для работы с файлами
	// первый аргумент конструктора, так же как и первый аргумент fopen, принимает путь до файла.
	// второй артумент - режим работы. std::fstream::out - это аналог "w" для fopen
	TFsream fl(filename, "w");
	std::string str = "London is the capital of GB";



	// записываем строку в файл
	fl << str << std::endl;
	// записываем еще одну строку в файл
	fl << "new line";

	// для закрытия файла используется метод close (аналог fclose для FILE *)
	// НО, fstream автоматически закрывает файл при вызове деструктора!
	fl.close();
}

std::string readFirstStringFromFile(const std::string & filename)
{
	// второй артумент - режим работы. std::fstream::in - это аналог "r" для fopen
	TFsream fl(filename, "r");
	std::string str;

	// считываем символы до первого пробела из файла
	fl >> str;

	// не вызываем метод close, потому что файл закроется автоматически при вызове дестуктора объекта fl
	return str;
}

std::string readFirstLineFromFile(const std::string & filename)
{
	TFsream fl(filename, "r");
	std::string line;

	// считываем всю строку из файла
	line = fl.getline1();
	return line;
}

int main() {

	writeToFile("one.txt");

	std::cout << readFirstStringFromFile("one.txt") << std::endl;

	std::cout << readFirstLineFromFile("one.txt");

}

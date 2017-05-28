#include <iostream>

#include <fstream>
#include <string>
#include "Source.h"

void writeToFile(const std::string & filename)
{
	// fstream - это класс для работы с файлами
	// первый аргумент конструктора, так же как и первый аргумент fopen, принимает путь до файла.
	// второй артумент - режим работы. std::fstream::out - это аналог "w" для fopen
	TFsream fl(filename, TFsream::out);
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
	std::fstream fl(filename, std::fstream::in);
	std::string str;

	// считываем символы до первого пробела из файла
	fl >> str;

	// не вызываем метод close, потому что файл закроется автоматически при вызове дестуктора объекта fl
	return str;
}

std::string readFirstLineFromFile(const std::string & filename)
{
	std::fstream fl(filename, std::fstream::in);
	std::string line;

	// считываем всю строку из файла
	std::getline(fl, line);
	return line;
}

std::string TFsream::out = "w";
std::string TFsream::in = "r";

int main() {

	writeToFile("one.txt");

	std::cout << readFirstStringFromFile("one.txt") << std::endl;

	std::cout << readFirstLineFromFile("one.txt");

}

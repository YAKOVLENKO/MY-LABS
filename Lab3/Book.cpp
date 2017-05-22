#include<iostream>
#include<vector>
#include<string>
class Book
{
	std::string author;
	std::string name;
	int quantity;
	int wanted_to_read;
public:
	
	Book(std::string aut, std::string nam, int qua, int want)
	{
		author = aut;
		name = nam;
		quantity = qua;
		wanted_to_read = want;
	}
	~Book() {};
	std::string GetName()
	{
		return name;
	}
	float MiddleCrowd()
	{
		return (float)wanted_to_read / (float)quantity;
	}
	void PrintParameters()
	{
		std::cout << std::endl <<"Author " << author << std::endl << "Name: " << name << std::endl << "Quantity: " << quantity << std::endl << "How much people want ro read it: " << wanted_to_read << std::endl;
		std::cout << "Queue for 1 book: " << this->MiddleCrowd() << std::endl;
	}
	int GetWanted()
	{
		return wanted_to_read;
	}
};
int main()
{
	std::vector<Book> book;
	Book a("Viktor Tolstoy", "Home", 5, 10);
	Book b("Natanella Neece", "Block", 7, 16);
	Book c("Nikolas Kingsley", "Lite", 12, 14);
	book.push_back(a);
	book.push_back(b);
	book.push_back(c);
	int theBiggest = 0;
	std::string The_biggest;
	for (int i = 0; i < 3; ++i)
	{
		if (book[i].GetWanted() > theBiggest)
		{
			theBiggest = book[i].GetWanted();
			The_biggest = book[i].GetName();
		}
	}
	std::cout << "People want to read " << The_biggest << std::endl;
	std::cout << "Books: " << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		book[i].PrintParameters();
	}
}

#include<iostream>
class Apartament
{
private:
	int price;
	int rooms;
public:
	Apartament(); // �����������(1)

	Apartament(int count1, int count2); // �����������(2)

	float average(); // ������� ��������� ����� �������

	void setPrice(int a);
	void setRooms(int a);
	int getPrice();
	int getRooms();

};
std::ostream & operator <<(std::ostream &out,Apartament str);
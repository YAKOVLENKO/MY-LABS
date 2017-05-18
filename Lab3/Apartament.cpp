#include<iostream>
#include<vector>

class Apartament
{
	int S;
	int payment;
public:
	Apartament(int i)
	{
		std::cout << std::endl << "Apartament " << i + 1 << std::endl;
		std::cout << "Write the S: ";
		std::cin >> S;
		std::cout << "Write  Payment for 1 m^3: ";
		std::cin >> payment;
	}
	~Apartament() {};
	int fullPay()
	{
		int full_pay = S * payment;
		return full_pay;
	}
	void PrintParameters()
	{
		std::cout << "S = " << S << std::endl << "Payment for 1 m^3: " << payment << std::endl << "Full payment: " << this->fullPay() << std::endl;
	}
	int GetS()
	{
		return S;
	}
	int GetPayment()
	{
		return payment;
	}
};
int main()
{
	int n;
	std::cout << "Write quantity of apartaments: ";
	std::cin >> n;
	std::vector<Apartament> newVect;
	for (int i = 0; i < n; ++i)
	{
		Apartament a(i);
		newVect.push_back(a);
	}
	std::cout << "Parameters of Apartaments: ";
	for (int i = 0; i < n; ++i)
	{
		std::cout << std::endl << "Apartament " << i + 1 << std::endl;
		newVect[i].PrintParameters();
	}

	std::cout << "Write the max payment you want:";
	std::cin >> n;
	for (int i = 0; i < newVect.size(); ++i)
	{
		if (newVect[i].GetPayment() * newVect[i].GetS() <= n)
			std::cout << "Apartament " << i + 1 << std::endl;
	}
}

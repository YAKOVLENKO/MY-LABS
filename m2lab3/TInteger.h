#include<iostream>
#include<exception>
class Overflow : std::exception
{
public:
	const char* what() const
	{
		return "Error: overflow";
	}
};

class TInteger
{
private:
	long long int value;
public:
	TInteger();
	TInteger(long long int val);
	TInteger(TInteger &integ);
	~TInteger();

	TInteger & operator = (const TInteger & val);
	TInteger & operator = (const long long int val);
	
	bool operator <= (const TInteger & val);
	bool operator <= (const  int val);
	
	bool operator >= (const TInteger & val);
	bool operator >= (const  int val);

	bool operator < (const TInteger & val);
	bool operator < (const int val);

	bool operator > (const TInteger & val);
	bool operator > (const int val);

	bool operator == (const TInteger & val);
	bool operator == (const int val);
	
	TInteger & operator *= (const TInteger & val);
	TInteger & operator *= (const int val);

	TInteger & operator -= (const TInteger & val);
	TInteger & operator -= (const int val);

	TInteger & operator += (const TInteger & val);
	TInteger & operator += (const  int val);

	TInteger & operator /= (const TInteger & val);
	TInteger & operator /= (const int val);
	
	TInteger operator % (const TInteger & val);
	TInteger operator % (const int val);

	bool operator != (const TInteger & val) const;
	bool operator != (const int val) const;

	int GetValue() const;
	friend std::ostream & operator << (std::ostream &out, const TInteger &val);
	operator int();
};

TInteger operator + (const TInteger & val, const TInteger & num);
TInteger operator + (const TInteger & val, const int num);
TInteger operator + (const  int num, const TInteger & val);

TInteger operator - (const TInteger & val, const TInteger & num);
TInteger operator - (const TInteger & val, const int num);
TInteger operator - (const int num, const TInteger & val);

TInteger operator * (const TInteger & val, const TInteger & num);
TInteger operator * (const TInteger & val, const int num);
TInteger operator * (const int num, const TInteger & val);

TInteger operator / (const TInteger & val, const TInteger & num);
TInteger operator / (const TInteger & val, const int num);
TInteger operator / (const int num, const TInteger & val);

std::ostream & operator << (std::ostream &out, const TInteger &val);

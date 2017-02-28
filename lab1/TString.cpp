#include"TString.h"

TString::TString()	
{
	Data = new char[1];
	Data[0] = '\0';
}
TString::TString(const char * data) {
	int l = 0;
	while (data[l])
	{
		l++;
	}
	//if (Data) delete[] Data;
	Data = new char[l + 1];
	for (int i = 0; i <= l; i++)
	{
		Data[i] = data[i];
	}
	Data[l] = '\0';
}
char TString::operator[](size_t index) const {

	return Data[index];

}


char& TString::operator [](size_t index)
{
	return Data[index];
}
size_t TString::Size() const
{
	int l = 0; 
	while (Data[l])
	{
		l++;
	}
	return l;
}
TString::TString(const TString& rhs)	
{
	delete[] Data;
	Data = new char[rhs.Size() + 1];
	for (int i = 0; i <= rhs.Size(); i++)
	{
		Data[i] = rhs[i];
	}
}
bool TString::operator ==(const TString& rhs) const
{
	int l = 0; 
	while (Data[l])
	{
		l++;
	}
	if (l != rhs.Size())
	{
		return 0;
	}
	for (int i = 0; i < l; i++)
	{
		if (Data[i] != rhs[i]) return 0;
	}
	return 1;
}

TString& TString::operator =(const TString& data)	
{
	if (*this == data) return *this;
	delete[] Data;
	int l = data.Size(); 
	Data = new char[l];
	for (int i = 0; i <= l; i++)
	{
		Data[i] = data[i];
	}
	return *this;
}
bool operator!=(const TString & a, const TString & b)
{
	return !(a == b);
}
bool TString::operator <(const TString& rhs) const
{
	int l = 0; 
	int min = 0;
	while (Data[l])
	{
		l++;
	}
	if (l < rhs.Size()) { min = l; }
	else { min = rhs.Size(); }
	for (int i = 0; i < min; i++)
	{
		if (Data[i] < rhs[i]) { return 1; }
		if (Data[i] > rhs[i]) { return 0; }
	}
	return 0;
}
bool operator>(const TString & a, const TString & b)
{
	return !(a < b) && (a != b);
}
TString operator+(const TString & a, const TString & b)
{
	TString str;
	int l = a.Size() + b.Size();
	char *tmp = new char[l + 1];
	for (int i = 0; i < a.Size(); i++)
	{
		tmp[i] = a[i];
	}
	for (int i = a.Size(); i - a.Size() < b.Size() + 1; i++)
	{
		tmp[i] = b[i - a.Size()];
	}
	str = tmp;
	return str;
}
TString& TString::operator +=(const TString& rhs)
{
	int l = 0;
	while (Data[l])
	{
		l++;
	}
	char * tmp = new char[l + rhs.Size() + 1];
	for (int i = 0; i < l; i++)
	{
		tmp[i] = Data[i];
	}
	for (int i = l; i < l + rhs.Size() + 1; i++)
	{
		tmp[i] = rhs[i - l];
	}
	delete[] Data;
	Data = tmp;
	return *this;
}
void TString::LTrim(char symbol)
{
	int l = 0; 
	int k = 0; 
	while (Data[l])
	{
		l++;
	}
	for (int i = 0; i < l; i++)
	{
		if (Data[i] != symbol)
		{
			break;
		}
		k++;
	}
	char* tmp = new char[l - k];
	for (int i = 0; i <= l - k; i++)
	{

		tmp[i] = Data[k + i];
	}
	delete[] Data;
	Data = tmp;
}
void TString::RTrim(char symbol)
{
	int l = 0; 
	while (Data[l])
	{
		l++;
	}
	char* tmp = new char[l + 1];
	for (int i = 0; i < l; i++)
	{
		tmp[i] = Data[l - i - 1];
	}
	tmp[l] = '\0';
	delete[] Data;
	Data = tmp;
	(*this).LTrim(symbol);
	l = 0;
	while (Data[l])
	{
		l++;
	}
	for (int i = 0; i < l; i++)
	{
		tmp[i] = Data[l - i - 1];
	}
	tmp[l] = '\0';
	delete[] Data;
	Data = tmp;

}
std::ostream & operator<<(std::ostream &out, const TString &str)
{
	out << str.Data;
	return out;
}
TString::~TString()
{
	if (Data != nullptr)
	{
		delete[] Data;
	}
}
size_t TString::Find(const TString& substr) const
{
	int l = 0;
	int st = 0;
	int sc = 0;
	int j = 0; 
	while (Data[l])
	{
		l++;
	}
	if (l < substr.Size())
	{
		return 0;
	}
	for (int i = 0; i < l; i++)
	{
		if (Data[i] == substr[0])
		{
			st = i;
			if (Data[i + substr.Size()])
			{
				j = 0;
				sc = 1;
				while (j < substr.Size()) {

					if (Data[st + j] != substr[j]) {
						sc = 0;
					}
					j++;
					if (j == substr.Size() && sc) {
						return st;
					}
				}
			}
		}
	}
	return -1;

}
bool TString::Empty() const
{
	if (Data != nullptr || Data[0] != '\0') { return 0; }
	return 1;
}
void TString::Replace(char oldSymbol, char newSymbol)
{
	int l = 0;
	while (Data[l])
	{
		if (Data[l] == oldSymbol) { Data[l] = newSymbol; }
		l++;
	}
}

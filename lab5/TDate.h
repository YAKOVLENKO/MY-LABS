#include"TTriad.h"

class TDate : public TTriad
{
private:
	int day;
	int month;
	int year;
public:
	TDate();
	TDate(int d, int m, int y);
	~TDate();
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	bool operator ==(const TDate& s) const;
	bool operator <(const TDate& s) const;
	bool operator!=(const TDate& s) const;
	bool operator >(const TDate& s) const;
	bool operator <=(const TDate& s) const;
	bool operator >=(const TDate& s) const;
	void Print();
};
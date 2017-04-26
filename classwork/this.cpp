#include <iostream>

#include <string>
#include <vector>
#include <map>

#include <algorithm>
#include <numeric>

enum Grade
{
	F = 1,
	D,
	C,
	B,
	A
};

struct Student
{
	std::string FIO;
	std::string Group;
	std::map<std::string, Grade> Grades;
};

std::vector<Student> LoadStudents()
{
	return{
		{
			"Anna", "G7",
			{
				{ "math", Grade::A },
				{ "cs", Grade::A },
				{ "english", Grade::A },
				{ "dutch", Grade::B },
			}
		},
		{
			"Petr", "G7",
			{
				{ "math", Grade::A },
				{ "cs", Grade::B },
				{ "dutch", Grade::C },
			}
		},
		{
			"Vova", "G1",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
			}
		},
		{
			"Vasya", "G3",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
				{ "cs", Grade::B },
				{ "dutch", Grade::C },
			}
		},
		{
			"Anton", "G4",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
				{ "dutch", Grade::C },
				{ "cs", Grade::C },
			}
		},
		{
			"Masha", "G2",
			{
				{ "math", Grade::A },
			}
		},
		{
			"Sasha", "G6",
			{
				{ "english", Grade::F },
				{ "russian", Grade::F },
				{ "dutch", Grade::F },
			}
		},
		{
			"Jeka", "G2",
			{
				{ "english", Grade::A },
			}
		},
		{
			"Sveta", "G3",
			{
			}
		}
	};
}


struct FindStudentGroup
{
	std::string neededGroup;
	bool operator()(const Student& s) const
	{
		return s.Group == neededGroup;
	}
};

struct PrinterStudent
{
	void operator()(const Student& s) const
	{
		std::cout << s.FIO << " studies in " << s.Group << std::endl;
	}
};

struct GradeEqual
{
	Grade grade = Grade::A;

	bool operator()(const std::pair<std::string, Grade> & el) const
	{
		return el.second == grade;
	}
};

float LowAverNum(std::vector<Student> stud)
{
	float min_average = Grade::A;
	float average = 0;
	for (int i = 0; i < stud.size(); ++i)
	{
		if (stud[i].Grades.size() == 0)
			return 0;
		for (auto it = stud[i].Grades.begin(); it != stud[i].Grades.end(); ++it)
		{
			average += it->second;
		}
		average /= stud[i].Grades.size();
		if (average < min_average)
			min_average = average;
	}
	return min_average;
}
float LowAverOneNum(Student& s)
{
	float average = 0;
	for (auto itav = s.Grades.begin(); itav != s.Grades.end(); ++itav)
	{
		average += itav->second;
	}
	average /= s.Grades.size();
	return average;
}
struct LowAver
{
	float min_average = LowAverNum(LoadStudents());
	void operator()(Student& s) const
	{
		if (s.Grades.size() == 0)
		{
			std::cout << "Low_Aver " << s.FIO << std::endl;
		}
		if (LowAverOneNum(s) == min_average)
		{
			std::cout << "Low_Aver " << s.FIO << std::endl;
		}
	}
};
size_t MaxSubVal(std::vector<Student> stud)
{
	size_t max = 0;
	for (int i = 0; i < stud.size(); ++i)
	{
		if (stud[i].Grades.size() > max)
			max = stud[i].Grades.size();
	}
	return max;
};
size_t MinSubVal(std::vector<Student> stud)
{
	size_t min = MaxSubVal(stud);
	for (int i = 0; i < stud.size(); ++i)
	{
		if (stud[i].Grades.size() < min)
			min = stud[i].Grades.size();
	}
	return min;
}

struct MaxAndMinSub
{
	std::vector<Student> st = LoadStudents();
	size_t max_num = MaxSubVal(st);
	size_t min_num = MinSubVal(st);
	void operator()(const Student& s) const
	{
		if (s.Grades.size() == max_num)
		{
			std::cout << "Max: " << s.FIO << std::endl;
		}
		if (s.Grades.size() == min_num)
		{
			std::cout << "Min: " << s.FIO << std::endl;
		}
	}

};

struct mathcs
{
	Grade mgrade = Grade::A;
	Grade csgrade = Grade::B;
	void operator()(const Student& s) const
	{
		if (s.Grades.count("math") == 1 && s.Grades.count("cs") == 1 && s.Grades.find("math")->second == mgrade && s.Grades.find("cs")->second == csgrade)
		{
			std::cout << s.FIO << std::endl;
		}
	}
};




int main()
{
	std::vector<Student> students = LoadStudents();

	// find students from G1
	FindStudentGroup finderObj;
	finderObj.neededGroup = "G1";
	auto it = std::find_if(students.begin(), students.end(), finderObj);
	if (it != students.end())
		std::cout << it->FIO << std::endl;


	// find students from G7
	it = std::find_if(students.begin(), students.end(), FindStudentGroup{ "G7" });
	if (it != students.end())
		std::cout << it->FIO << std::endl;


	// print info about all students
	std::for_each(students.begin(), students.end(), PrinterStudent());


	// count of grades eq 'A' of the student from G7
	auto cnt = std::count_if(it->Grades.begin(), it->Grades.end(), GradeEqual{});
	std::cout << cnt << std::endl;

	// count of grades eq 'B' of the student from G7
	auto cnt2 = std::count_if(it->Grades.begin(), it->Grades.end(),
		// lambda
		[](const std::pair<std::string, Grade> & el)
	{
		return el.second == Grade::B;
	}
	);
	std::cout << cnt2 << std::endl;

	std::for_each(students.begin(), students.end(), mathcs());
	//std::cout << students[1].Grades.size() << std::endl;

	std::for_each(students.begin(), students.end(), MaxAndMinSub());
	std::for_each(students.begin(), students.end(), LowAver());
}
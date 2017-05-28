

#include <string>
#include <iostream>
#include <sstream>


class TFsream 
{
	FILE *file;
public:

	static std::string out;
	static std::string in;
	
	TFsream() = default;

	TFsream(std::string str, std::string type) 
	{
		file = fopen(str.c_str(), type.c_str());
	};

	~TFsream() 
	{
		fclose(file);
	};

	TFsream& operator<<(std::string str) 
	{
		if (file == NULL)
			throw std::exception()
		fprintf(file, str.c_str());
		return *this;
	}

	TFsream& operator<<(char * str) 
	{
		if (file == NULL)
			throw std::exception()
		fprintf(file, str);
		return *this;
	}

	TFsream& operator<<(std::ostream&(*endl)(std::ostream&))
	{
		if (file == NULL)
			throw std::exception()
		std::ostringstream ss;
		ss << endl;
		fprintf(file, ss.str().c_str());
		return *this;
	}

	void close() 
	{
		fclose(file);
	}

};

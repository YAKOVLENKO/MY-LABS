#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>

class TFsream
{
    FILE *file;
    bool opened = 0;
public:

    static std::string out;
    static std::string in;

    TFsream() = default;

    TFsream(std::string str, std::string type)
    {
        file = fopen(str.c_str(), type.c_str());
        if (file != NULL) opened = 1;
    };

    void open(std::string str, std::string type)
    {

        if (opened) close();
        file = fopen(str.c_str(), type.c_str());
        if (file != NULL) opened = 1;

    }

    bool is_open()
    {

        return opened;
    }

    ~TFsream()
    {
        if (!opened) fclose(file);
        opened= 0;
    };

    TFsream& operator<<(std::string str)
    {
        if (!opened)
            throw std::exception();
        fprintf(file, str.c_str());
        return *this;
    }

    TFsream& operator<<(char * str)
    {
        if (!opened)
            throw std::exception();
        fprintf(file, str);
        return *this;
    }

    TFsream& operator<<(std::ostream&(*endl)(std::ostream&))
    {
        if (!opened)
            throw std::exception();
        std::ostringstream ss;
        ss << endl;
        fprintf(file, ss.str().c_str());
        return *this;
    }

    void close()
    {
        if(opened) fclose(file);
        opened= 0;
    }

    std::string getline1(){
        if (!opened) return "";
        char * line = NULL;
        size_t len = 0;
        ssize_t read;
        read = getline(&line, &len, file);
        std::string tmp(line);
        return tmp;
    }

    std::string read()
    {
        if (!opened) return "";
        fseek(file, 0, SEEK_END);
        int size = ftell(file);
        fseek(file, 0, SEEK_SET);
        char * fcontent = new char[size];
        fread(fcontent, 1, size, file);
        std::string tmp(fcontent);
        delete[] fcontent;
        return tmp;
    }

    std::string write(std::string s){

        if (opened) fprintf(file, s.c_str());
    }

    void seek(int pos){

        if (opened) fseek (file , pos , SEEK_SET );

    }


    int eof(){

        return feof(file);

    }

};

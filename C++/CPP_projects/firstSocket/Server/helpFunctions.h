#ifndef _FUNC_
#define _FUNC_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

void read_name_of_file(const std::string &nameOfFile, std::vector<std::string> &names)
{
    std::fstream file;
    file.open(nameOfFile, std::fstream::in);
    std::string str;

    while (!file.eof())
    {
        file >> str;
        if (str != " ")
            names.push_back(str);

        str = " ";
    }
    file.close();
}
void write_name_of_file(const std::string &nameOfFile, std::vector<std::string> &names)
{
    std::fstream file;
    file.open(nameOfFile, std::fstream::out);
    for (int i = 0; i < names.size(); ++i)
    {
        file << names[i] << std::endl;
    }
    file.close();
}
void error(const std::string &error)
{
    std::cout << error << std::endl;
    exit(1);
}
std::string check_command(const char *command)
{
    std::stringstream com(command);
    std::string str;
    std::getline(com, str, ' ');

    if (str == "EXIT") //read
    {
        return "EXIT";
    }
    else if (str == "GET") //read
    {
        return "GET";
    }
    else if (str == "POST") // create
    {
        return "POST";
    }
    else if (str == "PUT") //update
    {
        return "PUT";
    }
    else if (str == "DELETE") //delete
    {
        return "DELETE";
    }
    else
    {
        return " ";
    }
}
bool check_file(const char *buff, std::vector<std::string> &names)
{
    std::stringstream strm(buff);
    std::string str;
    std::getline(strm, str, ' ');
    std::getline(strm, str, ' ');

    if (find(names.begin(), names.end(), str) == names.end())
    {
        return false;
    }
    return true;
}

#endif //_FUNC_

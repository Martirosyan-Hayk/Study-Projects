#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cerrno>
#include <unistd.h>
#include <vector>
#include <utility>
#include <sstream>
#include <stdio.h>
#include "helpFunctions.h"

int main(int argc, char *argv[])
{
    std::vector<std::string> file_name;
    read_name_of_file("nameOfFile.txt", file_name);
    uint sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];

    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2)
    {
        error("ERROR, no port provided");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("ERROR opening socket");
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        error("ERROR on binding");
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

    std::string end_program;

    while (end_program != "$E_N_D$")
    {
        memset(buffer, 0, 256);
        n = read(newsockfd, buffer, 255);
        if (n < 0)
        {
            error("ERROR: reading from socket");
        }
        std::cout << "Here is the message:" << buffer << std::endl;

        std::string comm = check_command(buffer);

        if (comm != "EXIT" && comm != "GET" && comm != "PUT" && comm != "POST" && comm != "DELETE")
        {
            write(newsockfd, "ERROR: wrong command", 20);
        }

        if (comm == "EXIT")
        {
            write(newsockfd, "THE PROGRAM IS END: !THANKS YOU! GOOD BYE :)", 44);
            end_program = "$E_N_D$";
        }
        else if (comm == "GET") //read
        {

            if (check_file(buffer, file_name))
            {
                std::string command(buffer);
                std::stringstream com(command);
                std::string str;
                std::getline(com, str, ' ');
                std::getline(com, str, ' ');

                std::fstream file;
                file.open(str, std::fstream::in);
                std::string text_of_file;

                while (!file.eof())
                {
                    memset(buffer, 0, 255);
                    file.getline(buffer, 255);
                    write(newsockfd, buffer, 255);
                }
                write(newsockfd, "$E_N_D$", 7);

                file.close();
            }
            else
                write(newsockfd, "ERROR: wrong name of file", 25);
        }
        else if (comm == "POST") // create
        {
            if (check_file(buffer, file_name))
            {
                write(newsockfd, "ERROR: this file exists", 23);
            }
            else
            {
                std::string command(buffer);
                std::stringstream com(command);
                std::string str;
                std::getline(com, str, ' ');
                std::getline(com, str, ' ');
                std::fstream new_file;
                new_file.open(str, std::fstream::out);
                file_name.push_back(str);

                write(newsockfd, "Yor file is create!", 19);
                new_file.close();
            }
        }
        else if (comm == "PUT") //update
        {
            if (!check_file(buffer, file_name))
            {
                write(newsockfd, "ERROR: wrong name of file", 25);
            }
            else
            {
                std::string command(buffer);
                std::stringstream com(command);
                std::string str;
                std::getline(com, str, ' ');
                std::getline(com, str, ' ');
                std::fstream file(str, std::fstream::out | std::fstream::app);
                while (std::getline(com, str, ' '))
                {
                    file << str << " ";
                }
                file << std::endl;
                file.close();
                write(newsockfd, "Yor file is updated!", 20);
            }
        }
        else if (comm == "DELETE") //delete
        {
            if (!check_file(buffer, file_name))
            {
                write(newsockfd, "ERROR: wrong name of file", 25);
            }
            else
            {
                std::string command(buffer);
                std::stringstream com(command);
                std::string str;
                std::getline(com, str, ' ');
                std::getline(com, str, ' ');
                if (remove(str.c_str()) == 0)
                {
                    std::remove(file_name.begin(), file_name.end(), str);
                    write(newsockfd, "Yor file is deleted successfully!", 33);
                }
                else
                {
                    write(newsockfd, "Unable to delete the file", 25);
                }
            }
        }
    }

    write_name_of_file("nameOfFile.txt", file_name);

    close(newsockfd);
    close(sockfd);

    return 0;
}

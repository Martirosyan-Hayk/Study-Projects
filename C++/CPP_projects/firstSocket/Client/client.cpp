#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cerrno>
#include <unistd.h>
#include <netdb.h>

void error(const std::string &error)
{
    std::cout << error << std::endl;
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    if (argc < 3)
    {
        std::cout << "usage " << argv[0] << " hostname port" << std::endl;
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);

    if (server == NULL)
    {
        std::cout << "ERROR, no such host" << std::endl;
        exit(0);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        error("ERROR connecting");
    }

    std::string end_program;

    while (end_program != "EXIT")
    {
        std::cout << "Please enter the message: " << std::endl;
        memset(buffer, 0, 256);
        std::cin.getline(buffer, 255);
        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0)
        {
            error("ERROR writing to socket");
        }

        memset(buffer, 0, 256);
        // n = read(sockfd, buffer, 255);

        while (n > 0)
        {
            n = read(sockfd, buffer, 255);
            std::string end(buffer);
            //std::cout << end << " ***end";

            if (end == "$E_N_D$")
            {
                n = -1;
                break;
            }
            if (end == "THE PROGRAM IS END: !THANKS YOU! GOOD BYE :)")
            {
                end_program = "EXIT";
            }
            if (end == "ERROR: wrong name of file" || end == "ERROR: wrong command" || end == "Yor file is create!" || end == "ERROR: this file exists" || end == "Yor file is updated!" || end == "Yor file is deleted successfully!" || end == "Unable to delete the file")
            {
                std::cout << buffer << std::endl;
                n = -1;
            }
            else
            {
                std::cout << buffer << std::endl;
            }
            memset(buffer, 0, 256);
        }
    }

    close(sockfd);

    return 0;
}
#include <iostream>
#include "Admin.h"
#include "Student.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


int main()
{
    std::fstream file_names;
    file_names.open("File_names.txt", std::fstream::in | std::fstream::out | std::fstream::app);

    std::vector<std::string> name_file;
    while (!file_names.eof())
    {
        std::string hin_fil;

        file_names >> hin_fil;
        name_file.push_back(hin_fil);
    }
    file_names.close();

    file_names.open("File_names.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    std::string admin_or_student;
    std::cout <<  "     # You visited Google Forms #  " << std::endl;
    std::cout << "You want to register as an administrator or student" << std::endl;
    std::cin >> admin_or_student;

  if (admin_or_student == "administrator")  
  {
      std::string name_of_file;
      std::cout << "Enter name of topic " << std::endl;
      std::cin >> name_of_file;
      name_of_file += ".txt";
  
      for (int i = 0; i < name_file.size(); )
      {
          if (name_of_file == name_file[i])
          {
              std::cout << "This name is busy:Enter new name of topic " << std::endl;
              std::cin >> name_of_file;
              name_of_file += ".txt";
              i = 0;
          }
          else
              ++i;
      }
      std::cin.get();

      file_names << name_of_file << std::endl;

      Admin a(name_of_file);
      a.start();
      
  }
  else if (admin_or_student == "student")
  {

      for (int i = 0; i < name_file.size(); ++i)
      {
          std::cout << name_file[i] << std::endl;
      }

      std::string name_of_test;
      std::cout << "Choose one of the tests: Enter name of test: " << std::endl;
      std::cin >> name_of_test;
      int i = 0;
      while (name_of_test != name_file[i])
      {
          if (i == name_file.size() - 1)
          {
              std::cout << "With that name test was not found: Enter name of test: " << std::endl;
              std::cin >> name_of_test;
              i = 0;
          }
          else
            ++i;
      }
  
      Student s(name_of_test);
      s.red_test(name_of_test);
      s.rating();

  }

  file_names.close();
    return 0;
}
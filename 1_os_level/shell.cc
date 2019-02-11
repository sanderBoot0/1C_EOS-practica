#include "shell.hh"

int main()
{ std::string input;
  while(true)
  { std::getline(std::cin, input);
    if (input == "new_file") new_file();
    if (input == "ls") list();
    if (input == "find") find();
    if (input == "python") python();
    if (input == "quit") return 0;
    if (input == "error") return 1; } }

void new_file()
{ std::cout << "NEW" << std::endl; }

void list()
{ std::cout << "LS" << std::endl; }

void find()
{ std::cout << "FIND" << std::endl; }

void python()
{ std::cout << "PYTHON" << std::endl; }

#include "shell.hh"

int main()
{ std::string input;
  while(true)
  { std::getline(std::cin, input);
    if (input == "new_file") new_file();
    if (input == "ls") list();
    if (input == "src") src();
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

void src()
{ int fd = syscall(SYS_open, "shell.cc", O_RDONLY, 0755); // Gebruik de SYS_open call om een bestand te openen.
  char byte[1];                                           // 0755 zorgt dat het bestand de juiste rechten krijgt (leesbaar is).
  while(syscall(SYS_read, fd, byte, 1))                   // Blijf SYS_read herhalen tot het bestand geheel gelezen is,
    std::cout << byte; }                                  //   zet de gelezen byte in "byte" zodat deze geschreven kan worden.

#include "shell.hh"

int main()
{
    std::string input;

    // ToDo: Vervang onderstaande regel: Laad prompt uit bestand
    std::string prompt;

    std::ifstream promptFile ("prompt.txt");
    getline(promptFile, prompt);

    while (true)
    {
        std::cout << prompt;           // Print het prompt
        std::getline(std::cin, input); // Lees een regel
        if (input == "new_file")
            new_file(); // Kies de functie
        else if (input == "ls")
            list(); //   op basis van
        else if (input == "src")
            src(); //   de invoer
        else if (input == "python")
            python();
        else if (input == "exit")
            return 0;
        else if (input == "quit")
            return 0;
        else if (input == "error")
            return 1;

        if (std::cin.eof())
            return 0;
    }
} // EOF is een exit

void new_file() // ToDo: Implementeer volgens specificatie.
{
    std::cout << "Give name: ";
    char fileName[20];
    std::cin >> fileName;
    std::cin.ignore();

    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int fd = syscall(SYS_creat, fileName, mode);
    fd = syscall(SYS_open, fileName, O_WRONLY);
    
    std::string input;

    while(input != "EOF\n") {
        std::cout << "Give a sentence: ";
        getline(std::cin, input);
        input = input + "\n";
        const char *writeInput = input.c_str();
        ssize_t write = syscall(SYS_write, fd, writeInput, input.size());

    }

    syscall(SYS_close, fd);
}

void list() // ToDo: Implementeer volgens specificatie.
{
    int pid = fork();
    if (pid == 0) {
        char *args[] = {"/bin/ls", "-l", "-a", (char *) 0 };
        execv("/bin/ls", args);
    } 
    else {
        int exit_status;
        wait(&exit_status);
    }
}

void python() // ToDo: Implementeer volgens specificatie.
{
    int pid = fork();
    if (pid == 0) {
        char *args[] = {"/usr/bin/python", (char * ) 0};
        execv("/usr/bin/python", args);
    } 
    else {
        int exit_status;
        wait(&exit_status);
    }
}

void src() // Voorbeeld: Gebruikt SYS_open en SYS_read om de source van de shell (shell.cc) te printen.
{
    int fd = syscall(SYS_open, "shell.cc", O_RDONLY, 0755); // Gebruik de SYS_open call om een bestand te openen.
    char byte[1];                                           // 0755 zorgt dat het bestand de juiste rechten krijgt (leesbaar is).
    while (syscall(SYS_read, fd, byte, 1))                  // Blijf SYS_read herhalen tot het bestand geheel gelezen is,
        std::cout << byte;
} //   zet de gelezen byte in "byte" zodat deze geschreven kan worden.

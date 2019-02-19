#include "shell.hh"
 
using namespace std;
 
void new_file() {
    cout << "Give name: ";
    string fileName;
    cin >> fileName;
    ofstream outfile (fileName);
    string input;
    while (input != "EOF") {
        cout << "Give a sentence: ";
        cin >> input;
        outfile << input << endl;
    }
    outfile.close();
}
 
void list() {
    int pid = fork();
    if (pid == 0) {
        // char *args[] = {"/bin/ls", "-r", "-t", "-l", (char *) 0};
        // execv("/bin/ls", args);
        system("ls -la");
        _exit(0);
    } else {
        int exit_status;
        wait(&exit_status);
    }
}
 
void find() {
    cout << "Search for: ";
    string input;
    cin >> input;
 
    int pid = fork();
    if (pid == 0) {
        system("find .");// >> system("grep " + input);
        _exit(0);
    } else {
        int exit_status;
        wait(&exit_status);
    }
}
 
void python() {
    int pid = fork();
    if (pid == 0) {
        system("python");
        _exit(0);
    } else {
        int exit_status;
        wait(&exit_status);
    }
}
 
int main() {
    string promptLine;
    ifstream promptFile ("prompt.txt");
    getline(promptFile, promptLine);
 
    string input;
    while (true) {
        cout << promptLine << " ";
        getline(cin, input);
        if (input == "new_file") new_file();
        if (input == "ls") list();
        if (input == "find") find();
        if (input == "python") python();
        if (input == "quit") return 0;
        if (input == "error") return 1;
    }
}

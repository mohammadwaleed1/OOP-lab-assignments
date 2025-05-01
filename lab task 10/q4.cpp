#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void logMessage(const string& message) {
    static int fileNumber = 1;
    static int charCount = 0;
    const int MAX_CHARS = 1024; 

    string fileName = "log" + to_string(fileNumber) + ".txt";

    ofstream logFile(fileName, ios::app);
    if (!logFile) {
        cout << "Unable to open log file.\n";
        return;
    }

    logFile << message << "\n";
    charCount += message.length() + 1;

    if (charCount >= MAX_CHARS) {
        fileNumber++;
        charCount = 0;
    }

    logFile.close();
}

void addTask(const string& task) {
    ofstream out("tasks.txt", ios::app);
    out << "0 " << task << "\n"; 
    out.close();
}

void viewTasks() {
    ifstream in("tasks.txt");
    string line;
    int id = 1;
    while (getline(in, line)) {
        if (line.length() < 2) continue;
        char status = line[0];
        string task = line.substr(2);
        cout << id << ". [" << (status == '1' ? "Done" : "Todo") << "] " << task << endl;
        id++;
    }
    in.close();
}

void markTaskDone(int targetId) {
    ifstream in("tasks.txt");
    ofstream temp("temp.txt");

    string line;
    int id = 1;

    while (getline(in, line)) {
        if (line.length() < 2) continue;
        if (id == targetId && line[0] == '0') {
            line[0] = '1';
        }
        temp << line << "\n";
        id++;
    }

    in.close();
    temp.close();

    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");
}

int main() {
    int choice;
    string input;

    while (true) {
        cout << "\n=== MENU ===\n";
        cout << "1. Write Log Message\n";
        cout << "2. Add To-Do Task\n";
        cout << "3. View Tasks\n";
        cout << "4. Mark Task as Done\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            cout << "Enter log message: ";
            getline(cin, input);
            logMessage(input);
        } else if (choice == 2) {
            cout << "Enter task: ";
            getline(cin, input);
            addTask(input);
        } else if (choice == 3) {
            viewTasks();
        } else if (choice == 4) {
            cout << "Enter task number to mark as done: ";
            int id;
            cin >> id;
            cin.ignore();
            markTaskDone(id);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}

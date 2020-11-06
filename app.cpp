#include <iostream>
#include <fstream>
using namespace std;

void clearScreen() {
    system("clear");
}

void append_file(string user_input) {
    fstream file;
    file.open("ToDo.txt", ios::app);
    file << user_input << endl;
    file.close();
}

void list_file() {
    string file;
    ifstream listFile("ToDo.txt");
    while (getline (listFile, file)) {
        cout << file << endl;
    }
    listFile.close();
}

void remove_line(string user_input) {
    string line;

    ifstream file;
    file.open("ToDo.txt");
    ofstream temp;
    temp.open("temp.txt");
    while (getline(file, line)) {
        if (line != user_input) {
            temp << line << endl;
        }
    }
    temp.close();
    file.close();
    remove("ToDo.txt");
    rename("temp.txt", "ToDo.txt");
}


int main() {
    string user_input;

    cout << "Welcome To ToDo App\n";
    cout << "1.Add item\n";
    cout << "2.List item\n";
    cout << "3.Remove item\n";
    cout << "4.Quit\n";
    cout << "]>";
    getline(cin, user_input);

    if (user_input == "1") {
        clearScreen();
        cout << "Insert Here: ";
        getline(cin, user_input);
        append_file(user_input);
    } else if (user_input == "2") {
        clearScreen();
        list_file();
    } else if (user_input == "3") {
        clearScreen();
        cout << "What would you like to remove?\n";
        cout << "]>";
        getline(cin, user_input);
        remove_line(user_input);
    }
}
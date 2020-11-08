/*
Author  : John07-noob
Date    : Nov/09/2020
*/
#include <iostream>
#include <fstream>
using namespace std;

void clearScreen() {
    system("clear");
}

void append_file() {
    while(true){
        string user_input;
        cout << "Insert Here (q): ";
        getline(cin, user_input);
        if (user_input == "q") {
            break;
        }
    fstream file;
    file.open("ToDo.txt", ios::app);
    file << user_input << endl;
    file.close();}
}

void list_file() {
    string file;
    ifstream listFile("ToDo.txt");
    while (getline (listFile, file)) {
        cout << file << endl;
    }
    listFile.close();
    while(true){
    string user_input;
    cout << "Insert Here (q): ";
    getline(cin, user_input);
    if (user_input == "q") {
        break;
    }else {
        cout << "Invalid Command!\n";
    }}
}

void remove_line() {
	while(true){
		string line, user_input;
		cout << "Insert Here (q): ";
		getline(cin, user_input);
		if (user_input == "q") {
			break;
		}
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
    rename("temp.txt", "ToDo.txt");}
}


int main() {
    string user_input;

while(true){
    cout << "Welcome To ToDo App\n";
    cout << "1.Add item\n";
    cout << "2.List item\n";
    cout << "3.Remove item\n";
    cout << "4.Quit\n";
    cout << "Insert Here: ";
    getline(cin, user_input);

    if (user_input == "1") {
        clearScreen();
        append_file();
        clearScreen();
    } else if (user_input == "2") {
        clearScreen();
        list_file();
        clearScreen();
    } else if (user_input == "3") {
        clearScreen();
        remove_line();
		clearScreen();
    }else if (user_input == "4") {
		break;
	}}
}

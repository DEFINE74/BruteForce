#include <iostream>  
#include <string>  
#include <ctime>  
#include <set>  
#include <windows.h>  
#include <chrono>

using namespace std;
using namespace std::chrono;

void WelcomeMenu() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //low level console manipulations  

    cout << "Welcome to BRUTEFORCE" << endl;
    cout << "Your current version is: 1.0";

    COORD cursorPosition1 = { 0, 29 };
    SetConsoleCursorPosition(consoleHandle, cursorPosition1);
    cout << "Created by hatred8841. ";

    COORD cursorPosition2 = { 0, 3 };
    SetConsoleCursorPosition(consoleHandle, cursorPosition2);
}
string BruteForceSymbols() {
    return  "123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()";
}
string PasswordInput() {
    string password;
    cout << "Enter your password: ";
    cin >> password;
    return password;
}
string MainCycle(string password, string symbols) {
    int cycleCount = 0;
    set<string> generatedPasswords;
    cout << "\nThe hacking process: \n";
    cout << endl;
    while (true) {
        string randomPassword;
        for (int i = 0; i < password.length(); i++) {
            randomPassword += symbols[rand() % symbols.length()];
        }
        if (generatedPasswords.find(randomPassword) != generatedPasswords.end()) {
            continue;
        }
        generatedPasswords.insert(randomPassword);
        cycleCount++;
        if (password == randomPassword) {
            string newLine = "\rIteration: " + to_string(cycleCount) + "   Password: " + randomPassword;
            cout << newLine;
            cout << endl << "\nThe entered password is: " << randomPassword << endl;
            return randomPassword;
        }
        else {
            string newLine = "\rIteration: " + to_string(cycleCount) + "   Password: " + randomPassword;
            cout << newLine;
        }
    }
}
int main() {
    string userPassword;
    string availableSymbols = BruteForceSymbols();
    auto start = high_resolution_clock::now();

    srand(time(NULL));
    WelcomeMenu();
    userPassword = PasswordInput();
    string crackedPassword = MainCycle(userPassword, availableSymbols);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nPassword was cracked in: " << duration.count() / 1000 << "." << duration.count() % 1000 << " seconds" << endl;

    return 0;
}
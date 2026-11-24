#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    char name[20];
    int id;
    float grade;
    char delim;
};

int main() {
    ofstream outFile("students.txt", ios::app);
    if (!outFile.is_open()) {
        cout << "Error opening file!\n";
        return 1;
    }

    char choice;
    do {
        Student s;
        s.delim = '$';

        cout << "Enter student name: ";
        cin.getline(s.name, 20);

        cout << "Enter student ID: ";
        cin >> s.id;

        cout << "Enter student grade: ";
        cin >> s.grade;

        outFile << s.name << ", " << s.id << ", " << s.grade << " " << s.delim << endl;

        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    outFile.close();
    cout << "Records saved to students.txt successfully.\n";
    return 0;
}

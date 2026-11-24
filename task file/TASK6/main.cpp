#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main() {
    ofstream outFile("grades.txt");
    if (!outFile) {
        cout << "Error creating grades.txt!\n";
        return 1;
    }

    cout << "Enter 5 integer grades:\n";
    for (int i = 0; i < 5; i++) {
        int g;
        cin >> g;
        outFile << g << endl;
    }
    outFile.close();

    ifstream inFile("grades.txt");
    if (!inFile) {
        cout << "Error opening grades.txt for reading!\n";
        return 1;
    }

    cout << "\nGrades in file:\n";
    int grade;
    while (inFile >> grade) {
        cout << grade << endl;
    }
    inFile.close();

    int target;
    cout << "\nEnter grade to delete: ";
    cin >> target;

    ifstream srcFile("grades.txt");
    ofstream tempFile("temp.txt");
    if (!srcFile || !tempFile) {
        cout << "Error opening files for deletion!\n";
        return 1;
    }

    bool found = false;
    while (srcFile >> grade) {
        if (grade != target) {
            tempFile << grade << endl;
        } else {
            found = true;
        }
    }

    srcFile.close();
    tempFile.close();

    if (remove("grades.txt") == 0 && rename("temp.txt", "grades.txt") == 0) {
        if (found) {
            cout << "Grade deleted and grades.txt updated successfully.\n";
        } else {
            cout << "Grade not found, file updated without changes.\n";
        }
    } else {
        cout << "Error replacing the original file!\n";
        return 1;
    }

    return 0;
}

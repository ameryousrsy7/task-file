#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ofstream outFile("students_names.txt");
    if (!outFile) {
        cout << "Error creating file!\n";
        return 1;
    }

    outFile << "Hadeer Mahmoud\n";
    outFile << "Youssef Ali\n";
    outFile << "Ahmed Mostafa\n";
    outFile << "Esraa Ebrahim\n";
    outFile.close();

    ifstream inFile("students_names.txt");
    if (!inFile) {
        cout << "Error opening file!\n";
        return 1;
    }

    vector<string> names;
    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            names.push_back(line);
        }
    }
    inFile.close();

    sort(names.begin(), names.end());

    cout << "Sorted names (Ascending):\n";
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
    }

    return 0;
}

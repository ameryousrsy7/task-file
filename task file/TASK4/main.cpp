#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "Enter number of persons: ";
    cin >> n;

    ofstream outFile("persons.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < n; i++) {
            Person p;
            cout << "Enter name and age for person " << i + 1 << ": ";
            cin >> p.name >> p.age;
            outFile << p.name << " " << p.age << endl;
        }
        outFile.close();
    }

    vector<Person> people;
    ifstream inFile("persons.txt");
    Person temp;
    while (inFile >> temp.name >> temp.age) {
        people.push_back(temp);
    }
    inFile.close();

    if (!people.empty()) {
        Person youngest = people[0];
        Person oldest = people[0];

        for (int i = 1; i < people.size(); i++) {
            if (people[i].age < youngest.age) {
                youngest = people[i];
            }
            if (people[i].age > oldest.age) {
                oldest = people[i];
            }
        }

        ofstream resFile("results.txt");
        if (resFile.is_open()) {
            resFile << "Youngest: " << youngest.name << " (" << youngest.age << ")" << endl;
            resFile << "Oldest: " << oldest.name << " (" << oldest.age << ")" << endl;
            resFile.close();
            cout << "Results saved to results.txt successfully.\n";
        }
    } else {
        cout << "No data found in file.\n";
    }

    return 0;
}

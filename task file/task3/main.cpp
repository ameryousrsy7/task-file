#include <iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    ofstream outfile("welcome.txt");
    outfile<< "hello everyboody";
    outfile.close();
    fstream file;
    file.open("welcome.txt" ,ios::in|ios::out);
    file.seekp(-5, ios::end);
    file<<"one  ";
    file.close();


    return 0;
}

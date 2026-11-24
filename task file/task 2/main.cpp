#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
  string x,y,z;
  ifstream fruit;
  fruit.open("fruit.txt");
  fruit>>x>>y>>z;
  fruit.close();

  cout<<x<<endl;
  cout<<y<<endl;
  cout<<z<<endl;

  ofstream file;
  file.open("fruit.txt",ios::app|ios::out );
  file<<endl<<"fresh fruit"<<endl;
  file.close();





    return 0;
}

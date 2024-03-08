#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void openfile(string project, string point)
{
   string line;
   int count=0;
   ifstream file(project); // open original file
   string content[sizeof(file)];
   ofstream out;
   out.open("mod.txt", ios_base::app);
   if(file.is_open())
   {
       out << point << endl;
       while(getline(file, line))
       {
           content[count++]=line;
       }
       for(int i=0; i < count-3; i++)
       {
           out << content[i] << endl;
       }
       out << "Z80." << endl;

       out.close();
   }
   file.close();
   
}
void EndString()
{
    ofstream out;
    out.open("mod.txt", ios_base::app);
    out << "Z150." << endl;
    out << "M05" << endl;
    out << "M02" << endl;
    out.close();
} 

int main(int argc, char* argv[])
{
   int pointers;
   cout << "Enter count G-points: ";
   cin >> pointers;
   for(int i=1; i<=pointers; i++)
   {
       string offset;
       cout << "Enter G point: ";
       cin >> offset;
       openfile(argv[1], offset);
   }
   EndString();
   return 0;
}

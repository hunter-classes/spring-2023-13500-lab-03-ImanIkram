
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2){
// opening the file  
std::ifstream fin("Current_Reservoir_Levels.tsv");
if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
}
std::string junk;    // new string variable
getline(fin, junk); // read one line from the file 

double eastSt;
double eastEl;
double westSt;
double westEl;
std::string file_date;

std::string dates[365];
double westel[365];
int count = 0;

while(fin >> file_date >> eastSt >> eastEl >> westSt >> westEl) {  
  fin.ignore(INT_MAX, '\n'); 
if(count==0)
{
    if (date1 == file_date){
        dates[count] = file_date;
        westel[count] = westEl;
        count++;
    }
}
else
{
    dates[count] = file_date;
    westel[count] = westEl;
    count++;
    if (date2 == file_date)
    {
        break;
    }
}
 
}

for(int i = count-1; i >= 0; i--)
{
    std::cout << dates[i] << " "<< westel[i]<< " ft " << std::endl;
}

  fin.close();  
}
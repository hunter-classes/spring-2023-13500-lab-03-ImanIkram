
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include "reservoir.h"

//TASK A

double get_east_storage(std::string date)
{ 
// opening the file  
std::ifstream fin("Current_Reservoir_Levels.tsv");
if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
}
std::string junk;    // new string variable
getline(fin, junk); // read one line from the file 

double eastSt;
double answer;
std::string data_date;
  
while(fin >> data_date >> eastSt) {  
  fin.ignore(INT_MAX, '\n'); 

  if(data_date == date)
  {
    answer = eastSt;
    break;
  }
}

  fin.close();
  return answer;  
}

// TASK B

double get_min_east()
{
  // opening the file  
std::ifstream fin("Current_Reservoir_Levels.tsv");
if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
}
std::string junk;    // new string variable
getline(fin, junk); // read one line from the file 

double eastSt;
double min = 100000; //arbitrary large value 
std::string date;

while(fin >> date >> eastSt) {  
  fin.ignore(INT_MAX, '\n'); 
  
  if (min > eastSt){
    min = eastSt;
  }
}
  
 fin.close();
 return min;
}      

  
double get_max_east()
{
// opening the file  
std::ifstream fin("Current_Reservoir_Levels.tsv");
if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
}
std::string junk;    // new string variable
getline(fin, junk); // read one line from the file 

double eastSt;
double max = 0;
std::string date;

while(fin >> date >> eastSt) {  
  fin.ignore(INT_MAX, '\n'); 
  
  if (max < eastSt){
    max = eastSt;
  }
}

 fin.close();
 return max;
}  

//TASK C

std::string compare_basins(std::string date) 
{
// opening the file  
std::ifstream fin("Current_Reservoir_Levels.tsv");
if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
}
std::string junk;    // new string variable
getline(fin, junk); // read one line from the file 

std::string data_date;
double eastSt;
double westSt;
double eastEl;
double westEl;
std::string answer;
std::string east = "East";
std::string west = "West";
std::string equal = "Equal";
  
while(fin >> data_date >> eastSt >> eastEl >> westSt >> westEl) {  
  fin.ignore(INT_MAX, '\n'); 

  if(data_date == date)
  {
    if(eastEl > westEl){
       answer = east;
    }
    else if(eastEl < westEl){
      answer = west;
    }
    else if (eastEl == westEl){
      answer = equal;
    }
  }
}

  fin.close();
  return answer;
}
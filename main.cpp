// add your code as appropriate 
#include <iostream>
#include <string>
#include "reservoir.h"
#include "reverseorder.h"
int main()
{
  //Task A
  std::string test_date = "05/20/2018";
  double result =  get_east_storage(test_date); 
  std::cout << "East basin storage: " << result << " billion gallons." << std::endl;

  //Task B
  std::cout << "Minimum storage in East basin: " << get_min_east() << " billion gallons." << std::endl;
  std::cout << "Maximin storage in East basin: " << get_max_east() << " billion gallons." << std::endl;
  
  //Task C
  std::string result1 = compare_basins("01/03/2018"); 
  std::string result2 = compare_basins("06/27/2018");
  std::string result3 = compare_basins("09/28/2018");
  std::cout << "01/12/2018" << " " << result1 << std::endl;
  std::cout << "06/17/2018" << " " << result2 << std::endl;
  std::cout << "09/28/2018" << " " << result3 << std::endl; 
  
  //TASK D
  reverse_order("05/29/2018", "06/02/2018");


  return 0;
}
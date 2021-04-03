#include <vector>
#include <iostream>
#include "./../include/LCS.hpp"
int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    std::cout << "Error, 3 arguments expected." << std::endl;
    std::cout << "Usage: ./lcs string1 string2" << std::endl;
    std::cout << "Desc: It will find all the longest common subsequences between" << std::endl; 
    std::cout << "string1 and string2, and then output them through the console." << std::endl;
  }
  else 
  {
    LCS lcs(argv[1], argv[2]);
    std::vector<std::string> LCSs = lcs.getLCSs();
    for (int i = 0; i < LCSs.size(); i++)
    {
      std::cout << LCSs[i] << std::endl;
    }
  }
  return 0;
}
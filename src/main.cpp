#include <vector>
#include <iostream>
#include "./../include/LCS.hpp"
int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    std::cout << "Error, n arguments expected, where n >= 2" << std::endl;
    std::cout << "Usage: ./lcs string1 string2 ... stringN" << std::endl;
    std::cout << "Desc: It will find all the longest common subsequences between" << std::endl;
    std::cout << "every string given, and then output them through the console." << std::endl;
  }
  else
  {
    LCS lcs(argv[1], argv[2]);
    std::unordered_set<std::string> LCSs = lcs.getLCSs();
    int wordsLeft = argc - 3;
    while (wordsLeft > 0)
    {
      std::unordered_set<std::string> preLCSs = LCSs;
      LCSs.clear();
      for (const auto &preLcs : preLCSs)
      {
        lcs.resetFor(preLcs, argv[wordsLeft + 2]);
        std::unordered_set<std::string> tmpToAddLCSs = lcs.getLCSs();
        if (LCSs.empty() || tmpToAddLCSs.empty() || (*LCSs.begin()).size() == (*tmpToAddLCSs.begin()).size())
        {
          LCSs.insert(tmpToAddLCSs.begin(), tmpToAddLCSs.end());
        }
        else if ((*LCSs.begin()).size() < (*tmpToAddLCSs.begin()).size())
        {
          LCSs = tmpToAddLCSs;
        }
      }
      wordsLeft--;
    }
    std::cout << "LCSs size: " << (*LCSs.begin()).size() << std::endl;
    for (const auto &lcs : LCSs)
    {
      std::cout << lcs << std::endl;
    }
  }
  return 0;
}

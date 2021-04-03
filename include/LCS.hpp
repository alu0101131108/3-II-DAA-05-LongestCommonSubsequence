#ifndef __LCS_H__
#define __LCS_H__
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "Table.hpp"

class LCS
{
private:
  Table table_;
  std::string stringA_;
  std::string stringB_;
  std::unordered_set<std::string> LCSs_;
  void buildTables();
  std::unordered_set<std::string> backtrack(int i, int j);

public:
  LCS();
  LCS(std::string stringA, std::string stringB);
  std::unordered_set<std::string> getLCSs();
  void resetFor(std::string stringA, std::string stringB);
  void printTable();
  ~LCS();
};

#endif // __LCS_H__
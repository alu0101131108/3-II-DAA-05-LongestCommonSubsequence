#include "./../include/LCS.hpp"
LCS::LCS() 
{}

LCS::LCS(std::string stringA, std::string stringB) :
stringA_(stringA), stringB_(stringB)
{
  table_ = Table(stringA_.size() + 1, stringB_.size() + 1);
  buildTables();
  LCSs_ = backtrack(stringA_.size(), stringB.size());
}

void LCS::buildTables() 
{
  for (int i = 1; i <= stringA_.size(); i++)
  {
    for (int j = 1; j <= stringB_.size(); j++)
    {
      if (stringA_[i - 1] == stringB_[j - 1])
      {
        int lastLcsSize = table_.get(i - 1, j - 1);
        table_.set(i, j, lastLcsSize + 1);
      }
      else
      {
        table_.set(i, j, std::max(table_.get(i, j - 1), table_.get(i - 1, j)));
      }
    }
  }
}

std::unordered_set<std::string> LCS::backtrack(int i, int j)
{
  std::unordered_set<std::string> LCSs;
  if (i == 0 || j == 0)
  {
    LCSs.insert("");
  }
  else if (stringA_[i - 1] == stringB_[j - 1])
  {
    std::unordered_set<std::string> subLCSs = backtrack(i - 1, j - 1);
    for (const auto &subLCS : subLCSs)
    {
      LCSs.insert(subLCS + stringA_[i - 1]);
    }
  }
  else
  {
    if (table_.get(i, j - 1) >= table_.get(i - 1, j))
    {
      std::unordered_set<std::string> subLCSsA = backtrack(i, j - 1);
      LCSs.insert(subLCSsA.begin(), subLCSsA.end());
    }
    if (table_.get(i - 1, j) >= table_.get(i, j - 1))
    {
      std::unordered_set<std::string> subLCSsB = backtrack(i - 1, j);
      LCSs.insert(subLCSsB.begin(), subLCSsB.end());
    }
  }
  return LCSs; 
}

std::unordered_set<std::string> LCS::getLCSs()
{
  return LCSs_;
}

void LCS::resetFor(std::string stringA, std::string stringB) 
{
  stringA_ = stringA;
  stringB_ = stringB;
  table_ = Table(stringA_.size() + 1, stringB_.size() + 1);
  buildTables();
  LCSs_ = backtrack(stringA_.size(), stringB.size());
}

void LCS::printTable() 
{
  table_.print();
}

LCS::~LCS() 
{}

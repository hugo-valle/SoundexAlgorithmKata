#include "Portfolio.h"
using namespace boost::gregorian;
using namespace std;

bool Portfolio::IsEmpty() const
{
   return 0 == holdings_.size(); 
}

void Portfolio::Purchase(const string& symbol, unsigned int shareCount, const date& transactionDate)
{
   if (0 == shareCount)
      throw ShareCountCannotBeZeroException();
   holdings_[symbol] = shareCount + ShareCount(symbol);
   purchases_.push_back(PurchaseRecord(shareCount, transactionDate));
}

void Portfolio::Sell(const std::string& symbol, unsigned int shareCount, const date& transactionDate)
{
   if (shareCount > ShareCount(symbol))
      throw InvalidSellException();
   if(0 == shareCount)
      throw ShareCountCannotBeZeroException();
   holdings_[symbol] = ShareCount(symbol) - shareCount;
   purchases_.push_back(PurchaseRecord(-shareCount, transactionDate));
}

unsigned int Portfolio::ShareCount(const string& symbol) const
{
   auto it = holdings_.find(symbol);
   if (it == holdings_.end()) return 0;
   return it->second;
}

std::vector<PurchaseRecord> Portfolio::Purchases(const std::string &symbol) const
{
   return purchases_;
}

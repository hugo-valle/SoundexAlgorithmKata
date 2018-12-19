#include "Portfolio.h"
using namespace boost::gregorian;
using namespace std;

bool Portfolio::IsEmpty() const
{
   return 0 == holdings_.size(); 
}

void Portfolio::Purchase(const string& symbol, unsigned int shareCount, const date& transactionDate)
{
    Transact(symbol, shareCount, transactionDate);
}

void Portfolio::Sell(const std::string& symbol, unsigned int shareCount, const date& transactionDate)
{
   if (shareCount > ShareCount(symbol))
      throw InvalidSellException();
   Transact(symbol, -shareCount, transactionDate);
}

void Portfolio::Transact(const std::string &symbol, int shareCharge,
                         const boost::gregorian::date &transactionDate)
{
   if(0 == shareCharge)
      throw ShareCountCannotBeZeroException();
   holdings_[symbol] = ShareCount(symbol) + shareCharge;
   purchases_.push_back(PurchaseRecord(shareCharge, transactionDate));

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


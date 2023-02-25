#include <cassert>
#include <iterator>
#include <map>
#include <set>
#include <vector>

class StockPrice {
public:
  StockPrice() {}

  void update(int timestamp, int price) {
    auto iter = timestamp_.find(timestamp);
    if (iter == timestamp_.end()) {
      timestamp_.emplace(timestamp, price);
      price_[price]++;
      return;
    }

    auto oldPrice = iter->second;
    if (oldPrice == price) {
      return;
    }

    price_[price]++;
    iter->second = price;
    auto priceIter = price_.find(oldPrice);
    if (priceIter->second == 1) {
      price_.erase(priceIter);
    } else {
      priceIter->second--;
    }
  }

  int current() { return timestamp_.rbegin()->second; }

  int maximum() { return price_.rbegin()->first; }

  int minimum() { return price_.begin()->first; }

private:
  std::map<int, int> timestamp_;
  std::map<int, int> price_;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
int main(int argc, char *argv[]) {
  StockPrice obj;
  obj.update(1, 10);
  obj.update(2, 5);
  assert(obj.current() == 5);
  assert(obj.maximum() == 10);
  obj.update(1, 3);
  assert(obj.maximum() == 5);
  obj.update(4, 2);
  assert(obj.minimum() == 2);
  return 0;
}

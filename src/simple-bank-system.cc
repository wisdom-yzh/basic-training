#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Bank {
public:
  Bank(const vector<long long> &balance) : balance_{balance} {}

  bool transfer(int account1, int account2, long long money) {
    if (account1 <= 0 || account1 >= balance_.size() + 1 || account2 <= 0 ||
        account2 >= balance_.size() + 1) {
      return false;
    }
    return withdraw(account1, money) && deposit(account2, money);
  }

  bool deposit(int account, long long money) {
    if (account <= 0 || account >= balance_.size() + 1) {
      return false;
    }
    balance_[account - 1] += money;
    return true;
  }

  bool withdraw(int account, long long money) {
    if (account <= 0 || account >= balance_.size() + 1 ||
        balance_[account - 1] < money) {
      return false;
    }
    balance_[account - 1] -= money;
    return true;
  }

private:
  vector<long long> balance_;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
int main(int argc, char *argv[]) {
  Bank bank({10, 100, 20, 50, 30});
  // 返回 true ，账户 3 的余额是 $20 ，所以可以取款
  // $10 。 账户 3 余额为 $20 - $10 = $10 。
  assert(bank.withdraw(3, 10));
  // 返回 true ，账户 5 的余额是 $30 ，所以可以转账
  // $20 。 账户 5 的余额为 $30 - $20 = $10 ，账户 1
  // 的余额为 $10 + $20 = $30 。
  assert(bank.transfer(5, 1, 20));
  // 返回 true ，可以向账户 5 存款 $20 。
  // 账户 5 的余额为 $10 + $20 = $30 。
  assert(bank.deposit(5, 20));
  // 返回 false ，账户 3 的当前余额是 $10 。
  // 所以无法转账 $15 。
  assert(!bank.transfer(3, 4, 15));
  // 返回 false ，交易无效，因为账户 10 并不存在。
  assert(!bank.withdraw(10, 50));
  return 0;
}

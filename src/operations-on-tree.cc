#include <ios>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class LockingTree {
public:
  LockingTree(vector<int> &parent) {
    tree_ = vector<Node>(parent.size());
    for (int i = 0; i < parent.size(); i++) {
      if (parent[i] != -1) {
        tree_[parent[i]].children.push_back(i);
        tree_[i].parent = parent[i];
      }
    }
  }

  bool lock(int num, int user) {
    if (tree_[num].lockedUser == -1) {
      tree_[num].lockedUser = user;
      return true;
    }
    return false;
  }

  bool unlock(int num, int user) {
    if (tree_[num].lockedUser == user) {
      tree_[num].lockedUser = -1;
      return true;
    }
    return false;
  }

  bool upgrade(int num, int user) {
    auto &t = tree_[num];
    auto lockedChildren = getLockedChildren(num);
    if (hasLockedAncestor(num) || lockedChildren.empty()) {
      return false;
    }

    for (auto &x : lockedChildren) {
      tree_[x].lockedUser = -1;
    }
    tree_[num].lockedUser = user;
    return true;
  }

private:
  struct Node {
    int lockedUser;
    int parent;
    vector<int> children;
    Node() : lockedUser(-1), parent(-1){};
  };

  vector<int> getLockedChildren(int t) {
    vector<int> children;
    queue<int> q;
    q.push(t);

    while (!q.empty()) {
      int top = q.front();
      if (tree_[top].lockedUser != -1) {
        children.push_back(top);
      }
      for (auto &c : tree_[top].children) {
        q.push(c);
      }
      q.pop();
    }

    return children;
  }

  bool hasLockedAncestor(int t) {
    if (t == -1) {
      return false;
    }
    if (tree_[t].lockedUser != -1) {
      return true;
    }

    return hasLockedAncestor(tree_[t].parent);
  }

  vector<Node> tree_;
};

int main(int argc, char *argv[]) {
  vector<int> parent{-1, 0, 0, 1, 1, 2, 2};
  LockingTree lockingTree(parent);

  cout << boolalpha << lockingTree.lock(2, 2)
       << endl; // 返回 true ，因为节点 2 未上锁。
                // 节点 2 被用户 2 上锁。

  cout << boolalpha << lockingTree.unlock(2, 3)
       << endl; // 返回 false ，因为用户 3 无法解锁被用户 2 上锁的节点。

  cout << boolalpha << lockingTree.unlock(2, 2)
       << endl; // 返回 true ，因为节点 2 之前被用户 2 上锁。
                // 节点 2 现在变为未上锁状态。
  cout << boolalpha << lockingTree.lock(4, 5)
       << endl; // 返回 true ，因为节点 4 未上锁。
                // 节点 4 被用户 5 上锁。

  cout << boolalpha << lockingTree.upgrade(0, 1)
       << endl; // 返回 true ，因为节点 0
                // 未上锁且至少有一个被上锁的子孙节点（节点 4）。 节点 0 被用户
                // 1 上锁，节点 4 变为未上锁。

  cout << boolalpha << lockingTree.lock(0, 1)
       << endl; // 返回 false ，因为节点 0 已经被上锁了。

  return 0;
}

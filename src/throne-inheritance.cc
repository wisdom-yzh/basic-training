#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <map>
using namespace std;

class ThroneInheritance {
public:
    struct TreeNode {
        TreeNode(string &name): name(name), dead(false) {}
        vector<shared_ptr<TreeNode>> children;
        string name;
        bool dead;
    };

private:
    shared_ptr<TreeNode> king;
    map<string, shared_ptr<TreeNode>> dict;

public:
    ThroneInheritance(string kingName) {
        king = make_shared<TreeNode>(kingName);
        dict[kingName] = king;
    }

    void birth(string parentName, string childName) {
        auto child = make_shared<TreeNode>(childName);
        dict[parentName]->children.push_back(child);
        dict[childName] = child;
    }

    void death(string name) {
        dict[name]->dead = true;
    }

    void preorder(shared_ptr<TreeNode> &root, vector<string> &res) {
        if (!root->dead) {
            res.push_back(root->name);
        }
        for (auto &child: root->children) {
            preorder(child, res);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string> res;
        preorder(this->king, res);
        return res;
    }
};

int main() {
    std::unique_ptr<ThroneInheritance> obj(new ThroneInheritance("king"));
    obj->birth("king", "andy");
    obj->birth("king", "bob");
    obj->birth("king", "catherine");
    obj->birth("andy", "matthew");
    obj->birth("bob", "alex");
    obj->birth("bob", "asha");
    for (auto &o: obj->getInheritanceOrder()) {
        cout << o << endl;
    }
    obj->death("bob");
    for (auto &o: obj->getInheritanceOrder()) {
        cout << o << endl;
    }
    return 0;
}

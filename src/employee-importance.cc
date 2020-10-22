#include <vector>
#include <map>
using namespace std;

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int result = 0;
        for (const auto &employee: employees) {
            if (id != employee->id) {
                continue;
            }
            result = employee->importance;
            for (const auto &sub: employee->subordinates) {
                result += getImportance(employees, sub);
            }
        }
        return result;
    }
};

int main() {
    return 0;
}

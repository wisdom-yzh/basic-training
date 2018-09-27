// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned long long p = 0, q = n;
        while (p <= q) {
            unsigned long long mid = (p + q) / 2;
            if (isBadVersion(mid)) {
                if (mid == 1 || !isBadVersion(mid - 1)) {
                    return mid;
                }
                q = mid - 1;
            } else {
                p = mid + 1;
            }
        }
    }
};

int main() {
    return 0;
}

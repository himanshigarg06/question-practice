
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                s.insert(nums[i]);
            }
        }

        int i = 1;

        while (s.find(i) != s.end()) {
            i++;
        }

        return i;
    }
};

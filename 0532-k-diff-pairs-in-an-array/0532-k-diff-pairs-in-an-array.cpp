class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        unordered_set<int> seen;
        unordered_set<int> pairs;

        for (int num : nums) {
            if (seen.count(num - k)) {
                pairs.insert(num - k);
            }

            if (seen.count(num + k)) {
                pairs.insert(num);
            }

            seen.insert(num);
        }

        return pairs.size();
    }
};
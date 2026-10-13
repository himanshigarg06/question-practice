
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {
        vector<int> ans;

        for (int num : nums1) {
            int i = 0;

            while (i < nums2.size() && nums2[i] != num) {
                i++;
            }

            int greater = -1;

            for (int j = i + 1; j < nums2.size(); j++) {
                if (nums2[j] > num) {
                    greater = nums2[j];
                    break;
                }
            }

            ans.push_back(greater);
        }

        return ans;
    }
};

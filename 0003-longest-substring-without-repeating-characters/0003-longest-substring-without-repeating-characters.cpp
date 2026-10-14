class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            freq[(unsigned char)s[right]]++;

            while (freq[(unsigned char)s[right]] > 1) {
                freq[(unsigned char)s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
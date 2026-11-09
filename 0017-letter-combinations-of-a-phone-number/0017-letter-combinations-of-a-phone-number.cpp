
class Solution {
public:
    vector<string> ans;

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string temp;

        solve(digits, 0, temp, mp);

        return ans;
    }

    void solve(string digits, int index, string &temp,
               vector<string> &mp) {
        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (int i = 0; i < letters.size(); i++) {
            temp.push_back(letters[i]);

            solve(digits, index+1, temp, mp);

            temp.pop_back();
        }
    }
};

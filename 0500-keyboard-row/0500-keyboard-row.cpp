
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> ans;

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int row = 0;
            bool flag = true;

            for (int j = 0; j < word.size(); j++) {
                char ch = tolower(word[j]);

                if (row1.find(ch) != string::npos) {
                    if (row == 0) row = 1;
                    else if (row != 1) flag = false;
                }
                else if (row2.find(ch) != string::npos) {
                    if (row == 0) row = 2;
                    else if (row != 2) flag = false;
                }
                else {
                    if (row == 0) row = 3;
                    else if (row != 3) flag = false;
                }
            }

            if (flag) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};

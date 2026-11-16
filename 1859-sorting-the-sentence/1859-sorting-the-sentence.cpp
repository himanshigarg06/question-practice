class Solution {
public:
    string sortSentence(string s) {

        vector<string> arr(10);

        string word = "";

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                int pos = word[word.length() - 1] - '0';
                word.pop_back();

                arr[pos] = word;
                word = "";
            }
            else {
                word += s[i];
            }
        }

        int pos = word[word.length() - 1] - '0';
        word.pop_back();

        arr[pos] = word;

        string ans = "";

        for(int i = 1; i < 10; i++) {
            if(arr[i] != "") {
                ans += arr[i] + " ";
            }
        }

        ans.pop_back();

        return ans;
    }
};
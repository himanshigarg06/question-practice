
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        char a = 'a', b = 'b';

        if (x < y) {
            swap(x, y);
            a = 'b';
            b = 'a';
        }

        string remaining;

        for (char c : s) {
            if (!remaining.empty() &&
                remaining.back() == a && c == b) {
                remaining.pop_back();
                score += x;
            } else {
                remaining.push_back(c);
            }
        }

        string finalString;

        for (char c : remaining) {
            if (!finalString.empty() &&
                finalString.back() == b && c == a) {
                finalString.pop_back();
                score += y;
            } else {
                finalString.push_back(c);
            }
        }

        return score;
    }
};

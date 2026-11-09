
class Solution {
    public String[] findWords(String[] words) {
        String row1 = "qwertyuiop";
        String row2 = "asdfghjkl";
        String row3 = "zxcvbnm";

        ArrayList<String> ans = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            String word = words[i].toLowerCase();

            int row = 0;
            boolean flag = true;

            for (int j = 0; j < word.length(); j++) {
                char ch = word.charAt(j);

                if (row1.indexOf(ch) != -1) {
                    if (row == 0)
                        row = 1;
                    else if (row != 1)
                        flag = false;
                }
                else if (row2.indexOf(ch) != -1) {
                    if (row == 0)
                        row = 2;
                    else if (row != 2)
                        flag = false;
                }
                else {
                    if (row == 0)
                        row = 3;
                    else if (row != 3)
                        flag = false;
                }
            }

            if (flag) {
                ans.add(words[i]);
            }
        }

        return ans.toArray(new String[0]);
    }
}

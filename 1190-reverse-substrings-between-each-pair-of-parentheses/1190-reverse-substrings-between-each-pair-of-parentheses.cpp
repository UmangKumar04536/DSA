class Solution {
public:
    string reverseParentheses(string s) {
        string st;

        for (char c : s) {

            if (c == ')') {
                string temp;

                while (st.back() != '(') {
                    temp += st.back();
                    st.pop_back();
                }

                // Remove '('
                st.pop_back();

                // temp is already reversed
                st += temp;
            }
            else {
                st += c;
            }
        }

        return st;
    }
};
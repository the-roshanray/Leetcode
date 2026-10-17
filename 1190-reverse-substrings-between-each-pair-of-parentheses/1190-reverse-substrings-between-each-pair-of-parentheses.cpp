class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                int j = stk.top();
                stk.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        string result;
        int direction = 1;

        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                direction = -direction;
            } else {
                result += s[i];
            }
        }

        return result;
    }
};
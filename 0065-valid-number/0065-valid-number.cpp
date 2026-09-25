class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false;
        bool dotSeen = false;
        bool exponentSeen = false;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]))
                digitSeen = true;

            else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }

            else if (s[i] == '.') {
                if (dotSeen || exponentSeen)
                    return false;

                dotSeen = true;
            }

            else if (s[i] == 'e' || s[i] == 'E') {
                if (exponentSeen || !digitSeen)
                    return false;

                exponentSeen = true;
                digitSeen = false;
            } else
                return false;
        }
        return digitSeen;
    }
};
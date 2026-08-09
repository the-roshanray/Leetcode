class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        // Extract words (automatically handles multiple spaces)
        while (ss >> word) {
            words.push_back(word);
        }

        // Build result in reverse order
        string result = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];
            if (i > 0)
                result += " ";
        }

        return result;
    }
};
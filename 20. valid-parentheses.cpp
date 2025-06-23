class Solution {
public:
    bool isValid(string s) {
        bool ret = true;
        vector<char> queue;
        for (char c:s) {
            if (c == '[' || c == '{' || c == '(') 
                queue.push_back(c);
            else {
                if (queue.size() == 0) {
                    ret = false;
                    break;
                }
                char top = queue.back();
                queue.pop_back();
                if ((c == ']' && top == '[') || (c == '}' && top == '{') || (c == ')' && top == '('))
                    continue;
                else {
                    ret = false;
                    break;
                }
            }
        }
        if (queue.size() != 0)
            ret = false;
        return ret;
    }
};
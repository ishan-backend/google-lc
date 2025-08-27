class TextEditor {
    deque<char> left;
    deque<char> right;
public:
    TextEditor() {}
    
    void addText(string text) {
        left.insert(left.end(), text.begin(), text.end());
    }
    
    int deleteText(int k) {
        int cnt = 0;
        while (!left.empty() && k--) {
            left.pop_back();
            cnt++;
        }
        return cnt;
    }
    
    string cursorLeft(int k) {
        while (!left.empty() && k--) {
            right.push_front(left.back());  // ✅ FIXED
            left.pop_back();
        }
        return cursorShiftString();
    }
    
    string cursorRight(int k) {
        while (!right.empty() && k--) {
            left.push_back(right.front());   // ✅ FIXED
            right.pop_front();
        }
        return cursorShiftString();
    }
    
    string cursorShiftString() {
        if (left.size() < 10) 
            return string(left.begin(), left.end());
        return string(left.end() - 10, left.end());
    }
};
#include <iostream>
#include <string>
using namespace std;

class TextEditor {
private:
    struct Node {
        char ch;
        Node* prev;
        Node* next;
        
        Node(char c = '\0') : ch(c), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;     // Dummy head node
    Node* tail;     // Dummy tail node
    Node* cursor;   // Points to the node after which text will be inserted
    
    // Helper function to get up to 10 characters to the left of cursor
    string getLeftText() {
        string result = "";
        Node* current = cursor;
        
        // Collect up to 10 characters going backwards from cursor
        while (current != head && result.length() < 10) {
            result = current->ch + result;  // Prepend to maintain order
            current = current->prev;
        }
        
        return result;
    }
    
public:
    TextEditor() {
        // Create dummy head and tail nodes
        head = new Node();
        tail = new Node();
        
        // Connect head and tail
        head->next = tail;
        tail->prev = head;
        
        // Initially cursor is at head (before any text)
        cursor = head;
    }
    
    ~TextEditor() {
        // Clean up all nodes
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    void addText(string text) {
        /*
         * Adds text to the left of cursor.
         * Time: O(len(text)), Space: O(len(text))
         */
        for (char ch : text) {
            // Create new node
            Node* newNode = new Node(ch);
            
            // Insert after cursor
            Node* nextNode = cursor->next;
            cursor->next = newNode;
            newNode->prev = cursor;
            newNode->next = nextNode;
            nextNode->prev = newNode;
            
            // Move cursor to the newly inserted node
            cursor = newNode;
        }
    }
    
    int deleteText(int k) {
        /*
         * Deletes k characters to the left of cursor.
         * Returns the number of characters actually deleted.
         * Time: O(k), Space: O(1)
         */
        int deleted = 0;
        
        // Delete characters while cursor is not at head and we haven't deleted k chars
        while (cursor != head && deleted < k) {
            // Get the node to delete (current cursor position)
            Node* toDelete = cursor;
            
            // Move cursor back
            cursor = cursor->prev;
            
            // Remove the node from the list
            Node* prevNode = toDelete->prev;
            Node* nextNode = toDelete->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            
            // Free memory
            delete toDelete;
            deleted++;
        }
        
        return deleted;
    }
    
    string cursorLeft(int k) {
        /*
         * Moves cursor k steps to the left.
         * Returns the last min(10, len(text_left_of_cursor)) characters to the left of cursor.
         * Time: O(k + 10), Space: O(10)
         */
        // Move cursor left k steps
        int moved = 0;
        while (cursor != head && moved < k) {
            cursor = cursor->prev;
            moved++;
        }
        
        // Get up to 10 characters to the left of cursor
        return getLeftText();
    }
    
    string cursorRight(int k) {
        /*
         * Moves cursor k steps to the right.
         * Returns the last min(10, len(text_left_of_cursor)) characters to the left of cursor.
         * Time: O(k + 10), Space: O(10)
         */
        // Move cursor right k steps
        int moved = 0;
        while (cursor->next != tail && moved < k) {
            cursor = cursor->next;
            moved++;
        }
        
        // Get up to 10 characters to the left of cursor
        return getLeftText();
    }
    
    // Debug function to print current state
    void printState() {
        cout << "Text: ";
        Node* current = head->next;
        while (current != tail) {
            cout << current->ch;
            if (current == cursor) cout << "|";  // Mark cursor position
            current = current->next;
        }
        if (cursor == head) cout << "|";  // Cursor at beginning
        cout << endl;
    }
};

// // Test function
// void testTextEditor() {
//     TextEditor editor;
    
//     cout << "=== Test Case 1 ===" << endl;
    
//     editor.addText("leetcode");
//     cout << "After addText('leetcode'):" << endl;
//     editor.printState();
    
//     int result = editor.deleteText(4);
//     cout << "deleteText(4) returned: " << result << endl;
//     editor.printState();
    
//     editor.addText("practice");
//     cout << "After addText('practice'):" << endl;
//     editor.printState();
    
//     string str_result = editor.cursorRight(3);
//     cout << "cursorRight(3) returned: '" << str_result << "'" << endl;
//     editor.printState();
    
//     str_result = editor.cursorLeft(8);
//     cout << "cursorLeft(8) returned: '" << str_result << "'" << endl;
//     editor.printState();
    
//     result = editor.deleteText(10);
//     cout << "deleteText(10) returned: " << result << endl;
//     editor.printState();
    
//     str_result = editor.cursorLeft(2);
//     cout << "cursorLeft(2) returned: '" << str_result << "'" << endl;
//     editor.printState();
    
//     str_result = editor.cursorRight(6);
//     cout << "cursorRight(6) returned: '" << str_result << "'" << endl;
//     editor.printState();
    
//     cout << "\n=== Additional Test Case ===" << endl;
//     TextEditor editor2;
    
//     editor2.addText("hello");
//     cout << "Added 'hello'" << endl;
//     editor2.printState();
    
//     str_result = editor2.cursorLeft(2);
//     cout << "cursorLeft(2): '" << str_result << "'" << endl;
//     editor2.printState();
    
//     editor2.addText("world");
//     cout << "Added 'world' at cursor position" << endl;
//     editor2.printState();
    
//     str_result = editor2.cursorRight(10);
//     cout << "cursorRight(10): '" << str_result << "'" << endl;
//     editor2.printState();
// }

// int main() {
//     testTextEditor();
//     return 0;
// }
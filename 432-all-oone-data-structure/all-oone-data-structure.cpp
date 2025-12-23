// “We maintain a doubly linked list of frequency buckets and move keys between adjacent buckets in O(1) using hash maps.”
class AllOne {
private:
    struct Node {
        int freq;
        unordered_set<string> keys;
        Node *prev, *next;

        Node(int f) : freq(f), prev(nullptr), next(nullptr) {}
    };

    Node *head, *tail;
    unordered_map<string, Node*> keyNode;

    // Insert newNode after prevNode
    void insertAfter(Node* prevNode, Node* newNode) {
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
    }

    // Remove a node from DLL
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

public:
    AllOne() {
        head = new Node(0);  // dummy head
        tail = new Node(0);  // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (!keyNode.count(key)) {
            // new key → freq = 1
            if (head->next == tail || head->next->freq != 1) {
                Node* node = new Node(1);
                insertAfter(head, node);
            }
            head->next->keys.insert(key);
            keyNode[key] = head->next;
        } else {
            Node* curr = keyNode[key];
            int newFreq = curr->freq + 1;

            if (curr->next == tail || curr->next->freq != newFreq) {
                Node* node = new Node(newFreq);
                insertAfter(curr, node);
            }

            curr->next->keys.insert(key);
            keyNode[key] = curr->next;

            curr->keys.erase(key);
            if (curr->keys.empty()) removeNode(curr);
        }
    }

    void dec(string key) {
        if (!keyNode.count(key)) return;

        Node* curr = keyNode[key];
        int freq = curr->freq;

        if (freq == 1) {
            keyNode.erase(key);
        } else {
            int newFreq = freq - 1;
            if (curr->prev == head || curr->prev->freq != newFreq) {
                Node* node = new Node(newFreq);
                insertAfter(curr->prev, node);
            }
            curr->prev->keys.insert(key);
            keyNode[key] = curr->prev;
        }

        curr->keys.erase(key);
        if (curr->keys.empty()) removeNode(curr);
    }

    string getMaxKey() {
        if (tail->prev == head) return "";
        return *tail->prev->keys.begin();
    }

    string getMinKey() {
        if (head->next == tail) return "";
        return *head->next->keys.begin();
    }
};
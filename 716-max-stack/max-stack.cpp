class MaxStack {
private:
    int id;
    stack<pair<int, int>> stk;
    // to support peek max and delete it
    priority_queue<pair<int, int>> pq; // maxheap with id and item
    unordered_set<int> deleted; // ids of deleted items from maxheap

public:
    MaxStack() {
        id = 0;
    }
    
    void push(int x) { // logN
        stk.push({x, id}); // O(1)
        pq.push({x, id}); // O(logN)
        id++;
    }
    
    int pop() {
        // lazy update: first remove the last element in stack and add its id to deleted set O(1), and it results in deletion of top element in pq in future O(logN)
        // deleted contains ids from popMax
        while(deleted.count(stk.top().second)) {
            stk.pop();
        }

        // add p.second to deleted for lazy update for maxStack operations
        pair<int, int> p = stk.top();
        stk.pop();
        deleted.insert(p.second);
        return p.first;
    }
    
    int top() {
        // deleted contains ids from popMax
        while(deleted.count(stk.top().second)) {
            stk.pop();
        }

        return stk.top().first;
    }
    
    int peekMax() {
        // deleted contains ids from pop
        while(deleted.count(pq.top().second)) {
            pq.pop();
        }

        return pq.top().first;
    }
    
    int popMax() {
        // lazy update: O(logN) immediately, and O(1) in future ops.
        // lazy update can never happen in some cases

        // deleted contains ids from pop
        while(deleted.count(pq.top().second)) {
            pq.pop();
        }

        pair<int, int> p = pq.top();
        pq.pop();
        deleted.insert(p.second);
        return p.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
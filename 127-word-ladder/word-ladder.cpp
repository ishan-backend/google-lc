class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 2 end BFS search solution
        unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail, *pHead, *pTail;
        if(dict.find(endWord) == dict.end()) {
            return 0;
        }

        head.insert(beginWord);
        tail.insert(endWord);
        int ans = 2;
        while(!head.empty() && !tail.empty()) {
            // pHead will point to smaller set whose chance it is to do BFS
            if(head.size() < tail.size()) {
                pHead = &head;
                pTail = &tail;
            } else {
                pHead = &tail;
                pTail = &head;
            }

            unordered_set<string> temp;
            for(auto it = pHead->begin(); it != pHead->end(); it++) {
                string word = *it;
                // take out every word in head, and for each char, try changing it and finding it in pTail or tail set
                for(int i=0; i<word.size(); i++) {
                    char t = word[i];
                    // try changing this char
                    for(int j=0; j<26; j++) {
                        word[i] = 'a'+j;

                        // if word is found in pTail, we have found shortest path
                        if(pTail->find(word) != pTail->end()) {
                            return ans;
                        } else {
                            // when word is not found in pTail and is in dictionary
                            if(dict.find(word) != dict.end()) {
                                // add it to head set, because dict are only allowed
                                temp.insert(word);
                                dict.erase(word);
                            }
                        }
                    }
                    // reverse t
                    word[i] = t;
                }
            }

            // BFS done for one more level either head/tail
            ans++;
            pHead -> swap(temp);
        }

        return 0;
    }
};
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        int n = p.size(), m = t.size();
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());

        int match=0;
        for (int i=0, j=0; i<n && j<m; i++){
            j=lower_bound(t.begin()+j, t.end(), p[i])-t.begin();
            if (j<m) {
                j++;
                match++;
            }
        } 
        return match;
    }
};
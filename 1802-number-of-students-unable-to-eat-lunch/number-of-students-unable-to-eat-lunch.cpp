class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int cnt1=0, cnt0=0;
        for(int i=0; i<n; i++) {
            if(students[i] == 0)
                cnt0++;
            else
                cnt1++;
        }

        int j=0;
        while(j < sandwiches.size()) {
            if(sandwiches[j] == 1) {
                if(cnt1 > 0) cnt1--;
                else return sandwiches.size()-(j);
            } else {
                if(cnt0 > 0) cnt0--;
                else return sandwiches.size()-(j);
            }
            j++;
        }

        return  sandwiches.size()-j;
    }
};
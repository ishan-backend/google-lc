class Solution {
    private:
        int DFS(vector<NestedInteger>& nestedList, int depth){
            int n = (int)nestedList.size();
            int sum = 0;
            for(int i=0;i<n;i++){
                if(nestedList[i].isInteger()){
                    sum += nestedList[i].getInteger()*depth;
                }
                else{
                    sum += DFS(nestedList[i].getList(),depth+1);
                }
            }
            return sum;
        }
    public:
        int depthSum(vector<NestedInteger>& nestedList) {
            return DFS(nestedList, 1);
        }
};
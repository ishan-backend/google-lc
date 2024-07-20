class Solution {
public:
    string losingPlayer(int x, int y) {
        int moves=0;
        while(true){
            if(x>0 and y>=4){
                x=x-1;
                y=y-4;
                moves++;
            }
            else break;
        }        
        if(moves%2==0) return "Bob";
        return "Alice";
    }
};
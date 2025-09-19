class Spreadsheet {
public:
    unordered_map<string, int> mp;

    Spreadsheet(int rows) {
        mp.clear();
    }
    
    void setCell(string cell, int value) {
        mp[cell] = value;
    }
    
    void resetCell(string cell) {
        mp[cell] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1); // remove =
        // formula can be A1234 + G6789 or 6 + 8 or A1234 + 8
        for(int i=0; i<formula.size(); i++) {
            if(formula[i] == '+') {
                string bef = formula.substr(0, i), aft = formula.substr(i+1);
                int left = bef[0] >= 'A' and bef[0] <= 'Z' ? mp[bef] : stoi(bef);
                int right = aft[0] >= 'A' and aft[0] <= 'Z' ? mp[aft] : stoi(aft);
                return left + right;
            }
        }
        return 0;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
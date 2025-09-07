class ProductOfNumbers {
public:
    vector<int> prefixProd = {1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num > 0) {
            prefixProd.push_back(prefixProd.back()*num);
        } else {
            prefixProd = {1}; // for subsequent product calculations
        }
    }
    
    int getProduct(int k) {
        return k < prefixProd.size() ? prefixProd.back()/prefixProd[prefixProd.size()-1-k] : 0; // as some integer would be 0, for which 1 add hua hoga bs
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
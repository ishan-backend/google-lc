class FoodRatings {
public:


    unordered_map<string, int> f2r;               // food → rating
    unordered_map<string, string> f2c;            // food → cuisine

    // custom comparator: higher rating first, if tie → smaller name first
    struct cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first != b.first) return a.first > b.first; // higher rating first
            return a.second < b.second; // lexicographically smaller first
        }
    };

    unordered_map<string, multiset<pair<int,string>, cmp>> cuisineMap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            f2r[foods[i]] = ratings[i];
            f2c[foods[i]] = cuisines[i];
            cuisineMap[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = f2c[food];
        int oldRating = f2r[food];

        // erase old entry
        cuisineMap[cuisine].erase({oldRating, food});

        // insert new entry
        cuisineMap[cuisine].insert({newRating, food});
        f2r[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second; // first element is best
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
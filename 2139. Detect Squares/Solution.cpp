class DetectSquares {
public:
map<int,multiset<int>> mpx,mpy;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x=point[0];
        int y=point[1];
        mpx[x].insert(y);
        mpy[y].insert(x);

    }
    
    int count(vector<int> point) {
        int cal=0;
        int x=point[0];
        int y=point[1];
        for(auto i:mpx[x]){
             if (i == y) continue;
                    int d=abs(y-i);
                    int count1 = mpy[y].count(x + d) * mpy[i].count(x + d);
                     int count2 = mpy[y].count(x - d) * mpy[i].count(x - d);
                    cal += count1 + count2;
        }
        return cal;
        
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
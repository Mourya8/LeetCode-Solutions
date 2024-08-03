class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size()!=arr.size()) return 0;
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        if(target==arr) return 1;
        return 0;
    }
};
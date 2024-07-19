class Solution {
public:

    int bs(const vector<int>& potions, long long s, long long success) {
    int left = 0;
    int right = potions.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (s * (long long)potions[mid] >= success) {
            // Check if it's the first valid element
            if (mid == 0 || s * (long long)potions[mid - 1] < success) {
                return mid;
            }
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return potions.size();
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++)
        {
            int j= bs(potions,(long)spells[i],success);
            spells[i]=(potions.size()-j);
        }
        return spells;
    }
};
class Solution {
public:
    // int bs(vector<int> potions,long long s, long long success)
    // {
    //     int left = 0;
    //     int right =potions.size()-1;
    //     int mid = left+(right-left)/2;
    //     cout <<potions[mid]<<endl;
    //     while(left<right)
    //     {
    //         if((s*(long)potions[mid])>=success && (s*(long)potions[mid-1]<success)) 
    //         {
    //             cout<<mid <<" mid"<<endl;
    //             return mid;
    //         }
    //         if(s*(long)potions[mid]>=success) right= mid;
    //         else left= mid;
    //         mid = left+(right-left)/2;
    //         if(mid==0 || mid == potions.size()-1) 
    //         {
    //             cout<<mid <<" mid "<<endl;
    //             return mid;
    //         }
    //         cout <<potions[mid]<<endl;
    //     }
    //     return mid;
    // }

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
    
    // If no valid element found, return an index out of bounds to indicate failure
    return potions.size();
}

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> r;
        for(int i=0;i<spells.size();i++)
        {
            int j= bs(potions,(long)spells[i],success);
            r.push_back(potions.size()-j);
        }
        return r;
    }
};
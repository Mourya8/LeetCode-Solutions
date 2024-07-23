class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> ans;

        int s = 0;
        int e = numbers.size() - 1;
        int sum = 0;


        while(s < e)
        {
            int mid = s + (e - s) / 2;

            sum = numbers[s] + numbers[e];
            
            if(sum == target)
            {
                ans.push_back(s+1);
                ans.push_back(e+1);
                return ans;
            }
            else if(sum > target)
            {
                e--;
            }
            else
            {
                s++;
            }
        }
        

        return ans;

    }
};
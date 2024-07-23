class Solution {
public:
    int bs(vector<int> numbers, int x)
    {
        int l=0;
        int r=numbers.size()-1;
        int mid;
        while(l<r)
        {
            mid = l+(r-l)/2;
            if(numbers[mid]==x) return mid;
            else if(numbers[mid]>x)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> r;
        for(int i=0;i<numbers.size();i++)
        {
            if(target-numbers[i]==numbers[i])
            {
                if(i+1<numbers.size() && numbers[i]==numbers[i+1]) 
                {
                    r.push_back(i+1);
                    r.push_back(i+2);
                    return r;
                }
            }
            else if(binary_search(numbers.begin(),numbers.end(),target - numbers[i]))
            {
                int temp=bs(numbers, target-numbers[i]);
                r.push_back(i+1);
                r.push_back(temp+1);
                break;
            }
        }
        return r;
    }
};
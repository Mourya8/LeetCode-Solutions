class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        map<int,int> m;
        int n = skill.size();
        long long sum = 0;
        for(int i=0;i<skill.size();i++)
        {
            m[skill[i]]++;
            sum+=skill[i];
        }
        if(n%2==1) return -1;

        long long teamSum = (long long)(((long long)2*sum)/(long long)n);

        long long prod = 0;

        //cout <<teamSum<<endl;

        auto itr = m.begin();

while (!m.empty() && itr != m.end()) {
    int temp = teamSum - itr->first;

    if (m.find(temp) == m.end()) {
        return -1;
    } else {
        prod += (long long)(temp * itr->first); 

        if (itr->second > 1) {
            itr->second--;
        } else {
            itr = m.erase(itr);  
        }

        if (m[temp] > 1) {
            m[temp]--;
        } else {
            m.erase(temp);
        }
    }
}

        return prod;
    }
};
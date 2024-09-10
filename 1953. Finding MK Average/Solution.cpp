class MKAverage {
public:
    int M,K;
    vector<int> v;
    map<int,int> m;
    long long sum=0;
    int currentElements=0;
    MKAverage(int n, int k) {
        M=n;
        K=k;
    }
    
    void addElement(int num) {
        v.push_back(num);
        m[num]++;
        sum+=(long long)num;
        currentElements++;
        if(currentElements>M)
        {
            int t= v.size()-M-1;
            m[v[t]]--;
            sum-=(long long) v[t];
            if(m[v[t]]==0) m.erase(v[t]);
            currentElements--;
        }
        // cout<<"============"<<endl;

        // for (auto it = m.begin(); it != m.end(); ++it) {
        //     cout << "Key: " << it->first << ", Value: " << it->second << endl;
        // }
    }
    
    int calculateMKAverage() {
        if(currentElements<M) return -1;

        

        auto it=m.begin();
        long long tempSum=sum;
        int t=K;
        while(t>0)
        {
            int p = it->second;
            while(t>0&&p>0)
            {
                p--;
                tempSum-=(long long) it->first;
                t--;
            }
            ++it;
        }

        //cout<<tempSum<<endl;
        auto rit=m.rbegin();
        t=K;
        while(t>0)
        {
            int p=rit->second;
            while(t>0&&p>0)
            {
                p--;
                tempSum-=(long long) rit->first;
                t--;
            }
            ++rit;
        }
        //cout<<tempSum<<endl;
        int a = (int)(tempSum/(long long)(M-2*K));
        return a;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
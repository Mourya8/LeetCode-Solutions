class NumberContainers {
public:
    unordered_map<int,int> a;
    map<int,map<int,bool>> m;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(a[index])
        {
            int x = a[index];
            m[x].erase(index);
            a[index]=number;
            m[number][index]=0;
        }
        else
        {
            a[index]=number;
            m[number][index]=0;
        }
    }
    
    int find(int number) {
        if(m.find(number)!=m.end())
        {
            if(m[number].size()>0)
            {
                auto r = *m[number].begin();
                return r.first;
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
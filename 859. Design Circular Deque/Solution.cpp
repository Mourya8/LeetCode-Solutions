class MyCircularDeque {
public:
list <int> d;
int start =0;
int maxSize=0;
int end;
    MyCircularDeque(int k) {
        maxSize = k;
    }
    
    bool insertFront(int value) {
        if(d.size()<maxSize)
        {
            d.push_front(value);
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    
    bool insertLast(int value) {
        if(d.size()<maxSize)
        {
            d.push_back(value);
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    
    bool deleteFront() {
        if(d.size()>0)
        {
            d.pop_front();
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    
    bool deleteLast() {
        if(d.size()>0)
        {
            d.pop_back();
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    
    int getFront() {
        if(d.size()>0)
        {
            return d.front();
        }
        else 
        {
            return -1;
        }
    }
    
    int getRear() {
        if(d.size()>0)
        {
            return d.back();
        }
        else 
        {
            return -1;
        }
    }
    
    bool isEmpty() {
        if(d.size()==0)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    
    bool isFull() {
        if(d.size()==maxSize)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
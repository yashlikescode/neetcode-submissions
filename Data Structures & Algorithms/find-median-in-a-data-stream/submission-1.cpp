class MedianFinder {
private:
    vector<int> v;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        
        int n = v.size();
        if(n==0){
            v.push_back(num);
        } else {
            for(int i = 0; i < n; i++){
                if(v[i] >= num){
                    auto it = v.begin() + i;
                    v.insert(it,num);
                    return;
                }
            }
            v.push_back(num);
        }
        return;
    }
    
    double findMedian() {
        
        int n = v.size();
        if(n==1){
            return v[0];
        }
        if(n%2 == 1){
            return v[n/2];
        } else {
            return (v[n/2] + v[(n/2)-1])/2.0;
        }
    }
};


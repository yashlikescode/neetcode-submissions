class Solution {
public:
     int maxProfit(vector<int>& p) {
        int pri = 1000000;
        int maxp = 0;
        int sp = 0; 
        int psiz = p.size();
        for(int i = 0; i < psiz; i++)
        {
            if (p[i]<pri)
                pri = p[i];
            sp = p[i]-pri;
            if(maxp < sp)
                maxp = sp;
        }
        return maxp;
    }
};
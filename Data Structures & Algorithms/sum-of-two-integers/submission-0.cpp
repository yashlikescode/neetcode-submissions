class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        int car;
        do{
                sum = a ^ b;
                car = (a&b) << 1;
                b = car;
                a = sum;
        } while(b != 0);
        return sum;
    }
};

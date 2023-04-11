class Solution {
public:
    int solve(int a, int b, int c) {
        if(a>(2*(b+c) +2)||b>(2*(a+c) +2)||c>(2*(b+a) +2)) return -1;
        return a+b+c;
    }
};

class Solution {
public:
    int solve(int a, int b, int c) {
        if(a>(2*(b+c))||b>(2*(a+c))||c>(2*(b+a))) return -1;
        return a+b+c;
    }
};
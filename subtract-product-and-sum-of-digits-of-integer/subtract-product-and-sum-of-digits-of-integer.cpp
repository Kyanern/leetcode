//Please open this solution in VS2019
//https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
//2021 07 19

//STATUS: ACCEPTED

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getDigits(int n) {
        std::vector<int> retvec;
        while (n > 0) {
            retvec.push_back(n % 10);
            n = n / 10;
        }
        return retvec;
    }
    int subtractProductAndSum(int n) {
        std::vector<int> digits;
        digits = getDigits(n);
        int product = 1;
        int sum = 0;
        for (int i : digits) {
            product *= i;
            sum += i;
        }
        return product - sum;
    }
};

int main()
{
    int testcase = 234;
    Solution sln;
    std::cout << sln.subtractProductAndSum(testcase) << std::endl;
    return 0;
}
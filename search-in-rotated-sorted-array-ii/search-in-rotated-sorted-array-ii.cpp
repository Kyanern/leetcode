//Please open this solution in VS2019
//https://leetcode.com/problems/search-in-rotated-sorted-array-ii
//2021 05 05

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        auto itr = nums.begin();
        if (*itr == target)
        {
            return true;
        }
        else if (*itr > target)
        {
            auto ritr = nums.rbegin();
            if (*ritr == target)
            {
                return true;
            }
            else
            {
                auto ritr1 = ritr;
                ritr1++;
                while (ritr1 != nums.rend())
                {
                    if (*ritr1 > * ritr)
                    {
                        return false;
                    }
                    if (*ritr1 == target)
                    {
                        return true;
                    }
                    ritr++;
                    ritr1++;
                }
            }
        }
        else if (*itr < target)
        {
            auto itr1 = itr;
            itr1++;
            while (itr1 != nums.end())
            {
                if (itr > itr1)
                {
                    return false;
                }
                if (*itr1 == target)
                {
                    return true;
                }
                itr++;
                itr1++;
            }
        }
        return false;
    }
};

int main(void)
{
    vector<int> input{ 2,5,6,0,0,1,2 };
    Solution test;
    std::cout << test.search(input, 0) << std::endl;

    return 0;
}
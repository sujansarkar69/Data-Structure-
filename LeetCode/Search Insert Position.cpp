#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(logn)
Space Complexity: O(1).
*/
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int mid;

        while (start <= end)
        {
            mid = (start + end) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        if (target > nums[mid])
        {
            return mid + 1;
        }
        else
        {
            return mid;
        }
    }
};

int main()
{
}
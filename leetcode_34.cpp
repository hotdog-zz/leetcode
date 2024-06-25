#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> index;
            int start = 0, end = nums.size() - 1, temp, length = nums.size() - 1;
            if (end == -1)
                {
                    index = {-1, -1};
                    return index;
                }
            while (start < end)
            {
                temp = floor((start + end) / 2);
                if (nums[temp] < target)
                {
                    start = temp + 1;
                }
                else
                {
                    end = temp - 1;
                }
            }
            if (nums[start] == target)
            {
                index.push_back(start);
            }
            else
            {
                index = {-1, -1};
                return index;
            }
            end = nums.size() - 1;
            while (start <= end)
            {
                temp = floor((start + end) / 2);
                if (nums[temp] > target)
                {
                    end = temp - 1;
                }
                else
                {
                    start = temp + 1;
                }
            }
            index.push_back(end);
            return index;
        }
};

int main()
{
    Solution solution1;
    vector<int> num = {2, 2}, index;
    int target = 3;
    index = solution1.searchRange(num, target);
    cout << index[0] << "  " << index[1] << endl;
    return 0;
}
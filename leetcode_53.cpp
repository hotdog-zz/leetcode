#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> value;
        int i = 0, answer = nums[0], temp;
        value.push_back(nums[0]);
        for (i = 1; i < nums.size(); ++i)
        {
            temp = max(nums[i], value[i-1] + nums[i]);
            if (temp > answer)
                answer = temp;
            value.push_back(temp);
        }
        return answer;
    }
};

int main()
{
    Solution solution1;
    return 0;
}
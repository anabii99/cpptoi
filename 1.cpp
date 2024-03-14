#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> bucket;
        for (int i = 0; i < nums.size(); i++) {
            int value = target - nums[i];
            if (bucket.contains(value)) {
                return {bucket[value], i};
            }
            bucket[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15, 60};
    int target = 75;
    vector<int> result = s.twoSum(nums, target);
    cout << "The indices of the two numbers are " << result[0] << " and "
         << result[1] << "." << endl;
    return 0;
}

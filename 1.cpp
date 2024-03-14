#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> unordered_map;
        for (int i = 0; i < nums.size(); i++) {
            int value = target - nums[i];
            if (unordered_map.contains(value)) {
                return {unordered_map[value], i};
            }
            unordered_map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    // Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = Solution().twoSum(nums, target);
    cout << "The indices of the two numbers are " << result[0] << " and "
         << result[1] << "." << endl;
    return 0;
}
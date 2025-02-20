#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
class Solution {
 public:
  string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();
    vector<bool> exist(pow(2, nums[0].size()), false);
    for (int i = 0; i < n; i++) {
      //   cout << BinToDec(nums[i]);
      exist[BinToDec(nums[i])] = true;
    }
    for (int i = 0; i < exist.size(); i++) {
      if (!exist[i]) {
        return DectoBin(i, nums[0].size());
      }
    }
    return "";
  }

  int BinToDec(string bin) {
    int dec = 0;
    for (int i = 0; i < bin.size(); i++) {
      dec += (bin[i] - '0') * pow(2, bin.size() - i - 1);
    }
    return dec;
  }
  string DectoBin(int Dec, int size) {
    string s;
    while (Dec > 0) {
      s = to_string(Dec % 2) + s;
      Dec /= 2;
    }
    if (s.size() < size) {
      s = string(size - s.size(), '0') + s;
    }
    return s;
  }
};

int main() {
  Solution s;
  vector<string> nums = {"01", "10"};
  cout << s.findDifferentBinaryString(nums) << endl;
}
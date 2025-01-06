#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> ans(n, 0);
    vector<int> onePos;
    for (int i = 0; i < n; i++)
      if (boxes[i] == '1') onePos.push_back(i);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < onePos.size(); j++)
        if (i != onePos[j]) ans[i] += abs(i - onePos[j]);
    }
    return ans;
  }
};
int main() {
  Solution sol;
  string boxes = "110";
  vector<int> ans = sol.minOperations(boxes);
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    vector<int> shiftsCount(s.size(), 0);

    for (const auto& shift : shifts) {
      int start = shift[0];
      int end = shift[1];
      int direction = shift[2] == 0 ? -1 : 1;
      shiftsCount[start] += direction;
      if (end + 1 < shiftsCount.size()) {
        shiftsCount[end + 1] -= direction;
      }
    }

    // Compute prefix sums
    for (int i = 1; i < shiftsCount.size(); i++) {
      shiftsCount[i] += shiftsCount[i - 1];
    }

    // Apply the shifts
    for (int i = 0; i < shiftsCount.size(); i++) {
      shiftsCount[i] %= 26;
      if (shiftsCount[i] != 0) {
        for (int j = 0; j < abs(shiftsCount[i]); j++) {
          if (shiftsCount[i] > 0)
            s[i] = shift(s[i], 1);
          else
            s[i] = shift(s[i], 0);
        }
      }
    }
    return s;
  }
  char shift(char c, int dir) {
    if (dir == 0) return c - 1 < 'a' ? 'z' : c - 1;
    return c + 1 > 'z' ? 'a' : c + 1;
  }
};

int main() {
  Solution sol;
  string s = "abc";
  vector<vector<int>> shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
  cout << sol.shiftingLetters(s, shifts);
  return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
// how to prefix sum with vector<pair<int, int>>?
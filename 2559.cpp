#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> vowelStrings(vector<string>& words,
                           vector<vector<int>>& queries) {
    vector<int> ans(queries.size(), 0);
    vector<int> dp(words.size(), 0);
    if (isVowel(words[0][0]) && isVowel(words[0][words[0].size() - 1]))
      dp[0] = 1;
    for (int i = 1; i < words.size(); i++) {
      dp[i] = dp[i - 1];
      if (isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1]))
        dp[i]++;
    }

    for (int i = 0; i < queries.size(); i++) {
      if (queries[i][0] == 0)
        ans[i] = dp[queries[i][1]];
      else
        ans[i] = dp[queries[i][1]] - dp[queries[i][0] - 1];
    }

    return ans;
  }

  bool isVowel(char c) {
    char vowel[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++) {
      if (c == vowel[i]) return true;
    }
    return false;
  }
};
int main() {
  Solution solution;
  vector<string> words = {"aba", "baba", "aba", "xzxb"};
  vector<vector<int>> queries = {{0, 3}, {1, 3}, {2, 3}};
  vector<int> ans = solution.vowelStrings(words, queries);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}

// leetcode 2559. Vowel Strings
// https://leetcode.com/problems/vowel-strings/
// Given a list of words words and a list of queries queries, where each query
// consists of a pair of integers [l, r], return the number of words in the
// range [l, r] (inclusive) that start and end with a vowel. A string s starts
// with a vowel if s[0] is one of 'a', 'e', 'i', 'o', or 'u', solotion: dp time
// complexity: O(n*m) space complexity: O(n)

// slove it
// 1. create a vector dp to store the number of words that start and end with a
// vowel
// 2. loop through the words and check if the first and last character of the
// word is a vowel
// 3. loop through the queries and count the number of words that start and end
// with a vowel in the range [l, r]
// 4. return the answer
// 5. done
/**
  给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？ 
  输出需要删除的字符个数。
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int num_to_del(string &input) {
  string input_reverse(input);
  int length = input.size();
  reverse(input_reverse.begin(), input_reverse.end());
  vector<vector<int>> dp(length + 1, vector<int>(length + 1, 0));
  for (size_t i = 1; i <= length; i++) {
    for (size_t j = 1; j <= length; j++) {
      if (input[i - 1] == input_reverse[j - 1]) {
	dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
	dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return length - dp[length][length];
}

int main(void) {
  string input;
  while (cin >> input) {
    cout << num_to_del(input) << endl;
  }
  return 0;
}

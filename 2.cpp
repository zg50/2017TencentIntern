/**
  小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
  你能帮帮小Q吗？（这题还有一个比较无赖的做法就是大小写分开输出）
 */
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

string bubble(string & input) {
  // 用冒泡排序的思想
  int length = input.size();
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - 1 - i; j++) {
      if ((input[j] <= 'Z' && input[j] >= 'A') &&
	  (input[j + 1] <= 'z' && input[j + 1] >= 'a')) {
	swap(input[j], input[j + 1]);
      }
    }
  }
  return input;
}

int main(void) {
  string input;
  while (cin >> input) {
    string res = bubble(input);
    cout << res << endl;
  }
}

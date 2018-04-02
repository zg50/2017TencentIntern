/**
 假定一种编码的编码范围是a ~ y的25个字母 从1位到4位的编码 如果我们把该编码 按字典序排序 形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 其中a的Index为0，aa的Index为1 aaa的Index为2 以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.
  https://www.nowcoder.com/test/question/done?tid=14760229&qid=105227
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
  string input;
  cin >> input;
  long long res = 0;
  for (size_t i = 0; i < input.size(); i++) {
    if (i == 0) {
      // 分别对应长度为4，3，2，1长度情况
      res += (pow(25, 3) + pow(25, 2) + 25 + 1) * (input[i] - 'a'); 
    } else if (i == 1) {
      // 多出来的+1是空，比如"a",后面什么都不选这个也要考虑上
      res += (pow(25, 2) + 25 + 1) * (input[i] - 'a') + 1;
    } else if (i == 2) {
      res += (25 + 1) * (input[i] - 'a') + 1;
    } else if (i == 3) {
      res += (1) * (input[i] - 'a') + 1;
    }
  }
  cout << res << endl;
  return 0;
}

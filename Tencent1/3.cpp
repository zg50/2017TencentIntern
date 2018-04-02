/**
 小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？ 
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

pair<int, int> getPair(vector<int> & numbers) {
  sort(numbers.begin(), numbers.end());
  int size = numbers.size()
  if (numbers[0] == numbers[size - 1]) {
    // size * (size - 1) / 2 == 1 + 2 + 3 + .. + (size - 1)
    return pair<int, int>(size * (size - 1) / 2, size * (size - 1) / 2);
  }
  map<int, int> mymap;
  // 计数
  for (size_t i = 0; i < numbers.size(); i++) {
    if (mymap.find(numbers[i]) == mymap.end()) {
      mymap[numbers[i]] = 1;
    } else {
      mymap[numbers[i]] += 1;
    }
  }
  int count = 0;
  // 没有重复 求最小差的对数
  if (mymap.size() == numbers.size()) {
    int min = numbers[1] - numbers[0];
    for (size_t i = 1; i < numbers.size(); i++) {
      int diff = numbers[i] - numbers[i - 1];
      if (diff == min) {
	count++;
      } else if (diff < min) {
	min = diff;
	count = 1;
      }
    }
  } else {// 有重复 求对数
    for (pair<int, int> p : mymap) {
      if (p.second > 1) {
	count += (p.second) * (p.second - 1) / 2;
      }
    }
  }
  int first = count;
  int second = mymap[numbers[0]] * mymap[numbers[numbers.size() - 1]];
  return pair<int, int>(first, second);
}

int main(void) {
  int n;
  while (cin >> n) {
    if (n <= 2) {
       cout << n / 2 << " " << n / 2 << endl;
    } else {
       vector<int> numbers(n);
       for (int i = 0; i < n; i++) {
         cin >> numbers[i];
       }
       pair<int, int> res = getPair(numbers);
       cout << res.first << " " << res.second << endl;
    }
  }
  return 0;
}

/*给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)）
输入描述:*/
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

bool isPrime(int n) {
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int countTwoSum(vector<int> &prime, int &n) {
  int count = 0;
  int left = 0;
  int right = prime.size() - 1;
  while (left <= right) { // 10, (5, 5), 重复也算一对
    int sum = prime[left] + prime[right];
    if (sum == n) {
      count++;
      left++;
      right--;
    } else if (sum < n) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int main(void) {
  int n;
  cin >> n;

  vector<int> prime;
  for (int i = 2; i <= n - 2; i++) {
    if (isPrime(i)) {
      prime.push_back(i);
    }
  }
  
  cout << countTwoSum(prime, n) << endl;
  return EXIT_SUCCESS;
}

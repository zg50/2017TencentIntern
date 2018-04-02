/**
在一组数的编码中，若任意两个相邻的代码只有一位二进制数不同， 则称这种编码为格雷码(Gray Code)，请编写一个函数，使用递归的方法生成N位的格雷码。
给定一个整数n，请返回n位的格雷码，顺序为从0开始。
测试样例
 */

class GrayCode {
public:
  vector<string> getGray(int n) {
    // write code here
    // 格雷码是怎么生成的其实我还没太明白
    // 递归的思路就是n位gray码是由n-1位gray码生成，举个例子简单一些：
    // 比如求n=3的gray码，首先知道n=2的gray码是(00,01,11,10)
    // 那么n=3的gray码其实就是对n=2的gray码首位添加0或1生成的，添加0后变成(000,001,011,010)
    // 添加1后需要顺序反向就变成(110,111,101,100)
    // 组合在一起就是(000,001,011,010,110,111,101,100)
    vector<string> gray;
    if (n == 1) {
      gray.push_back("0");
      gray.push_back("1");
      return gray;
    }
    
    vector<string> temp = getGray(n - 1);
    for (int i = 0; i < temp.size(); i++) {
      gray.push_back("0" + temp[i]);
    }
    for (int i= temp.size() - 1; i >= 0;i--) {
      gray.push_back("1" + temp[i]);
    }
    return gray;
  }
};

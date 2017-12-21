#include <stdio.h>
#include <math.h>
//入力a,bの平均値の小数点以下を切上げた値を出力
int main(void) {
  int a, b, c;
  // scanfで入力を読み込み
  scanf("%d%d", &a, &b);
  // 平均値の計算 ceil:小数点を切上げる関数
  c = ceil((a + b) / 2.0);
  // 答えの出力
  printf("%d\n", c);
  return 0;
}
#include <stdio.h>
#define MAXLINE 100000
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int s[MAXLINE];
  int i = 0, q, j;
  while (scanf("%d", &q) != EOF) {
    s[i] = q;
    i++;
  }
  int ans = s[0];
  int x = 1;
  for (j = 1; j < b + 1; j++) {
    x *= a;
    ans += s[j] * x;
  }
  printf("%d\n", ans);
  return 0;
}

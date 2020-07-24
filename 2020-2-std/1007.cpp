#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 20005, M = 25;
int Case, n, m, i, A, B, g[N], V[N << 1], a[N << 1], b[N << 1], nxt[N << 1], ed, size[N];
ll f[N][M], h[N], l, r, mid, ans;
inline void up(ll &a, ll b) { a > b ? (a = b) : 0; }
void dfs(int u, int fa)
{
  size[u] = f[u][0] = 0;
  for (int i = g[u]; i; i = nxt[i])
  {
    int v = V[i];
    if (v == fa)
      continue;
    dfs(v, u);
    int A = a[i], B = b[i], pre = size[u], cur = size[v], now = min(pre + cur + 1, m);
    for (int j = 0; j <= now; j++)
      h[j] = mid + 1;
    for (int j = 0; j <= pre; j++)
      for (int k = 0; k <= cur && j + k <= m; k++)
      {
        if (f[u][j] + f[v][k] + A <= mid)
          up(h[j + k + 1], max(f[u][j], f[v][k] + A));
        if (f[u][j] + f[v][k] + B <= mid)
          up(h[j + k], max(f[u][j], f[v][k] + B));
      }
    size[u] = now;
    for (int j = 0; j <= now; j++)
      f[u][j] = h[j];
  }
}
int main()
{
  scanf("%d", &Case);
  while (Case--)
  {
    scanf("%d%d", &n, &m);
    l = r = 0;
    for (ed = i = 0; i <= n; i++)
      g[i] = 0;
    int u, v;
    for (i = 1; i < n; i++)
    {
      scanf("%d%d%d%d", &u, &v, &A, &B);
      V[++ed] = v;
      a[ed] = A;
      b[ed] = B;
      nxt[ed] = g[u];
      g[u] = ed;
      V[++ed] = u;
      a[ed] = A;
      b[ed] = B;
      nxt[ed] = g[v];
      g[v] = ed;
      r += max(A, B);
    }
    while (l <= r)
    {
      mid = (l + r) >> 1;
      dfs(1, 0);
      if (f[1][m] <= mid)
        r = (ans = mid) - 1;
      else
        l = mid + 1;
    }
    printf("%lld\n", ans);
  }
}
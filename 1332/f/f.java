import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);
    private static long MOD = 998244353;

    static class Tree {
        private ArrayList<Integer>[] adj;
        private boolean[] vis;
        private long[] f, g, h;
        // f: taken, but not colored
        // g: taken and colored
        // h: not taken

        private void dfs(int u) {
            vis[u] = true;
            f[u] = 1;
            g[u] = 1;
            h[u] = 1;
            for (int v : adj[u]) {
                if (!vis[v]) {
                    dfs(v);
                    f[u] *= 2 * f[v] + 2 * g[v] - h[v];
                    f[u] %= MOD;
                    g[u] *= 2 * f[v] + g[v] - h[v];
                    g[u] %= MOD;
                    h[u] *= f[v] + g[v] - h[v];
                    h[u] %= MOD;
                }
            }
        }

        public Tree(int n) {
            adj = new ArrayList[n + 1];
            for (int i = 1; i <= n; ++i)
                adj[i] = new ArrayList();
            f = new long[n + 1];
            g = new long[n + 1];
            h = new long[n + 1];
            vis = new boolean[n + 1];
        }

        public void add(int u, int v) {
            adj[u].add(v);
            adj[v].add(u);
        }

        public void solve() {
            dfs(1);
            long ans = (f[1] + g[1] - h[1] - 1) % MOD;
            if (ans < 0)
                ans += MOD;
            System.out.println(ans);
        }
    }

    public static void main(String[] args) {
        int n = scanner.nextInt();
        Tree tree = new Tree(n);
        for (int i = 0; i < n - 1; ++i) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            tree.add(u, v);
        }
        tree.solve();
    }
}

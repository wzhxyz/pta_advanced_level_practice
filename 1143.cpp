#include <cstdio>
#include <iostream>
#include <set>

int V[10000 + 10];
using namespace std;
int main() {
    int M, N;
    scanf("%d%d", &M, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int t = -1;
        set<int> vis;
        for (int j = 0; j < N; j++) {
            vis.insert(V[j]);
            int d = V[j];
            if (t == -1 && vis.count(d) && ((d >= a && b >= d)||(d >= b && a >= d))) {
                t = j;
            }
            
        }
        bool found_a = vis.count(a);
        bool found_b = vis.count(b);
        if (!found_a && !found_b) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if (!found_a) {
            printf("ERROR: %d is not found.\n", a);
        } else if (!found_b) {
            printf("ERROR: %d is not found.\n", b);
        } else {
            if (V[t] == b) {
                printf("%d is an ancestor of %d.\n", b, a);
            } else if (V[t] == a) {
                printf("%d is an ancestor of %d.\n",a, b);
            } else {
                printf("LCA of %d and %d is %d.\n", a, b, V[t]);
            }
        }

    }
    return 0;
}

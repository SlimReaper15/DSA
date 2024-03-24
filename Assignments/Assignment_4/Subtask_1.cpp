#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int depth;
    int time;
} Node;

bool compare(const Node& a, const Node& b) {
    return a.depth < b.depth;
}

int main(void) {
    int n, k, d, p;
    cin >> n >> k >> d >> p;

    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<Node> node(n);

    for (int i = 0; i < n; i++) {
        node[i].depth = y[i];
        node[i].time = t[i];
    }

    sort(node.begin(), node.end(), compare);

    priority_queue<int> pq;

    int curr = 0;

    while (curr <= d) {
        
    }
}

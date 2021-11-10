#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

map<int, vector<int>> nbd{};
vector<bool> isVisited;

int count(int N) {
    int result{ 0 };

    for (int i = 1; i <= N; ++i)
    {
        if (isVisited[i - 1])
            continue;

        stack<int> s{};
        s.push(i);
        isVisited[i - 1] = true;

        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            for (auto v : nbd[t])
            {
                if (!isVisited[v - 1])
                    s.push(v);

                isVisited[v - 1] = true;
            }
        }

        result += 1;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        nbd[i] = vector<int>{};
    }

    isVisited = vector<bool>(N, false);

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;

        nbd[u].push_back(v);
        nbd[v].push_back(u);
    }

    cout << count(N);

    return 0;
}
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <stack>
#include <utility>
#include <deque>
#include <string>
#include <climits>
#include <cmath>
#include <string>
#include <array>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cstring>
#include <cstdlib>
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

vector<vector<int>> graph;
vector<int> visited;	//0 : 미방문, 1 : 방문 중, 2 : 방문 완료
vector<int> discoverTime;
vector<int> finishTime;
vector<int> parent;	//backedge를 체크할 때, 인접하는 노드와의 관계는 고려하지 않기 위함
int time_cnt = 0;


//topological sorting
void DFS(int num, int p)
{
	visited[num] = GRAY;
	discoverTime[num] = time_cnt++;	//entry
	cout << num << " ";
	for (int i = 0; i < graph[num].size(); i++) {
		if (visited[graph[num][i]] == WHITE) {
			parent[graph[num][i]] = num;
			DFS(graph[num][i], num);

		}
		if (visited[graph[num][i]] == GRAY &&( graph[num][i] != p)) {
			//back edge
			//have cycle
		}

	} 
	cout << num << " ";	//reverse topological order;
	visited[num] = BLACK;
	finishTime[num] = time_cnt++;	//exit
}

int main() {
	int n, m, v;

	cin >> n >> m >> v;

	graph.resize(n + 1);
	visited.resize(n + 1, WHITE);
	discoverTime.resize(n + 1, 0);
	finishTime.resize(n + 1, 0);

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(v, 0);

	cout << '\n';
	return 0;
}
// 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

// 입력
// 첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

// 출력
// 첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//깊이 우선 탐색
void dfs(int start, vector<int> graph[], bool visited[]){
    visited[start] = true;
    cout << start << ' ';
    for(int i=0; i<graph[start].size(); i++){
        int y = graph[start][i];
        if(!visited[y]){
            dfs(y, graph, visited);
        }
    }
}

//너비 우선 탐색
void bfs(int start, vector<int> graph[], bool visited[]){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for(int i=0; i<graph[x].size(); i++){
            int y = graph[x][i];
            if(!visited[y]){
                visited[y] = true;
                q.push(y);
            }
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;
    vector<int> graph[N+1] = {};
    bool visited[N+1] = {false};
    
    for(int i=0; i<M; i++){
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    
    for(int i=1; i<=N; i++){
		sort(graph[i].begin(), graph[i].end());
	}
    
    dfs(V, graph, visited);
    cout << endl;
    
    //visited 재초기화
    fill(visited, visited + N + 1, false);

    bfs(V, graph, visited);
    
    return 0;
}
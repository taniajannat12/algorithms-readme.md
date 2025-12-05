#include<bits/stdc++.h>
using namespace std;
int main() {
int nodes, edges;
cin >> nodes >> edges;
vector<int> graph[100];
int visited[100] = {0};
for(int i = 0; i < edges; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
}
int start;
cin >> start;
stack<int> st;
st.push(start);
visited[start] = 1;
cout << "DFS: ";
while(!st.empty()) {
    int node = st.top();
    st.pop();
    cout << node << " ";
    for(int next : graph[node]) {
        if(!visited[next]) {
            visited[next] = 1;
            st.push(next);
        }
    }
}



}

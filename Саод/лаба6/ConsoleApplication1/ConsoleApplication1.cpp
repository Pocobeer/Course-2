#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <list>
using namespace std;
#define edge pair<int,int>

class Graph {
private:
    vector<pair<int, edge>> G; // graph
    vector<pair<int, edge>> T_krus; // mst
	vector<pair<int, edge>> T_prim;
    int* parent;
    int V; // number of vertices/nodes in graph
    vector<vector<int>> adj; // Список смежности
    vector<bool> visited; // Массив для отслеживания посещенных вершин
    vector<int> path; // Путь, по которому происходит поиск циклов
    vector<vector<int>> cycles; // Список всех найденных циклов
    vector<int> shortestDistances;
    // Метод обхода графа в глубину для поиска циклов
    void dfs(int v, int parent) {
        visited[v] = true;
        path.push_back(v);

        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u, v);
            }
            else if (u != parent) {
                // Найден цикл
                vector<int> cycle;
                // Найдите индекс первого вхождения u в path
                int idx = find(path.begin(), path.end(), u) - path.begin();
                // Запишите вершины в цикл в порядке, обходя вершины по пути от idx до path.size() - 1
                for (int j = idx; j < path.size(); ++j) {
                    cycle.push_back(path[j]);
                }
                // Добавьте вершины от начала пути до u
                for (int j = 0; j < idx; ++j) {
                    cycle.push_back(path[j]);
                }
                // Добавьте цикл в список циклов
                cycles.push_back(cycle);
            }
        }

        path.pop_back();
    }

public:
    
    Graph(int V) {
        parent = new int[V];

        //i 0 1 2 3 4 5
        //parent[i] 0 1 2 3 4 5
        for (int i = 0; i < V; i++)
            parent[i] = i;

        G.clear();
        T_krus.clear();
		T_prim.clear();
		this->V = V;
		adj.resize(V);
		visited.resize(V, false);
    }
    
    
    void AddEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void AddWeightedEdge(int u, int v, int w) {
        G.push_back(make_pair(w, edge(u, v)));
    }
    void findFundamentalCycles() {
        for (int v = 0; v < V; ++v) {
            if (!visited[v]) {
                path.clear();
                dfs(v, -1);
            }
        }
    }
    int find_set(int i) {
        // If i is the parent of itself
        if (i == parent[i])
            return i;
        else
            // Else if i is not the parent of itself
            // Then i is not the representative of his set,
            // so we recursively call Find on its parent
            return find_set(parent[i]);
    }
    void union_set(int u, int v) {
        parent[u] = parent[v];
    }
    void kruskal() {
        int i, uRep, vRep;
        sort(G.begin(), G.end()); // increasing weight
        for (i = 0; i < G.size(); i++) {
            uRep = find_set(G[i].second.first);
            vRep = find_set(G[i].second.second);
            if (uRep != vRep) {
                T_krus.push_back(G[i]); // add to tree
                union_set(uRep, vRep);
            }
        }
    }
    void prim() {
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1); // Родительская вершина в остовном дереве
        priority_queue<pair<int, edge>, vector<pair<int, edge>>, greater<pair<int, edge>>> pq;
        pq.push(make_pair(0, edge(-1, 0))); // Start from vertex 0

        while (!pq.empty()) {
            int u = pq.top().second.second;
            int parent_u = pq.top().second.first;
            int weight = pq.top().first;
            pq.pop();

            if (inMST[u]) continue; // Skip if u is already in MST
            inMST[u] = true;

            if (parent_u != -1) { // Skip if u is the starting vertex
                T_prim.push_back(make_pair(weight, edge(parent_u, u)));
            }

            for (auto& e : G) {
                int v = e.second.second;
                if (e.second.first == u && !inMST[v]) {
                    parent[v] = u;
                    pq.push(make_pair(e.first, edge(u, v))); // corrected weight here
                }
            }
        }
    }
    void print_k() {
        cout << "Kruskal method:" << endl;
        cout << "Edge :" << " Weight" << endl;
        for (int i = 0; i < T_krus.size(); i++) {
            cout << T_krus[i].second.first << " <-> " << T_krus[i].second.second << " : "
                << T_krus[i].first;
            cout << endl;
        }
        
        T_krus.clear();
    }
    void print_p() {
        cout << "Prim method:" << endl;
        cout << "Edge : Weight" << endl;
        for (int i = 0; i < T_prim.size(); ++i) {
            cout << T_prim[i].second.first << " <-> " << T_prim[i].second.second << " : " << T_prim[i].first << endl;
        }
		T_prim.clear();
    }
    void findLongestCycle(int v, int parent, vector<int>& currentCycle, vector<int>& longestCycle, vector<bool>& visited) {
        visited[v] = true;
        currentCycle.push_back(v);

        for (int u : adj[v]) {
            if (!visited[u]) {
                findLongestCycle(u, v, currentCycle, longestCycle, visited);
            }
            else if (u != parent && find(currentCycle.begin(), currentCycle.end(), u) != currentCycle.end()) {
                // Найден цикл
                if (currentCycle.size() > longestCycle.size()) {
                    longestCycle = currentCycle;
                }
            }
        }

        currentCycle.pop_back();
    }

    void printFundamentalCycle() {
        cout << "Fundamental cycle:" << endl;
        vector<int> currentCycle, longestCycle;
        vector<bool> visited(V, false);
        for (int v = 0; v < V; ++v) {
            if (!visited[v]) {
                currentCycle.clear();
                findLongestCycle(v, -1, currentCycle, longestCycle, visited);
            }
        }

        if (longestCycle.empty()) {
            cout << "No cycles found." << endl;
            return;
        }

        cout << "Cycle: ";
        for (int i = 0; i < longestCycle.size(); ++i) {
            cout << longestCycle[i];
            if (i != longestCycle.size() - 1) {
                cout << " <-> ";
            }
        }
        cout << endl;
    }
    void BFS(int startVertex) {
        vector<bool> visited(V, false); // Локальный массив для отслеживания посещенных вершин
        queue<int> queue;
        visited[startVertex] = true;
        queue.push(startVertex);
        int k = 0;
        while (!queue.empty()) {
            int currVertex = queue.front();
            cout << currVertex ;
            k++;
			if(k != V) cout << " <-> ";
            
            queue.pop();

            for (int adjVertex : adj[currVertex]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push(adjVertex);
                }
            }
        }
        cout << endl;
    }
    ~Graph() = default;
};
int main() {
    Graph g(6);
    g.AddWeightedEdge(0, 1, 4);
    g.AddWeightedEdge(0, 2, 4);
    g.AddWeightedEdge(1, 2, 2);
    g.AddWeightedEdge(2, 3, 3);
    g.AddWeightedEdge(2, 5, 2);
    g.AddWeightedEdge(2, 4, 4);
    g.AddWeightedEdge(3, 4, 3);
    g.AddWeightedEdge(5, 4, 3);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(2, 4);
    g.AddEdge(2, 5);
    g.AddEdge(3, 4);
    g.AddEdge(5, 4);

    g.kruskal();
    g.print_k();

    g.prim();
	g.print_p();
    
    g.findFundamentalCycles();
    g.printFundamentalCycle();
    cout << "BFS traversal from vertex 0:" << endl;
    g.BFS(0);
}
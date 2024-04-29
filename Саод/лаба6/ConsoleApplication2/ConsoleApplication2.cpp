#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Бесконечность для обозначения недостижимых вершин

// Структура для представления ребра графа
struct Edge {
    int destination;
    int weight;

    Edge(int dest, int w) : destination(dest), weight(w) {}
};

// Граф с взвешенными ребрами
class Graph {
private:
    vector<vector<Edge>> adjacencyList;
    int numVertices;

public:
    Graph(int n) : numVertices(n), adjacencyList(n) {}

    // Добавление взвешенного ориентированного ребра в граф
    void AddWeightedEdge(int source, int destination, int weight) {
        adjacencyList[source].emplace_back(destination, weight);
    }

    // Алгоритм Дейкстры для поиска кратчайших путей
    vector<int> Dijkstra(int start) {
        vector<int> distance(numVertices, INF); // Инициализируем расстояния до всех вершин как бесконечность
        distance[start] = 0; // Расстояние от стартовой вершины до неё самой равно 0

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Очередь с приоритетом для хранения пар (расстояние, вершина)
        pq.push({ 0, start }); // Добавляем стартовую вершину в очередь

        while (!pq.empty()) {
            int currDistance = pq.top().first;
            int currVertex = pq.top().second;
            pq.pop();

            if (currDistance > distance[currVertex]) // Пропускаем вершины, уже достигнутые с более коротким путем
                continue;

            for (const Edge& edge : adjacencyList[currVertex]) {
                int newDistance = currDistance + edge.weight;
                if (newDistance < distance[edge.destination]) {
                    distance[edge.destination] = newDistance;
                    pq.push({ newDistance, edge.destination });
                }
            }
        }

        return distance;
    }

    // Вывод ребер графа в формате "source <-> destination : weight"
    void PrintEdges() {
        for (int i = 0; i < numVertices; ++i) {
            for (const Edge& edge : adjacencyList[i]) {
                cout << i << " <-> " << edge.destination << " : " << edge.weight << endl;
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    // Создание графа
    Graph g(6);

    // Добавление взвешенных ориентированных рёбер в граф
    g.AddWeightedEdge(0, 1, 2);
    g.AddWeightedEdge(0, 2, 4);
    g.AddWeightedEdge(1, 2, 1);
    g.AddWeightedEdge(2, 3, 3);
    g.AddWeightedEdge(2, 5, 2);
    g.AddWeightedEdge(2, 4, 4);
    g.AddWeightedEdge(3, 4, 3);
    g.AddWeightedEdge(5, 4, 3);

    // Вывод ребер графа
    //cout << "Ребра графа:" << endl;
    //g.PrintEdges();

    int startVertex = 0;
    vector<int> shortestPaths = g.Dijkstra(startVertex);

    cout << "\nКратчайшие расстояния от вершины " << startVertex << " до всех остальных вершин:\n";
    for (int i = 0; i < shortestPaths.size(); ++i) {
        cout << "До вершины " << i << ": ";
        if (shortestPaths[i] == INF)
            cout << "недостижима";
        else
            cout << shortestPaths[i];
        cout << endl;
    }

    return 0;
}
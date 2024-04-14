#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для представления ребра графа
struct Edge {
    int src, dest, weight;
};

// Структура для представления графа
class Graph {
public:
    int V, E; // Количество вершин и ребер
    vector<Edge> edges; // Вектор ребер

    // Конструктор графа
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    // Добавление ребра в граф
    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }

    // Функция для нахождения корня вершины i
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    // Функция для объединения двух компонент связности в одну
    void Union(vector<int>& parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    // Алгоритм Крускала для поиска минимального остовного дерева
    void KruskalMST() {
        vector<int> parent(V, -1); // Инициализация родительских вершин

        // Сортировка всех ребер графа по весу
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
            });

        int edgeCount = 0; // Счетчик ребер, добавленных в остовное дерево
        int i = 0; // Индекс для перебора ребер

        // Пока не будет добавлено V-1 ребер в остовное дерево
        while (edgeCount < V - 1 && i < E) {
            Edge nextEdge = edges[i++];

            // Найдем корни двух вершин, соединенных ребром
            int x = find(parent, nextEdge.src);
            int y = find(parent, nextEdge.dest);

            // Если добавление ребра не приведет к циклу, то добавляем его в остовное дерево
            if (x != y) {
                cout << nextEdge.src << " - " << nextEdge.dest << " (" << nextEdge.weight << ")" << endl;
                Union(parent, x, y);
                edgeCount++;
            }
        }
    }
};

int main() {
    // Количество вершин и ребер в графе
    int V = 4, E = 5;
    Graph graph(V, E);

    // Добавление ребер графа
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    // Вызов алгоритма Крускала для поиска минимального остовного дерева
    cout << "Edges of MST:" << endl;
    graph.KruskalMST();

    return 0;
}

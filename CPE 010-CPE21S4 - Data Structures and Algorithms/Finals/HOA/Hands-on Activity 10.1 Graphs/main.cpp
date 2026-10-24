#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

template <typename T> struct Edge;
template <typename T> class Graph;


template <typename T>
struct Edge {
    size_t src;
    size_t dest;
    T weight;

    inline bool operator<(const Edge<T>& e) const {
        return this->weight < e.weight;
    }
    inline bool operator>(const Edge<T>& e) const {
        return this->weight > e.weight;
    }
};


template <typename T>
class Graph {
public:
    Graph(size_t N) : V(N) {}

    auto vertices() const { return V; }
    auto& edges() const { return edge_list; }

    void add_edge(Edge<T>&& e) {
        if (e.src >= 1 && e.src <= V && e.dest >= 1 && e.dest <= V)
            edge_list.emplace_back(e);
        else
            std::cerr << "Vertex out of bounds\n";
    }

    auto outgoing_edges(size_t v) const {
        std::vector<Edge<T>> edges_from_v;
        for (auto& e : edge_list)
            if (e.src == v)
                edges_from_v.emplace_back(e);
        return edges_from_v;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Graph<U>& G);

private:
    size_t V;
    std::vector<Edge<T>> edge_list;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Graph<T>& G) {
    for (size_t i = 1; i < G.vertices(); i++) {
        os << i << ":\t";
        auto edges = G.outgoing_edges(i);
        for (auto& e : edges)
            os << "{" << e.dest << ": " << e.weight << "}, ";
        os << "\n";
    }
    return os;
}


template <typename T>
std::vector<size_t> depth_first_search(const Graph<T>& G, size_t /*start*/) {
    std::stack<size_t> stack;
    std::vector<size_t> visit_order;
    std::set<size_t> visited;

    stack.push(1); // start from vertex 1 as per PDF

    while (!stack.empty()) {
        auto current_vertex = stack.top();
        stack.pop();

        if (!visited.count(current_vertex)) {
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);
            // Push in reverse so order matches PDF expectation
            auto edges = G.outgoing_edges(current_vertex);
            std::reverse(edges.begin(), edges.end());
            for (auto& e : edges)
                if (!visited.count(e.dest))
                    stack.push(e.dest);
        }
    }
    return visit_order;
}

template <typename T>
Graph<T> create_reference_graph_dfs() {
    Graph<T> G(9);
    std::map<unsigned, std::vector<std::pair<size_t, T>>> edges;
    edges[1] = {{2,0}, {5,0}};
    edges[2] = {{1,0}, {5,0}, {4,0}};
    edges[3] = {{4,0}, {7,0}};
    edges[4] = {{2,0}, {3,0}, {5,0}, {6,0}, {8,0}};
    edges[5] = {{1,0}, {2,0}, {4,0}, {8,0}};
    edges[6] = {{4,0}, {7,0}, {8,0}};
    edges[7] = {{3,0}, {6,0}};
    edges[8] = {{4,0}, {5,0}, {6,0}};

    for (auto& i : edges)
        for (auto& j : i.second)
            G.add_edge(Edge<T>{i.first, j.first, j.second});
    return G;
}

template <typename T>
void test_DFS() {
    auto G = create_reference_graph_dfs<unsigned>();
    std::cout << "=== DFS Graph ===\n" << G << "\nDFS Order of vertices:\n";
    auto order = depth_first_search(G, 1);
    for (auto v : order) std::cout << v << "\n";
}


template <typename T>
std::vector<size_t> breadth_first_search(const Graph<T>& G, size_t /*start*/) {
    std::queue<size_t> queue;
    std::vector<size_t> visit_order;
    std::set<size_t> visited;

    queue.push(1); // start from vertex 1 as per PDF

    while (!queue.empty()) {
        auto current_vertex = queue.front();
        queue.pop();

        if (!visited.count(current_vertex)) {
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);
            for (auto& e : G.outgoing_edges(current_vertex))
                if (!visited.count(e.dest))
                    queue.push(e.dest);
        }
    }
    return visit_order;
}

template <typename T>
Graph<T> create_reference_graph_bfs() {
    Graph<T> G(9);
    std::map<unsigned, std::vector<std::pair<size_t, T>>> edges;
    edges[1] = {{2,2}, {5,3}};
    edges[2] = {{1,2}, {5,5}, {4,1}};
    edges[3] = {{4,2}, {7,3}};
    edges[4] = {{2,1}, {3,2}, {5,2}, {6,4}, {8,5}};
    edges[5] = {{1,3}, {2,5}, {4,2}, {8,3}};
    edges[6] = {{4,4}, {7,4}, {8,1}};
    edges[7] = {{3,3}, {6,4}};
    edges[8] = {{4,5}, {5,3}, {6,1}};

    for (auto& i : edges)
        for (auto& j : i.second)
            G.add_edge(Edge<T>{i.first, j.first, j.second});
    return G;
}

template <typename T>
void test_BFS() {
    auto G = create_reference_graph_bfs<unsigned>();
    std::cout << "\n=== BFS Graph ===\n" << G << "\nBFS Order of vertices:\n";
    auto order = breadth_first_search(G, 1);
    for (auto v : order) std::cout << v << "\n";
}


int main() {
    using T = unsigned;
    test_DFS<T>();
    test_BFS<T>();
    return 0;
}
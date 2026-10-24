#include <iostream>

// stores adjacency list items
struct adjNode {
    int val, cost;
    adjNode* next;
};

// structure to store edges
struct graphEdge {
    int start_ver, end_ver, weight;
};

class DiaGraph {
    adjNode* getAdjListNode(int value, int weight, adjNode* head) {
        adjNode* newNode = new adjNode;
        newNode->val = value;
        newNode->cost = weight;
        newNode->next = head; // point new node to current head
        return newNode;
    }
public:
    int N; // number of nodes in the graph
    adjNode** head; // adjacency list as array of pointers

    // Constructor
    DiaGraph(graphEdge edges[], int n, int N) {
        this->N = N;
        head = new adjNode*[N]();
        // initialize head pointer for all vertices
        for (int i = 0; i < N; ++i)
            head[i] = nullptr;
        // construct directed graph by adding edges
        for (unsigned i = 0; i < n; i++) {
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;
            adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);
            head[start_ver] = newNode;
        }
    }

    // Destructor
    ~DiaGraph() {
        for (int i = 0; i < N; i++)
            delete head[i];
        delete[] head;
    }

    // print all adjacent vertices of given vertex
    void display_AdjList(adjNode* ptr, int i) {
        while (ptr != nullptr) {
            std::cout << "(" << i << ", " << ptr->val << ", " << ptr->cost << ") ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // graph edges array: (x, y, w) -> edge from x to y with weight w
    graphEdge edges[] = {
        {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
    };
    int N = 6; // Number of vertices
    int n = sizeof(edges)/sizeof(edges[0]);
    DiaGraph diagraph(edges, n, N);

    std::cout << "Graph adjacency list\n(start_vertex, end_vertex, weight):\n";
    for (int i = 0; i < N; i++)
        diagraph.display_AdjList(diagraph.head[i], i);

    return 0;
}
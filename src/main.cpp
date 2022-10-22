#include "iostream"
#include "MatrixGraph.h"
#include "ListGraph.h"

#define TYPE_GRAPH_ERROR 69

int main() {
    IGraph *graph;

    std::string command;
    int verticesCount {0};

    std::cout << "input graph type:" << std::endl;
    std::cin >> command;

    std::cout << "Input vertices count:" << std::endl;
    std::cin >> verticesCount;

    if (command == "matrix")
        graph = new MatrixGraph(verticesCount);
    else if (command == "list")
        graph = new ListGraph(verticesCount);
    else exit(TYPE_GRAPH_ERROR);

    do {
        std::cout << "Input command:" << std::endl;
        std::cin >> command;

        if (command == "add") {
            int from{0}, to{0};

            std::cout << "Input from-to vertices:" << std::endl;
            std::cin >> from >> to;

            graph->AddEdge(from, to);
        } else if (command == "prev") {
            std::vector<int> vertices;
            int vertex {0};

            std::cout << "Input vertex:" << std::endl;
            std::cin >> vertex;

            graph->GetPrevVertices(vertex, vertices);

            for (auto i : vertices)
                std::cout << i << " ";

            std::cout << std::endl;
        } else if (command == "next") {
            std::vector<int> vertices;
            int vertex {0};

            std::cout << "Input vertex:" << std::endl;
            std::cin >> vertex;

            graph->GetNextVertices(vertex, vertices);

            for (auto i : vertices)
                std::cout << i << " ";

            std::cout << std::endl;
        } else if (command == "count") {
            std::cout << graph->VerticesCount();
        } else if (command == "print") {
            graph->PrintGraph();
        }

    } while (command != "exit");

    delete graph;
}

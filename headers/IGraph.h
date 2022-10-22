#ifndef INC_31_5_2_IGRAPH_H
#define INC_31_5_2_IGRAPH_H

#include <vector>
#include <iostream>

class IGraph {
public:
    IGraph() = default;
    virtual ~IGraph() = default;
    IGraph(const IGraph &obj) = default;
    virtual void AddEdge(int from, int to) = 0;
    virtual int VerticesCount() const = 0;
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0;
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0;
    virtual void PrintGraph() const = 0;
};


#endif
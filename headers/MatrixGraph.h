#ifndef INC_31_5_2_MATRIXGRAPH_H
#define INC_31_5_2_MATRIXGRAPH_H

#include <map>
#include "IGraph.h"


class MatrixGraph : public IGraph {
private:
    std::vector<std::vector<int>> mMatrix;
public:
    MatrixGraph(int verticesCount);
    ~MatrixGraph() override = default;
    MatrixGraph(const MatrixGraph &obj);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    void PrintGraph() const override;
};


#endif
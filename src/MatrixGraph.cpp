#include <cassert>
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int verticesCount) {
    assert(verticesCount > 0 && verticesCount < 100);
    for (int i = 0; i < verticesCount; ++i) {
        std::vector<int> tmp(verticesCount,0);
        mMatrix.push_back(tmp);
    }
}

MatrixGraph::MatrixGraph(const MatrixGraph &obj) : mMatrix(obj.mMatrix) {}

void MatrixGraph::AddEdge(int from, int to) {
    assert(from > 0 && from <= mMatrix.size());
    assert(to > 0 && to <= mMatrix.size());
    mMatrix[to - 1][from - 1] += 1;
}

int MatrixGraph::VerticesCount() const { return static_cast<int>(mMatrix.size()); }

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex > 0 && vertex <= mMatrix.size());
    for (int i = 0; i < mMatrix[vertex - 1].size(); i++) {
        if (mMatrix[vertex - 1][i] != 0)
            vertices.push_back(i + 1);
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex > 0 && vertex <= mMatrix.size());
    for (int i = 0; i < mMatrix.size(); i++) {
        if (mMatrix[i][vertex - 1] != 0)
            vertices.push_back(i + 1);
    }
}

void MatrixGraph::PrintGraph() const {
    for (auto &i : mMatrix) {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << std::endl;
    }
}

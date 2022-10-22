#include <cassert>
#include "ListGraph.h"

ListGraph::ListGraph(int verticesCount) {
    assert(verticesCount > 0 && verticesCount < 100);
    for (int i = 1; i <= verticesCount; ++i)
        mList.insert({i, std::multiset<int>() });
}

ListGraph::ListGraph(const ListGraph &obj) : mList(obj.mList) {}

void ListGraph::AddEdge(int from, int to) {
    assert(from > 0 && from <= mList.size());
    assert(to > 0 && to <= mList.size());
    mList.find(to)->second.insert(from);
}

int ListGraph::VerticesCount() const { return static_cast<int>(mList.size()); }

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex > 0 && vertex <= mList.size());
    for (const auto &i : mList) {
        if (i.second.contains(vertex))
            vertices.push_back(i.first);
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex > 0 && vertex <= mList.size());
    for (const auto i : mList.find(vertex)->second)
        vertices.push_back(i);
}

void ListGraph::PrintGraph() const {
    for (const auto &i : mList) {
        std::cout << "Vertex: " << i.first << ";\t" << "List: { ";
        for (const auto j : i.second) {
            std::cout << j << " ";
        }
        std::cout << "};" << std::endl;
    }
}


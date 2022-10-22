#ifndef INC_31_5_2_LISTGRAPH_H
#define INC_31_5_2_LISTGRAPH_H

#include <map>
#include <set>
#include "IGraph.h"

class ListGraph : public IGraph {
private:
    std::map<int, std::multiset<int>> mList;
public:
    ListGraph(int verticesCount);
    ~ListGraph() override = default;
    ListGraph(const ListGraph &obj);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    void PrintGraph() const override;
};


#endif

#include "pch.h"
#include "Graph.h"
#include <vector>
#include <queue>
using namespace std;

// =============================================================================
// SpanningTreePrim ============================================================
// =============================================================================


CSpanningTree SpanningTreePrim(CGraph& graph)
{
	std::vector<CVertex> list;
	for (auto i = graph.m_Vertices.begin(); i != graph.m_Vertices.end(); i++) {
		list.push_back(*i);
	}
	CSpanningTree stp = CSpanningTree(&graph);
	stp.Clear();
	CVertex* v = graph.GetVertex(0);
	double min = 999999999;
	CEdge* e = graph.NewEdge(v, v);
	while (list.empty() != 1) {
		for (auto i = v->m_Edges.begin(); i != v->m_Edges.end(); i++) {
			for (auto j = list.begin(); j != list.end(); j++) {
				if (j->m_Name!=(*i)->m_pDestination->m_Name && stp.MemberP(*i)==0 && (*i)->m_Length<min){
					min = (*i)->m_Length;
					e = *i;
					break;
				}
			}				
		}
		stp.Add(e);
		for (auto j = list.begin(); j != list.end(); j++) {
			if (j->m_Name == e->m_pDestination->m_Name) {
				list.erase(j);
			}
		}
	}
	return stp;
}


//	return CSpanningTree(&graph);

#include "mstree.h"

priority_queue< Edge, vector<Edge>, Compare > PQ;

//크루스칼은 최소우선순위큐가 1개!

void kruskal() {
	Sets sets(NNODES);
	int nedges = 0; // #edges found up to now. 
	while ((nedges < NNODES - 1) && !PQ.empty()) 
	{
						
		Edge e = PQ.top(); // 최소비용 간선e 선택
		PQ.pop(); // e를 PQ에서 삭제

		// 간선e의 각 점v1 과 v2가 어느 집합에 속했는지 Find.
		int v1root=sets.Find(e.v1);
		int v2root=sets.Find(e.v2);

		if (v1root != v2root) // e가 사이클을 만들지 않는다면
		{
			// 두 집합을WeightedUnion, nedges 갯수 추가, 간선e 출력
			sets.WeightedUnion(v1root, v2root);
			nedges++;
			cout << e;
						
		}
		
	}
}

void ReadEdges4kruskal(istream& is) {
	Edge e;
	while (GetEdge(is, e))
		PQ.push(e);
}


int main(int argc, char* argv[]) 
{
	ifstream is;
	if (argc == 1) 
		is.open("kin.txt");

	else 
		is.open(argv[1]);

	if (!is) 
	{ 
		cerr << "No such input file\n"; 
		exit(1); 
	}

	is >> NNODES;

	if (NNODES < 2) 
	{ 
		cerr << "#nodes must be 2.." << endl; 
		exit(1); 
	}

	try {
		ReadEdges4kruskal(is);
		kruskal();
	}

	catch (char const* str)
	{
		cerr << "Exception: " << str << endl; exit(1);
	}
}
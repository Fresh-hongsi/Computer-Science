#include "mstree.h"


priority_queue< Edge, vector<Edge>, Compare >* PQ=0;
// 필요함수를 정의 및 구현하시오

void MoveIntoPQ_From_PQ(int from, int to)
{
	
	while (!PQ[from].empty())
	{

		Edge temp = PQ[from].top();
		PQ[from].pop();
		PQ[to].push(temp);
		
	}
}


void ReadEdges4sollin(istream& is) {
	//각 점(tree) 마다 연결된 간선들의 minheap이 필요함.
	// NNODES개의 minheap을 갖고 있는 PQ 배열을 생성하시오.
	//PQ = new ....
	PQ = new priority_queue< Edge, vector<Edge>, Compare >[NNODES];

	Edge e;
	while (GetEdge(is, e)) {
		PQ[e.v1].push(e);
		PQ[e.v2].push(e);
	}
}


void sollin() {
	Sets sets(NNODES);
	// 코드 추가 하기
	int nedges = 0;
	while (nedges < NNODES - 1)
	{
		for (int i = 0; i < NNODES; i++)
		{
			int v = sets.Find(i);

			if (PQ[v].empty())
				continue;

			if (!PQ[v].empty())
			{
				Edge e = PQ[v].top();
				PQ[v].pop();

				int v1root = sets.Find(e.v1);
				int v2root = sets.Find(e.v2);

				if (v1root != v2root) //cycle이 아니라면
				{
					
					sets.WeightedUnion(v1root, v2root);
					nedges++;
					cout << e;
					
					if (sets.Find(v1root) == v2root) //v1root의 parent가 v2root -> v1에서 v2로 옮기기
					{
						MoveIntoPQ_From_PQ(v1root, v2root); 
					}
					if (sets.Find(v2root) == v1root) //v2root의 parent가 v1root->v2에서 v1으로 옮기기
					{
						MoveIntoPQ_From_PQ(v2root, v1root);
					}

					
			
					//v1root가 작은 쪽으로 move해줘야함
					/*
					if (v1root < v2root)
					{
						MoveIntoPQ_From_PQ(v2root, v1root); //작은 점에서 큰 점으로 옮기기
					}
					else
					{
						MoveIntoPQ_From_PQ(v1root, v2root);
					}
					*/

					
				}
			}

			



		}
	}
}
	




int main(int argc, char* argv[]) {
	//파일 입력 부분은 kruskal경우와 동일하게
	//추가

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
		ReadEdges4sollin(is);
		sollin();
	}
	catch (char const* str)
	{
		cerr << "Exception: " << str << endl; exit(1);
	}
}
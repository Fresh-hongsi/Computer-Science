#include "mstree.h"


priority_queue< Edge, vector<Edge>, Compare >* PQ=0;
// �ʿ��Լ��� ���� �� �����Ͻÿ�

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
	//�� ��(tree) ���� ����� �������� minheap�� �ʿ���.
	// NNODES���� minheap�� ���� �ִ� PQ �迭�� �����Ͻÿ�.
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
	// �ڵ� �߰� �ϱ�
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

				if (v1root != v2root) //cycle�� �ƴ϶��
				{
					
					sets.WeightedUnion(v1root, v2root);
					nedges++;
					cout << e;
					
					if (sets.Find(v1root) == v2root) //v1root�� parent�� v2root -> v1���� v2�� �ű��
					{
						MoveIntoPQ_From_PQ(v1root, v2root); 
					}
					if (sets.Find(v2root) == v1root) //v2root�� parent�� v1root->v2���� v1���� �ű��
					{
						MoveIntoPQ_From_PQ(v2root, v1root);
					}

					
			
					//v1root�� ���� ������ move�������
					/*
					if (v1root < v2root)
					{
						MoveIntoPQ_From_PQ(v2root, v1root); //���� ������ ū ������ �ű��
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
	//���� �Է� �κ��� kruskal���� �����ϰ�
	//�߰�

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
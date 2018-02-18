#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "graph.h"
#include "heapforkruskal.h"


typedef pair<int, pair<int,int> > edge;
typedef list<pair<int,int> > tedge;

class kruskal{
	private:
		stack<int> S;
		int* PARENT;
		int* RANK;
		int* COLOR;
		int* BW;
		int* UF_PARENT;
		int  v_count;
		list<pair<int,int> > *tedge;//tree edge
	public:
		kruskal(int VERTICES_COUNT){
			v_count = VERTICES_COUNT;
			UF_PARENT = new int[VERTICES_COUNT+1];
			PARENT = new int[VERTICES_COUNT+1];
			RANK = new int[VERTICES_COUNT+1];
			COLOR = new int[VERTICES_COUNT+1];
			BW = new int[VERTICES_COUNT+1];
			tedge  = new list<pair<int,int> > [VERTICES_COUNT+1];

			for(int i=1;i<=VERTICES_COUNT;i++){
				UF_PARENT[i] = i;
			}
		};
		void find_maxbw_path(int,int,const Graph &,HeapSort &);
		void construct_heap(const Graph &,HeapSort &);
		void construct_maxst(HeapSort &,int);
		void check_cycle(int ,int ,int );
		void union_set(int,int);
		int find_set(int);
		void run_dfs(int);
		void tracePath(int* , int);
		~kruskal(){
			delete UF_PARENT;
			delete PARENT;
			delete RANK;
			delete COLOR;
			delete BW;
			delete tedge;
		};
};
#endif

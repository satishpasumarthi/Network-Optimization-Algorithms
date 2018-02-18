#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <algorithm>
#include <utility>
#include <stack>
#include <map>

using namespace std;

//Graph class
typedef pair<int,int> vpair;

enum colors{
	WHITE,GREY,BLACK
};

enum status{
	UNSEEN,FRINGE,INTREE
};

class Graph{
	private:
		#define EDGE_WEIGHT_LIMIT 10000
		int* scc;
		int* vcolor;
		int* degree;
		int cc;
		map<int, int> umap;

	public:
		int vertices_count;
		int v_count;
		int edges_count;
		list<pair<int,int> > *edge;		
		int s_edge_count,d_edge_count;
		int sg_avg_degree;
		float dg_avg_degree;

		Graph(int VERTICES_COUNT){
			v_count = VERTICES_COUNT;
			s_edge_count	= 0;
			d_edge_count	= 0;
			sg_avg_degree	= 0;
			dg_avg_degree	= 0;
			edge  	= new list<pair<int,int> > [VERTICES_COUNT+1];
			degree	= new int [VERTICES_COUNT+1]; 
			vcolor	= new int [VERTICES_COUNT+1];
			scc 	= new int [VERTICES_COUNT+1];
		};

		void createSparseGraph(int);//input arg is No.Of vertices
		void createDenseGraph(float);
		void addEdge(int,int,int);
		void printGraph(int);
		void run_sccdfs(int);
		~Graph() {
			delete edge;
			delete degree;
			delete vcolor;
			delete scc;
		};
};
#endif

#ifndef DIJKSTRAWITHOUTHEAP_H
#define DIJKSTRAWITHOUTHEAP_H
//Header file for Dijkstra Without Heap
#include "graph.h"

using namespace std;

class DijkstraWithOutHeap {
	private:
		int* PARENT;
		int* STATUS;
		int* BW;
		int	 v_count;
	public:
		DijkstraWithOutHeap(int VERTICES_COUNT){
			v_count = VERTICES_COUNT;
			PARENT 	= new int [VERTICES_COUNT+1];
			BW 		= new int [VERTICES_COUNT+1];
			STATUS 	= new int [VERTICES_COUNT+1];
		}

		int find_maxbw_fringe(const Graph &); //return the vertex
		void find_maxbw_path(int,int,const Graph &);
		void tracePath(int*,int);

		~DijkstraWithOutHeap() {
			delete PARENT;
			delete BW;
			delete STATUS;
		};
};
#endif

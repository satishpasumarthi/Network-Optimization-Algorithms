#ifndef DIJKSTRAWITHHEAP_H
#define DIJKSTRAWITHHEAP_H


#include "graph.h"
#include "maxheap.h"

using namespace std;

class DijkstraWithHeap {
	private:
		int* PARENT;
		int* STATUS;
		int* BW;
	public:
		DijkstraWithHeap(int VERTICES_COUNT){
			PARENT	= new int [VERTICES_COUNT+1];
			BW		= new int [VERTICES_COUNT+1];
			STATUS	= new int [VERTICES_COUNT+1];
		}
		void find_maxbw_path2(int,int,const Graph &,MaxHeap &);
		void tracePath(int*,int);		
		~DijkstraWithHeap() {
			delete PARENT;
			delete BW;
			delete STATUS;
		};
};
#endif

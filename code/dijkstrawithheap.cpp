#include "dijkstrawithheap.h"

using namespace std;

void DijkstraWithHeap::find_maxbw_path2(int src,int dest,const Graph &G1,MaxHeap &H) {
	int u,v,w,wt;
	
	H.size = 0;
	H.index = 1;

	STATUS[src] = INTREE;
	//Wavefront at source
	for(list<pair<int,int> >::iterator node=G1.edge[src].begin();node!=G1.edge[src].end();node++){
			v = (*node).first;
			wt = (*node).second;
			STATUS[v] = FRINGE;
			PARENT[v] = src;
			BW[v] = wt;
			H.insert_into_heap(v,wt);
	}
	u = src;

	//Propagate till the destination becomes in-tree
	while(STATUS[dest] != INTREE){

		v = H.getmaxvertex_from_heap();
		STATUS[v] = INTREE;
		H.delete_from_heap(v);

		for(list<pair<int,int> >::iterator node=G1.edge[v].begin();node!=G1.edge[v].end();node++){
			w = (*node).first;
			wt = (*node).second;
			if(STATUS[w] == UNSEEN && BW[w] != INT_MIN) {
				STATUS[w] = FRINGE;
				PARENT[w] = v;
				BW[w]		= BW[v]<wt ? BW[v]:wt;	
				H.insert_into_heap(w,BW[w]);
			}else if (STATUS[w] == FRINGE && BW[w] < (BW[v]<wt ? BW[v]:wt) && BW[w] != INT_MIN){
				BW[w]	= BW[v] < wt ? BW[v]:wt;
				PARENT[w] = v;
				//updating bandwidth for vertex w
				H.delete_from_heap(w);
				H.insert_into_heap(w,BW[w]);
			}
		}//for
		u = v;
	}//end-while

	if(src != dest) {
		cout << "DijkstraWithHeap :: "<<BW[dest]<<endl;
	}else{
		cout << "DijkstraWithHeap :: INIFINITY"<<endl;
	}
	
	cout << src <<"->";
	if(src != dest) {
		tracePath(PARENT,PARENT[dest]);
	}
	cout << dest << "("<< BW[dest]<<")\n";
}

void DijkstraWithHeap::tracePath(int* PARENT,int dest){
	if (PARENT[dest] == 0) {	
		return;
	}
	tracePath(PARENT,PARENT[dest]);
	cout << dest << "("<< BW[dest]<<")"<<"->";
}

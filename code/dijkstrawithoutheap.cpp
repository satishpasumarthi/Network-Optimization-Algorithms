#include "dijkstrawithoutheap.h"

using namespace std;

int DijkstraWithOutHeap::find_maxbw_fringe(const Graph &G1){
	int max_bw = INT_MIN;
	int w,wt,max_v;
	for(int i=1;i<= v_count;i++){
		if(STATUS[i] == FRINGE){
			if(BW[i] > max_bw){
				max_v = i;
				max_bw = BW[i];
			}
		}
	}
	return max_v;
}

void DijkstraWithOutHeap::find_maxbw_path(int src,int dest,const Graph &G1) {
	int u,v,w,wt;
	STATUS[src] = INTREE;
	//Wavefront at source
	for(list<pair<int,int> >::iterator node=G1.edge[src].begin();node!=G1.edge[src].end();node++){
			v = (*node).first;
			wt = (*node).second;
			STATUS[v] = FRINGE;
			PARENT[v] = src;
			BW[v] = wt;
	}
	u = src;
	//Propagate till the destination becomes in-tree
	while(STATUS[dest] != INTREE){
		v = find_maxbw_fringe(G1);
		STATUS[v] = INTREE;
		for(list<pair<int,int> >::iterator node=G1.edge[v].begin();node!=G1.edge[v].end();node++){
			w = (*node).first;
			wt = (*node).second;
			if(STATUS[w] == UNSEEN && BW[w] != INT_MIN) {
				STATUS[w] = FRINGE;
				PARENT[w] = v;
				BW[w]		= BW[v]<wt ? BW[v]:wt;	
			}else if (STATUS[w] == FRINGE && BW[w] < (BW[v]<wt ? BW[v]:wt) && BW[w] != INT_MIN){
				BW[w]	= BW[v]<wt ? BW[v]:wt;
				PARENT[w] = v;
			}
		}
		u = v;
	}

	if(src != dest) {
		cout << "DijkstraWithOutHeap :: "<<BW[dest]<<endl;
	}else{
		cout << "DijkstraWithOutHeap :: INIFINITY"<<endl;
	}

	cout << src <<"->";
	if(src != dest) {
		tracePath(PARENT,PARENT[dest]);
	}
	cout << dest << "("<< BW[dest]<<")\n";
}

void DijkstraWithOutHeap::tracePath(int* PARENT,int dest){
	if (PARENT[dest] == 0) {	
		return;
	}
	tracePath(PARENT,PARENT[dest]);
	cout <<dest<< "("<< BW[dest]<<")"<<"->";
}

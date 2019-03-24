#include "kruskal.h"

void kruskal::find_maxbw_path(int src,int dest,const Graph &G1,HeapSort &HS){

	construct_heap(G1,HS);
	construct_maxst(HS,G1.edges_count);

	BW[src] = INT_MAX;

	run_dfs(src);

	if(src != dest) {
		cout << "Kruskal :: "<<BW[dest]<<endl;
	}else{
		cout << "Kruskal :: INFINITY"<<endl;
	}

	cout << src<<"->";
	if(src != dest) {
		tracePath(PARENT,PARENT[dest]);
	}
	cout << dest << "("<< BW[dest]<<")"<<endl;

}

void kruskal::construct_heap(const Graph &G1,HeapSort &HS){
	//Push all the edges into Heap
	for(int i=1; i<=v_count; i++){
		for(list<pair<int,int> >::iterator node=G1.edge[i].begin(); node!=G1.edge[i].end(); node++){
			if(i < (*node).first){
				//(wt,(v1,v2))
				HS.insertedge_into_heap(make_pair((*node).second,make_pair(i,(*node).first)));
			}
		}
	}
	//cout << "-kruskal- Done inserting into Heap\n";
	//run heapify since we finished pushing all edges into Heap
	HS.buildHeapedgeSort(1);
}

void kruskal::construct_maxst(HeapSort &HS,int e_count){
	//cout << "-kruskal- MST construction\n";
	int i = e_count;
	while(i >= 1){
		edge e1 = HS.getmaxedge_from_heap();
		check_cycle(e1.second.first,e1.second.second,e1.first);
		HS.deleteedge_from_heap(1);
		i--;
	}
	//cout << "Done\n";
}

//Find by Path Compression
int kruskal::find_set(int v){
	if (v != UF_PARENT[v]){
		UF_PARENT[v] = find_set(UF_PARENT[v]);
	}
	return UF_PARENT[v];
}

//Union by Rank
void kruskal::union_set(int v1,int v2){
	if (RANK[v1] > RANK[v2]){
		UF_PARENT[v2] = v1;
	}else if (RANK[v1] < RANK[v2]){
		UF_PARENT[v1] = v2;
	}else{
		UF_PARENT[v1] = v2;
		RANK[v2]++;
	}
}

void kruskal::check_cycle(int v1,int v2,int wt){
	int set_v1 = find_set(v1);
	int set_v2 = find_set(v2);
	if(set_v1 != set_v2){
		union_set(set_v1,set_v2);
		tedge[v1].push_back(make_pair(v2,wt));
		tedge[v2].push_back(make_pair(v1,wt));
	}
}

void kruskal::run_dfs(int v){
	//cout << "-kruskal- DFS\n";
	COLOR[v] = GREY;
	for(list<pair<int,int> >::iterator node=tedge[v].begin();node!=tedge[v].end();node++){
		int w = (*node).first;
		int wt = (*node).second;
		int tmp = BW[v] < wt ? BW[v]:wt ;
		if(COLOR[(*node).first] == WHITE){
			BW[w] = BW[w] > tmp ? BW[w]:tmp;
			PARENT[w] = v;
			run_dfs(w);
		}
	}
	COLOR[v] = BLACK;
}

void kruskal::tracePath(int* PARENT,int dest){
	if (PARENT[dest] == 0) {	
		return;
	}
	tracePath(PARENT,PARENT[dest]);
	cout << dest <<"("<< BW[dest]<<")"<<"->";
}

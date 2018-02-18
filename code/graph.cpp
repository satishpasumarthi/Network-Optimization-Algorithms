#include "graph.h"

using namespace std;

void Graph::addEdge(int v1,int v2,int wt){
	//Since the graph is undirected, we need to update either of the vertices
	// v1 [v2,wt]
	// v2 [v1,wt]
	edge[v1].push_back(make_pair(v2,wt));
	edge[v2].push_back(make_pair(v1,wt));
}

void Graph::printGraph(int v){
	for(list<pair<int,int> >::iterator node=edge[v].begin();node!=edge[v].end();node++){
		int	w  = (*node).first; 
		int wt = (*node).second;
		cout <<w<<"("<<wt<<") ";
	}
}

//avg degree of vertex -> 8
void Graph::createSparseGraph(int avg_degree){

	int j,wt;
	edges_count = 0;
	s_edge_count = (v_count*avg_degree)/2;
	
	//creating cycle
	for(int i=1; i <= v_count; i++){
		j = i%v_count+1;//adjacent vertex
		wt = rand()%EDGE_WEIGHT_LIMIT +1;
		int hash = i*j + trunc(pow(abs(i-j)-1,2)/4);
		umap[hash] = 1;
		addEdge(i,j,wt);
		edges_count++;
		degree[i]++;
		degree[j]++;
	}
	
	int counter = 0;
	
	while(counter < (s_edge_count-v_count)){
		int u = rand()%v_count+1;
		int v = rand()%v_count+1;
		int wt = rand()%EDGE_WEIGHT_LIMIT +1;
		int hash = u*v + trunc(pow(abs(u-v)-1,2)/4);
		if (umap.find(hash)  == umap.end() && u != v){
			//cout << "-SparseGraph- Adding Pairs\n";
			umap[hash] =1;
			addEdge(u,v,wt);
			counter++;
			edges_count++;
			degree[u]++;
			degree[v]++;
		}
	}
	
	int s_sum = 0;
	for (int i=1;i<=v_count;i++){
		s_sum += degree[i];
	}
	sg_avg_degree = s_sum/v_count;
}

void Graph::createDenseGraph(float prob){
	vertices_count = v_count;
	edges_count = 0;

	for(int i=1; i <= v_count; i++){
		int j = i%v_count+1;//adjacent vertex
		int wt = rand()%EDGE_WEIGHT_LIMIT +1;
		int hash = i*j + trunc(pow(abs(i-j)-1,2)/4);
		umap[hash] = 1;
		addEdge(i,j,wt);
		edges_count++;
		degree[i]++;
		degree[j]++;
	}

	int counter = 0;

	//20% neighbors 
	for (int u = 1; u<= v_count; u++){
		for (int v = 1; v<= v_count; v++){
			double prediction = (double) rand()/RAND_MAX;
			int hash = u*v  + trunc(pow(abs(u-v)-1,2)/4);
			if ((prediction < 0.5*prob ) && (u!=v) && (umap.find(hash) == umap.end()) ){
				int wt = rand()%EDGE_WEIGHT_LIMIT+1;
				umap[hash] =1;
				addEdge(u,v,wt);
				edges_count++;
				degree[u]++;
				degree[v]++;
			}
		}
	}

	//average degree calculation
	int d_sum = 0;
	for (int i=1;i<=v_count;i++){
		d_sum += degree[i];
	}
	dg_avg_degree = d_sum/v_count;
	d_edge_count = edges_count;
}


void Graph::run_sccdfs(int v){
	vcolor[v] = GREY;
	scc[v] = cc;
	for(list<pair<int,int> >::iterator node=edge[v].begin();node!=edge[v].end();node++){
		int w = (*node).first;
		if (vcolor[w] == WHITE) run_sccdfs(w);
	}
	vcolor[v] = BLACK;
}

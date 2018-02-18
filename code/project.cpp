#include <iostream> 
#include <limits.h>
#include <time.h>
#include <vector>
#include <list>

//Including my header files
#include "heapforkruskal.h"
#include "maxheap.h"
#include "dijkstrawithoutheap.h"
#include "dijkstrawithheap.h"
#include "kruskal.h"


   ////////////////////////////////////////
  //UIN: 726006526						//
 //S Venkata Satish Kumar Pasumarthi   //
////////////////////////////////////////

using namespace std;

int main() {
	int src,dest;

	//variables for tracking algo run stats
	int dg_dtime,dg_dhtime,dg_ktime;
	int sg_dtime,sg_dhtime,sg_ktime;
	//variables for tracking graph generation stats
	int dg_start_time,dg_end_time,dg_time;
	int sg_start_time,sg_end_time,sg_time;
	
	dg_dhtime=dg_dtime=dg_ktime=dg_time=0;
	sg_dhtime=sg_dtime=sg_ktime=sg_time=0;
	
	int start_time =0; 
	int end_time =0;
	int s_degree;
	float d_degree;
	int s_edges,d_edges;

	s_degree = d_degree = 0;
	s_edges = d_edges = 0;
	//parameters
	int n_vertices = 5000;
	int avg_degree = 8;
	int n_sparsegraphs = 5;
	int n_densegraphs = 5;
	int n_pairs = 5;
	float prob  = 0.2;

	srand(time(NULL));
	/////////////////////////
	//Sparse Graph Testing//
	////////////////////////
	for (int i=1;i <= n_sparsegraphs ; i++) {
		sg_start_time = clock();		
		Graph* SG;
		SG = new Graph(n_vertices);
		SG->createSparseGraph(avg_degree);
		sg_end_time = clock();		
		sg_time += sg_end_time-sg_start_time;
		s_degree += SG->sg_avg_degree;		
		s_edges  += SG->s_edge_count;		
		cout << "========================================\n";
		cout << "Random Sparse Graph: "<<i<<endl;
		cout << "========================================\n";
		for (int j = 1; j <= n_pairs ; j++) {
			src  = rand()%n_vertices+1;
			dest = rand()%n_vertices+1;
			cout << "------------------------------------------\n";
			cout << "Source & Destination Pair"<<j<<": ("<<src<<","<<dest<<")"<<endl;
			cout << "------------------------------------------\n";

			start_time = clock();
			DijkstraWithOutHeap* D;//Dijkstra without heap
			D = new DijkstraWithOutHeap(n_vertices);
			D->find_maxbw_path(src,dest,*SG);
			end_time = clock();
			sg_dtime += end_time-start_time;
			
			cout << "--------\n";
			MaxHeap* x;
			x = new MaxHeap(n_vertices);
			start_time = clock();
			DijkstraWithHeap* DH; //Dijkstra with heap
			DH = new DijkstraWithHeap(n_vertices);
			DH->find_maxbw_path2(src,dest,*SG,*x);
			end_time = clock();
			sg_dhtime += end_time-start_time;

			cout << "--------\n";
			HeapSort* H;
			H = new HeapSort(SG->edges_count);
			start_time = clock();
			kruskal* K; 
			K = new kruskal(n_vertices);
			K->find_maxbw_path(src,dest,*SG,*H);
			end_time = clock();
			sg_ktime += end_time-start_time;
		}
	}	
	cout << "\n-------Done testing on Sparse Graph------\n\n";
	
	//Densee Graph Testing
	for (int i=1;i <= n_densegraphs ; i++) {
		cout << "========================================\n";
		cout << "Random Dense Graph: "<<i<<endl;
		cout << "========================================\n";
		dg_start_time = clock();		
		Graph* DG;
		DG = new Graph(n_vertices);
		DG->createDenseGraph(prob);
		dg_end_time = clock();
		dg_time += dg_end_time-dg_start_time;
		d_degree += DG->dg_avg_degree;		
		d_edges  += DG->d_edge_count;		
		
		for (int j = 1; j <= n_pairs ; j++) {
			src  = rand()%n_vertices+1;
			dest = rand()%n_vertices+1;
			cout << "------------------------------------------\n";
			cout << "Source & Destination Pair"<<j<<": ("<<src<<","<<dest<<")"<<endl;
			cout << "------------------------------------------\n";

			start_time = clock();
			DijkstraWithOutHeap* D;//Dijkstra without heap
			D = new DijkstraWithOutHeap(n_vertices);
			D->find_maxbw_path(src,dest,*DG);
			end_time = clock();
			dg_dtime += end_time-start_time;

			cout << "--------\n";
			MaxHeap* x;
			x = new MaxHeap(n_vertices);
			start_time = clock();
			DijkstraWithHeap* DH; //Dijkstra with heap
			DH = new DijkstraWithHeap(n_vertices);
			DH->find_maxbw_path2(src,dest,*DG,*x);
			end_time = clock();
			dg_dhtime += end_time-start_time;

			cout << "--------\n";
			HeapSort* H;
			H = new HeapSort(DG->edges_count);
			start_time = clock();
			kruskal* K;//Kruskal 
			K = new kruskal(n_vertices);
			K->find_maxbw_path(src,dest,*DG,*H);
			end_time = clock();
			dg_ktime += end_time-start_time;
		}
	}
	cout << "-------Done testing on Dense Graph------\n\n";

	//Print the runtime stats
	cout << "\n------------------------------------\n";	
	cout << "RunTime profiling for Sparse Graphs:\n";
	cout << "------------------------------------\n";
	cout << "Avg. Degree			: "<<s_degree/n_sparsegraphs << endl;
	cout <<	"Edge Count			: "<<s_edges/n_sparsegraphs<<endl;
	cout << "Sprase Graph generation		: "<<sg_time/(double(CLOCKS_PER_SEC)*n_sparsegraphs)*1000<<" ms\n"<<endl;
	cout << "Dijkstra without heap		: "<<sg_dtime/(double(CLOCKS_PER_SEC)*n_sparsegraphs*n_pairs)*1000<<" ms"<<endl;
	cout << "Dijkstra with    heap 		: "<<sg_dhtime/(double(CLOCKS_PER_SEC)*n_sparsegraphs*n_pairs)*1000<<" ms"<<endl;
	cout << "Krushkal 			: "<<sg_ktime/(double(CLOCKS_PER_SEC)*n_sparsegraphs*n_pairs)*1000<<" ms"<<endl;
	cout << "------------------------------------\n";
	cout << "\n------------------------------------\n";	
	cout << "RunTime profiling for Dense Graphs:\n";
	cout << "------------------------------------\n";
	cout << "Avg. Degree			: "<< d_degree/n_densegraphs << endl;
	cout <<	"Avg. Edge Count			: "<<(double) d_edges/n_densegraphs<<endl;
	cout << "Dense Graph generation		: "<<dg_time/(double(CLOCKS_PER_SEC)*n_densegraphs)*1000<<" ms\n"<<endl;
	cout << "Dijkstra without heap		: "<<dg_dtime/(double(CLOCKS_PER_SEC)*n_densegraphs*n_pairs)*1000<<" ms"<<endl;
	cout << "Dijkstra with    heap		: "<<dg_dhtime/(double(CLOCKS_PER_SEC)*n_densegraphs*n_pairs)*1000<<" ms"<<endl;
	cout << "Krushkal			: "<<dg_ktime/(double(CLOCKS_PER_SEC)*n_densegraphs*n_pairs)*1000<<" ms"<<endl;
	cout << "------------------------------------\n";
	cout << "\n------------------------------------\n";	

	return 0;	
}

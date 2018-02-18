//Graph Vertices are named as 1,2,3,....n
//VERT[i] gives the name of the vertex
//POS[v] gives the Position of the vertex v in V array - used for deletion
//BW[v] gives the bandwidth of vertex v ( v = VERT[i])
#ifndef HEAPFORKRUSKAL_H
#define HEAPFORKRUSKAL_H

#include <utility>
#include <iostream>
using namespace std;

typedef std::pair<int, std::pair<int,int> > evv_pair; //(wt,(v1,v2)) tuple definition

class HeapSort {
    private:
        int size;
		int index;   	
        int edge_count; //counter for edges
    public:
    	std::pair<int, std::pair<int,int> > *edge_vector;
		
        HeapSort(int e_count){
			index       = 1; //variable for indexing
			size        = 0; //size of heap
            edge_count  = e_count;
			edge_vector = new evv_pair [e_count+1]; //dynamic memory allocation
		};

        int my_max(int,int);
        void my_swap(evv_pair&,evv_pair&);
        void deleteedge_from_heap(int);
        void insertedge_into_heap(evv_pair);
        std::pair<int, std::pair<int,int> > getmaxedge_from_heap();
        void buildHeapedgeSort(int);

        ~HeapSort(){
            delete edge_vector;
        };
};
#endif

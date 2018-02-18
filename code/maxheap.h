//Graph Vertices are named as 1,2,3,....n
//VERT[i] gives the name of the vertex
//POS[v] gives the Position of the vertex v in V array - used for deletion
//BW[v] gives the bandwidth of vertex v ( v = VERT[i])
#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
using namespace std;
class MaxHeap {
    private:
		int vertex;
		int* VERT;	//Vertices array
		int* POS;	//Array to track position of vertices
		int* BW;	//Array to store BW of the vertices
    public:
    	int size;
		int index;
		MaxHeap(int VERTICES_COUNT){
			index 	= 1; //variable for indexing the heap 
			size	= 0; //size of heap
			VERT	= new int [VERTICES_COUNT+1];
			POS		= new int [VERTICES_COUNT+1];
			BW 		= new int [VERTICES_COUNT+1];
		}
		int my_max(int,int);
		void my_swap(int&,int&);
        int getmax_from_heap();
        int getmaxvertex_from_heap();
        void delete_from_heap(int);
        void insert_into_heap(int,int);
        void buildmaxheap(int);
        ~MaxHeap(){};
};
#endif

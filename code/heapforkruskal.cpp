#include "heapforkruskal.h"

using namespace std;
//Graph Vertices are named as 1,2,3,....n
//edge_vector[i] gives the name of the vertex
//POS[v] gives the Position of the vertex v in V array - used for deletion
//BW[v] gives the bandwidth of vertex v ( v = edge_vector[i])

int HeapSort::my_max(int a,int b){
	return ( a > b ? a:b );
}

void HeapSort::my_swap(evv_pair& a,evv_pair& b){
	evv_pair c;
	c = a;
	a = b;
	b = c;
}

void HeapSort::buildHeapedgeSort(int i) {
	//Push the max element to the top
	if(i > 1 && edge_vector[i].first > edge_vector[(int)i/2].first) {
		while (i != 1 && edge_vector[(int) i/2].first < edge_vector[i].first){
			 my_swap(edge_vector[i],edge_vector[(int) i/2]);
			i = (int) i/2;
		}
	}//Push elements down 
	else if (i <= (int) size/2 && edge_vector[i].first < my_max(edge_vector[2*i].first,edge_vector[2*i+1].first)) { 
		while (i <= (int) size/2 && edge_vector[i].first < my_max(edge_vector[2*i].first,edge_vector[2*i+1].first)){
			if(edge_vector[2*i].first > edge_vector[2*i+1].first){
				 my_swap(edge_vector[i],edge_vector[2*i]);
				i = 2*i;
			}else{
				 my_swap(edge_vector[i],edge_vector[2*i+1]);
				i = 2*i+1;
			}
		}
	}
}

//subroutine to insert edge into heap
void HeapSort::insertedge_into_heap(evv_pair edge_vect){
	//Check if the array size is full
	if(size == edge_count) {
		return ;
	}
	//inserting key at the last
	size++;
	index = size;
	edge_vector[index] = edge_vect;
	buildHeapedgeSort(size);
}

//sub-routine to delete the element from heap
void HeapSort::deleteedge_from_heap(int v){
	edge_vector[v]= edge_vector[size];
	size--;
	buildHeapedgeSort(v);
}

//sub-routine to return the edge with max bw
std::pair<int, std::pair<int,int> > HeapSort::getmaxedge_from_heap(){
	//Error out when the size is 0
	if(size > 0) { 
		return edge_vector[1];
	}
}
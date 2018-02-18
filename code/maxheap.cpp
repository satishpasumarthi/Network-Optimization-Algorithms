#include "maxheap.h"

using namespace std;
//Graph Vertices are named as 1,2,3,....n
//VERT[i] gives the name of the vertex
//POS[v] gives the Position of the vertex v in V array - used for deletion
//BW[v] gives the bandwidth of vertex v ( v = VERT[i])
int MaxHeap::my_max(int a,int b){
	return (a>b ? a:b);
}

void MaxHeap::my_swap(int& a,int& b){
	int c;
	c = a;
	a = b;
	b = c;
}

void MaxHeap::buildmaxheap(int i) {
	//Push the max element to the top
	if(i > 1 && BW[VERT[i]] > BW[VERT[(int)i/2]]) {
		while (i > 1 && BW[VERT[i]] > BW[VERT[(int) i/2]] ){
			 my_swap(VERT[i],VERT[(int) i/2]);
			POS[VERT[i]] = i;
			POS[VERT[(int) i/2]] =(int) i/2;
			i = (int) i/2;
		}
	}//Push elements down 
	else if (i <= (int) size/2 && BW[VERT[i]] < my_max(BW[VERT[2*i]],BW[VERT[2*i+1]])) { 
		while (i <= (int) size/2 && BW[VERT[i]] < my_max(BW[VERT[2*i]],BW[VERT[2*i+1]])){
			if(BW[VERT[2*i]] > BW[VERT[2*i+1]]){
				 my_swap(VERT[i],VERT[2*i]);
				POS[VERT[i]]= i;
				POS[VERT[2*i]] = 2*i;
				i = 2*i;
			}else{
				 my_swap(VERT[i],VERT[2*i+1]);
				POS[VERT[i]]= i;
				POS[VERT[2*i+1]] = 2*i+1;
				i = 2*i+1;
			}
		}
	}
}

//sub-routine for heap insertion
void MaxHeap::insert_into_heap(int v,int bw){
	//Check if the array size is full
	//if(size == VERTICES_COUNT) {
	//	return ;
	//}
	//inserting key at the last
	size++;
	VERT[size] = v;
	POS[v] = size;
	BW[v] = bw;
	buildmaxheap(size);
}

void MaxHeap::delete_from_heap(int v){
	int i = POS[v];
	VERT[i] = VERT[size];
	POS[VERT[size]] = size;
	POS[VERT[i]] = i;
	size--;
	buildmaxheap(i);
}

int MaxHeap::getmax_from_heap(){
	//Error out when the size is 0
	if(size <= 0) {
		return -1;
	}else{
		//Return the first vertex 
		return BW[VERT[1]];
	}
}

int MaxHeap::getmaxvertex_from_heap(){
	//Error out when the size is 0
	if(size <= 0) {
		return -1;
	}else{
		//Return the first vertex 
		return VERT[1];
	}
}

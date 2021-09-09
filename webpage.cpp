#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include "jrbgraph.hpp"

void menu(){
	printf("1. Doc ban do\n");
	printf("2. In danh sach ke\n");
	printf("3. Result\n");
	printf("4. Tim duong di ngan nhat\n");
	printf("5. Tim duong di bo ngan nhat\n");
	printf("6. Thoat\n");
}
void readfile(char* filename, Graph g){
	int matrix[30][30]={0};
	int c, vernum, edgenum, id, ver1, ver2;
	float weight;
	char name[30];
	FILE* fin=fopen(filename,"r");
	if(fopen==NULL){
		printf("can't open this file\n");
		return ;
	}
				fscanf(fin,"%d", &vernum);
				fscanf(fin,"%d", &edgenum);
				for(int i=0; i<edgenum; i++){
					fscanf(fin,"%d", &ver1);
					fscanf(fin,"%d", &ver2);
					fscanf(fin,"%f", &weight);
					printf("%d %d %f\n",ver1,ver2,weight);
					addEdge_int(g, ver1, ver2, weight);
					addEdge_int(g, ver2, ver1, weight);
					matrix[ver1-1][ver2-1]=weight;
					matrix[ver2-1][ver1-1]=weight;
				}
				printf("\n["); 
				for(int i=0; i<vernum; i++){
					for(int j=0; j<vernum; j++){
						printf("%d  ", matrix[i][j]);
					}
					printf("\n");
				}
				printf("]\n");
				fclose(fin);
}
void danhsachke(Graph g){
	int output[10];
	int n;
	for(int i=1; i <= 8; i++){
		printf("Castle %d: ", i);
		n = getAdjacentVertices_int(g, i, output);
		for(int j=0; j<n; j++){
			printf("%d ", output[j]);
		}
		printf("\n");
	}
}
void result(Graph g){
	int n, check = 0, max=0;
	int output[10];
	for(int i=1; i <= 8; i++){
		check = 0;
		n = getAdjacentVertices_int(g, i, output);
		if(max < n) max = n;
		for(int j=0; j<n; j++){
			if(getEdgeWeight_int(g,  i, output[j]) >= 50) check++;
		}

		if(check == n) printf("%d ", i);
	}
	printf("\n");
	for(int i=1; i <= 8; i++){
		n = getAdjacentVertices_int(g, i, output);
		if(n == max){
			printf("%d ", i);
		}		
	}
	printf("\n");
}
void bo_dijkstra_int(Graph graph, int start, int end){
	typedef pair<int, int> pi;	
	priority_queue<pi, vector<pi>, greater<pi> > Q;
	
	map<int,int> dist;
	dist.insert(pair<int,int>(start,0));
	
	JRB ptr;
	jrb_traverse(ptr, graph){
		if(ptr->key.i == start) continue;
		cout << ptr->key.i<< endl;
//		Q.push(pair<int, int> (999,ptr->key.i));
		dist.insert(pair<int,int>(ptr->key.i, 999));
	}
	Q.push(pair<int, int>(0,start));

	unordered_set <int> visitedList ;
	map<int, int> pre;
	pre.insert(pair<int, int>(start, -1));
	
	cout << endl;
	int v;
		

	while(!Q.empty()){
		pair<int, int> top = Q.top();
		cout << top.second << "-";
		cout << dist[top.second] << endl;
		v = top.second;
		visitedList.insert(v);
		Q.pop();	
		
		map<int,int>::iterator itr;
		map<int,int>::iterator itr2;
		int output[10];	
		int n = getAdjacentVertices_int(graph, v, output);
			for (int i=0; i<n; i++) {
				if(getEdgeWeight_int(graph,v,output[i]) >= 50){
				
				if(visitedList.find(output[i]) == visitedList.end()   ){
						if(dist[output[i]] > dist[v]+getEdgeWeight_int(graph,v,output[i]))
						
				{
					
					itr = dist.find(output[i]);
					itr->second = dist[v]+getEdgeWeight_int(graph,v,output[i]);
				//	cout << itr->second << endl;
					Q.push(make_pair(dist[output[i]], output[i]));	
					itr2 = pre.find(output[i]);
					if(itr2 != pre.end()){
						itr2->second= v;
					}
					else{
//						cout << v << "-";
//		                cout << output[i] << endl;
						pre.insert(pair<int, int>(output[i], v));
					}
				}
				}
}
			}
	}

	cout << endl;

	int temp = end;
	stack<int> rev;
	rev.push(end);


	if(dist[temp]== 999){
		printf("ROUTE NOT FOUND");
	}
	else{
		while(end != start){
		end = pre[end];
		rev.push(end);
	}
	printf("Quang duong tu %d den %d la: %d\n", start, temp, dist[temp]);
		cout << rev.top() ;
		rev.pop();
		while(!rev.empty()){
			cout << " --> " << rev.top() ;
			rev.pop();
		}
	} 
}

int main(){
	int c;
	Graph g = createGraph();
	menu();
	do{
		printf("\nNhap chuc nang tuong ung: ");
		scanf("%d", &c);
		switch(c){
			case 1:{
				//readfile("C:\\Users\\asus\\Desktop\\phongkien.txt", g);
				readfile_undirectedGraph("C:\\Users\\asus\\Desktop\\phongkien.txt", g);
				break;
			}
			case 2:{
				danhsachke(g);
				break;
			}
			case 3:{
				result(g);
				break;
			}
			case 4:{
				dijkstra_int(g,1,5);
				break;
			}
			case 5:{
				bo_dijkstra_int(g, 4, 8);
				break;
			}
			case 6:{
				break;
			}
			case 7:{ //hidden function
				PRIM_int(g,1);
				break;
			}
			case 8:{
				BFS_int(g,5);
				break;
			}
			case 9:{
				DFS_int(g,5);
				break;
			}
		}
	} while(c!=6);
}

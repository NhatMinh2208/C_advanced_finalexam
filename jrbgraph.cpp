#include "jrbgraph.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <iterator>
#include <map>
#include <stack>
#include <bits/stdc++.h>

#define MAXVAL 9999

using namespace std;

Graph createGraph()
{
	Graph newGraph = make_jrb();
	return newGraph;
}
Graphs createGraphs(){

	Graphs newGraph;
	newGraph = (Graphs)malloc(sizeof(struct graph));
	if(newGraph == NULL) return NULL;
	newGraph->indgrees = make_jrb();
	newGraph->outdgrees = make_jrb();
	return newGraph;

}
void addVertex_int(Graph graph, int v){
	JRB bn = jrb_find_int(graph, v);
	if(bn == NULL){
		JRB tree = make_jrb(); 
		jrb_insert_int(graph, v, new_jval_v((void*)tree));
	}
}
void addVertex_str(Graph graph, char* v){
	JRB bn = jrb_find_str(graph, v);
	if(bn == NULL){
		JRB tree = make_jrb(); 
		jrb_insert_str(graph, strdup(v), new_jval_v(tree));
	}	
}

void addEdge_int(Graph graph, int v1, int v2, float weight)
{
	// do thi vo huong nen can co (v1 v2) va (v2 v1)
	// them canh v1 v2
	// check xem da co dinh tren cay chua
	JRB bn = jrb_find_int(graph, v1);
	if(bn==NULL) // neu chua co thi them vao
	{		
		JRB tree = make_jrb(); 
		jrb_insert_int(tree, v2, new_jval_f(weight));
		jrb_insert_int(graph, v1, new_jval_v((void*)tree));
	}
	else // dinh v1 da co tren cay
	{
		//node = jrb_find_int(g, v1);
		// them canh v1 v2
		JRB tree = (JRB) jval_v(bn->val);
		jrb_insert_int(tree, v2, new_jval_f(weight));			
	}
	
	// them canh v2 v1
//	bn = jrb_find_int(graph, v2);
//	if(bn==NULL) // neu chua co thi them vao
//	{
//		JRB tree = make_jrb();
//		jrb_insert_int(tree, v1, new_jval_f(weight));
//		jrb_insert_int(graph, v2, new_jval_v(tree));
//	}
//	else  // da co dinh v2 thi chi them canh v2 v1
//	
//		JRB tree = (JRB) jval_v(bn->val);
//		jrb_insert_int(tree, v1, new_jval_f(weight));
//	}
}

void addEdge_str(Graph graph, char* v1, char* v2, int weight)
{
	// do thi vo huong nen can co (v1 v2) va (v2 v1)
	// them canh v1 v2
	// check xem da co dinh tren cay chua
	JRB bn = jrb_find_str(graph, v1);
	if(bn==NULL) // neu chua co thi them vao
	{		
		JRB tree = make_jrb(); 
		jrb_insert_str(tree, strdup(v2), new_jval_i(weight));
		jrb_insert_str(graph, strdup(v1), new_jval_v(tree));
	}
	else // dinh v1 da co tren cay
	{
		//node = jrb_find_int(g, v1);
		// them canh v1 v2
		JRB tree = (JRB) jval_v(bn->val);
		jrb_insert_str(tree, strdup(v2), new_jval_i(weight));			
	}
	// them canh v2 v1
	// check xem da co dinh tren cay chua
//	bn = jrb_find_str(graph, v2);
//	if(bn==NULL) // neu chua co thi them vao
//	{		
//		JRB tree = make_jrb(); 
//		jrb_insert_str(tree, strdup(v1), new_jval_i(weight));
//		jrb_insert_str(graph, strdup(v2), new_jval_v(tree));
//	}
//	else // dinh v2 da co tren cay
//	{
//		// them canh v1 v2
//		JRB tree = (JRB) jval_v(bn->val);
//		jrb_insert_str(tree, strdup(v1), new_jval_i(weight));			
//	}
}

void addEdgenon_int(Graph graph, int v1, int v2, float weight)
{
	// do thi vo huong nen can co (v1 v2) va (v2 v1)
	// them canh v1 v2
	// check xem da co dinh tren cay chua
	JRB bn = jrb_find_int(graph, v1);
	if(bn==NULL) // neu chua co thi them vao
	{		
		JRB tree = make_jrb(); 
		jrb_insert_int(tree, v2, new_jval_f(weight));
		jrb_insert_int(graph, v1, new_jval_v((void*)tree));
	}
	else // dinh v1 da co tren cay
	{
		//node = jrb_find_int(g, v1);
		// them canh v1 v2
		JRB tree = (JRB) jval_v(bn->val);
		jrb_insert_int(tree, v2, new_jval_f(weight));			
	}
	
	 //them canh v2 v1
	bn = jrb_find_int(graph, v2);
	if(bn==NULL) // neu chua co thi them vao
	{
		JRB tree = make_jrb();
		jrb_insert_int(tree, v1, new_jval_f(weight));
		jrb_insert_int(graph, v2, new_jval_v(tree));
	}
	else  // da co dinh v2 thi chi them canh v2 v1
	{
		JRB tree = (JRB) jval_v(bn->val);
		jrb_insert_int(tree, v1, new_jval_f(weight));
	}
}

void addEdgenon_str(Graph graph, char* v1, char* v2, int weight)
{
	// do thi vo huong nen can co (v1 v2) va (v2 v1)
	// them canh v1 v2
	// check xem da co dinh tren cay chua
	JRB bn = jrb_find_str(graph, v1);
	if(bn==NULL) // neu chua co thi them vao
	{		
		JRB tree = make_jrb(); 
		jrb_insert_str(tree, strdup(v2), new_jval_i(weight));
		jrb_insert_str(graph, strdup(v1), new_jval_v(tree));
	}
	else // dinh v1 da co tren cay
	{
		//node = jrb_find_int(g, v1);
		// them canh v1 v2
		JRB tree = (JRB) jval_v(bn->val);
		jrb_insert_str(tree, strdup(v2), new_jval_i(weight));			
	}
	// them canh v2 v1
	 //check xem da co dinh tren cay chua
	bn = jrb_find_str(graph, v2);
	if(bn==NULL) // neu chua co thi them vao
	{		
		JRB tree = make_jrb(); 
		jrb_insert_str(tree, strdup(v1), new_jval_i(weight));
		jrb_insert_str(graph, strdup(v2), new_jval_v(tree));
	}
	else // dinh v2 da co tren cay
	{
		// them canh v1 v2
		JRB tree = (JRB) jval_v(bn->val);
		jrb_insert_str(tree, strdup(v1), new_jval_i(weight));			
	}
}

int getAdjacentVertices_str (Graph graph, char* v, char output[10][10])
{
	JRB node = jrb_find_str(graph, v);
	JRB tree = (JRB) jval_v(node->val);
	int total = 0;   
	jrb_traverse(node, tree)
	{
		strcpy(output[total],jval_s(node->key));
		total++;
	}    
	return total;
}

int getAdjacentVertices_int (Graph graph, int v, int* output)
{
	JRB node = jrb_find_int(graph, v);
	JRB tree = (JRB) jval_v(node->val);
	int total = 0;   
	jrb_traverse(node, tree)
	{
		output[total++] = jval_i(node->key);
	}    
	return total;
}

list<string> getAllVertexes(Graph graph)
{
	list<string> vertexes;
	for(JRB ptr = jrb_first(graph); ptr != jrb_nil(graph); ptr = jrb_next(ptr))
	{
		vertexes.push_back(jval_s(ptr->key));
	}
	return vertexes;
}

unordered_set<string> getAllVertexe(Graph graph){
	unordered_set<string> vertexes;
	for(JRB ptr = jrb_first(graph); ptr != jrb_nil(graph); ptr = jrb_next(ptr))
	{
		vertexes.insert(jval_s(ptr->key));
	}
	return vertexes;
}
void BFS_str(Graph graph, char* start)
{
	queue<string> Q;
	Q.push(start);
	char v[10];
	unordered_set <string> visitedList ;
	
	visitedList.insert(start);
	
	while(!Q.empty())
	{		
		strcpy(v, (Q.front()).c_str());
		printf("%5s, ", v);
		Q.pop();
		char output[10][10];
		int n = getAdjacentVertices_str (graph, v, output);
		for (int i=0; i<n; i++) {
			if(visitedList.find(output[i]) == visitedList.end())
			{
				Q.push(output[i]);
				visitedList.insert(output[i]);
			}	
		}
	}
}
void BFS_int(Graph graph, int start){
	queue<int> Q;
	Q.push(start);
	int v;
	unordered_set <int> visitedList ;
	
	visitedList.insert(start);
	
	while(!Q.empty())
	{		
		v = Q.front();
		printf("%5d, ", v);
		Q.pop();
		int output[10];
		int n = getAdjacentVertices_int(graph, v, output);
		for (int i=0; i<n; i++) {
			if(visitedList.find(output[i]) == visitedList.end())
			{
				Q.push(output[i]);
				visitedList.insert(output[i]);
			}	
		}
	}
}
int findcc(Graph graph /*map<string,int>& previsited, map<string,int>& postvisited*/){
	int cc=0;
	int *clock; //
	*clock=0;//
	char* temp;
	unordered_set<string> visited;
	unordered_set<string> vertexes=getAllVertexe(graph);
	for (auto itr = vertexes.begin(); itr != vertexes.end(); ++itr) {
		strcpy(temp,(*itr).c_str());
    	if(visited.find(temp)==visited.end()){
			cc++;
			explore(graph, temp , visited/*, previsited, postvisited, clock*/); //
		}
	}
	
	return cc;
}
void explore(Graph graph, char* v, unordered_set<string>& visited/*,  map<string,int>& previsited, map<string,int>& postvisited, int* clock*/){
	visited.insert(v);
	JRB node = jrb_find_str(graph, v);
	JRB tree = (JRB) jval_v(node->val);   
	jrb_traverse(node, tree)
	{
		if(visited.find(node->key.s)==visited.end()){
//			*clock=*clock+1;//
//			previsited[v]=*clock;//
			explore(graph,node->key.s,visited/*,previsited,postvisited,clock*/); //
//			*clock=*clock+1;//
//			postvisited[v]=*clock;//
		}
	}    
	
}


void DFS_str(Graph graph, char* start)
{
	stack<string> S;
	S.push(start);
	char v[10];
	// gan nhan cac dinh la chua duoc tham
	unordered_set <string> notvisitedList ;
	for(JRB ptr = jrb_first(graph); ptr != jrb_nil(graph); ptr = jrb_next(ptr))
	{
		notvisitedList.insert(jval_s(ptr->key));
	}
	
	int timecount = 1;
	// dinh bat dau chuyen thanh dang tham
	notvisitedList.erase(start);
	printf("Bat dau tham %5s tai %d\n",start, timecount);
	
	while(!S.empty())
	{
		timecount++;
		// xet dinh v o dau stack		
		strcpy(v, (S.top()).c_str());
		//printf("%5s, ", v);
		char output[10][10];
		
		// kiem tra co dinh nao ke voi v ma chua tham
		int n = getAdjacentVertices_str (graph, v, output);
		int check = 0;
		for (int i=0; i<n; i++) {
			if(notvisitedList.find(output[i]) != notvisitedList.end())
			{
				S.push(output[i]);
				notvisitedList.erase(output[i]);
				printf("Bat dau tham %5s tai %d\n", output[i], timecount);
				check = 1;
				break;
			}	
		}
		if(check==0) // khong ton tai dinh nao ma chua tham
		{
			S.pop();
			printf("Ket thuc tham %5s tai %d\n", v, timecount);
		}
	}
}
void DFS_int(Graph graph, int start){
	stack<int> S;
	S.push(start);
	int v;
	// gan nhan cac dinh la chua duoc tham
	unordered_set <int> notvisitedList;
	for(JRB ptr = jrb_first(graph); ptr != jrb_nil(graph); ptr = jrb_next(ptr))
	{
		notvisitedList.insert(jval_i(ptr->key));
	}
	
	int timecount = 1;
	// dinh bat dau chuyen thanh dang tham
	notvisitedList.erase(start);
	printf("Bat dau tham %5d tai %d\n",start, timecount);
	
	while(!S.empty())
	{
		timecount++;
		// xet dinh v o dau stack		
		v = S.top();
		//printf("%5s, ", v);
		int output[10];
		
		// kiem tra co dinh nao ke voi v ma chua tham
		int n = getAdjacentVertices_int (graph, v, output);
		int check = 0;
		for (int i=0; i<n; i++) {
			if(notvisitedList.find(output[i]) != notvisitedList.end())
			{
				S.push(output[i]);
				notvisitedList.erase(output[i]);
				printf("Bat dau tham %5d tai %d\n", output[i], timecount);
				check = 1;
				break;
			}	
		}
		if(check==0) // khong ton tai dinh nao ma chua tham
		{
			S.pop();
			printf("Ket thuc tham %5d tai %d\n", v, timecount);
		}
	}
}
void dropGraph(Graph graph)
{
	JRB node;
	jrb_traverse(node, graph)
	{
		jrb_free_tree((jrb_node*) jval_v(node->val) );
	}
    
}
int getEdgeWeight_str(Graph graph, char* v1, char* v2)
{
	JRB node = jrb_find_str(graph, v1);
	JRB tree = (JRB) jval_v(node->val);
	int total = 0;   
	jrb_traverse(node, tree)
	{
		if(strcmp(jval_s(node->key),v2)==0)
			return jval_i(node->val);
	}   
	return -1; 
}
float getEdgeWeight_int(Graph graph, int v1, int v2){
	JRB node = jrb_find_int(graph, v1);
	JRB tree = (JRB) jval_v(node->val);
	int total = 0;   
	jrb_traverse(node, tree)
	{
		if(jval_i(node->key)==v2)
			return jval_f(node->val);
	}   
	return -1; 
}

//void dijkstra(Graph graph, char* start, char* end)
//{
//	typedef pair<int, string> pi;
//	
//	priority_queue<pi, vector<pi>, greater<pi> > Q;
//	Q.push(make_pair(0,start));
//	char v[10];
//	unordered_set <string> visitedList ;
//	
//	//map<string, string> preVertexList;
//	//string preVertex = "NaN";
//	
//	while(!Q.empty())
//	{		
//		pair<int, string> top = Q.top();
//		strcpy(v, top.second.c_str());
//		
//		Q.pop();
//		if(visitedList.find(v) != visitedList.end()) continue;
//		//preVertexList[v] = preVertex;
//		//preVertex = v;
//		visitedList.insert(v);
//		int currentWeight = top.first;
//		printf("%5s , total weight %d\n", v, currentWeight);
//		if(strcmp(v,end)==0)
//		{
//			printf("Reach %s\n",end);
//			printf("Total cost: %d\n", currentWeight);
//			/*preVertex = preVertexList[end];
//			while(preVertex.compare("NaN")!=0)
//			{
//				cout<<preVertex<<",";
//				preVertex = preVertexList[preVertex];
//			}*/
//			return;
//		}
//		char output[10][10];
//		int n = getAdjacentVertices_str (graph, v, output);
//		for (int i=0; i<n; i++) {
//			if(visitedList.find(output[i]) == visitedList.end())
//			{
//				int edgeweight = getEdgeWeight_str(graph,v,output[i]);
//				Q.push(make_pair(currentWeight+edgeweight, output[i]));	
//			}	
//		}
//	}
//}

void dijkstra_str(Graph graph, char* start, char* end)
{
	typedef pair<int, string> pi;	
	priority_queue<pi, vector<pi>, greater<pi> > Q;
	
	map<string,int> dist;
	dist.insert(pair<string,int>(start,0));
	
	JRB ptr;
	jrb_traverse(ptr, graph){
		if(strcmp(start, ptr->key.s)==0) continue;
		cout << ptr->key.s<< endl;
//		Q.push(pair<int, string> (MAXVAL,ptr->key.s));
		dist.insert(pair<string,int>(ptr->key.s, MAXVAL));
	}
	Q.push(pair<int, string>(0,start));
	char v[30];
	

	unordered_set <string> visitedList ;
	map<string, string> pre;
	pre.insert(pair<string, string>(start, "start"));
	

	cout << endl;
	
	while(!Q.empty()){
		pair<int, string> top = Q.top();
		cout << top.second << endl;
		cout << dist[top.second] << endl;
		strcpy(v, top.second.c_str());
		visitedList.insert(v);
		Q.pop();	
		
		map<string,int>::iterator itr;
		map<string,string>::iterator itr2;
		char output[10][10];	
		int n = getAdjacentVertices_str (graph, v, output);
			for (int i=0; i<n; i++) {
				if(visitedList.find(output[i]) == visitedList.end()){
						if(dist[output[i]] > dist[v]+getEdgeWeight_str(graph,v,output[i]))
						
				{
					
					itr = dist.find(output[i]);
					itr->second = dist[v]+getEdgeWeight_str(graph,v,output[i]);
				//	cout << itr->second << endl;
					Q.push(make_pair(dist[output[i]], output[i]));	
					itr2 = pre.find(output[i]);
					if(itr2 != pre.end()){
						itr2->second= v;
					}
					else{
						pre.insert(pair<string, string>(output[i], v));
					}
				}
				}
	
			}
	}
	
//

	string endstring = end ;
	string temp=end;

	cout << endl;
	
	stack<string> rev;
	rev.push(endstring);
//	cout << pre[end] << endl;
	if(dist[temp]== MAXVAL){
		printf("ROUTE NOT FOUND");
	}
	
	else{

		while(endstring != start){
			endstring = pre[endstring];
//			printf("surprise mo");
			rev.push(endstring);
		}
		printf("Quang duong tu %s den %s la: %d\n", start, temp.c_str(), dist[temp]);
		cout << rev.top() ;
		rev.pop();
		while(!rev.empty()){
			cout << " --> " << rev.top() ;
			rev.pop();
		}
	}
}

void dijkstra_int(Graph graph, int start, int end){
	typedef pair<int, int> pi;	
	priority_queue<pi, vector<pi>, greater<pi> > Q;
	
	map<int,int> dist;
	dist.insert(pair<int,int>(start,0));
	
	JRB ptr;
	jrb_traverse(ptr, graph){
		if(ptr->key.i == start) continue;
		cout << ptr->key.i<< endl;
//		Q.push(pair<int, int> (MAXVAL,ptr->key.i));
		dist.insert(pair<int,int>(ptr->key.i, MAXVAL));
	}
	Q.push(pair<int, int>(0,start));

	unordered_set <int> visitedList ;
	map<int, int> pre;
	pre.insert(pair<int, int>(start, -1));
	
	cout << endl;
	int v;
	while(!Q.empty()){
		pair<int, int> top = Q.top();

		v = top.second;
		visitedList.insert(v);
		Q.pop();	
		
		map<int,int>::iterator itr;
		map<int,int>::iterator itr2;
		int output[10];	
		int n = getAdjacentVertices_int(graph, v, output);
			for (int i=0; i<n; i++) {
				if(visitedList.find(output[i]) == visitedList.end()){
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
						cout << v << "-";
		                cout << output[i] << endl;
						pre.insert(pair<int, int>(output[i], v));
					}
				}
				}
	
			}
	}
	
	cout << endl;

	int temp = end;
	stack<int> rev;
	rev.push(end);

	if(dist[temp]== MAXVAL){
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
	

void PRIM_str(Graph graph, char* start)
{
	unordered_set <string> Connected, Unconnected;
	int totalweight = 0;
	// them cac dinh tren do thi vao tap chua co tren cay
	for(JRB ptr = jrb_first(graph); ptr != jrb_nil(graph); ptr = jrb_next(ptr))
	{
		Unconnected.insert(jval_s(ptr->key));
	}
	Connected.insert(start);
	Unconnected.erase(start);
	char u[10], c[10], minc[10], minu[10];
	int min;
	while(!Unconnected.empty())
	{
		min = 99999;
		// can tim canh co trogn so nho nhat ma 1 dinh thuoc C  dinh thuoc U
		for (auto itr = Connected.begin(); itr != Connected.end(); ++itr) {
			strcpy(c,(*itr).c_str());
			char output[10][10];
			int n = getAdjacentVertices_str (graph, c, output);
			for (int i=0; i<n; i++) {
				if(Unconnected.find(output[i]) != Unconnected.end())
				{
					int edgeweight = getEdgeWeight_str(graph,c,output[i]);
					if(min>edgeweight)
					{
						min = edgeweight;
						strcpy(minc,c);
						strcpy(minu,output[i]);
					}
				}	
			}
		}	
		printf("them canh (%s,%s), weight %d\n",minu,minc,min);
		// bo sung them canh (minc, minu)
		totalweight = totalweight + min;
		Connected.insert(minu);
		Unconnected.erase(minu);	
	}
	printf("Total weight : %d\n",totalweight);	
}

void PRIM_int(Graph graph, int start)
{
	unordered_set <int> Connected, Unconnected;
	float totalweight = 0;
	// them cac dinh tren do thi vao tap chua co tren cay
	for(JRB ptr = jrb_first(graph); ptr != jrb_nil(graph); ptr = jrb_next(ptr))
	{
		Unconnected.insert(jval_i(ptr->key));
	}
	Connected.insert(start);
	Unconnected.erase(start);

	int u, c, minc, minu;
	float min;
	while(!Unconnected.empty())
	{
		min = MAXVAL;
		// can tim canh co trogn so nho nhat ma 1 dinh thuoc C  dinh thuoc U
		for (auto itr = Connected.begin(); itr != Connected.end(); ++itr) {
			c = *itr;
			int output[10];
			int n = getAdjacentVertices_int(graph, c, output);
			for (int i=0; i<n; i++) {
				if(Unconnected.find(output[i]) != Unconnected.end())
				{
					float edgeweight = getEdgeWeight_int(graph,c,output[i]);
					if(min>edgeweight)
					{
						min = edgeweight;
						minc = c;
						minu = output[i];
					}
				}	
			}
		}	
		printf("them canh (%d,%d), weight %f\n",minu,minc,min);
		// bo sung them canh (minc, minu)
		totalweight = totalweight + min;
		Connected.insert(minu);
		Unconnected.erase(minu);	
	}
	printf("Total weight : %f\n",totalweight);	
}

void readfile_undirectedGraph(char* filename, Graph g){
	int vernum, edgenum, id, ver1, ver2;
	float weight;
	char name[30];
	FILE* fin=fopen(filename,"r");
	if(fin==NULL){
		printf("Can't open this file\n");
		return ;
	}
	fscanf(fin,"%d", &vernum);
	fscanf(fin,"%d", &edgenum);
	for(int i=0; i<edgenum; i++){
		fscanf(fin,"%d", &ver1);
		fscanf(fin,"%d", &ver2);
		fscanf(fin,"%f", &weight);
		printf("%d %d %f\n",ver1,ver2,weight);
		addEdgenon_int(g, ver1, ver2, weight);
	}
	fclose(fin);
}
void readfile_directedGraph(char* filename, Graph g){
		FILE* fin=fopen(filename, "r");
		if(fin == NULL){
			printf("Can't open this file\n");
			return ;
		}
		int n,j=0,k;
		char id[30], id1[30], id2[30];
		char output1[30][30], output2[30][30];
		char temp[30], input[255];
		char name[255];
		printf("\n");
		do{
			fgets(input,255,fin);
			int i=0,k, count=0,check=0;
			while(i < strlen(input))
			{
				int j=i+1;
				while(j<strlen(input) && input[j]!=' ') j++;
				if(j>=strlen(input)) j = strlen(input)-1;
				if(j>i){
					if(check==0){
						for(k=0; k<j-i; k++) id1[k] = input[k+i];
						id1[k] = '\0';
						check=1;
						printf("%s ",id1);
						addVertex_str(g, id1);
					}
					else{
						for(k=0; k<j-i; k++)
						id2[k] = input[k+i];
						id2[k] = '\0';
						printf("%s ",id2);
						addVertex_str(g, id2);
						addEdge_str(g, id1, id2, 1);
						}
					}
						
				i=j+1;
				while(i<strlen(input) && input[i]==' ')i++;
			}		
		printf("\n");
 	}while(!feof(fin));
 	fclose(fin);
}




void showlist(list <string> g)
{
    list <string> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout<<'\t'<<*it;
    cout<<'\n';
}

void showmap_str_str(map<string, string> Map){
		map<string, string>::iterator itr;
		for (itr = Map.begin(); itr != Map.end(); ++itr) {
     	   cout  << itr->first
            << '\t' << itr->second << '\n';
    	}
}

void readfile_mapping(char* filename, map<string, string> &Map){
	int n;
	char name[255];
	char id[30];
	FILE* fin=fopen(filename, "r");
	if(fin == NULL){
		printf("Can't open this file\n");
		return ;
	}
	fscanf(fin,"%d",&n);
		
	for(int i=0;i<n;i++){
		fscanf(fin,"%s",name);
		fscanf(fin,"%s",id);
		Map.insert(pair<string, string>(id, name));
	}
	fclose(fin);
}
void readfile_mapping_ver2(char* filename, map<string, string> &Map){
	int dem=0;
	//cout << "ua";
	FILE* fin=fopen(filename, "r");
	if(fin == NULL){
		printf("Can't open this file\n");
		return ;
	}
	char input[255], key[5], value[255];
	do{
		//if(feof(fin)) break;
			fgets(input,255,fin);
			int i=0,k, count=0,check=0;
			while(i < strlen(input))
			{
				int j=i+1;
				while(j<strlen(input) && input[j]!=' ') j++;
				if(j>=strlen(input)) j = strlen(input)-1;
				if(j>i){
					if(check==0){
						for(k=0; k<j-i; k++) value[k] = input[k+i];
						value[k] = '\0';
						check=1;
						printf("%s ",value); 
					}
					else{
						for(k=0; k<j-i; k++) 
						key[k] = input[k+i];
						key[k] = '\0';
						printf("%s ",key); 
						}
					}
				
		
						
				i=j+1;
				while(i<strlen(input) && input[i]==' ')i++;
			}
			Map.insert(pair<string, string>(key,value));		
		printf("\n");
 	}while(!feof(fin));
 	fclose(fin);
}
void readfile_specialCharacter(char* filename, Graph g){
	char s[30];
    char v[30];
    char e[1000][30];
    int i;
	FILE* f = fopen(filename, "r");
    if(f == NULL) return;
    while(!feof(f))
    {
        fscanf(f, "%s%*c", s);
        if(s[strlen(s) - 1] == ':') 
        {
            strcpy(v, s);
            clean(v);
            i = 0;
        }
        else {
            strcpy(e[i], s);
            clean(e[i]);
            addEdge_str(g, v, e[i], 1);
            i++;
        }
    }
    fclose(f);
}
void adjacencylist_printf_str(Graph g){
	char output[10][10];
	int n;
	JRB ptr;
	jrb_traverse(ptr, g){
		printf("%s: ", ptr->key.s);
		n = getAdjacentVertices_str(g, ptr->key.s, output);
		for(int j=0; j<n; j++){
			printf("%s ", output[j]);
		}
		printf("\n");
	}
}
void clean(char *s)
{
    int i = strlen(s) - 1;
     if(s[i] < 'A' || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z') s[i] = 0;
    while (s[0] == ' ' || s[0] == '\t' || s[0] == '\n')  for(int j = 0; j <strlen(s); j++) s[j] = s[j+1];    
}

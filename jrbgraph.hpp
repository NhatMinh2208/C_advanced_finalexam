#pragma once
#include "jrb.hpp"
#include <list>
#include<string.h>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;
typedef JRB Graph;
typedef struct graph
{
	JRB indgrees;
	JRB outdgrees;
} *Graphs;
//khoi tao
Graph createGraph(); //normal graph
Graphs createGraphs(); //graph with indgree and outdgreee
//them dinh
void addVertex_int(Graph graph, int v);
void addVertex_str(Graph graph, char* v);
//them canh co huong
void addEdge_int(Graph graph, int v1, int v2, float weight);
void addEdge_str(Graph graph, char* v1, char* v2, int weight);
//them canh vo huong
void addEdgenon_int(Graph graph, int v1, int v2, float weight);
void addEdgenon_str(Graph graph, char* v1, char* v2, int weight);
//lay canh ke
int getAdjacentVertices_int (Graph graph, int v, int* output);
int getAdjacentVertices_str (Graph graph, char* v, char output[10][10]);
// tra ve trong so canh v1,v2
int getEdgeWeight_str(Graph graph, char* v1, char* v2); 
float getEdgeWeight_int(Graph graph, int v1, int v2); 
//tra ve cac dinh hien co tren do thi
list<string> getAllVertexes(Graph graph);
unordered_set<string> getAllVertexe(Graph graph);
// duyet do thi theo chieu rong, dinh bat dau start
void BFS_str(Graph graph, char* start);// duyet theo chieu rong
void BFS_int(Graph graph, int start);

void DFS_str(Graph graph, char* start);// duyet theo chieu sau
void DFS_int(Graph graph, int start); 
//xoa do thi
void dropGraph(Graph graph);
//dijkstra
void dijkstra_str(Graph graph, char* start, char* end);
void dijkstra_int(Graph graph, int start, int end);
//prim
void PRIM_str(Graph graph, char* start);
void PRIM_int(Graph graph, int start);
//read file function
void readfile_undirectedGraph(char* filename, Graph g); //vernum edgenum \n  list of edge
void readfile_directedGraph(char* filename, Graph g); //adj list
void readfile_mapping(char* filename, map<string, string> &Map); //know number of vertex
void readfile_mapping_ver2(char* filename, map<string, string> &Map); //dunno number of vertex
void readfile_specialCharacter(char* filename, Graph g);

//support function
void showlist(list <string> g); 
void showmap_str_str(map<string, string> Map);
void adjacencylist_printf_str(Graph g);
void clean(char *s);




//thu vien cua nhat minh
int findcc(Graph graph);
//int findcc(Graph graph, map<string,int>& previsited, map<string,int>& postvisited);
void explore(Graph graph, char* v, unordered_set<string>& visited);
//void explore(Graph graph, char* v, unordered_set<string>& visited,  map<string,int>& previsited, map<string,int>& postvisited, int* clock);







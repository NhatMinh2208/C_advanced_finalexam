#include "jrbgraph.hpp"
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

//int main(){
//	Graph g = createGraph();
//	map<string,string> Map;
//	readfile_mapping_ver2("C:\\Users\\asus\\Desktop\\webpages.txt", Map);
//
////	showlist(getAllVertexes(g));
////	dijkstra_str(g,"2001","2011");
//showmap_str_str(Map);
//}


//int main()
//{
//	int i,n;
//	char output[10][10];
//    Graph g = createGraph();
//    addEdge_str(g, "A", "D", 7);
//	addEdge_str(g, "A", "E", 7);
//	addEdge_str(g, "A", "C", 4);
//	addEdge_str(g, "A", "B", 3);
//	addEdge_str(g, "E", "D", 11);
//	addEdge_str(g, "C", "E", 9);
//	addEdge_str(g, "E", "F", 2);
//	addEdge_str(g, "C", "F", 8);
//	addEdge_str(g, "B", "C", 3);
//	addEdge_str(g, "B", "F", 12);
//	
//	n = getAdjacentVertices_str (g, "A", output);
//    printf("Number of adjacent vertices : %d\n",n);
//    if (n==0) printf("No adjacent vertices of node \n");
//    else {   
//       printf("Adjacent vertices of node A:");
//       for (i=0; i<n; i++) printf("%5s", output[i]);
//    } 
//    printf("\n");
//    PRIM(g,"A");
//    PRIM(g,"E");
//}

//int main()
//{
//	int i,n;
//	char output[10][10];
//    Graph g = createGraph();
//    addEdgenon_str(g, "HNL", "LAX", 2555);
//  //  addEdge_str(g, "LAX", "HNL", 2555);
//	addEdgenon_str(g, "LAX", "SFO", 337);
////	addEdge_str(g, "SFO", "LAX", 337);
//	addEdgenon_str(g, "LAX", "ORD", 1743);
////	addEdge_str(g, "ORD", "LAX", 1743);
//	addEdgenon_str(g, "LAX", "DFW", 1233);
////	addEdge_str(g, "DFW", "LAX", 1233);
//	addEdgenon_str(g, "SFO", "ORD", 1843);
////	addEdge_str(g, "ORD", "SFO", 1843);
//	addEdgenon_str(g, "ORD", "PVD", 849);
////	addEdge_str(g, "PVD", "ORD", 849);
//	
//	addEdgenon_str(g, "ORD", "DFW", 802);
////	addEdge_str(g, "DFW", "ORD", 802);
//	addEdgenon_str(g, "DFW", "LGA", 1387);
////	addEdge_str(g, "LGA", "DFW", 1387);
//	addEdgenon_str(g, "DFW", "MIA", 1120);
////	addEdge_str(g, "MIA", "DFW", 1120);
//	addEdgenon_str(g, "LGA", "PVD", 142);
////	addEdge_str(g, "PVD", "LGA", 142);
//	addEdgenon_str(g, "LGA", "MIA", 1099);
////	addEdge_str(g, "MIA", "LGA", 1099);
//	addEdgenon_str(g, "MIA", "PVD", 1205);
////	addEdge_str(g, "PVD", "MIA", 1205);
//
//    
//	n = getAdjacentVertices_str (g, "LAX", output);
//    printf("Number of adjacent vertices : %d\n",n);
//    if (n==0) printf("No adjacent vertices of node \n");
//    else {   
//       printf("Adjacent vertices of node LAX:");
//       for (i=0; i<n; i++) printf("%5s", output[i]);
//    } 
//    printf("\n");
//    
//    //printf("\nBFS tu HN\n");
//    //BFS(g, "HN");
//    printf("Cac dinh hien co tren do thi: \n");
//    list<string> vertexes = getAllVertexes(g);
//    showlist(vertexes);
//    printf("\n");
//    
//    printf("\nDFS tu HNL\n");
//	DFS(g, "HNL");
////    
//	printf("\nBFS tu HNL\n");
//    BFS(g, "HNL");
//    printf("\nDuong di ngan nhat tu HNL toi PVD\n");
//    dijkstra_str(g,"HNL","PVD");
//	return 0;
//}


//*/
/*
int main()
{
    map<char*,int> first;
  
  //initializing
  first["HN"]=10;
  first["HP"]=20;

   map<char*, int>::iterator it;
   for(it=first.begin(); it!=first.end(); ++it){
      cout << it->first << " => " << it->second << '\n';
   }
}*/

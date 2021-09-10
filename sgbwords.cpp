#include "jrbgraph.hpp"
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

int check(char *a, char *b){
	int k=0;
	for(int i=0;i<6;i++){
		if(a[i]!=b[i]){
			k++;
		}
	}
	if(k==1) return 1;
	else return 0;
}

int check2(char* a, char* b){

	int check[5];
	int dem=0;
	for(int i=0;i<5;i++) check[i]=0;
	for(int i=1;i<5;i++){
		for(int j=0;j<5;j++){
			if(a[i]==b[j] && check[j]==0){
				check[j]=1;
				dem++;
				break;
			}
		}
	}
	if(dem==4) return 1;
	return 0;
} 
//int main(){
//	int canh=0;
//	int k;
//	JRB data = make_jrb();
//	std::fstream op("C:\\Users\\asus\\Desktop\\sgb-words.txt");
//    std::string v;
//    while (!op.eof()) {
//        op >> v;
//        jrb_insert_str(data, strdup(v.c_str()), new_jval_v(NULL));
//    }
//      op.close();
//	Graph g = createGraph();
//	Graph g2= createGraph(); //create a graph nguoc
//	char output[10][10];
//	int n;
//	for(JRB ptr = jrb_first(data); ptr != jrb_nil(data); ptr = jrb_next(ptr)){
//		k=0;
//		for(JRB ptr2 = jrb_next(ptr); ptr2 != jrb_nil(data); ptr2 = jrb_next(ptr2)){
//
//			if(ptr2==ptr){
//				continue;
//			}
//			 if(check(ptr->key.s,ptr2->key.s)){
//				addEdge_str(g, ptr->key.s,ptr2->key.s,1);
////				addEdge_str2(g2, ptr2->key.s,ptr->key.s,1);
//				canh++;
//				k++;
//			}
//
//		}
//		if(k==0) addEdge_str(g, ptr->key.s,"nothing",1);
//	}
//	printf("%d", canh);
//	n = getAdjacentVertices_str (g, "heart", output);
//  	printf("Number of adjacent vertices : %d\n",n);
//    if (n==0) printf("No adjacent vertices of node \n");
//    else {   
//      printf("Adjacent vertices of node graph:");
//      for (int i=0; i<n; i++) printf("%6s", output[i]);
//   } 
//   
////   	printf("%d", canh);
////	n = getAdjacentVertices_str (g2, "graph", output);
////  	printf("Number of adjacent vertices : %d\n",n);
////    if (n==0) printf("No adjacent vertices of node \n");
////    else {   
////      printf("Adjacent vertices of node graph:");
////      for (int i=0; i<n; i++) printf("%6s", output[i]);
////   } 
//
//   	
////   	map<string,int> previsited;
////   	map<string,int> postvisited;
////    printf("\n%d", findcc(g2/*,previsited,postvisited*/));
//	printf("%d", findcc(g));
//}





	
	
//	JRB data = make_jrb();
//	std::fstream op("C:\\Users\\asus\\Desktop\\sgb-words.txt");
//    std::string v;
//    while (!op.eof()) {
//        op >> v;
//        jrb_insert_str(data, strdup(v.c_str()), new_jval_v(NULL));
//    }
//      op.close();
//	Graph g = createGraph();
//	char output[10][10];
//	int n;
//	for(JRB ptr = jrb_first(data); ptr != jrb_nil(data); ptr = jrb_next(ptr)){
//		for(JRB ptr2 = ptr; ptr2 != jrb_nil(data); ptr2 = jrb_next(ptr2)){
//			if(ptr2==ptr){
//				continue;
//			}
//			 if(check(ptr->key.s,ptr2->key.s)){
//				addEdge_str(g, ptr->key.s,ptr2->key.s,1);
//			}
//		}
//		
//	}
//	n = getAdjacentVertices_str (g, "graph", output);
//  	printf("Number of adjacent vertices : %d\n",n);
//    if (n==0) printf("No adjacent vertices of node \n");
//    else {   
//      printf("Adjacent vertices of node graph:");
//      for (int i=0; i<n; i++) printf("%6s", output[i]);
//   } 
//   printf("\n");
//   printf("%d", findcc(g));
//   dijkstra(g,"grape","crazy");
//   
   
   
   
   
   
  
  
   
//	for(JRB ptr = jrb_first(data); ptr != jrb_nil(data); ptr = jrb_next(ptr)){
//		cout<< ptr->key.s << ' ';
//	}
//	for(JRB ptr2 = jrb_first(data); ptr2 != jrb_nil(data); ptr2 = jrb_next(ptr2)){
//		cout<< ptr2->key.s << ' ';
//	}
//	printf("%s",jrb_next(jrb_first(data))->key);
//}
//
//int main() {
//    JRB tree = make_jrb();
//    std::fstream op("C:\\Users\\asus\\Desktop\\sgb-words.txt");
//    std::string v;
//
//    while (!op.eof()) {
//        op >> v;
//        jrb_insert_str(tree, strdup(v.c_str()), new_jval_v(NULL));
//    }
//    
//    op.close();
//
//    for (JRB temp=jrb_first(tree); temp != jrb_nil(tree); temp = jrb_next(temp)) {
//        std::cout << temp->key.s << ' ';
//    }
//    
//    std::cout << '\n';
//    for (JRB temp1=jrb_first(tree); temp1 != jrb_nil(tree); temp1 = jrb_next(temp1)) {
//        std::cout << temp1->key.s << ' ';
//    }
//}
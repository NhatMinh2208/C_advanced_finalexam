//#include<stdio.h> 
//#include<string.h>
//#include<stdlib.h>
//#include "jrbgraph.hpp"
//void menu(){
//	printf("1. In danh sach dinh\n");
//	printf("2. Tim ban than thiet nhat\n");
//	printf("3. Kiem tra quan he bac cau\n");
//	printf("4. Tim ban chung\n");
//	printf("5. Thoat\n");
//}
//void readfile(char* filename, Graph g, map<int, string> &friends){
//	int c, vernum, edgenum, id, ver1, ver2;
//	float weight;
//	char name[30];
//	FILE* fin=fopen(filename,"r");
//	if(fopen==NULL){
//		printf("can open this file\n");
//		return ;
//	}
//				fscanf(fin,"%d", &vernum);
//				fscanf(fin,"%d", &edgenum);
//				for(int i=0; i<vernum; i++){
//					fscanf(fin,"%d", &id);
//					fscanf(fin, "%s", name);
//					printf("%d %s\n",id,name);
//					friends.insert(pair<int,string>(id,name));
//					JRB tree = make_jrb(); 
//					jrb_insert_int(g, id , new_jval_v(tree));
//				}
//				for(int i=0; i<edgenum; i++){
//					fscanf(fin,"%d", &ver1);
//					fscanf(fin,"%d", &ver2);
//					fscanf(fin,"%f", &weight);
//					printf("%d %d %f\n",ver1,ver2,weight);
//					addEdge_int(g, ver1, ver2, weight);
//				}
//				JRB ptr;
//				jrb_traverse(ptr, g){
//					printf("%d ", ptr->key.i);
//				}
//				fclose(fin);
//}
//void findbestfriend(Graph g, map<int, string> friends){
//				int id;
//				printf("\nNhap id: ");
//				scanf("%d", &id);
//				int output[10];
//				float max = -1;
//				int n = getAdjacentVertices_int (g, id, output);
//				for(int i=0; i<n; i++){
//					if(max < getEdgeWeight_int(g,id,output[i])) max = getEdgeWeight_int(g,id,output[i]);
//				}
//				
//				printf("%f", max);
//				for(int i=0; i<n; i++){
//					if(getEdgeWeight_int(g,id,output[i]) == max){
//						printf("\n%d %s",output[i], friends[output[i]].c_str());
//					}
//				}	
//}
//int quanhebaccau(Graph g){
//					int id1, id2, output1[10], output2[10];
//				scanf("%d %d",&id1, &id2);
//				int n1 = getAdjacentVertices_int (g, id1, output1);
//				int n2 = getAdjacentVertices_int (g, id2, output2);
//				int check=0;
//				int check2=1;
//				for(int i=0; i<n1; i++){
//					for(int j=0; j<n2; j++){
//						if(output1[i]==output2[j]){
//							check=1;
//						}
//						if(output1[i] == id2 || output2[j] == id1){
//							check2=0;
//						}
//					}
//				}
//				switch(check && check2){
//					case 1:{
//						return 1;
//					}
//					case 0:{
//						return -1;
//					}
//				}
//}
//int timbanchung(Graph g, map<int, string> friends){
//	int id1, id2, output1[10], output2[10];
//				scanf("%d %d",&id1, &id2);
//				int n1 = getAdjacentVertices_int (g, id1, output1);
//				int n2 = getAdjacentVertices_int (g, id2, output2);
//				int count=0;
//				for(int i=0; i<n1; i++){
//					for(int j=0; j<n2; j++){
//						if(output1[i]==output2[j]){
//							count ++;
//							printf("%d %s\n",output1[i], friends[output1[i]].c_str());
//
//						}
//					}
//				}
//				if(count == 0){
//					return -1;
//				}
//				else{
//					return count;
//				}
//}
//int main(){
//	Graph g = createGraph();
//	int c, vernum, edgenum, id, ver1, ver2;
//	float weight;
//	char name[30];
////	FILE* fin=fopen("C:\\Users\\asus\\Desktop\\banbe.txt","r");
////	if(fopen==NULL){
////		printf("can open this file\n");
////		return 0;
////	}
//	map<int,string> friends;
//	menu();
//	do{
//		printf("\nNhap chuc nang tuong ung: ");
//		scanf("%d", &c);
//		switch(c){
//			case 1:{
////				fscanf(fin,"%d", &vernum);
////				fscanf(fin,"%d", &edgenum);
////				for(int i=0; i<vernum; i++){
////					fscanf(fin,"%d", &id);
////					fscanf(fin, "%s", name);
////					printf("%d %s\n",id,name);
////					friends.insert(pair<int,string>(id,name));
////					JRB tree = make_jrb(); 
////					jrb_insert_int(g, id , new_jval_v(tree));
////				}
////				for(int i=0; i<edgenum; i++){
////					fscanf(fin,"%d", &ver1);
////					fscanf(fin,"%d", &ver2);
////					fscanf(fin,"%f", &weight);
////					printf("%d %d %f\n",ver1,ver2,weight);
////					addEdge_int(g, ver1, ver2, weight);
////				}
////				JRB ptr;
////				jrb_traverse(ptr, g){
////					printf("%d ", ptr->key.i);
////				}
//				readfile("C:\\Users\\asus\\Desktop\\banbe.txt",g,friends);
//				break;
//			}
//			case 2:{
////				printf("\nNhap id: ");
////				scanf("%d", &id);
////				int output[10];
////				float max = -1;
////				int n = getAdjacentVertices_int (g, id, output);
////				for(int i=0; i<n; i++){
////					if(max < getEdgeWeight_int(g,id,output[i])) max = getEdgeWeight_int(g,id,output[i]);
////				}
////				
////				printf("%f", max);
////				for(int i=0; i<n; i++){
////					if(getEdgeWeight_int(g,id,output[i]) == max){
////						printf("\n%d %s",output[i], friends[output[i]].c_str());
////					}
////				}
//				findbestfriend(g,friends);
//				break;
//			}
//			case 3:{
////				int id1, id2, output1[10], output2[10];
////				scanf("%d %d",&id1, &id2);
////				int n1 = getAdjacentVertices_int (g, id1, output1);
////				int n2 = getAdjacentVertices_int (g, id2, output2);
////				int check=0;
////				int check2=1;
////				for(int i=0; i<n1; i++){
////					for(int j=0; j<n2; j++){
////						if(output1[i]==output2[j]){
////							check=1;
////						}
////						if(output1[i] == id2 || output2[j] == id1){
////							check2=0;
////						}
////					}
////				}
////				switch(check && check2){
////					case 1:{
////						printf("1");
////						break;
////					}
////					case 0:{
////						printf("-1");
////						break;
////					}
////				}
//				printf("%d",quanhebaccau(g));
//				break;
//			}
//			case 4:{
////				int id1, id2, output1[10], output2[10];
////				scanf("%d %d",&id1, &id2);
////				int n1 = getAdjacentVertices_int (g, id1, output1);
////				int n2 = getAdjacentVertices_int (g, id2, output2);
////				int count=0;
////				for(int i=0; i<n1; i++){
////					for(int j=0; j<n2; j++){
////						if(output1[i]==output2[j]){
////							count ++;
////							printf("%d %s\n",output1[i], friends[output1[i]].c_str());
////						}
////					}
////				}
////				if(count == 0){
////					printf("-1");
////				}
////				else{
////					printf("%d", count);
////				}
//				printf("%d", timbanchung(g,friends));
//				break;
//			}
//			case 5:{
//				break;
//			}	
//		}
//	}while(c!=5);
//}
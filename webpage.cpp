//#include "jrbgraph.hpp"
//#include <stdio.h>
//#include <iostream>
//#include <map>
//#include <string>
//
//void menu(){
//	printf("1. Doc noi dung file\n");
//	printf("2. Pagerank\n");
//	printf("3. Pagerank sau m lan lap\n");
//	printf("4. Spambot\n");
//	printf("5. Dijkstra\n");
//	printf("6. Thoat\n");
//	printf("\n");
//}
//void readfile_Mapping(char* filename, map<string, string> &Map){
//	int n;
//	char name[255];
//	char id[30];
//	FILE* fin=fopen(filename, "r");
//	fscanf(fin,"%d",&n);
//		
//		for(int i=0;i<n;i++){
//			fscanf(fin,"%s",name);
//			fscanf(fin,"%s",id);
//			Map.insert(pair<string, string>(id, name));
//		}
//}
//void readfile_directedgraph(char* filename1, char* filename2, Graphs g){
//		FILE* fin=fopen(filename1, "r");
// 		FILE* fin2=fopen(filename2,"r");
// 			
//		int n,j=0,k;
//		char id[30], id1[30], id2[30];
//		char output1[30][30], output2[30][30];
//		char temp[30], input[255];
//		char name[255];
//		
//		//file1
//		fscanf(fin,"%d",&n);
//		map<string, string> web;
//		for(int i=0;i<n;i++){
//			fscanf(fin,"%s",name);
//			fscanf(fin,"%s",id);
//			web.insert(pair<string, string>(id, name));
//		}
//		map<string, string>::iterator itr;
//		for (itr = web.begin(); itr != web.end(); ++itr) {
//     	   cout << '\t' << itr->first
//            << '\t' << itr->second << '\n';
//    	}
//
//		//file2
//		printf("\n");
//		do{
//			fgets(input,255,fin2);
//			int i=0,k, count=0,check=0;
//			while(i<strlen(input))
//			{
//				int j=i+1;
//				while(j<strlen(input) && input[j]!=' ') j++;
//				if(j>=strlen(input)) j = strlen(input)-1;
//				if(j>i){
//					if(check==0){
//						for(k=0; k<j-i; k++) id1[k] = input[k+i];
//						id1[k] = '\0';
//						check=1;
//						printf("%s ",id1);
//						JRB tree = make_jrb(); 
////			JRB bn1 = jrb_find_str(g->outdgrees, id1);
////			if(bn1==NULL){
//						jrb_insert_str(g->outdgrees, strdup(id1), new_jval_v(tree));
////			}
//					}
//					else{
//						for(k=0; k<j-i; k++)
//						id2[k] = input[k+i];
//						id2[k] = '\0';
//						printf("%s ",id2);
////			JRB tree = make_jrb(); 
////			jrb_insert_str(g->indgrees, strdup(id2), new_jval_v(tree));
//						addEdge_str(g->outdgrees,id1,id2,1);
//						addEdge_str(g->indgrees,id2,id1,1);
//						JRB tree = make_jrb(); 
//						JRB bn1 = jrb_find_str(g->indgrees, id1);
//						if(bn1==NULL){
//							jrb_insert_str(g->indgrees, strdup(id1), new_jval_v(tree));
//						}
//					}
//				}		
//				i=j+1;
//				while(i<strlen(input) && input[i]==' ')i++;
//			}		
//		printf("\n");
// 	}while(!feof(fin2));
// 	fclose(fin);
//	fclose(fin2);
//}
//void pagerank(Graphs g, map<string, float> &web2){
////	map<string, float> web2;
//	map<string, float> web3;
//	JRB ptr;
//	int n,n1;
//	float sum;
//	char output[100][10], output2[100][10];
////	jrb_traverse(ptr, g->indgrees){
////		web2.insert(pair<string, float>(ptr->key.s, 1));
////	}
//	jrb_traverse(ptr, g->indgrees){
//		sum=0;
//		n=getAdjacentVertices_str(g->indgrees,ptr->key.s,output);
//		for(int i=0;i<n;i++){
//			n1=getAdjacentVertices_str(g->outdgrees,output[i],output2);
//			sum+=web2[output[i]]/n1;
//		}
//		web3.insert(pair<string, float>(ptr->key.s,sum));
//	}
//	web2.swap(web3);
////	jrb_traverse(ptr, g->indgrees){
//////		web2.insert(pair<string, float>(ptr->key.s, web3[ptr->key.s]));
//////		printf(" %s: %f",ptr->key.s,web3[ptr->key.s]);
////	}
//map<string, float>::iterator itr2;
//
//    for (itr2 = web2.begin(); itr2 != web2.end(); ++itr2) {
//        cout << '\t' << itr2->first
//             << '\t' << itr2->second << '\n';
//    }
//	printf("\n");
//}
//void printPair(pair<float, string> p)
//{
//  
//    cout << "("
//         << p.first << ", "
//         << p.second << ") ";
//}
//int main(){
//	menu();
//		Graphs g = createGraphs();
//						map<string, float> web2;
//						map<string, string> Map;
//	int c;
//	do{
//		printf("\nNhap vao chuc nang tuong ung: ");
//		scanf("%d", &c);
//		switch(c){
//			case 1:{
////				FILE* fin=fopen("C:\\Users\\asus\\Desktop\\webpages.txt","r");
//// 				FILE* fin2=fopen("C:\\Users\\asus\\Desktop\\pageconect.txt","r");
//// 			
////				int n,j=0,k;
////				char id[30], id1[30], id2[30];
////				char output1[1000][30], output2[1000][30];
////				char temp[30], input[255];
////				char name[255];
////				fscanf(fin,"%d",&n);
////				map<string, string> web;
////				for(int i=0;i<n;i++){
////					fscanf(fin,"%s",name);
////					fscanf(fin,"%s",id);
////					web.insert(pair<string, string>(id, name));
////				}
////				map<string, string>::iterator itr;
////
////    			for (itr = web.begin(); itr != web.end(); ++itr) {
////     			   cout << '\t' << itr->first
////     			        << '\t' << itr->second << '\n';
////    				}
////
////				printf("\n");
////				do{
////					fgets(input,255,fin2);
////					int i=0,k, count=0,check=0;
////					while( i<strlen(input))
////				{
////					int j=i+1;
////		while(j<strlen(input) && input[j]!=' ')
////			j++;
////		if(j>=strlen(input)) j = strlen(input)-1;
////		if(j>i){
////		if(check==0)
////		{
////			for(k=0; k<j-i; k++)
////				id1[k] = input[k+i];
////			id1[k] = '\0';
////			check=1;
////			printf("%s ",id1);
////			JRB tree = make_jrb(); 
//////			JRB bn1 = jrb_find_str(g->outdgrees, id1);
//////			if(bn1==NULL){
////				jrb_insert_str(g->outdgrees, strdup(id1), new_jval_v(tree));
//////			}
////
////						
////
////		}
////
////		else{
////			for(k=0; k<j-i; k++)
////				id2[k] = input[k+i];
////			id2[k] = '\0';
////			printf("%s ",id2);
//////			JRB tree = make_jrb(); 
//////			jrb_insert_str(g->indgrees, strdup(id2), new_jval_v(tree));
////			addoutEdge_str(g,id1,id2);
////			addinEdge_str(g,id2,id1);
////			JRB tree = make_jrb(); 
////			JRB bn1 = jrb_find_str(g->indgrees, id1);
////			if(bn1==NULL){
////				jrb_insert_str(g->indgrees, strdup(id1), new_jval_v(tree));
////			}
////		}
////		}
////		i=j+1;
////		while(i<strlen(input) && input[i]==' ')i++;
////	}
////		printf("\n");
//// 	}while(!feof(fin2));
//// 		fclose(fin);
////	fclose(fin2);
//				readfile_directedgraph("C:\\Users\\asus\\Desktop\\webpages.txt", "C:\\Users\\asus\\Desktop\\pageconect.txt", g);
//				
//					
//				break;
//			}
//			case 2:{
//
// 				JRB ptr;
// 				jrb_traverse(ptr, g->indgrees){
//					web2.insert(pair<string, float>(ptr->key.s, 1));
//				}
//				pagerank(g,web2);
//				break;
//			}
//			case 3:{
//				int loop;
//				printf("nhap vao so lan lap");
//				scanf("%d", &loop);
//				while(loop){
//					pagerank(g,web2);
//					loop--;
//				}
//			multimap<float, string> web4; // sort
//			map<string, float>::iterator itr2;
//
//    		for (itr2 = web2.begin(); itr2 != web2.end(); ++itr2){
//    				web4.insert(pair<float,string>(itr2->second, itr2->first));
//    			        cout << '\t' << itr2->first
//             << '\t' << itr2->second << '\n';
//			}
//    	  // Flip the pairs.
//			int a=3;
//			stack<pair<float, string> > stk;
//			multimap<float, string>::iterator itr3;
//			for (itr3 = web4.begin(); itr3 != web4.end(); ++itr3){
//				        cout << '\t' << itr3->first
//             << '\t' << itr3->second << '\n';
//			stk.push({itr3->first,itr3->second});
//			}
//			while(a){
//				printPair(stk.top());
//
//  
//			
//    			stk.pop();
//    			a--;
//    		}
//				break;
//			}
//			case 4:{
//				int l1,l2;
//				char output[1000][10];
//				JRB ptr;
//				jrb_traverse(ptr, g->indgrees){
//					l1=getAdjacentVertices_str(g->indgrees,ptr->key.s,output);
//					l2=getAdjacentVertices_str(g->outdgrees,ptr->key.s,output);
//					if(l1==0 && l2!=0){
//						printf("%s: spambot\n", ptr->key);
//					}
//					if(l1!=0 && l2==0){
//						printf("%s: vippro\n", ptr->key);
//
//					}
//				}
//				break;
//			}
//			case 5:{
//				char id4[30];
//				char id5[30];
//				while(getchar()!='\n');
//				gets(id4);
//			
//				gets(id5);
//				
//				dijkstra_str(g->outdgrees,id4,id5);
//				break;
//			}
//			case 7:{
//				adjacencylist_printf_str(g->outdgrees);
//				break;
//			}
//			
//		}
//	} while(c!=6);
//}


















//	FILE* fin=fopen("C:\\Users\\asus\\Desktop\\webpages.txt","r");
//	FILE* fin2=fopen("C:\\Users\\asus\\Desktop\\pageconect.txt","r");
//	Graph g = creategraph();
//	int n,j=0,k;
//	char id[30], id1[30], id2[30];
//	char output1[1000][30], output2[1000][30];
//	char temp[30], input[255];
//	char name[255];
//	fscanf(fin,"%d",&n);
//	map<string, string> web;
//	for(int i=0;i<n;i++){
//		fscanf(fin,"%s",name);
//		fscanf(fin,"%s",id);
//		web.insert(pair<string, string>(id, name));
//	}
//	map<string, string>::iterator itr;
//
//    for (itr = web.begin(); itr != web.end(); ++itr) {
//        cout << '\t' << itr->first
//             << '\t' << itr->second << '\n';
//    }
////	fscanf(fin2,"%d",&n);
//	printf("\n");
//	do{
//	fgets(input,255,fin2);
//	int i=0,k, count=0,check=0;
//	while( i<strlen(input))
//	{
//		int j=i+1;
//		while(j<strlen(input) && input[j]!=' ')
//			j++;
//		if(j>=strlen(input)) j = strlen(input)-1;
//		if(j>i){
//		if(check==0)
//		{
//			for(k=0; k<j-i; k++)
//				id1[k] = input[k+i];
//			id1[k] = '\0';
//			check=1;
//			printf("%s ",id1);
//			JRB tree = make_jrb(); 
////			JRB bn1 = jrb_find_str(g->outdgrees, id1);
////			if(bn1==NULL){
//				jrb_insert_str(g->outdgrees, strdup(id1), new_jval_v(tree));
////			}
//
//						
//
//		}
//
//		else{
//			for(k=0; k<j-i; k++)
//				id2[k] = input[k+i];
//			id2[k] = '\0';
//			printf("%s ",id2);
////			JRB tree = make_jrb(); 
////			jrb_insert_str(g->indgrees, strdup(id2), new_jval_v(tree));
//			addoutEdge_str(g,id1,id2);
//			addinEdge_str(g,id2,id1);
//			JRB tree = make_jrb(); 
//			JRB bn1 = jrb_find_str(g->indgrees, id1);
//			if(bn1==NULL){
//				jrb_insert_str(g->indgrees, strdup(id1), new_jval_v(tree));
//			}
//		}
//		}
//		i=j+1;
//		while(i<strlen(input) && input[i]==' ')i++;
//	}
//		printf("\n");
// 	}while(!feof(fin2));
//	printf("%d,%d", getOutdgree(g,"2001",output1),getIndgree(g,"2001",output2));
//	printf("\n");


//	pagerank(g);
//	printf("\n");
//	Dijkstra(g,"1013","1010");
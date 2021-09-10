#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jrbgraph.hpp"
//int check(char *s, char out[][10], int size)
//{
//    for(int i = 0; i < size; i++) if(strcasecmp(s, out[i]) == 0) return 1;
//    return 0;
//}
//int friendly(Graph g, char *s1, char *s2)
//{
//    char out1[10][10];
//    char out2[10][10];
//    int i1 = getAdjacentVertices_str(g, s1, out1);
//    int i2 = getAdjacentVertices_str(g, s2, out2);
//    if(!i1 || !i2) return 0;
//    else{
//        if(check(s1, out2, i2) && check(s2, out1, i1)) return 1;
//    }
//    return 0;
//}
//void Listfriend(Graph g, char *s1, char *s2)
//{
//    char out1[10][10];
//    char out2[10][10];
//    int i1 = getAdjacentVertices_str(g, s1, out1);
//    int i2 = getAdjacentVertices_str(g, s2, out2);
//    printf("Danh sach ban chung: ");
//    for(int j1 = 0; j1 < i1; j1++)
//    {
//        for(int j2 = 0; j2 < i2; j2++)
//        {
//            if(strcasecmp(out1[j1], out2[j2]) == 0) 
//            { 
//                printf("%s ", out1[j1]);
//                break;
//            }
//        }
//    }
//    printf("\n");
//}
//void readfilewithspecial(char* filename, Graph g){
//	char s[30];
//    char v[30];
//    char e[1000][30];
//    int i;
//	FILE* f = fopen(filename, "r");
//    if(f == NULL) return ;
//    while(!feof(f))
//    {
//        fscanf(f, "%s%*c", s);
//        if(s[strlen(s) - 1] == ':') 
//        {
//            strcpy(v, s);
//            clean(v);
//            i = 0;
//        }
//        else {
//            strcpy(e[i], s);
//            clean(e[i]);
//            addEdge_str(g, v, e[i], 1);
//            i++;
//        }
//    }
//    fclose(f);
//}

void readme(char* filename, Graph g){
	char s[30];
    char v[30];
    char e[1000][30];
    int i = 0;
    FILE* f = fopen(filename, "r");
    if(f == NULL) return;
    
    fscanf(f, "%s%*c", s);
    
        clean(s);
        strcpy(v, s);

        i++;
 
 	e[i][0] = ' ';
    fscanf(f, "%s%*c", s); strcpy(e[i],s);
    fscanf(f, "%s%*c", s); strcat(e[i], " "); strcat(e[i], s);
 //   printf("-%s- -%s- \n", v, e[i]);
   		addEdge_str(g, v, e[i],1);

    i++;
 
    while(!feof(f))
    {
        fscanf(f, "%s%*c", s);
        
        if(s[strlen(s) - 1] == ':') 
        {
            if(e[i] == "\0")
            	strcpy(e[i],s);
			else {
				strcat(e[i], " ");
				strcat(e[i], s);
			}
			
            clean(e[i]);
            strcpy(v, e[i]);
 //           printf("\n ten %s*   ", v);
            i++;

        }
        else if(s[0] >= '0' && s[0] <= '9'  && (s[strlen(s) - 1] == '%' || s[strlen(s) - 1] == 'g' || s[strlen(s) - 1] == ',')){
        	i++;
            strcpy(e[i], s);
            clean(e[i]);
//            printf("^ %s ^", e[i]);
            i++;
           strcat(e[i-2]," ");
           strcat(e[i-2], s);
           
            addEdge_str(g, v, e[i-2],1);

//            printf("-%s-%s \n",v, e[i-2]);
            
        }

		 else {
        	if(e[i] == "\0")
            	strcpy(e[i],s);
        	else {
				strcat(e[i], " ");
				strcat(e[i], s);
			}
		}
	}
}
//int main()
//{
//    FILE *f;
//    Graph g = createGraph();
////    char s[30];
////    char v[30];
////    char e[1000][30];
////    int i;
////	char tet[30]="uaalo:";
////	clean(tet);
////	printf("%s", tet);
//        readme("C:\\Users\\asus\\Desktop\\friendname.txt", g);
//
//		
////    f = fopen("C:\\Users\\asus\\Desktop\\friendname.txt", "r");
////    if(f == NULL) return 0;
////    while(!feof(f))
////    {
////        fscanf(f, "%s%*c", s);
////        if(s[strlen(s) - 1] == ':') 
////        {
////            strcpy(v, s);
////            clean(v);
////            i = 0;
////        }
////        else {
////            strcpy(e[i], s);
////            clean(e[i]);
////            addEdge_str(g, v, e[i],1);
//////            addinEdge_str(g, e[i], v);
////            i++;
////        }
////    }
// adjacencylist_printf_str(g);
////    char s1[30], s2[30];
////    char out[1000][30];
////    int sure;
////    printf("Nhap 2 ban: \n");
////    fgets(s1, 30, stdin); fgets(s2, 30, stdin);
////    clean(s1), clean(s2);
////    if(!friendly(g, s1, s2)) printf("%s, %s khong la ban than\n", s1, s2);
////    else
////    {
////        printf("%s, %s la ban than\n", s1, s2);
////        Listfriend(g, s1, s2);
////    }
////    
//}
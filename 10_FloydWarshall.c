#include<stdio.h>
#define INF 999

void printpath(int v,int pi[v][v],int i,int j){
    if(i==j){
        printf("%d",i);
        return;
    }
    if(pi[i][j]==-1){
        printf("no path\n");
        return;
    }
    printpath(v, pi, i, pi[i][j]);
    printf("->%d",j);
}

void floydwarshall(int v, int graph[v][v]){
    int d[v][v];
    int pi[v][v];
    int i,j,k;
    
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            d[i][j]=graph[i][j];
		}
	}
	
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(i!=j && graph[i][j]!=INF){
                pi[i][j]=i;
			}else{
                pi[i][j]=-1;
			}
		}
	}
	
    for(k=0;k<v;k++){
        for(i=0;i<v;i++){
            for(j=0;j<v;j++){
                if(d[i][k]!=INF && d[k][j]!=INF && d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    pi[i][j]=pi[k][j];
                }
			}
		}
	}
	
    printf("distance table\n");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            printf("%d\t",d[i][j]);
		}
        printf("\n");
    }
    
    printf("pi table\n");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            printf("%d\t",pi[i][j]);
		}
        printf("\n");
    }
    
    printf("paths from each vertice\n");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(i!=j){
                printf("%d to %d :",i,j);
                printpath(v,pi,i,j);
                printf("\n");
            }
		}
	}
}

int main(){
    int v;
    
    printf("enter number of vertices\n");
    scanf("%d",&v);
    
    int i,j;
    int graph[v][v];
    printf("enter graph\n");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            scanf("%d",&graph[i][j]);
		}
	}
	
    floydwarshall(v,graph);
    
    return 0;
}


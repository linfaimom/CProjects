#include <stdio.h>
#define MAX_VEX 100

int create(int cost[][MAX_VEX]){
	int vexnum,arcnum,i,j,k,v1,v2;
	printf("请输入顶点数和边数:\n");
	scanf("%d",&vexnum);
	scanf("%d",&arcnum);
	//初始化邻接矩阵即全赋值为０
	for(i=0;i<vexnum;i++){
		for(j=0;j<vexnum;j++){
			cost[i][j]=0;
		}
	}
	for(k=0;k<arcnum;k++){
		printf("输入相连顶点v1,v2:\n");
		scanf("%d",&v1);
		scanf("%d",&v2);
		//相连则将值变为１
		cost[v1][v2]=1;
		//若为无向图，则需加上cost[v2][v1]=1;
	}
	return vexnum;
}

int main(){
	int vexnum,i,j;
	int cost[MAX_VEX][MAX_VEX];
	int create(int cost[][MAX_VEX]);
	vexnum = create(cost);
	printf("所构建的邻接矩阵为:\n");
	for(i=0;i<vexnum;i++){
		for(j=0;j<vexnum;j++){
			printf("%3d",cost[i][j]);
		}
		printf("\n");
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

char grid[51][51];
int vis[2][51][51]; //vis[0]表示可以从起始点到达此位置，vis[1]表示可以由该位置到达终点 
int m,n,cnt=0;
bool is_legal(int i,int j,int flag){ // 合法没有被访问过而且能去的
	return i>=0&&i<m&&j>=0&&j<n&&vis[flag][i][j]==0&&grid[i][j]!='#';
}
void DFS(int i,int j){ //flag：0表示从起始点遍历，1表示从结尾遍历，因为两者遍历时对于'.'的解释不同 
	switch(grid[i][j]){
		case 'S':
		case 'T':
		case '+':
			if(is_legal(i,j-1,0)){vis[0][i][j-1]=1;DFS(i,j-1);}
			if(is_legal(i,j+1,0)){vis[0][i][j+1]=1;DFS(i,j+1);}
			if(is_legal(i-1,j,0)){vis[0][i-1][j]=1;DFS(i-1,j);}
			if(is_legal(i+1,j,0)){vis[0][i+1][j]=1;DFS(i+1,j);}
			break;
		case '|':
			if(is_legal(i-1,j,0)){vis[0][i-1][j]=1;DFS(i-1,j);}
			if(is_legal(i+1,j,0)){vis[0][i+1][j]=1;DFS(i+1,j);}
			break;
		case '-':
			if(is_legal(i,j-1,0)){vis[0][i][j-1]=1;DFS(i,j-1);}
			if(is_legal(i,j+1,0)){vis[0][i][j+1]=1;DFS(i,j+1);}
			break;
		case '.':
			if(is_legal(i+1,j,0)){vis[0][i+1][j]=1;DFS(i+1,j);}
			break;
		case '#':
			break;
	}
}

void DFS2(int i,int j){
	//这里要考虑的是分别判断从哪个节点可以走到当前节点，而不是从当前节点可以走到哪个节点
	if(is_legal(i,j-1,1)){
		char c=grid[i][j-1];
		if(c=='S'||c=='T'||c=='+'||c=='-')
		{vis[1][i][j-1]=1;DFS2(i,j-1);}
	}
	if(is_legal(i,j+1,1)){
		char c=grid[i][j+1];
		if(c=='S'||c=='T'||c=='+'||c=='-')
		{vis[1][i][j+1]=1;DFS2(i,j+1);}
	}
	if(is_legal(i-1,j,1)){
		char c=grid[i-1][j];
		if(c=='S'||c=='T'||c=='+'||c=='|'||c=='.')
		{vis[1][i-1][j]=1;DFS2(i-1,j);}
	}
	if(is_legal(i+1,j,1)){
		char c=grid[i+1][j];
		if(c=='S'||c=='T'||c=='+'||c=='|')
		{vis[1][i+1][j]=1;DFS2(i+1,j);} 
	}
} 
int main() {
	cin >> m >> n;  // m和n是全局变量，这里直接赋值，局部这里定义了m和n的话就会导致全局失效，其他地方就都为0了
	
	int start[2],end[2]; //记录开始结束节点 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> grid[i][j];
			if(grid[i][j]=='S'){
				start[0]=i;
				start[1]=j;
			}else if(grid[i][j]=='T'){
				end[0]=i;
				end[1]=j;
			}
		}
	}
	
	memset(vis,0,2*51*51*sizeof(int));
	vis[0][start[0]][start[1]]=1;
	vis[1][end[0]][end[1]] = 1;
	DFS(start[0],start[1]); // 遍历从起点能到达的点
	if(vis[0][end[0]][end[1]] == 0) {
		cout << "I'm stuck!" << endl;
		return 0;
	}

	DFS2(end[0],end[1]);  // 遍历能到达终点的点
	cnt = 0;
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++){
			if(vis[0][i][j]==1 && vis[1][i][j]==0){
				cnt++;
			} 
		}
	}
	cout << cnt << endl;
	return 0;
}

#include<iostream>
#include<math.h>
using namespace std;
bool can_place(int mat[][9],int i,int j, int n, int num){
	//check for row and column
	for(int x=0;x<n;x++){
		if(mat[x][j]==num||mat[i][x]==num){
			return false;
		}
		
	}
	//check for sub grid
	int rn=sqrt(n);
	int sx=(i/rn)*rn; //starting point of sub grid
	int sy=(j/rn)*rn;//starting point of sub grid
	for(int x=sx;x<sx+rn;x++){//updated <
		for(int y=sy;y<sy+rn;y++){//updated <
			if(mat[x][y]==num){
				return false;
				
			}
		}
	}
	return true;
	
}
bool solve_sudoku(int mat[][9],int i,int j,int n){
	//base case
	if(i==n){
		//print the matrix
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	//case for end of the row
	if(j==n){
		return solve_sudoku(mat,i+1,0,n);
	}
	//skip the already filled cells
	if(mat[i][j]!=0){
		return solve_sudoku(mat,i,j+1,n);
	}
	
	//recursive case
	//fill the current cell with possible options
	for(int num=1;num<=n;num++){
		if(can_place(mat,i,j,n,num)){
			mat[i][j]=num;
			bool could_we_solve=solve_sudoku(mat,i,j+1,n);
			if(could_we_solve==true){
				return true;
			}
			
		}
	}
	//backtrack here
	mat[i][j]=0;
	return false;
	
}


int main(){
	int n;
	cin>>n;
	int mat[9][9];
	for(int p=0;p<9;p++){
		for(int q=0;q<9;q++){
			cin>>mat[p][q];
		}
	}

	solve_sudoku(mat,0,0,9);
	return 0;
	
}


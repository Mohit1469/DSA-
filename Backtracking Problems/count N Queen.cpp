/*You are given an empty chess board of size N*N. Find the number of ways to place N queens on the board, such that no two queens can kill each other in one move. 
A queen can move vertically, horizontally and diagonally.

Input Format
A single integer N, denoting the size of chess board.

Constraints
1<=N<=11

Output Format
A single integer denoting the count of solutions.

Sample Input
4
Sample Output
2                      */

#include<iostream>
using namespace std;
int count;
bool is_safe(int board[][11],int i,int j,int n){
	//check for the column
	for(int row=0;row<i;row++){
		if(board[row][j]==1){
			return false;
		}
	}
	//check for the left diagonal
	int x=i;
	int y=j;//updated j 
	while(x>=0 and y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}
	//check for the right diagonal
    x=i;
    y=j;//reinitialise
	while(x>=0 and y<n){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y++;
	}
	//position is now safe
	return true;
	
}
bool N_Queen(int board[][11],int i,int n){
	//base case
	if(i==n){
		//you have successfully placed queens in n rows (0....n-1)
		//print the board
		
		
        count++;
        
        return false;
	}
	//recursive case
	//try to place the queen in the current row and call on the remaining part which will be solved by recursion
	for(int j=0;j<n;j++){
		//i have to check if i,j th position is safe to place a queen or not
		if(is_safe(board,i,j,n)){
			//place the queen - assuming i,j is the right position
			board[i][j]=1;//updated =
			
			bool next_queen_rakh_paye=N_Queen(board,i+1,n);
			if(next_queen_rakh_paye){
				return true;
			}
			//means i,j is not the right position-assumption is wrong
			board[i][j]=0;//backtrack
			
			
			
			
		}
	}
	//you have tried all positions in the current row but could't place a queen
	return false;
}


int main(){
	int n;
	cin>>n;
	int board[11][11]={0};
	N_Queen(board,0,n);
    cout<<count;
	return 0;
}

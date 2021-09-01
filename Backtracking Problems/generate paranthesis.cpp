/*Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
The output strings should be printed in the sorted order considering '(' has higher value than ')'.

Input Format
Single line containing an integral value 'n'.

Constraints
1<=n<=11

Output Format
Print the balanced parentheses strings with every possible solution on new line.

Sample Input
2
Sample Output
()() 
(()) */
#include<iostream>
using namespace std;
void generate_brackets(char *out,int n,int idx,int open,int close){
	// base case
	if(idx==2*n){
		out[idx]='\0';
		cout<< out <<endl;
		return;
	}
	//recursive case
	//2 options
	
	if(close<open){
		out[idx]=')';
		generate_brackets(out,n,idx+1,open,close+1);
	}
	if(open<n){
		out[idx]='(';
		generate_brackets(out,n,idx+1,open+1,close);
		
	}
	return;
}
int main(){
	int n;
	cin>>n;
	char out[1000];
	int idx=0;
	generate_brackets(out,n,0,0,0);
	return 0;
}

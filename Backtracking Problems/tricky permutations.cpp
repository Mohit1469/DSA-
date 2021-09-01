/*Given a string containing duplicates, print all its distinct permutations such that there are no duplicate permutations and all permutations are 
printed in a lexicographic order.

Input Format
The first and only line of the test case contains the input string.

Constraints
Length of the string <= 8

Output Format
Print all the distinct permutations in a lexicographic order such that each permutation is in a new line. Note that there should not be any duplicate permutations.

Sample Input
ABA
Sample Output
AAB
ABA
BAA
Explanation
The possible permutations for the given string are { "AAB" , "AAB" , "ABA" , "BAA" } . We skip the repeating "AAB" permutation and only print it in once. 
Also we print the final output in lexicographical order.*/
#include<iostream>
#include<set>
#include<string>
using namespace std;
void permute(char *in,int i,set<string> &s){
	//base case
	if(in[i]=='\0'){
		//cout<<in<<" , ";
		string t(in);
		s.insert(t);
		
		return;
		
	}

	
	
	//recursive case
	for(int j=i;in[j]!='\0';j++){
		swap(in[i],in[j]);
		permute(in,i+1,s);
		//restore the original array (backtracking)
		swap(in[i],in[j]);
	}
	
	
	
}

int main(){
	char in[100];
	cin>>in;
	set<string>s;
	
	permute(in,0,s);
	//loop over the s
	for(auto str:s){
		cout<<str<<endl;
	}
	return 0;
}

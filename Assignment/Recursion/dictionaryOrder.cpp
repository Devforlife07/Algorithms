#include <iostream>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;

bool compare(string a,string b){
	return a>b;
}

void permute(string s,string t,int i,bool &flag){
	if(s[i]=='\0'){
		if(compare(s,t)){
			// flag = false;
			cout<<s<<"\n";
		}
		return;
	}
	else{
		for(int j=i;s[j]!='\0';j++){
			swap(s[j],s[i]);
			permute(s,t,i+1,flag);
            swap(s[j],s[i]);
		}
	}
}

int main(){

	string s;
	cin >> s;
	string t = s;
	sort(s.begin(),s.end());
	bool flag = true;
	permute(s,t,0,flag);
	
}

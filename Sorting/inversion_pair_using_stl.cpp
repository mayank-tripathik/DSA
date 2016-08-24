#include<iostream>
#include<map>
#include<algorithm>
#include<utility>
using namespace std;
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n,i,x;
		cin>>n;
		map<int,int> arr;
		for(i=0;i<n;i++){
			cin>>x;
			arr.insert(make_pair(x,i+1));
		}
		map<int,int> :: iterator itr,temp,it;
		for(it=arr.begin();it!=arr.end();it++){
			cout<<(*it).first<<":"<<(*it).second<<endl;
		}
		temp=arr.begin();
		temp++;
		cout<<"Inversion Pairs:\n";
		for(itr=arr.begin();temp!=arr.end();itr++)
		{ 
			if((*itr).second>(*temp).second)
				cout<<(*temp).first<<" and "<<(*itr).first<<endl;
			temp++;
		}
	}
		
}

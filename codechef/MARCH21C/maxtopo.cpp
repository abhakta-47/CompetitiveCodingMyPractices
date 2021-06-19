#include <bits/stdc++.h>

using namespace std;

int MOD=1000000007;

// nCr, get_nCr
class NCR
{
public:
	int curLevel;
	int **nCr;
	NCR(int n){
		curLevel=n;
		nCr=new int *[n+1];
		int i,j;
		for(int i=0;i<=n;i++){
			nCr[i]=new int[i/2+1];
			nCr[i][0]=1;
			nCr[i][1]=i;
			for(int j=2;j<=i/2;j++)
				nCr[i][j]=(getNCR(i-1,j-1)%MOD+getNCR(i-1,j)%MOD)%MOD;
	
		}
		// for(int i=0;i<=n;i++){
		// 	cout<<"\n"<<i<<"->\n";
		// 	for(int j=0;j<=i;j++)
		// 		cout <<i<<"C"<<j<<" "<<getNCR(i,j)<<"	  ";
		// }
	}
	~NCR(){
		for(int i=0;i<=curLevel;i++){
			delete nCr[i];
		}
		delete nCr;
	}
	int getNCR(int x, int y){
		if(y>x/2)
			return nCr[x][x-y];
		return nCr[x][y];
	}
};

// Node
class Node{
public:
	int v;//value
	vector<int>children;
	int nChild;
	Node(){
		nChild=0;
	}
	void addChild(int x){
		children.push_back(x);
		++nChild;
	}
};

int findTreeCenters(Node *tree, int n){
	
	
}

struct TopoReturn{
	int value, noSubOrd;
};

TopoReturn minTopoOrder(Node *tree, int index, bool *isVisited, NCR &ncr){
	// cout<<index<<"->\n";
	isVisited[index]=true;
	TopoReturn ans;
	ans.value=1;
	ans.noSubOrd=0;
	if( tree[index].nChild==0 ){
		// cout<<" "
		// 	<<ans.value<<" "
		// 	<<ans.noSubOrd<<",\n";
		return ans;
	}
	vector<int>subOrds;
	int totalSubOrd=0;
	for(int i=0; i<tree[index].nChild; i++){
		int tmpNodeIndex=tree[index].children[i];
		if( !isVisited[ tmpNodeIndex ] ){
			TopoReturn tmp=minTopoOrder(tree, tmpNodeIndex, isVisited, ncr);
			
			ans.value*=tmp.value%MOD;
			ans.value %= MOD;
			
			ans.noSubOrd+=(tmp.noSubOrd+1)%MOD;
			ans.noSubOrd %= MOD;
			
			subOrds.push_back((tmp.noSubOrd+1)%MOD);
			
			totalSubOrd+=(tmp.noSubOrd+1)%MOD;
			totalSubOrd %= MOD;
		}
	}
	// cout<<index<<"->";
	for(int i=0; i<subOrds.size(); i++){
		// cout<<ans.value<<"*get "<<totalSubOrd<<"C"<<subOrds[i]<<" ";
		ans.value*=ncr.getNCR(totalSubOrd, subOrds[i])%MOD;
		ans.value %= MOD;
		// cout<<ans.value<<"   ";
		totalSubOrd-=subOrds[i]%MOD;
		totalSubOrd%=MOD;
	}
	// cout<<" "
	// 	<<ans.value<<" "
	// 	<<ans.noSubOrd<<",\n";
	return ans;
}

void func(){
	int n,k;
	cin>>n>>k;
	Node tree[n+1];
	int x,y,i;
	for(i=1; i<=n; i++)
		tree[i].v=i;
	for(i=1;i<n;i++){
		cin>>x>>y;
		tree[x].addChild(y);
		tree[y].addChild(x);
	}

	// for(i=1;i<=n;i++){
	// 	cout<<i<<" -> ";
	// 	for(int j=0; j<tree[i].nChild; j++)
	// 		cout<<tree[i].children[j]<<" ";
	// 	cout<<"\n";
	// }
	// n=11;
	NCR ncr(n);
	// for(int i=0;i<=n;i++){
	// 	cout<<"\n"<<i<<"->\n";
	// 	for(int j=0;j<=i;j++)
	// 		cout <<i<<"C"<<j<<" "<<ncr.getNCR(i,j)<<"\t";
	// }

	//by Center
	if(k==1){
		bool isVisited[n+1]={0};
		int tmpp=findTreeCenters(tree,n);
		cout<< tmpp<<" "
			<<minTopoOrder(tree, tmpp, isVisited,ncr).value%MOD<<"\n";
		return;
	}

	//by brute
	vector< pair<int, int>>topoOrderPairs;
	for(i=1;i<=n;i++){
		bool isVisited[n+1]={0};
		int tmpp=minTopoOrder(tree,i,isVisited,ncr).value;
		// cout<<i<<"->\n"
		// 	<<tmpp<<" ans\n";
		topoOrderPairs.push_back({tmpp,i});
	}
	sort( topoOrderPairs.begin(), topoOrderPairs.end());
	reverse( topoOrderPairs.begin(), topoOrderPairs.end());
	cout<<topoOrderPairs[k-1].second<<" "<<topoOrderPairs[k-1].first;

	cout<<"\n";
}

int main(){
	int t;
	cin>>t;
	while(t--)
		func();
}
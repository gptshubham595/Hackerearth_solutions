```
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int val;
	vector<node*> children;
};

node *newNode(int key) 
{ 
    node *temp = new node; 
    temp->val = key; 
    return temp; 
} 

pair<int, node*> highest;
pair<int,int> rec(node* root)
{
	if(root->children.size()==0)
		return {root->val, 1};
	int tot=0, cnt=0;
	pair<int,int> p;
	for(auto& x: root->children)
	{
		p=rec(x);
		tot+=p.first;
		cnt+=p.second;
	}
	if(highest.first<tot/cnt)
		highest={tot/cnt, root};
	return {tot,cnt};
}

node* findHighestTenure(node* root)
{
	highest = {INT_MIN, newNode(0)};
	rec(root);
	return highest.second;
}

node* search(node* root, int k)
{
	if(root==nullptr || root->val==k) return root;
	node* temp;
	for(auto &child: root->children)
	{
		temp=search(child, k);
		if(temp!=nullptr) return temp;
	}
	return temp;
}

int main() {
	node* root;
	int n;
	cin>>n;
	int a,b;
	node* temp;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(a==-1) root= newNode(b);
		else
		{
			temp = search(root, a);
			temp->children.push_back(newNode(b));
		}
	}
	node* ans=findHighestTenure(root);
	if(ans==NULL) cout<<-1<<endl;
	else cout<<ans->val<<endl;
	return 0;
}
```

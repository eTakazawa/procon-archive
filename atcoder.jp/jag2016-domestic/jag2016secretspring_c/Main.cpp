#include <bits/stdc++.h>
using namespace std;

struct Node{
	int num;
	Node *rch,*lch,*par;
	Node(){
		num = -1;
		rch = NULL;
		lch = NULL;
		par = NULL;
	}
};

void print(Node* node,int d=0){
	if(node->lch != NULL)print(node->lch,d+1);
	for(int i=0;i<d;i++)
	cout << "\t";
	cout << node->num << endl;
	if(node->rch != NULL)print(node->rch,d+1);
}

void syns(Node* root1, Node* root2, Node* newNode){
	newNode->num = root1->num + root2->num;
	if(root1->lch->num != -1 && root2->lch->num != -1){
		newNode->lch = new Node();
		syns( root1->lch, root2->lch, newNode->lch);
	}
	if(root1->rch->num != -1 && root2->rch->num != -1){
		newNode->rch = new Node();
		syns( root1->rch, root2->rch, newNode->rch);
	}
}

void printAns(Node* node){
	cout << '(';
	if(node->lch != NULL)printAns(node->lch);
	cout << ')';
	cout <<'['<< node->num<<']';
	cout << '(';
	if(node->rch != NULL)printAns(node->rch);
	cout << ')';
}

int main(void){
	string A;
	string B;
	cin >> A >> B;

	Node* root1 = new Node();
	Node* now = root1;
	bool right = false;
	for(int i=0;i<A.size();i++){
		if(A[i] == '('){
			if(!right){
				Node* prev = now;
				now->lch = new Node();
				now = now->lch;
				now->par = prev;
			}else{
				Node* prev = now;
				now->rch = new Node();
				now = now->rch;
				now->par = prev;
				right = false;
			}
		}else if(A[i] == ')'){
			now = now->par;
		}else if(A[i] == '['){
			right = true;
			string num;
			i++;
			while(A[i] != ']'){
				num += A[i];i++;
			}
			now->num = stoi(num);
		}
	}

	Node* root2 = new Node();
	now = root2;
	for(int i=0;i<B.size();i++){
		if(B[i] == '('){
			if(!right){
				Node* prev = now;
				now->lch = new Node();
				now = now->lch;
				now->par = prev;
			}else{
				Node* prev = now;
				now->rch = new Node();
				now = now->rch;
				now->par = prev;
				right = false;
			}
		}else if(B[i] == ')'){
			now = now->par;
		}else if(B[i] == '['){
			right = true;
			string num;
			i++;
			while(B[i] != ']'){
				num += B[i];i++;
			}
			now->num = stoi(num);
		}
	}

	Node* newNode = new Node();
	syns( root1, root2, newNode );
	// print(newNode);
	printAns(newNode);cout << endl;
	return 0;
}
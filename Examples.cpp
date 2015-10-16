//============================================================================
// Name        : Examples.cpp
// Author      : wb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <cmath>
using namespace std;


class KDTree
{
public:
	KDTree():parent(NULL),left(NULL),
	right(NULL){

	}

	vector<double> root;

	KDTree* parent;
	KDTree* left;
	KDTree* right;

	bool isEmpty(){
		return root.empty();
	}


};

int data[6][2] = { {2,3},{5,4}, {9,6}, {4,7}, {8,1}, {7,2} };

template<typename T>
vector< vector<T> > Transpose(vector<vector<T> > Matrix)
{
	unsigned row = Matrix.size();
	unsigned col = Matrix[0].size();
	vector<vector<T> > Trans(col, vector<T>(row,0));
	for(unsigned i=0;i<col;++i){
		for(unsigned j=0;j<row;++j){
			Trans[i][j] = Matrix[j][i];
		}
	}
	return Trans;
}

template<typename T>
T findMiddleValue(vector<T> vec)
{
	sort(vec.begin(),vec.end());
	int pos = vec.size() / 2;

	return vec[pos];
}

void buildKDTree(KDTree* tree, vector<vector<double> > data, unsigned depth )
{
	unsigned samplesNum = data.size();
	if(samplesNum == 0){
		return;
	}
	if(samplesNum == 1){
		tree->root = data[0];
		return;
	}
	unsigned k = data[0].size();
	vector<vector<double> > transData = Transpose(data);
	// pick the split attribute
	unsigned splitAttribute = depth % k;
	vector<double> splitAttributeValues = transData[splitAttribute];

	double splitValue = findMiddleValue(splitAttributeValues);

	vector<vector<double> > subset1;
	vector<vector<double> > subset2;
	for(unsigned i=0;i<samplesNum;++i){
		if(splitAttributeValues[i] == splitValue && tree->root.empty()){
			tree->root = data[i];
		}
		else{
			if(splitAttributeValues[i] < splitValue){
				subset1.push_back(data[i]);
			}else{
				subset2.push_back(data[i]);
			}

		}

	}

	tree->left = new KDTree;
	tree->right = new KDTree;
	tree->left->parent = tree;
	tree->right->parent = tree;

	buildKDTree(tree->left,subset1,depth+1);
	buildKDTree(tree->right,subset2, depth+1);


}

void PrintKDTree(KDTree* tree, unsigned depth)
{
	for(unsigned i = 0; i<depth; ++i)
	{
		cout<<"\t";
	}
	for(vector<double>::size_type j = 0;j<tree->root.size();++j){
		cout<<tree->root[j]<<",";
	}
	cout<<endl;
	if(tree->left ==NULL && tree->right ==NULL)
		return;
	else{
		if(tree->left != NULL){
			for(unsigned i=0;i<depth+1;++i){
				cout<<"\t";
			}
			cout<<" left:";
			PrintKDTree(tree->left, depth+1);
		}

		cout<<endl;

		if(tree->right != NULL)
		{
			for(unsigned i=0;i<depth+1;++i){
				cout<<"\t";
			}
			cout<<" right:";
			PrintKDTree(tree->right, depth+1);
		}
		cout<<endl;
	}

}







int main() {


	vector<vector<double> > tran(6, vector<double>(2,0));

	for(unsigned i = 0;i<6;++i){
		for(unsigned j=0;j<2;++j){
			tran[i][j] = data[i][j];
		}
	}

	KDTree* tree = new KDTree;
	buildKDTree(tree,tran,0);

	PrintKDTree(tree, 0);

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;




}





#include <iostream>
#include <vector>
using namespace std;
//this method is about testing the quick sort algorithm
// testing the parameters number;

///from min to max;
void QuickSort(vector<double>& can)
{
	if(can.empty()){
		return;
	}

	int r = can.size() - 1;
	int l = 0;

	if(l>r){return;}
	double pivot = can[l];

	while(l!=r){

		while(pivot <= can[r] && l<r){
			r--;
		}

		while(pivot >= can[l] && l<r){
			l++;
		}

		if(l<r){
			double t = can[l];
			can[l]   = can[r];
			can[r]   = t;
		}

	}
	can[0] = can[l];
	can[l] = pivot;

//	QuickSort();

}


int main()
{






	cout<<"The end!"<<endl;
	return 0;

}



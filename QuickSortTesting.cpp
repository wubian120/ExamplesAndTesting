



#include <iostream>
#include <vector>
#include "SrcPoint.h"
#include <stdlib.h>

using namespace std;
//this method is about testing the quick sort algorithm
// testing the parameters number;



///from min to max;
void QuickSort(Container& can,int s, int e, int sort_d)
{
	if(can.empty()){
		return;
	}

	if(s>e){return;}

	int r = e;
	int l = s;
	SrcPoint* pivot = can.at(s);

	while(l!=r){

		if(sort_d == 0)
		{
			while(pivot->x <= can.at(r)->x && l<r){
				r--;
			}
			while(pivot->x >= can.at(l)->x && l<r){
				l++;
			}
		}

		if(sort_d == 1)
		{
			while(pivot->y <= can.at(r)->y && l<r){
				r--;
			}
			while(pivot->y >= can.at(l)->y && l<r){
				l++;
			}
		}

		if(l<r){
			SrcPoint* t = can.at(l);
			can.at(l)   = can.at(r);
			can.at(r)   = t;
		}

	}
	can.at(s)= can.at(l);
	can.at(l) = pivot;

	QuickSort(can,s,l-1, sort_d);
	QuickSort(can,l+1,e, sort_d);
}


void PrintContainer(const Container& can)
{
	if(can.empty())
	{
		cout<<"empty"<<endl;
		return;
	}
	int i = 0;
	Container::const_iterator itr = can.begin();
	for(;itr!=can.end();++itr){

		cout<<" the ["<<i<<"] is :"<<(*itr)->x<<"\t";
		cout<<(*itr)->y<<endl;
		i++;
	}
}

void BuildContainerExample(Container& can)
{
	SrcPoint* s[12];

	can.clear();
	for(int i=0;i<12;++i){
		s[i]  = new SrcPoint;
		s[i]->x = (double)rand();
		s[i]->y = (double)rand();
		can.push_back(s[i]);
	}



}


int main()
{

	Container can;
	cout<<"can size: "<<can.size()<<endl;
	BuildContainerExample(can);

	cout<<"can size: "<<can.size()<<endl;
	PrintContainer(can);

	int s = 0;
	int e = can.size()-1;
	QuickSort(can,s,e,0);
	PrintContainer(can);

	QuickSort(can,s,e,1);
	PrintContainer(can);

//	cout<<"i:"<<i<<endl;

	cout<<"The end!"<<endl;
	return 0;

}



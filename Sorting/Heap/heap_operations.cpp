#include <iostream>
#include<vector>
using namespace std;

void top_down_heapify(vector<int> &arr,int i){
	int n=arr.size();
	int left,right,min;
	while(2*i+1<n){
		left=2*i+1;
		right=2*i+2;
		if(right<n && arr[right]<arr[left])
			min=right;
		else
			min=left;
		if(arr[i]>arr[min])
		{
			swap(arr[i],arr[min]);
			i=min;
		}
		else
			break;
	}
	
}

void bottom_up_heapify(vector<int> &heap,int i){
	while((i-1)/2>=0){
		int parent=(i-1)/2;
		if(heap[i]<heap[parent])
		{
			swap(heap[i],heap[parent]);
			i=parent;
		}
		else
			break;
	}
}

void build_heap(vector<int> &arr, int n){
	for(int i=(n-1)/2;i>=0;i--)
		top_down_heapify(arr,i);
}

void add_element(vector<int> &heap,int element){
	heap.push_back(element);
	bottom_up_heapify(heap,heap.size()-1);
}

int extract(vector<int> &heap){
	return heap[0];
}

void update(vector<int> &heap,int index, int value){
	if(value>heap[index]){
		heap[index]=value;
		top_down_heapify(heap,index);
	}
	else{
		heap[index]=value;
		bottom_up_heapify(heap,index);
	}
}

void delete_from_heap(vector<int> &heap,int index)
{
	int size=heap.size();
	int updated=heap[size-1];
	heap.pop_back();
	update(heap,index,updated);
}

void print_heap(vector<int> &heap){
	cout<<"Heap Contents:\n";
	for(int i=0;i<heap.size();i++)
		cout<<heap[i]<<" ";
	cout<<endl;
}
int main(){
	int n,x,choice;
	cin>>n;
	vector<int> heap;
	for(int i=0;i<n;i++){
		cin>>x;
		heap.push_back(x);
	}	
	build_heap(heap,heap.size());
	print_heap(heap);
	while(1){
		cout<<"Press 1 to add element\nPress 2 to extract\nPress 3 to update element\nPress 4 to delete element\nPress 5 to exit\n";
		cin>>choice;
		if(choice==1){
			int element;
			cout<<"Enter element to be added:\n";
			cin>>element;
			add_element(heap,element);
			print_heap(heap);
		}
		else if(choice==2){
			int extracted=extract(heap);
			cout<<"Element extracted:"<<extracted<<endl;
			print_heap(heap);
		}
		else if(choice==3){
			int index,updated_value;
			cout<<"Enter index of element to be updated:\n";
			cin>>index;
			cout<<"Enter updated value:\n";
			cin>>updated_value;
			update(heap,index,updated_value);
			print_heap(heap);
		}
		else if(choice==4){
			int index;
			cout<<"Enter index of element to be deleted:\n";
			cin>>index;
			delete_from_heap(heap,index);
			print_heap(heap);
		}
		else if(choice==5)
			break;
			
		}
}

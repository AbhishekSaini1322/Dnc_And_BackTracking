#include <iostream>
using namespace std;

void merge(int arr[], int s, int e) {

	int mid = (s+e)/2;

	int lenLeft = mid - s + 1;
	int lenRight = e - mid;

	//create left and right array
	int *left = new int[lenLeft];
	int *right = new int[lenRight];

	//copy values from original array to left array
	int k = s;
	//k -> starting index of left array values in original arrya
	for(int i=0; i<lenLeft; i++) {
		left[i] = arr[k];
		k++;
	}

	//copy values from original array to right array
	k = mid+1;
	for(int i=0; i<lenRight; i++) {
		right[i] = arr[k];
		k++;
	}

	//actual merge logic here
	//left array is already sorted
	//right array is already sorted
	int leftIndex = 0;
	int rightIndex = 0;
	//yahi pr galti karte h log
	int mainArrayIndex = s;

	while(leftIndex < lenLeft &&  rightIndex < lenRight) {
		
		if(left[leftIndex] < right[rightIndex] ) {
			arr[mainArrayIndex] =  left[leftIndex];
			mainArrayIndex++;
			leftIndex++;
		}
		else {
			arr[mainArrayIndex] =  right[rightIndex];
			mainArrayIndex++;
			rightIndex++;
		}
	}


	//2 more cases

	//1 case -> left array exhaust but right array me element abhi bhi bache hai
	while(rightIndex < lenRight) {
		arr[mainArrayIndex] =  right[rightIndex];
		mainArrayIndex++;
		rightIndex++;
	}
	

	//2nd case -> rigght array exhaust but left array me element abhi bhi bache hai
	while(leftIndex < lenLeft) {
		arr[mainArrayIndex] =  left[leftIndex];
		mainArrayIndex++;
		leftIndex++;
	}
	//1 more step pending
	delete[] left;
	delete[] right;
}

void mergeSort(int arr[], int s, int e) {
	//base case
	if(s >= e) {
		return;
	}
	//break
	int mid = (s+e)/2;
	//recusive call for left array
	mergeSort(arr,s, mid);
	//recusive call for right array
	mergeSort(arr, mid+1, e);
	//merge 2 sorted arrays
	merge(arr, s, e);
}

int main() {

	int arr[] = {2,5,9,3,5,8};
	int size = 6;
	int s = 0;
	int e = size - 1;

	cout << "Before merge sort: " << endl;
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	mergeSort(arr,s,e);

	cout << "After merge sort: " << endl;
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;



	return 0;
}





























// #include<iostream>
// using namespace std;

// void merge(int arr[],int start,int end){

//     int mid = start + (end - start)/2;
//     // left array ki length niklo
//     int lenLeft = mid - start + 1;
//     // right array ki length niklo
//     int lenRight = end - mid;

//     // create left and right array
//     int *left = new int[lenLeft];
//     int *right = new int[lenRight];

//     // copy value from original array to left array
//     int k = start;
//     for(int i=0; i<lenLeft; i++){
//         left[i] = arr[k];
//         k++;
//     }
//     // copy value from original array to right array
//     // k is starting index of right array
//     k = mid+1;
//     for(int i=0; i<lenRight; i++){
//         right[i] = arr[k];
//         k++;
//     }

//     // actual logic here
//     // left and right array already sorted
//     int leftIndex = 0;
//     int rightIndex = 0;
//     // yaha galti krte hai lok
//     int mainArrayIndex = start;

//     while(leftIndex < lenLeft && rightIndex < lenRight){

//         if(left[leftIndex] < right[rightIndex]) {
//             arr[mainArrayIndex] = left[leftIndex];
//             mainArrayIndex++;
//             leftIndex++;
//         }
//         else{
//             arr[mainArrayIndex] = right[rightIndex];
//             mainArrayIndex++;
//             rightIndex++;
//         }

//         // 2 more cases 
//         // case 1 -> left array exhaust(katham) ho chuka hai 
//         // par right array me abhi value bachi hai
//         while(rightIndex < lenRight){
//             arr[mainArrayIndex] = right[rightIndex];
//             mainArrayIndex++;
//             rightIndex++;
//         }

//         // Case 2 ->  right array exhaust(katham) ho chuka hai 
//         // par left array me abhi value bachi hai
//         while(leftIndex < lenLeft){
//             arr[mainArrayIndex] = left[leftIndex];
//             mainArrayIndex++;
//             leftIndex++;
//         }
//     }

//     // DELETED HEAP MEMORY
//     delete [] left;
//     delete [] right;

// }

// void mergeSort(int arr[],int start,int end){
//     // base case
//         if(start > end){
//             return;
//         }

//         if(start == end){
//             return;
//         }

//         int mid = start + (end - start) /2;
//         // start -> mid = left 
//         // mid+1 ->end = right

//         // recursion ko bhulao
//         // right or left array ko sort krwao
//         // recursive call for left array
//         mergeSort(arr,start,mid);
//         // recursive call for right array
//         mergeSort(arr,mid+1,end);

//         // merge two sorted arrays
//         merge(arr,start,end);

// }

// int main(){
//     int arr[] = {2,5,9,3,5,8};
//     int size = 6;
//     int start = 0;
//     int end = size-1;

//     cout<<endl;
//     cout<<endl;

//     cout<<"Befor merge sort :";
//     for(int i=0; i<size; i++){
//         cout<<arr[i]<<" ";
//     }

//     mergeSort(arr,start,end);

//     cout<<endl;
//     cout<<"After mergeSort :";
//     for(int i=0; i<size; i++){
//         cout<<arr[i]<<" ";
//     }

//     cout<<endl;
//     cout<<endl;
// }
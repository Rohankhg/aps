#include <bits/stdc++.h> 
using namespace std; 

int ternarySearchRecursion(int l, int r, int key, int ar[]) 
{ 
	if (r >= l) { 
		// Find the mid1 and mid2 
		int mid1 = l + (r - l) / 3; 
		int mid2 = r - (r - l) / 3;
		if (ar[mid1] == key) { 
			return mid1; 
		} 
		if (ar[mid2] == key) { 
			return mid2; 
		} 
		if (key < ar[mid1]) { 
			return ternarySearchRecursion(l, mid1 - 1, key, ar); 
		} 
		else if (key > ar[mid2]) { 

			return ternarySearchRecursion(mid2 + 1, r, key, ar); 
		} 
		else {

			return ternarySearchRecursion(mid1 + 1, mid2 - 1, key, ar); 
		} 
	} 

	return -1; 
} 

int ternarySearchIterative(int l, int r, int key, int ar[])   
{ 
    while (r >= l) { 
        int mid1 = l + (r - l) / 3; 
        int mid2 = r - (r - l) / 3; 
        if (ar[mid1] == key) { 
            return mid1; 
        } 
        if (ar[mid2] == key) { 
            return mid2; 
        } 

        if (key < ar[mid1]) { 
            r = mid1 - 1; 
        } 
        else if (key > ar[mid2]) { 
            l = mid2 + 1; 
        } 
        else { 
            l = mid1 + 1; 
            r = mid2 - 1; 
        } 
    } 

    return -1; 
} 
int main() 
{ 
	int left, right, index, key; 	
	cout<<"Enter Number Of Elements in the array:\n";
	cin>>right;
	int ar[right];
	cout<<"Enter The Elements In Array:\n";
	for(int i=0;i<right;i++){
	    cin>>ar[i];
	}
	left = 0;
	cout<<"Enter The Element To Be Searched:\n";
	cin>>key;
	index = ternarySearchIterative(left, right, key, ar);
	cout << "Iterative Approach : Index of " << key << " is " << index << endl; 
	index = ternarySearchRecursion(left, right, key, ar); 
	cout << "Recursive Approach : Index of " << key << " is " << index << endl; 
} 
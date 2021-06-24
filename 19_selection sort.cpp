include<bits/stdc++.h>
using namespace std;

void selection_sort(vector <int> &arr, int n) 
{
   int i=0;
   while(i<n)
   {
      int mini=i;
      int j=i+1;
      while(j<n)
      {
         if(arr[j]<arr[mini])mini=j;
         j++;
      }
      swap(arr[mini],arr[i]);
      i++;
   }   
}

int main() {
   int n;
   cout << "Enter the size of array:";
   cin >> n;
   vector <int> arr(n);
   cout << "Enter the elements of array:";
   for(auto &e:arr)cin>>e;
   selection_sort(arr, n);
   for(auto e:arr)cout<<e<<" ";

   return 0;
}

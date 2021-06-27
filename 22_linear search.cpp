#include<iostream>
using namespace std;

int main()
{
  int n,i,a;
  int pos=-1;      
  cout<<"Enter number of elements: ";
  cin>>n;
  cout<<"Enter the elements "<<endl;
  int arr[n];

  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  cout<<"Enter element to search ";
  cin>>a;

  for(i=0;i<n;i++)    
  {
    if(arr[i]==a)       
    {
      pos = i;       
      cout<<"Found at "<<pos;
      break;        
    }
  }

  if(pos == -1)    
  {
    cout<<"Not Found";
  }
  return 0;
}
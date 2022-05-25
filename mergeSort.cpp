/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;


void print(vector<int>& arr);
void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp(arr.size(),0);
    int i = start;
    int j = mid+1;
    int k = start;

    while(i <= mid || j <= end)
    {
        if(( j> end || i <= mid && arr[i] < arr[j]))
        {
            temp[k] = arr[i];
			i++;
        }
        else
        {
            temp[k] = arr[j];
			j++;
		}
		k++;
    }
    for(int l = start; l <= end; l++)
    {
        arr[l] = temp[l];
    }
}
void mergeSort(vector<int>& arr, int start, int end)
{
    if(start >= end) return;
    
    int mid = start + (end - start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
    
}
void print(vector<int>& arr)
{
    for(int i = 0; i< arr.size(); i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
}
int main()
{
    
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v[i] = num;
    }
    print(v);
    mergeSort(v, 0, n-1);
    print(v);

    return 0;
}




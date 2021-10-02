/*
Quick Sort code
Time complexity: O(n*log(n))
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll partition(ll ar[], ll low, ll high)
{
    ll i = low - 1, j, temp;

    for (j = low; j < high; j++)
    {
        if (ar[j] < ar[high])   // ar[high] is the chosen pivot(rightmost implementation)
        {
            i++;
            temp = ar[i];
            ar[i] = ar[j];
            ar[j] = temp;
        }
    }
    temp = ar[high];
    ar[high] = ar[i + 1];
    ar[i + 1] = temp; // actual pivot used(to be excluded now)

    return i + 1; //pivot location
}
void quick_sort(ll ar[], ll low, ll high)
{
    if (low < high) // low==high  means only one element(No need)
    {
        ll pi = partition(ar, low, high); // pivot

        quick_sort(ar, low, pi - 1);
        quick_sort(ar, pi + 1, high);
    }
}
int main()
{
    ll i;
    cout<<"Enter the total numbers to be sorted"<<endl;
    cin >> n;

    ll ar[n];
    cout<<"Enter the numbers(space separated) to sorted using quick sort"<<endl;
    for (i = 0; i < n; i++)
        cin >> ar[i];

    quick_sort(ar, 0, n - 1);
    cout<<"Sorted numbers :"<<endl;
    for (i = 0; i < n; i++)
        cout << ar[i] << ' ';
    cout << endl;

    return 0;
}
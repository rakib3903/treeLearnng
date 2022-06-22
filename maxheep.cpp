#include<bits/stdc++.h>
using namespace std;
int arr[1000];

int solve(int item,int n) {
    n = n + 1;
    int ptr = n;
    while(ptr > 1) {
        int par = ptr/2;
        if(item <= arr[par]) {
            arr[ptr] = item;
            return n;
        }
        arr[ptr] = arr[par];
        ptr = par;
    }
    arr[1] = item;
    return n;
}
int main() {

    int n;
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>arr[i];
    }
    int item;
    cin>>item;
    int x = solve(item,n);
    for(int i=1; i<=x; i++) cout<<arr[i]<< " ";
    cout<<endl;
    return 0;
}

#include<queue>
vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    vector<int> v;
    if(n==0){
        return v;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i =0; i< n; i++){
        pq.push(arr[i]);
    }
    for(int i =0; i< k; i++){
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}

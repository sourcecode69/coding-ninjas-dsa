
#include<vector>
#include<queue>
vector<int> kLargest(int arr[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    vector<int> v;
    if(n==0){
        return v;
    }
    priority_queue<int> pq;
    for(int i =0; i< n; i++){
        pq.push(arr[i]);
    }
    for(int i =0; i< k; i++){
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}

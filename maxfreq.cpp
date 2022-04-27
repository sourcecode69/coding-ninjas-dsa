#include<unordered_map>
int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> map;
    int max =0;
    for(int i =0; i<n; i++){
        map[arr[i]]++;
    }
    int key =0; int val=0;
    for(int i=0; i<n; i++){
        if(map[arr[i]] > val){
            val = map[arr[i]];
            key = arr[i];
        }
    }
    return key;
}

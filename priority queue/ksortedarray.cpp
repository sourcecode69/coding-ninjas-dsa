#include<queue>
void ksorted(int arr[], int n, int k ){
      priority_queue<int> pq;//inbuilt max .
      for(int i =0; i<k; i++){
          pq.push(arr[i]);
      }
      int j =0;
      for(int i =k; i< n; i++){
         arr[j] = pq.top();
         j++;
         qp.pop();
          pq.push(arr[i]); 
      }
      while(!pq.empty()){
        input[j] = pq.top();
        p.pop();
      }

}

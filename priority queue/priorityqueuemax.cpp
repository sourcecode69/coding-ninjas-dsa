#include<vector>
#include<algorithm>
#include<climits>
//generally ther is min priority que, thia class of max priority queue.
class PriorityQueue {
    // Declare the data members here
    vector<int> v;

   public:
    PriorityQueue() {
        // Implement the constructor here
        //now construcotr needed here.
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        v.push_back(element);
        int child = v.size()-1;
        while(child>0){
            int parent = (child-1)/2;
            if(v[child] > v[parent]){
                swap(v[child], v[parent]);
                child=parent;
            }
            else
            {
                break;
            }
        }
        
    }
//done.
    int getMax() {
        // Implement the getMax() function here
        return v[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(v.size() ==0){
        return INT_MIN;
        }
        int ans = v[0];
        v[0] = v[v.size()-1];
        v.pop_back();
        
        int p =0;
     
        int maxindex = 0;
    while(2*p+1<v.size()-1){
         int lci = 2*p+1;
        int rci=(2*p) +2;
        if(v[p] < v[lci] || v[p] < v[rci]){
            if(v[lci] > v[rci] && v[lci] > v[p]){
                swap(v[lci] , v[p]);
                maxindex = lci;
            }
            else if(v[rci] > v[lci] && v[p] < v[rci]){
                swap(v[rci] , v[p]);
                maxindex=rci;
            }
        }
        else
        {
            break;
        }
        }
        return ans;
    }
//done
    int getSize() { 
        // Implement the getSize() function here
        return v.size();
    }
//done
    bool isEmpty() {
        // Implement the isEmpty() function here
        if(v.size() == 0){
            return true;
        }
        else
        {
            return false;
        }
    }
};


#include <iostream>
using namespace std;

#include "solution.h"//class made above.

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}

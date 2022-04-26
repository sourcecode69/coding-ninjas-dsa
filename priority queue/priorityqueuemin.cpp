class priorityqueue{
    private:
    vector<int> v;
    public:
    //constructor -- no need to make a constructor.
    priorityqueue(){

    }
    bool isempty(){
        return v.size() == 0;
    }

    int getsize(){
        return v.size();
    }

    int getmin(){
        if(isempty){
            return 0;//empty queue.
        }
        else
        return v[0];
    }

    void insert(int data){
    v.push_back(data);
   
    int childindex = v.size()-1;
    while(childindex>0){
    
    int parentindex = (childindex-1)/2;
    if(v[childindex] < v[parentindex]){
        swap(v[child] , v[parentindex]);//using swap function.can be done by temp too.
    }
    else{
        break;
    }
childindex = parentindex;
    }
    }

int removeMin() {
        // Write your code here
        if(isempty){
            return 0;
        }
        int ans= pq[0];
        int rindex = pq.size() -1;
        pq[0] = pq[rindex];
        pq.pop_back();
        
        int p =0;
        int minindex = 0;
        while(p<rindex-1){
        int lci = (2*p) +1;
        int rci = (2*p)+2;
        
        if(pq[p] > pq[lci] || pq[p] > pq[rci]){
            if(pq[lci] < pq[rci] && pq[lci] < pq[p]){
                minindex = lci;
                swap(pq[lci] , pq[p]);
                            p=minindex;
            }
            else if(pq[rci] < pq[lci] && pq[rci] < pq[p]){
                minindex = rci;
                swap(pq[rci] , pq[p]);
                            p=minindex;
            }
        }
            else
            {
                break;
            }

        }
        return ans;
    }




};

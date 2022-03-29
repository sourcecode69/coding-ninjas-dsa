class dynamicarray(){
    int *data;
    int next;
    int size;
    public:
    // we make a constructor
    dyanamicarray(){
        data = new int[5];
        next =0;
        size =5;
    }
    // making a copy constructor so it does deep copy.
    dyanamicarray(dyanamicarray const &d){
        //now to do deep copy
        this-> data = new int[d.size];
        for(int i=0; i< d.next; i++){
            this->data = d.data[i];
        }
        this->next = d.next;
        this->size = d.size;
    }
    // copy assgnment 
    void operator=(dyanamicarray const &d){

         this-> data = new int[d.size];
        for(int i=0; i< d.next; i++){
            this->data = d.data[i];
        }
        this->next = d.next;
        this->size = d.size;
    }

    void add(int a){
        if(next == size){
            int *newdata = new int[2*size];
            for(int i =0; i< size; i++){
                newdata[i] = data[i];
            }
            delete data[];
            data = newdata;
            size *=2;

        }
        data[next] = a;
        next ++;

    }

    void getdata(int i ){
        if(i<next){
            return data[i];
        }
        else 
        return-1;

    }

    void add(int i, int a){
        if(i< next){
            data[i] = a;
        }
        else if (i == next){
            add(a);
        }
        else if(i>next){
            return;
        }
    }


    void print(){
        for(int i=0; i < next; i++){
            cout<<data[i]<<" ";
        }
    }
};

int main(){


    dynamicarray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.print();


    dyanamicarray d2(d1);
    // d2 will copy all of d1, but will do shallow copy .
    // now if we change d1, d2 will also change.
    dyanamicarray d3;
    d3 = d1;
    // this will do the same thing as the copy assignment also does shallow copy.
    //now to have deep copy you have to make your own copy constructor.
    // 
}

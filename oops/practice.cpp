#include<iostream>
using namespace std;

class fraction{
    private:
    int num;
    int dem;
    public:
    // we make a constructor 
    fraction(int num, int dem){
        this->num = num;
        this->dem = dem;

    }
    // this is just a getter function.
    void print (){
cout<<this->num <<"/"<<this->dem<<endl;
}
// simplify is greatest common factor.

void simplify(){
    int gcd = 1;
    int j = min(this->num, this -> dem);
    for(int i-0; i <=j ;i++){
        if(this->num%i == 0 && this->dem%i == 0){
            gcd=i;
        }
    }

    //now we simplify.
    this->num = this->num/ gcd;
    this->dem = this->dem/ gcd;
}

void add(fraction const &f2){
      int lcm = dem *f2.dem;
      int x =  lcm / dem;
      int y = lcm/ f2.dem;

      int num = x*num + (f2.num *y) ;
      
      this-> num = num;
      this->dem = lcm;
      simplify();

}
// now we make a function in which we return a fraction f3.
fraction add(fraction const &f2){
      int lcm = dem *f2.dem;
      int x =  lcm / dem;
      int y = lcm/ f2.dem;

      int num = x*num + (f2.num *y) ;
      
      //this-> num = num;
      //this->dem = lcm;
// we make a new fraction and then store the data

      fraction fnew(num,lcm);
      
      fnew.simplify();
      return fnew;

}

// this makes operator overloading.
fraction operator+(fraction const &f2){
      int lcm = dem *f2.dem;
      int x =  lcm / dem;
      int y = lcm/ f2.dem;

      int num = x*num + (f2.num *y) ;
      
      //this-> num = num;
      //this->dem = lcm;
// we make a new fraction and then store the data

      fraction fnew(num,lcm);
      fnew.simplify();
      return fnew;

}

bool operator==(fraction const &f2){
    return (num == f2.num && dem == f2.dem);
    // this will return true or false.
}

//pre increament operator.

void operator++(){
    num = num + dem ;
    simplify();
}
// now lets take we have to return it to a fraction.
fraction operator++(){
    num = num+dem;
    simplify();
    return *this;
    // now defernece this means that this had the address of num and dem .
    // by defernce we get the value of num and dem.
}
// now if we call ++(++f1) then it will change once and then it wont cause compiler makes
// a temporary memory an then if we store the whole in f3 it will change
// so to do this we have tp make the function by reference .
// this is function passed by reference
fraction& operator++(){
    num = num+dem;
    simplify();
    return *this;
    // now defernece this means that this had the address of num and dem .
    // by defernce we get the value of num and dem.
}

// now we want post increement 
// if we put int there then it becomes post inreement operator.
fraction operator++(int){
fraction fnew(num,dem);
num = num + dem;
simplify();
fnew.simplify();
return fnew;
}

// now += operator overloading
void operator+=(fraction cont &f2){
        int lcm = dem *f2.dem;
      int x =  lcm / dem;
      int y = lcm/ f2.dem;

      int num = x*num + (f2.num *y) ;
      
      this-> num = num;
      this->dem = lcm;
      simplify();
}
// although it is a correct function but nesting would now be possible cause the return type is void.
// to make it nested . we have to return the same fraction. *this and so it doesnt make a temporary copy
// we should make it refernce fucntion.
fraction& operator+=(fraction cont &f2){
        int lcm = dem *f2.dem;
      int x =  lcm / dem;
      int y = lcm/ f2.dem;

      int num = x*num + (f2.num *y) ;
      
      this-> num = num;
      this->dem = lcm;
      simplify();
      return *this;
}



};


int main(int argc, char const *argv[])
{
cout<<"hello world"<<endl;
    fration f1(10,35);
    fraction f2(15,40);
    fraction f3 = f1.add(f2);
    f3.print();
    fraction f4 = ++f3;
    f4.print();
    return 0;
}

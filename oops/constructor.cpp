int setdata(){

}
class student {
    Private:
    int age;
    int roll;
    // static member.
    static int totalstudnts;

    public:

    // to make such that every time we make a object of class total studnt updates
    // we make a copy constructor and then intialise the totalstudents.
    student(){
        totalstudents++;
    }
     int getage(){
         return this->age;
         // this char is used to specify which age we are talking about here.
     }
     int getroll() const {
         return this->roll;
     }

}

// static variables are always initialized outside the class .
int student::totalstudents = 20;

int main(){
    
   // if we make a const object of student class it means we cannot acess the fucntuons other than
   // the const function which doesnt change anything in the object.
   student const s1;
   s1.getage();//this will give error.
   s1.getroll(); // this will not give error as it is a const function.

    return 0;
}

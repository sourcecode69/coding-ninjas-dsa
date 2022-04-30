#include<unordered_map>
#include<iostream>
using namespace std;


template<typename V>
class mapnode{
    //cou;d have made it a friend class with ourmap.
    public:
string key;
V value;
mapnode* next;

mapnode(string key, V value){
this->key = key;
this->value = value;
thi->next = NULL;
}
//now we have to make a recursive destructor.
~mapnode{
    delete next;
}
};


template<typename V>
class ourmap{
mapnode<V>** bucket;
int size;
int numbuck;
//constructor.
ourmap(){
count =0;
numbuck=5;
bucket = new mapnode<V>* [numbuck];
//now all thi contain garbage value which is quite dangerous.
for(int i =0; i< numbuck; i++){
    bucket[i] = NULL;
}
}
//now we make destructor.
~ourmap(){
    for(int i =0; i< numbuck; i++){
    delete bucket[i];//first we would delete alll the linked list then we would delete the array.
}
delete []bucket;
}

int size(){
return count;
}
private:
int getbucketindex(string key){
    nt hashcode = 0;
int currentcoeff = 1;
for(int i=key.length()-1; i>=0;i--){
    hascode += key[i]* currentcoeff;
    currentcoeff *= 37;//taking 7 as our prime number could be any prime number.
    currentcoeff = currentcoeff % numbuck;
    hascode = hashcode % numbuck;}
return hashcode%numbuck;
}
private:
void rehash(){
mapnode<V> ** temp = bucket;
 bucket = new mapnode<v>*[2*numbuck];
 numbuck= 2*numbuck;
 for(int i =0; i< numbuck; i++){
     bucket[i] = NULL;
 }
 int oldbucket = numbuck/2;
 for(int i=0; i< oldbucket; i++){
     mapnode<V> * head = temp[i];
     while(head !=NULL){
         insert(head->key, head->value);
         head= head->next;
     }
 }
//now we rehashed so delete temp  now.
for(int i =0; i< oldbucket; i++){
    mapnode<V> * head = temp[i];
    delete head;
}
delete []temp;

}

public:
void insert(string key, V value){
int bucketindex = getbucketindex(key);
//now we get bucket index
//we have to check if it is preset or not ;
mapnode<V> * head = bucket[bucketindex];
while(head!=NULL){
    if(head->key == key){
        head->value=value;
        return;
    }
    head=head->next;
}
head = bucket[bucketindex];
mapnode<V> * node = new mapnode<V>(key,value);
node->next = head;
bucket[bucketindex] = node;
count++;//when new node is added not when node is updated.
//now rehashing because of load factor.
double loadfactor = (1.0 *count)/ numbuck;
if(loadfactor>0.7){
    //need of rehashing.
    reshash();
} 

}

return hashcode%numbuck;
}
V getvalue(string key){
    int bucketindex = getbucketindex(key);
mapnode<V>* head = bucket[bucketindex];
while(head!=NULL){
    if(head->key == key){
        return head->value;
    }
    head= head->next;
}
//if we dont get then.
return 0;
}
V remove(string key){
int bucketindex = getbucketindex(key);
mapnode<V>* head = bucket[bucketindex];
mapnode<V> * prev = NULL;
while(head != NULL){
    if(head->key ==key){
        if(prev==NULL){
            head= head->next;
            bucket[bucketindex] = head;
        }else{
        prev->next = head->next;
    }
    V valuetoreturn = head->value;
    head->next = NULL;
    delete head;
    count--;
    return valuetoreturn;
    }
    prev= head;
head= head->next;
}
//if we dont get the value.
return 0;

}

};



int main(){

}

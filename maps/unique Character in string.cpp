#include<unordered_map>
#include<string>
string uniqueChar(string str) {
	// Write your code here
    unordered_map<char, int> there;
    int index =0;
    // for(int i =0; i< str.length(); i++){
    //     map[str[i]++];
    // }
    //in this starting mien map mein sab zero hai and if map mein 1 bua then it measn it is already present .
    for(int i =0; i< str.size(); i++){
        if(there[str[i]] == 0){
            str[index] = str[i];
            index++;
            there[str[i]]++;
        }
    }
    str.erase(index);
   return str;
}

#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
bool hh(vector<int> seq){
    sort(seq.begin(),seq.end());
    while(true){
        sort(seq.begin(),seq.end(),greater<int>());
        if(seq[0]==0)return true;
        int i = seq[0];
        if(i>seq.size()-1)return 0;
        for(int j=1;i>0;i--,j++){
            if(--seq[j]<0)return 0;
            //cout << seq[j] << ' ';
        }
        //cout << endl;
        seq.erase(seq.begin());
    }
}
int main()
{
    vector<int> test;// {0, 0, 1, 1}; //{2, 1, 1, 1, 1};//{3, 2, 1, 0} ;
   /* 
    test.clear();
    ifstream in("input");
    streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    int t;
    while(cin >> t)
        test.push_back(t);
    cin.rdbuf(cinbuf);      
        
    cout << hh(test);
    return 0;
}

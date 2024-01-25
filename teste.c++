#include <bits/stdc++.h>

using namespace std;

bool func(pair<int,int> a,pair<int,int> b){
    return a < b; //True or false
}
int main(){
    pair <int,int> vet[4] = {{1,2},{2,3}, {3,4}, {4,5}};

    sort(vet,vet+4,func);
    for (int i = 0; i <4; i++  )
    {
        cout << "{ " << vet[i].first << " , " << vet[i].second << "} ";
    }
    

}
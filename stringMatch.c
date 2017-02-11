
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int matriz[50][50];

void transition(string P, string Alfabeto){
    int m = P.length();
    int k;

    for(int q = 0; q <= m; q++){
        for(int i=0;i<Alfabeto.size();i++){
            k = min(m+1, q+2);
            string PQ, PK;
            do{
                k = k-1;
                PQ = P.substr(0,q) + Alfabeto[i];
                PK = P.substr(0,k);

            }while(PQ.compare (PQ.length() - PK.length(), PK.length(), PK) != 0);
            matriz[q][Alfabeto[i]] = k;
        }
    }
}

int matcher(string Text, int m){
    int n = Text.length();
    int q = 0;
    int i;
    int sum = 0;
    for (i = 0; i<n;i++){
        q = matriz[q][Text[i]];
        if (q == m)
        sum++;
    }
    return sum;
}

int main(int argc, char* argv[]){
    string Alfabeto;
    cin >> Alfabeto;
    string P;
    cin >> P;
    string text;
    cin >>text;
    transition(P, Alfabeto);
    cout << matcher(text, P.length());
    return 0;
}
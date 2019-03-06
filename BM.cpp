#include<iostream>
#include<cstring>

using namespace std;

int Dist(const string &T, char ch);
int BM(const string &S, const string &T);

int main()
{
    string a = "ababcabcacbab", b = "abcac";
    cout << BM(a, b) << endl;
    return 0;
}

int Dist(const string &T, char ch){
    int i = T.length() - 1;
    if(ch == T[i]){
        return T.length();
    }
    i --;
    while(i >= 0){
        if(ch == T[i]){
            return T.length() - i - 1;
        }else{
            i--;
        }
    }
    return T.length();
}
int BM(const string &S, const string &T){
    int i = T.length() - 1;
    int j = T.length() - 1;
    while(j >= 0 && i < S.length()){
        if(S[i] == T[j]){
            i--;
            j--;
        }else{
            j = T.length() - 1;
            i += Dist(T, S[i]);
        }
    }
    if(j < 0){
        return i + 1;
    }
    return -1;
}
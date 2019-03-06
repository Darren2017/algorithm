#include<iostream>
#include<cstring>

using namespace std;

void GetNext(const string &T, int next[]);
int KMP(const string &S, const string &T);

int main()
{
    string a = "ababcabcacbab", b = "abcac";
    cout << KMP(a, b) << endl;
    return 0;
}

int KMP(const string &S, const string &T){
    int i = 0, j = 0, next[T.length()];
    GetNext(T, next);
    // for(int i = 1; i <= T.length(); i++){
    //     cout << next[i] << "  ";
    // }
    // cout << endl;
    while(i < S.length() && j < T.length()){
        if(j == 0 || S[i] == T[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
        if(j == T.length()){
            return i - T.length();
        }
    }
    return -1;
}

void GetNext(const string &T, int next[]){
    int j = 1, k = 0;
    next[1] = 0;
    while(j < T.length()){
        if(k == 0 || T[j - 1] == T[k - 1]){
            j++;
            k++;
            next[j] = k;
        }else{
            k = next[k];
        }
    }
}
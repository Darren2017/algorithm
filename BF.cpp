#include<iostream>
#include<cstring>

using namespace std;

int BF(const string &S, const string T);

int main()
{
    string a = "aabdsbdsfsfds", b = "sbds";
    cout << BF(a, b) << endl;
    return 0;
}

int BF(const string &S, const string T){
    int i = 0, j = 0, ret = 0;
    while(j < T.length() && i < S.length()){
        if(T[j] == S[i]){
            j++;
            i++;
        }else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(i < S.length()){
        ret = i - T.length();
    }else{
        ret = -1;
    }

    return ret;
}
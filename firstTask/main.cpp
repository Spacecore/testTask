#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool primeNumberCheck(int aNumber);
vector<int>* factorization(int aNumber);

int main()
{
    int number = 0;
    vector<int>* valueArray;
    cout<<"Enter number"<<endl;
    cin>>number;
    for(int i=1; i<=number; i++){
        if(!primeNumberCheck(i)) {
            valueArray = factorization(i);
            cout<<i<<" = ";
            for(int i = 0; i<valueArray->size(); i++) {
                cout<<valueArray->at(i);
                if(i<valueArray->size()-1){cout<<" * ";}
            }
            cout<<endl;
        }
        else{
            cout<<i<<" = "<<i<<" * 1"<<endl;
        }
    }
    return 0;
}

bool primeNumberCheck(int aNumber) {
    bool isPrime = true;
    if(aNumber <= 1){return isPrime;}
    else {
        for(int i = 2; i<aNumber; i++) {
            if(aNumber%i==0){isPrime = false;break;}
        }
    }
    return isPrime;
}

vector<int>* factorization(int aNumber) {
    vector<int>* factorizationArray = new vector<int>;
    int i = 2;
    while(i<=aNumber) {
        if(aNumber%i == 0) {
            factorizationArray->push_back(i);
            aNumber = aNumber/i;
        } else {i += 1;}
    }
    return factorizationArray;
}

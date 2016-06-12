#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int>* container;
    container = new vector<int>;
    srand(time(NULL));
    for(int i=0; i<rand()%300; i++){
        container->push_back(i);
    }
    cout<<"Length of the vector = "<<container->size()<<endl;
    int countOfSection = container->size()/2;
    while(container->size()%countOfSection != 0) {
        countOfSection--;
        if(countOfSection == 1) {countOfSection = container->size();}
    }
    int dotInSection = container->size()/countOfSection;
    int currentDot = 0;
    int currentSection = 1;
    while(currentDot < container->size()-1) {
        cout<<"Section: "<<currentSection<<" = ["<<currentDot<<" ";
        for(int i=1;i<=dotInSection;i++) {
            currentDot++;
            if(currentDot == container->size()-1){break;}
            if(currentDot + 1 == container->size()-1){currentDot++;break;}
        }
        cout<<currentDot<<"]"<<endl;
        currentSection++;
        currentDot++;
    }
    return 0;
}


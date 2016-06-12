#include <iostream>

using namespace std;

struct list {
public:
    int index;
    struct list* next;
};


int main()
{
    struct list* start = NULL;
    struct list** end = &start;

    int length = 0;
    cout<<"Enter length ";
    cin>>length;

    start = new list;
    for(int i=0; i<length; i++) {
        if(!start) {start = *end;}
        *end = new list;
        (*end)->index = i+1;
        end = &(**end).next;
        *end = NULL;
    }
    struct list* p;
    p = start;
    while(p) {
        cout<<p->index<<endl;
        p = (*p).next;
    }
    cout<<endl<<endl;
    struct list* p2;
    p2 = start;
    for(int i=0; i<length/2; i++) {
        struct list* tempEndP;
        p = start;
        while(p->next->next) {
            p = p->next;
        }
        tempEndP = p->next;
        p->next = NULL;
        struct list* tempP;
        tempP = p2->next;
        p2->next = tempEndP;
        tempEndP->next = tempP;
        p2=p2->next->next;
    }
    p = start;
    while(p) {
        cout<<p->index<<endl;
        p = (*p).next;
    }
    return 0;
}


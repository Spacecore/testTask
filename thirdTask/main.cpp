#include <iostream>
#include <getopt.h>
#include <cstring>
#include <stdio.h>
#include <cstdlib>

using namespace std;


int main(int argc, char *argv[])
{
    int response = 0;
    const char* shortOpt = "abc";           //добавлен т.к. getOpt требует этот параметр, однако в обработке не используется
    const struct option optionsArray[] = {
        {"help", no_argument, NULL, 1},
        {"print", optional_argument, NULL, 2},
        {"mult", required_argument, NULL, 3},
        {NULL,0,NULL,0}
    };

    while((response = getopt_long(argc,argv,shortOpt,optionsArray,NULL)) != -1) {
        switch(response){
            case 1: {
                cout<<"--help to see this menu"<<endl;
                cout<<"--print [val] to print val"<<endl;
                cout<<"--mult val to squared val"<<endl;
                break;
            }
            case 2: {
                if(optarg != NULL) {
                    printf("print: %s\n", optarg);
                } else {
                    printf("print:\n");
                }
                break;
            }
            case 3:{
                printf("%f\n", atof(optarg)*atof(optarg));
                break;
            }
        }
    }
    return 0;
}

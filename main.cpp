#include <iostream>
#include <windows.h>

#include "keylist.h"

#define button num_9
#define tps 40
#define tpr 1.0/tps

using namespace std;

int init();

HWND hwnd;

int main() {

}

int init(int count = 0){
    cout << "Acquiring BlueStacks hwnd" << endl;
    hwnd = FindWindow(NULL, "BlueStacks App Player");
    Sleep(1000);
    if (hwnd == 0){
        cout << "Failed to acquired hwnd (or BlueStacks isn't opened)" << endl;
        if (count > 4) return -1;
        cout << "Retry in 5 seconds";
        for (int i = 0; i < 4; i++) { cout << "."; Sleep(1000); } cout << endl;
        init(count+1);
    } else {
        cout << "Got " << hwnd << " as hwnd of BlueStacks" << endl;
        cout << "Spamming [" << button << "] to BlueStacks" << endl;
        cout << "Rate of tap is ("  << tps << ") tap per second" << endl;
        cout << "Tap every {" << tpr << "} second" << endl;
    }
}
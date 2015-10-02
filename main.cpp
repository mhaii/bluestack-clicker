#include <iostream>
#include <windows.h>

#include "keylist.h"

#define button spacebar
#define tps 40
#define tpr 1000.0/tps

using namespace std;

int init(int);
int tap();
inline void sleep(DWORD sec) { Sleep(sec*1000); }

HWND hwnd;

int main() {
    tap();
}

int tap(){
    while (init(0)){
        while (hwnd){
            if (GetForegroundWindow() == hwnd) {
                while (GetKeyState(VK_LBUTTON) < 0);
            }
            PostMessage(hwnd, WM_KEYDOWN, button, 0);
            PostMessage(hwnd, WM_KEYUP, button, 0);
            Sleep(tpr);
        }
    }
}

int init(int count){
    cout << "Acquiring BlueStacks hwnd" << endl;
    hwnd = FindWindow(NULL, "BlueStacks App Player");
    sleep(1);
    if (hwnd == 0){
        cout << "Failed to acquired hwnd (or BlueStacks isn't opened)" << endl;
        if (count > 4) return 0;
        cout << "Retry in 5 seconds";
        for (int i = 0; i < 4; i++) { cout << "."; sleep(1); } cout << endl;
        return init(count+1);
    } else {
        cout << "Got " << hwnd << " as hwnd of BlueStacks" << endl;
        cout << "Spamming [" << button << "] to BlueStacks" << endl;
        cout << "Rate of tap is ("  << tps << ") tap per second" << endl;
        cout << "Tap every {" << tpr << "} miliseconds" << endl;
        return 1;
    }
}

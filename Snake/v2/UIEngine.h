#ifndef UIENGINE_H
#define UIENGINE_H

#include <windows.h>
#include <iostream>

using namespace std;
class UIEngine
{
    public:
        static UIEngine & getInstance() {
            static UIEngine instance; 
            return instance;
        }    
        UIEngine(UIEngine const&) = delete;
        void operator=(UIEngine const&) = delete;

        void update(int x, int y, char o) {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {short(x), short(y)});
            cout << o;
        }

    private:
        UIEngine() {}  
};

#endif
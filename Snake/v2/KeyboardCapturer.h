#include <conio.h>
#ifndef KEYBOARDCAPTURER_H
#define KEYBOARDCAPTURER_H

#include <iostream>

using namespace std;
class KeyboardCapturer
{
    public:
        static KeyboardCapturer & getInstance() {
            static KeyboardCapturer instance; 
            return instance;
        }    
        KeyboardCapturer(KeyboardCapturer const&) = delete;
        void operator=(KeyboardCapturer const&) = delete;

        bool capture(char & key) {
            if (!_kbhit())
                return false;

            key = _getch();
            return true;
        }

    private:
        KeyboardCapturer() {}  
};

#endif
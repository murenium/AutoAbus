#include <iostream>
#include <windows.h>

using namespace std;

void wait() {
    cout << "Зажмите Alt, атака через:" << endl;
    cout << 3;
    Sleep(1000);
    cout << 2;
    Sleep(1000);
    cout << 1;
    Sleep(1000);
    cout << 0 << endl << "Атака...";
    return;
}

void Add() {
     cout << "Задержка(милисекунды): ";
    DWORD time;
    cin >> time;
    wait();
    while(true) {
        keybd_event('Y', 0, 0 ,0);
        keybd_event('Y', 0, KEYEVENTF_KEYUP, 0);
        Sleep(time);
    }
}

void Super() {
    wait();
    while(true) {
        keybd_event('Y', 0, 0 ,0);
        keybd_event('Y', 0, KEYEVENTF_KEYUP, 0);
    }
}

int main() {
    SetWindowText(GetConsoleWindow(), "AutoAbus");
    cout << "INFO: AutoAbus v1.0-RRC x64"<< endl << "license: GNU GPL v3" << endl;
    setlocale(LC_ALL, "Russian");
    cout << "Создатель: big_floppa#1441" << endl << "Сделано для Союза рейдеров" << endl << "https://t.me/SOUZREIDEROV" << endl << "Выберите режим:" << endl << "1 - Super" << endl << "2 - Addvansted" << endl << "Режим: ";
    int mode;
    cin >> mode;
    if(mode == 1) {
        Super();
    }
    else{
        if(mode == 2) {
            Add();
        }
        else{
            cout << "Error!";
            Sleep(5000);
        }
    }
    return 0;
}


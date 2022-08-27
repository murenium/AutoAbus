#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

bool timeout_on_start;
char attack_key;

void wait() {
    if(timeout_on_start) {
        cout << "Зажмите Alt, атака через:" << endl;
        cout << 3;
        Sleep(1000);
        cout << 2;
        Sleep(1000);
        cout << 1;
        Sleep(1000);
        cout << 0 << endl;
    }
    cout << "Атака...";
}

Attack(DWORD time) {
    while(true) {
        keybd_event(attack_key, 0, 0 ,0);
        keybd_event(attack_key, 0, KEYEVENTF_KEYUP, 0);
        Sleep(time);
    }
}

int main() {
    SetWindowText(GetConsoleWindow(), "AutoAbus for zoom");
    cout << "INFO: AutoAbus v2.1-RRC x64"<< endl << "license: GNU GPL v3" << endl;
    setlocale(LC_ALL, "Russian");
    ifstream settings_file;
    settings_file.open("settings.config");
    if(!settings_file){
        cout << "Не найден файл settings.config" << endl << "Копия программы испорчена.";
        Sleep(5000);
        return -1;
    }
    string line, line2, line3;
    getline(settings_file, line);
    getline(settings_file, line2);
    getline(settings_file, line3);
    if(line == string("timeout")){
        if(line2 == string("1")) timeout_on_start = true;
        else if(line2 == string("0")) timeout_on_start = false;
        else{
            cout << "Файл settings.config повреждён." << endl << "Копия программы испорчена.";
            Sleep(5000);
            return -1;
        }
    }
    char buf[1];
    strcpy(buf, line3.c_str());
    attack_key = buf[0];
    settings_file.close();
    cout << "Создатель: big_floppa#1441" << endl << "Сделано для Союза рейдеров" << endl << "https://t.me/SOUZREIDEROV" << endl << "Выберите режим:" << endl << "1 - Super" << endl << "2 - Addvansted" << endl << "3 - Normal" << endl << "4 - Fast" << endl << "5 - Smart" << endl << "6 - Smart+" << endl << "Режим: ";
    int mode;
    cin >> mode;
    if(mode == 1) {
        char yn;
        cout << "Этот режим работает не очень хорошо, вы точно уверены?[Y/n]";
        cin >> yn;
        if(yn == 'Y'){
            wait();
            while(true) {
                keybd_event(attack_key, 0, 0 ,0);
                keybd_event(attack_key, 0, KEYEVENTF_KEYUP, 0);
            }
        }
        else{
            return 0;
        }

    }
    else if(mode == 2) {
        cout << "Задержка(милисекунды): ";
        DWORD time;
        cin >> time;
        wait();
        Attack(time);
    }
    else if(mode == 3) {
        wait();
        Attack(100);
    }
    else if(mode == 4) {
        wait();
        Attack(50);
    }
    else if(mode == 5) {
        wait();
        while(true){
            keybd_event(attack_key, 0, 0 ,0);
            keybd_event(attack_key, 0, KEYEVENTF_KEYUP, 0);
            Sleep(rand() % 200 + 25);
        }
    }
    else if(mode == 6) {
        int tMin, tMax;
        cout << "Минимальное время: ";
        cin >> tMin;
        cout << "Максимальное время: ";
        cin >> tMax;
        wait();
        while(true){
            keybd_event(attack_key, 0, 0 ,0);
            keybd_event(attack_key, 0, KEYEVENTF_KEYUP, 0);
            Sleep(rand() % tMax + tMin);
        }
    }
    else{
        cout << "Error!";
        Sleep(5000);
    }
    return 0;
}


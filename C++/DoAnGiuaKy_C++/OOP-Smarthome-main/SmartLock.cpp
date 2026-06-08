#include "SmartLock.h"
#include <iostream>

using namespace std;


SmartLock::SmartLock(int id, string name, bool lockedStatus)
: Device(id, name), isLocked(lockedStatus){}

void SmartLock::toggle(){
    if(isError){
        cout << "[!] " << name << " lỗi không thể mở!" << endl;
        return;
    }

    isLocked = !isLocked;
    cout << "[KHÓA] " << name << (isLocked ? " KHÓA" : " MỞ KHÓA") << endl;
}

void SmartLock::locked(){
    isLocked = true;
}

void SmartLock::unlocked(){
    isLocked = false;
}

void SmartLock::getStatus(){
    cout << "[KHÓA] " << name 
         << " ID: " << id << " - " 
         << (isLocked ? "KHÓA" : "MỞ KHÓA") << endl;
}


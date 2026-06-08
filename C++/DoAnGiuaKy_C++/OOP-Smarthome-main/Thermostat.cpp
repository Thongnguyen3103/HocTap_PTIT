#include "Thermostat.h"
#include "SmartHomeExceptions.h"
#include <cmath>
#include <iostream>
#include <ctime>
#include <cstdlib>

Thermostat::Thermostat(int id, string name, float init, float target)
: Device(id, name), currentTemp(init), targetTemp(target), heaterOn(false), coolerOn(false) {}

void Thermostat::toggle(){
    if (isError) {
        cout << "[!] " << name << " lỗi không thể mở!" << endl;
        return;
    }

    isOn = !isOn;
    if(!isOn){
        heaterOn = false;
        coolerOn = false;
    }

    cout << "[NHIỆT] " << name << (isOn ? " BẬT" : " TẮT") << endl;
}

void Thermostat::updateEnvironment(){
    if(!isOn){
        coolerOn = false;
        heaterOn = false;
        if(currentTemp < 30.0f) currentTemp += 0.5f;
        if(currentTemp > 30.0f) currentTemp -= 0.5f;
        return;
    }

    if(currentTemp > targetTemp + 0.5f){
        coolerOn = true;
        heaterOn = false;
        currentTemp -= 0.5f;
    }else if(currentTemp < targetTemp - 0.5f){
        coolerOn = false;
        heaterOn = true;
        currentTemp += 0.5f;
    }else{
        coolerOn = false;
        heaterOn = false;
    } 
}

void Thermostat::getStatus(){
    if(heaterOn){
        cout << "Đang sưởi ấm..." << endl;
    }else if(coolerOn){
        cout << "Đang làm mát..." << endl;
    }else{
        cout << "Đang ổn định." << endl;
    }

    cout << "[NHIỆT] " << name << " hiện tại " << currentTemp << " độ C" << endl;
    cout << "[NHIỆT] " << name << " mục tiêu " << targetTemp << " độ C" << endl;
}

void Thermostat::setTargetTemp(float t){
    targetTemp = t;
    cout << "[NHIỆT] " << name << " đã đặt mục tiêu " << targetTemp << " độ C" << endl;
}

void Thermostat::forceFeedbackLoop(){
    cout << "MÔ TẢ VÒNG LẶP PHẢN HỒI (LỖI HỆ THỐNG)" << endl;
    cout << "Nhiệt độ hiện tại: " << currentTemp
         << ", Mục tiêu: " << targetTemp << endl;

    srand(time(0));
    isOn = true; 
    int feedbackCount = 0;

    while (feedbackCount < MAX_FEEDBACK) {
        feedbackCount++;
        cout << "Chu kỳ " << feedbackCount << endl;

        //LẠNH ĐỘT NGỘT -> BẬT MÁY SƯỞI
        if (feedbackCount % 2 != 0) {
            currentTemp = 10.0f + (rand() % 11);
            cout << "Nhiệt độ GIẢM đột ngột: " << currentTemp << " độ C" << endl;
            updateEnvironment(); 
            
            if (heaterOn) cout << "Máy sưởi: BẬT!" << endl;
        }
        //NÓNG ĐỘT NGỘT -> BẬT MÁY LẠNH
        else {
            currentTemp = 32.0f + (rand() % 11);
            cout << "Nhiệt độ TĂNG đột ngột: " << currentTemp << " độ C" << endl;
            updateEnvironment(); 
            
            if (coolerOn) cout << "Máy lạnh: BẬT!" << endl;
        }

        if (feedbackCount == MAX_FEEDBACK) {
            throw FeedbackLoopException();
        }
    }
}

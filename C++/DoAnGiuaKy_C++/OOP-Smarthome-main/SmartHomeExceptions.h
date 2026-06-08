#ifndef SMART_HOME_EXCEPTION_H
#define SMART_HOME_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class UnauthorizedAccessException : public exception {
    string msg;
public:
    UnauthorizedAccessException(const string& device)
        : msg("[CẢNH BÁO BẢO MẬT] Truy cập trái phép vào thiết bị: " + device) {}
    const char* what() const noexcept override { return msg.c_str(); }
};
 
class FeedbackLoopException : public exception {
public:
    const char* what() const noexcept override {
        return "[LỖI HỆ THỐNG] Vòng lặp phản hồi phát hiện! Hệ thống dừng khẩn cấp.";
    }
};

#endif
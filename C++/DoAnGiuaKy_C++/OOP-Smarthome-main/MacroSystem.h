#ifndef MACRO_SYSTEM_H
#define MACRO_SYSTEM_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <functional>
using namespace std;

class MacroSystem {
    map<string, vector<function<void()>>> macros;

    public:
        // NẠP HÀNH ĐỘNG KỊCH BẢN
        void addMacro(const string& name, vector<function<void()>> actions) {
            macros[name] = actions;
        }

        // THỰC THI KỊCH BẢN
        void execute(const string& name){
            auto it = macros.find(name);
            if(it == macros.end()){
                cout << "[KỊCH BẢN] Không tìm thấy kịch bản tự động: " << name << endl;
                return;
            }

            for(size_t i = 0; i < it->second.size(); i++){
                cout << "  -> Bước " << (i+1) << ": " << endl;
                it->second[i]();
            }
        }

        // DANH SÁCH KỊCH BẢN
        void listMacro(){
            cout << "Danh sách các kịch bản tự động hóa:" << endl;
            for(auto &macro: macros){
                cout << " - " << macro.first << " (" << macro.second.size() << " bước hành động)" << endl;
            }
        }
};

#endif
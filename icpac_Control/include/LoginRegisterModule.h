//
// Created by NWT on 2024/11/10.
//

#ifndef ICPAC_CONTROL_LOGINREGISTERMODULE_H
#define ICPAC_CONTROL_LOGINREGISTERMODULE_H


#include <string>

class LoginRegisterModule {
public:
    //注销账号
    virtual bool resign(std::string name, std::string power) = 0;

    //注册账号
    virtual bool sign(std::string name, std::string power) = 0; // 无需实

    //登入账号
    virtual bool Login(std::string name, std::string power) = 0;


private:
    std::string name;  //用户名
    std::string power;  // 用户密码
};

#endif //ICPAC_CONTROL_LOGINREGISTERMODULE_H

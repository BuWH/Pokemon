//
// Created by 温和 on 2018/10/8.
//
#pragma once
#ifndef SERVER_CONST_DEFINE_H
#define SERVER_CONST_DEFINE_H

#define ERROR -1
#define TRUE 1
#define FALSE 0

enum RequestType {
    login,
    signup,
    logout,
    updateuser
};

#endif //SERVER_CONST_DEFINE_H
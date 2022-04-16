//
// Created by Osama  Mohammed on 4/16/2022.
//
#include<bits/stdc++.h>
#include "Message.h"
using namespace std;

#pragma once

class User {
private:
    int ID;
    string Username;
    string Password;
    vector<int> Contacts;
    queue<Message> FavMsgs;
    vector<Message> RecMessages;
    stack<pair<int,Message>> SentMessages;

public:
    User();
    User(string User, string Pass, int id);
    string GetUsername();
    string GetPassword();
    ~User();
};




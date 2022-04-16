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
    User(string User, string Pass);

    void addUserToContact(int);
    void searchContact(int);
    void displayUserContacts(int);

    ~User();
};




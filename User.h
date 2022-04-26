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
    vector<Message> RecMessages[101];
    stack<pair<int,Message>> SentMessages;


public:
    //Base
    User();
    User(string User, string Pass, int id);
    string GetUsername();
    string GetPassword();


    //7alw&ASHRAF
    /*----------------------------*/
    void addContact(int userID);
    static void displayContacts(int userID, User data[]);
    void searchForContact(string name , User data[]);
    /*----------------------------*/

    //soha
    void sendMessage(int Id, const string &txt, User data[]);
    void undoLastMessage(User data[]);
    void getMessagesFrom(int Id);

    //yasmin
    void addRecentMsgToFav(int id);
    void viewAllFavMsgs();
    void removeOldestFavMsg();

    ~User();
};




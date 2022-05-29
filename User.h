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


    void SaveDataToFile(ofstream &data);
    void ReadDataFromFile(ifstream &data);

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
    void viewSentMessages(User data[]);

    //yasmin
    void addRecentMsgToFav(int id);
    void viewAllFavMsgs();
    void removeOldestFavMsg();

    ~User();
};




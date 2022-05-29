//
// Created by Osama  Mohammed on 4/16/2022.
//

#include "Message.h"
#include<bits/stdc++.h>
using namespace std;

Message::Message() = default;

Message::Message(string tx) {
    this->Content = tx;
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    this->Time = buf;
}

Message::Message(string tx, string t){
    this->Content = tx;
    this->Time = t;
}

string Message::GetContent() {
    return this->Content;
}

string Message::GetTime() {
    return this->Time;
}


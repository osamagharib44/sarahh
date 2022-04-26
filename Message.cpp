//
// Created by Osama  Mohammed on 4/16/2022.
//

#include "Message.h"
#include<bits/stdc++.h>
using namespace std;

Message::Message() = default;

Message::Message(string tx) {
    this->Content = tx;
    this->Time = "12:00 AM";
}

string Message::GetContent() {
    return this->Content;
}

string Message::GetTime() {
    return this->Time;
}


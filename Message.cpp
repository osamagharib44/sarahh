//
// Created by Osama  Mohammed on 4/16/2022.
//

#include "Message.h"
#include<bits/stdc++.h>
using namespace std;

Message::Message(string tx, int t) {
    this->Content = tx;
    this->Time = t;
}

string Message::GetContent() {
    return this->Content;
}

int Message::GetTime() {
    return this->Time;
}

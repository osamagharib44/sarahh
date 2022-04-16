#include<bits/stdc++.h>
#include "User.h"

using namespace std;
User arr[100];

int main(){
    arr[1] = User("Osama","123", 1);
    arr[10] = User("7alaaawaaaa", "mashy", 10);

    cout << arr[1].GetUsername() << endl;
    cout << arr[10].GetUsername() << endl;
}
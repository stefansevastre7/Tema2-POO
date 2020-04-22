#include <iostream>
#include <cstring>
#include "Nod.h"
#include "Coada.h"
#include "Deque.h"
#include "Deque_marcaj.h"

using namespace std;

int main()
{
    Coada a;
    a.insert("555",1);
    a.insert("111", 5);
    a.insert("abc", 1);
    a.pop();
    cout << a;
    return 0;
}

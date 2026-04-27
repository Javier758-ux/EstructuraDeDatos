#include <iostream>
#include "QueueDin.h"

using namespace std;

int main()
{
    QueueDin s;
    DATA_TYPE d;

    // llenando la cola
    for (d = 'A'; d <= 'Z'; d++) {
        s.put(d);
        cout << d << " ";
    }

    cout << endl;

    // vaciando la cola
    while (!s.empty())
        cout << s.get() << " ";

    cout << "\nPara terminar presione <Enter>...";
    cin.get();

    return 0;
}
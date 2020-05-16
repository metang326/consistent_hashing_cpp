#include <iostream>
#include "my_hash.h"
#include <sys/types.h>
#include <winsock2.h>

using namespace std;
#pragma comment(lib, "ws2_32.lib")

int main() {
    consistent_hash hash = consistent_hash();
    hash.add_real_node("192.168.2.136", 300);

    hash.put("metang1996");
    hash.put("buaa");
    hash.put("hello world");
    hash.put("test add data");
    hash.put("python");
    hash.put("c++");

    cout << endl << "---------------------------------step 1---------------------------------" << endl;
    hash.print();

    cout << endl << "---------------------------------step 2---------------------------------" << endl;
    hash.add_real_node("192.168.2.137", 300);
    hash.add_real_node("192.168.2.138", 300);
    hash.print();

    cout << endl << "---------------------------------step 3---------------------------------" << endl;
    hash.drop_real_node("192.168.2.136");
    hash.print();
    return 0;
}


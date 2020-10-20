#include<iostream>
#include "queue.h"
#include "stack.h"
using namespace std;

int main() {

    LinkedQueue linkQ;
    for (int i = 1; i <= 10; i++)
        linkQ.insert_last(i);

    linkQ.delete_front();
 
    cout << "=== Linked Queue ===" << endl; 
    linkQ.print_list();
   
    cout << endl;
    cout << "Search Data 4 : Node " << linkQ.serach(4) << endl;


    cout << endl;


    LinkedStack linkS;
    for (int i = 1; i <= 10; i++)
        linkS.insert_front(i);

    linkS.delete_front();
    linkS.delete_front();

    cout << "=== Linked Stack ===" << endl;
    linkS.print_list();
    
    cout << endl;
    cout << "Search Data 7 : Node " << linkS.serach(7) << endl;

}
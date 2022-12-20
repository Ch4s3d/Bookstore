#include "Bookstore.h"

int main()
{
    Bookstore* bookstore = new Bookstore();

    while(bookstore->showMenu()){}

    cout << "Ch4s3d!" << endl;
    return 0;
}

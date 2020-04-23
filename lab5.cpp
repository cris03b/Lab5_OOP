// lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <atlstr.h>
#include "Controller.cpp"

using namespace std;

int main()
{
    //system("<mybrowser> http://google.com");
    /*CString url = "http://www.cs.ubbcluj.ro/~rusu/oop/lab/L4.pdf";
    ShellExecute(0, 0, url, 0, 0, SW_SHOW);*/
    Controller cont;
    cont.repo.create_list();
    cont.show_watchlist("drama");

    return 0;
}


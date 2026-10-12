// Homework4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MyString.h";
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h";


    TEST_CASE("testing functions") {
        MyString s1("Jerusalem", 10);
        MyString s2("is", 3);
        MyString s3("my home", 8);
        MyString s4("home", 8);
        CHECK(s1[2] == 'r');
        //CHECK_THROWS(S1[20]);
        CHECK(s2 == s2);
        CHECK(s2.getData() != s1.getData());
        CHECK(bool(s2) == true);
        CHECK(bool(MyString()) == false);
        //CHECK(s3.getData()+s4.getData()=="my home home");
        //CHECK(s3.getData() - s4.getData() == "my home home");
    }
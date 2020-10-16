// static_string_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "vld.h"
#include "static_string.h"

void access_strings()
{
    // Just do something with the string so it isn't optimized away
    std::string copied_string = my_string::the_string;
    printf("Copied string %s\n", copied_string.c_str());

    std::string copied_string2 = string_global;
    printf("Copied string %s\n", copied_string2.c_str());
}

int main(int argc, char **argv)
{
    access_strings();

    int leaks = static_cast<int>(VLDGetLeaksCount());
    if (0 != leaks)
    {
        printf("!!! FAILED - Leaks detected: %i\n", leaks);
        VLDReportLeaks();
    }
    else
    {
        printf("PASSED\n");
    }


    return leaks;
}

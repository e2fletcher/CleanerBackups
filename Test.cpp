#include <iostream>
#include <fnmatch.h>
using namespace std;

int main()
{
    const char* a[] = {
        "Tacoma,como un rayito de luna entre las selvas dormidas \
            la luz de mis ojos a iluminado mi pobre vida\
            como te extraño mi amor porque sera me falta todo en \
            la vida si no estas, como será mi amor que debo hacer\
            Te extraño tando que voy a enloquecer. Ahy amor divino",
        "Icidori",
        "Rio",
        "Marihuana",
        "Tucupacta Merú Herrero"
    };

    cout << fnmatch("marinero", a[0], FNM_CASEFOLD);
    return 0;
}

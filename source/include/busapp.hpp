#ifndef __BUSAPP_H
#define __BUSAPP_H

#define BERROR_OK 0
#define BERROR_FAILED 1
#define BERROR_ADDRNOTCORRECT 2
#define BERROR_ADDRPROVIDED 3
#define BERROR_CURLINIT 4
#define BERROR_CURLPROVIDED 5
#define BERROR_URLCONNECT 6

#include <stdio.h>
#include <curl/curl.h>

struct cstr {
    char* ptr;
    size_t len;
};

/*
Poni�ej znajduje si� klasa "Busapp".
W niej znajduj� si� wszystkie mo�liwe funkcje zwi�zane z BusApp.
*/
class Busapp {

private:

    char* addr;

    CURL* curl;
    CURLcode ccode;

    char* resp;

public:

    const char* getError(int);

    /*
    Konstruktory domy�lny i parametryczny oraz destruktor
    Ten parametryczny od razu ustawia domy�lny adres na podstawie podanego argumentu i nie potrzeba go ustawia� metod� "setAddress"
    */
    Busapp(); Busapp(const char*); ~Busapp();

    /*
    Metoda ta inicjuje adres, pod kt�ry Busapp ma si� ��czy� i zbiera� dane.
    Je�li klasa zosta�a utworzona za pomoc� konstr. parametrycznego, nie potrzeba.
    Zwraca 0 je�li OK oraz kod b��du je�li co� posz�o nie tak.
    */
    int setAddress(const char*);

    /*
    Ta metoda zwraca wska�nik do �a�cucha znak�w, kt�ry zawiera adres. Je�eli adres nie zosta� wcze�niej podany, zwr�ci nullptr.
    */
    const char* getAddress();
    int httpGet(const char*, bool);
    const char* getResponse();

};

#endif // BUSAPP_H

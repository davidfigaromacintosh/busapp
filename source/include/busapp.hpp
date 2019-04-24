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
Poni¿ej znajduje siê klasa "Busapp".
W niej znajduj¹ siê wszystkie mo¿liwe funkcje zwi¹zane z BusApp.
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
    Konstruktory domyœlny i parametryczny oraz destruktor
    Ten parametryczny od razu ustawia domyœlny adres na podstawie podanego argumentu i nie potrzeba go ustawiaæ metod¹ "setAddress"
    */
    Busapp(); Busapp(const char*); ~Busapp();

    /*
    Metoda ta inicjuje adres, pod który Busapp ma siê ³¹czyæ i zbieraæ dane.
    Jeœli klasa zosta³a utworzona za pomoc¹ konstr. parametrycznego, nie potrzeba.
    Zwraca 0 jeœli OK oraz kod b³êdu jeœli coœ posz³o nie tak.
    */
    int setAddress(const char*);

    /*
    Ta metoda zwraca wskaŸnik do ³añcucha znaków, który zawiera adres. Je¿eli adres nie zosta³ wczeœniej podany, zwróci nullptr.
    */
    const char* getAddress();
    int httpGet(const char*, bool);
    const char* getResponse();

};

#endif // BUSAPP_H

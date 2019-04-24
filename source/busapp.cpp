#include <busapp.hpp>

const char* Busapp::getError(int _errno) {

    switch(_errno) {
        case BERROR_OK:
            return "OK";
        case BERROR_FAILED:
            return "Failed";
        case BERROR_ADDRNOTCORRECT:
            return "Address is not correct";
        case BERROR_ADDRPROVIDED:
            return "Address already provided";
        case BERROR_CURLINIT:
            return "Error in initializing cURL";
        case BERROR_CURLPROVIDED:
            return "cURL is already initialized";
        case BERROR_URLCONNECT:
            return "Error while connecting to server";

        default:
            throw "Incorrect error number";
    }

}

Busapp::Busapp() {

    addr = NULL;

    curl = NULL;
    resp = NULL;
}

Busapp::Busapp(const char* _addr) {

    //Kopiowanie podanego adresu do addr
    size_t addrlen = strlen(_addr);
    addr = new char[addrlen];
    strcpy(addr, _addr);

    curl = NULL;
    resp = NULL;
}

int Busapp::setAddress(const char* _addr) {

    //Je¿eli nie zosta³ wczeœniej podany adres
    if (addr == NULL) {
        size_t addrlen = strlen(_addr);
        addr = new char[addrlen];
        strcpy(addr, _addr);
        return BERROR_OK;
    }

    //Je¿eli zosta³ podany, zwróæ b³¹d #3
    else return BERROR_ADDRPROVIDED;
}

const char* Busapp::getAddress() {

    return addr;
}

int Busapp::httpGet(const char* _request=NULL, bool _https = false) {

    struct cstr response;

    response.ptr = new char[0xffff];
    response.len = 0;

    if ((curl = curl_easy_init()) == NULL) return BERROR_CURLINIT;

    curl_easy_setopt(curl, CURLOPT_URL, addr);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "busapp/1.0");

    if (_https) {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    }

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&response);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl = NULL;

    if (resp != NULL) {

        delete resp;
        resp = NULL;
    }

    resp = new char[response.len + 1];
    memcpy(resp, response.ptr, response.len);
    resp[response.len] = 0;

    delete(response.ptr);
    return BERROR_OK;

}

const char* Busapp::getResponse() {

    return resp;
}

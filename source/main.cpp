#pragma pack(1)

#include <busapp.hpp>

main() {

    Busapp *bus = new Busapp();

    bus->setAddress("http://145.239.82.231/busapp/");
    printf("Ustawiono adres na \"%s\"\n", bus->getAddress());

    bus->httpGet("", false);

    printf("OdpowiedŸ: %s\n", bus->getResponse());

    return 0xF19A20;
}

#include <iostream>

#include "Container.h"
#include "Product.h"
#include "Section.h"

using namespace std;

/*
Vytvořme informační systém, který bude evidovat obsah skladu. Budeme evidovat produkty. Každý produkt má váhu a popis.
Obě vlastnosti jsou povinné.

Dále máme kontejnery. Kontejner obsahuje popis pozice (string), maximální nosnost a seznam zboží, které je v něm uloženo.
Nosnost a pozice jsou povinné informace. Kontejner musí být schopen:

přidat nový produkt (produkt můžeme do kontejneru přidat pouze tehdy, pokud není překročena nosnost)

odstranit produkt, který je vybrán pomocí popisu (ano, není to zcela jednoznačné)

vrátit pozici

nastavit pozici

Poslední částí je sekce skladu. Každá sekce obsahuje pozici (v jaké je např. budově) a seznam kontejnerů, které se v ní
nachází. V sekci můžeme dělat následující operace:

Přidat prázdný kontejner na určitou pozici v sekci. Kontejner se vytvoří automaticky. Nepředávám jej nijak "z venku".

Přidat prázdný kontejner na určitou pozici v sekci, s výchozí nosností pro náš sklad (třeba 500 kg). Stejně jako u
předchozí metody se vytvoří uvnitř sekce.

Odstranit kontejner z pozice.

Přidat produkt do kontejneru, který je na dané pozici. Produkt převezmeme již vytvořený a předáme jej pomocí ukazatele.

Odstranit produkt s popisem v kontejneru na dané pozici.

Vypsat statistiky o využití jednotlivých sekcí a kontejnerů. (Lze různě modifikovat.)
*/

int main() {
    Product* applePie = new Product("An apple pie", 3.2);
    Product* measuringStation = new Product("Measuring station", 10.2);

    Section* warehouseSection = new Section("A2");
    warehouseSection->createContainer("S3");
    warehouseSection->createContainer("S4", 250);
    warehouseSection->createContainer("S5", 50);

    warehouseSection->addProductToContainer("S3", measuringStation);
    warehouseSection->addProductToContainer("S4", applePie);

    warehouseSection->printStats();

    delete measuringStation;
    delete applePie;
    delete warehouseSection;
    return 0;
}
#include "CosmicMap.h"

int main(void)
{
    // Cosmic List tests

    Something some("dude"), fella("fella"), guy("ledouche"), person("glen");

    // person.value = 3;
    
    // CosmicList<Something> newList;
    // newList.append(&fella);
    // newList.append(&guy);
    // newList.insert(&person, 20);
    // newList.insert(&some, 21);
    // newList.printAll();

    CosmicMap<Something> hashTest;
    
    hashTest.insert(&some);
    hashTest.insert(&fella);
    hashTest.insert(&guy);
    hashTest.insert(&person);
    //hashTest.printAll();

    Something* anotherNode = hashTest.returnNode("glen");
    std::cout << anotherNode->value << "\n";
    person.value = 4;
    std::cout << anotherNode->value << "\n";
    anotherNode = hashTest.returnNode("glen");
    std::cout << anotherNode->value << "\n";

    std::cout << "\nAll good, gov'ner!\n";
    return 0;   
}
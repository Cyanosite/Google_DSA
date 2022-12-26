#include <iostream>
#include "MyHashSet.h"

int main() {
    auto* hashSet = new MyHashSet();
    hashSet->add(1);
    hashSet->add(2);
    hashSet->remove(2);
    std::cout << std::boolalpha << hashSet->contains(1) << std::endl;
    return 0;
}

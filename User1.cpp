#include "User1.h"

User01::User01(): User() {}
User01::~User01() {}

const unsigned char User01::getInformation() {
    return manager->controlUser01();
}

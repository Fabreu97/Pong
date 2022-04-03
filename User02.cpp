#include "User02.h"

User02::User02(): User() {}
User02::~User02() {}

const unsigned char User02::getInformation() {
    return manager->controlUser02();
}


//
// Created by thunder on 2023/3/17.
//

#include "sip_server.h"

SipServer::SipServer() {
    init();
}
SipServer::~ SipServer() {

}
void SipServer::init() {
    std::cout << "test:" << TEST(EXOSIP_REGISTRATION_SUCCESS) << std::endl;
}
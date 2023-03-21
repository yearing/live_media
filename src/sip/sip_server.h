//
// Created by thunder on 2023/3/17.
//

#ifndef LIVE_MEDIA_SIP_SERVER_H
#define LIVE_MEDIA_SIP_SERVER_H

#include <iostream>
#include <thread>

#include <osipparser2/osip_message.h>
#include <osipparser2/osip_parser.h>
#include <osipparser2/osip_port.h>

#include <eXosip2/eXosip.h>
#include <eXosip2/eX_setup.h>
#include <eXosip2/eX_register.h>
#include <eXosip2/eX_options.h>
#include <eXosip2/eX_message.h>

#define TEST(A) #A
class SipServer{
public:
    SipServer();
    virtual ~SipServer();

private:
    void init();
    std::atomic<bool> _exit_thread_flag = false;
};
#endif //LIVE_MEDIA_SIP_SERVER_H

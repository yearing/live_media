//
// Created by thunder on 2023/3/17.
//

#ifndef LIVE_MEDIA_SIP_SERVER_H
#define LIVE_MEDIA_SIP_SERVER_H

#incude <iostream>

#include <osipparser2/osip_message.h>
#include <osipparser2/osip_parser.h>
#include <osipparser2/osip_port.h>

#include <eXosip2/eXosip.h>
#include <eXosip2/eX_setup.h>
#include <eXosip2/eX_register.h>
#include <eXosip2/eX_options.h>
#include <eXosip2/eX_message.h>

class SipServer{
public:
    SipServer();
    virtual ~SipServer();

private:
    void init();
    std::thread _sip_thread;
    std::atomic<bool> _exit_thread_flag = false;
};
#endif //LIVE_MEDIA_SIP_SERVER_H

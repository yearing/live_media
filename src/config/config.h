//
// Created by thunder on 2023/3/13.
//

#ifndef LIVE_MEDIA_CONFIG_H
#define LIVE_MEDIA_CONFIG_H

#include "media_define.h"
#include <hv/hstring.h> // for split
#include <hv/singleton.h>
#include <hv/iniparser.h>

const static char *g_config_file = "media_config.ini";
const static char *g_version = "live_media V1.0.1#20230319-1";


class Config {
public:
    bool LoadConfig(const char *configfile);

    const char *GetConfigFile() { return g_config_file; }

    std::map<std::string, std::string> _configs;
    SINGLETON_DECL(Config);
protected:
    Config();

    ~Config() {}

    void LogManger();
};

#endif //LIVE_MEDIA_CONFIG_H

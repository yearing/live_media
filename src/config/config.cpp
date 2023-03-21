//
// Created by thunder on 2023/3/13.
//

#include "config.h"
#include "hv/hlog.h"
#include "hv/hbase.h"
#include "hv/hversion.h"

SINGLETON_IMPL(Config)

Config::Config() {
    _configs[kSystemHttpPort] = "8897";
    _configs[kSystemLogFile] = "logs/live_media_sip.log";
    _configs[kSystemLogLevel] = "INFO";
    _configs[kSystemLogRemainDays] = "30";
    _configs[kSystemLogFileSize] = "20M";
    _configs[kSystemWorkerProcesses] = "2";
    _configs[kSystemWorkerThreads] = "2";

    _configs[kGB28181ExosipLog] = "1";
    _configs[kGB28181ServerId] = "";
    _configs[kGB28181ServerDomain] = "";
    _configs[kGB28181ServerUsr] = "admin";
    _configs[kGB28181ServerPwd] = "123456";
    _configs[kGB28181ServerIp] = "127.0.0.1";
    _configs[kGB28181RemoteAuto] = "1";
    _configs[kGB28181RemoteId] = "";
    _configs[kGB28181RemoteIp] = "127.0.0.1";
}

bool Config::LoadConfig(const char *configfile) {
    IniParser ini;
    int ret = 0;
    if (configfile == nullptr || (ret = ini.LoadFromFile(configfile) != 0)) {
        std::cout << "load config[" << configfile << "]fail, ret=" << ret << std::endl;
        return false;
    }
    std::cout << "load config[" << configfile << "]ok, ret=" << ret << std::endl;
    for (auto &kv:_configs) {
        auto keys = hv::split(kv.first, '.');
        if (keys.size() != 2) {
            std::cout << kv.first << " cannot split by ." << std::endl;
            continue;
        }
        kv.second = ini.GetValue(keys[1], keys[0]);
        std::cout << "[" << kv.first << "]=[" << kv.second << "]" << std::endl;
    }
    LogManger();
    hlog_set_format("%s");
    logger_print(hlog, LOG_LEVEL_INFO, "-----------------------------%s-----------------------------\n", g_version);
    logger_print(hlog, LOG_LEVEL_INFO, "-----------------------------libhv: %s | %s-----------------------------\n",
                 hv_version(), hv_compile_version());
    hlog_set_format("%y-%m-%d %H:%M:%S.%z %l %s");
    for (auto &kv:_configs) {
        hlogi("[%s]=[%s]", kv.first.c_str(), kv.second.c_str());
    }
    return true;
}

void Config::LogManger() {
    char log_path[256] = {0};
    char exe_path[256] = {0};

    std::string slog_path = _configs["system.log_file"];

    sprintf_s(exe_path, sizeof(exe_path) - 1, "%s/../logs", get_executable_dir(exe_path, sizeof(exe_path) - 1));
    hv_mkdir(exe_path);
    sprintf_s(log_path, sizeof(log_path) - 1, "%s/%s", exe_path,
              _configs["system.log_file"].c_str());
    std::cout << "log_path:[" << log_path << "]" << std::endl;

    hlog_set_file(log_path);
    hlog_set_format("%y-%m-%d %H:%M:%S.%z %l %s");
    hlog_set_max_filesize_by_str(_configs["system.log_filesize"].c_str());
    hlog_set_remain_days(atoi(_configs["system.log_remain_days"].c_str()));
    hlog_set_level_by_str(_configs["system.log_level"].c_str());
}
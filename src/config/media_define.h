//
// Created by thunder on 2023/3/20.
//

#ifndef LIVE_MEDIA_MEDIA_DEFINE_H
#define LIVE_MEDIA_MEDIA_DEFINE_H
#include <iostream>
#include <string>

#define SYSTEM_FIELD "system."
const static std::string kSystemHttpPort = SYSTEM_FIELD"http_port";
const static std::string kSystemLogFile = SYSTEM_FIELD"log_file";
const static std::string kSystemLogLevel = SYSTEM_FIELD"log_level";
const static std::string kSystemLogRemainDays = SYSTEM_FIELD"log_remain_days";
const static std::string kSystemLogFileSize = SYSTEM_FIELD"log_filesize";
const static std::string kSystemWorkerProcesses = SYSTEM_FIELD"worker_processes";
const static std::string kSystemWorkerThreads = SYSTEM_FIELD"worker_threads";

#define GB28181_FIELD "gb28181."
const static std::string kGB28181ExosipLog = GB28181_FIELD"exosip_log_enable";
const static std::string kGB28181ServerId = GB28181_FIELD"server_id";
const static std::string kGB28181ServerUsr = GB28181_FIELD"server_usr";
const static std::string kGB28181ServerPwd = GB28181_FIELD"server_passwd";
const static std::string kGB28181ServerIp = GB28181_FIELD"server_ip";
const static std::string kGB28181RemoteAuto = GB28181_FIELD"remote_automatic";
const static std::string kGB28181RemoteId = GB28181_FIELD"remote_id";
const static std::string kGB28181RemoteIp = GB28181_FIELD"remote_ip";

#endif //LIVE_MEDIA_MEDIA_DEFINE_H

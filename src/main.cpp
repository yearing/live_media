#include <iostream>
#include "config/config.h"


using namespace std;

int main() {
    cout << "load config[" << Config::instance()->GetConfigFile()<<"]"<<endl;
    const char* config = "D:\\workspace\\git\\OpenSource\\live_media\\bin\\media_config.ini";
    Config::instance()->LoadConfig(config);

    
    return 0;
}

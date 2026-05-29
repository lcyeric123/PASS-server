#include "config.h"
#include <fstream>
#include <sstream>
#include <string>

ServerConfig load_config(const std::string& path)
{
    ServerConfig cfg;
    std::ifstream f(path);
    if (!f.is_open()) return cfg;

    std::string line;
    while (std::getline(f, line))
    {
        if (line.empty() || line[0] == '#') continue;
        std::istringstream iss(line);
        std::string key, val;
        iss >> key >> val;

        if (key == "listen")
        {
            try { cfg.port = std::stoi(val); } catch (...) {}
        }
        else if (key == "root")
        {
            if (val.size() >= 2)
                cfg.root = val.substr(1, val.size() - 2);
        }
        else if (key == "autoindex")
        {
            cfg.autoindex = (val == "on");
        }
    }
    return cfg;
}

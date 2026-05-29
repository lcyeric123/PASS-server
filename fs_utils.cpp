#include "fs_utils.h"
#include <windows.h>
#include <direct.h>
#include <cstdio>

bool create_dir(const std::string& path)
{
    return _mkdir(path.c_str()) == 0;
}

bool write_file(const std::string& path, const std::string& content)
{
    FILE* f = fopen(path.c_str(), "w");
    if (!f) return false;
    fwrite(content.data(), 1, content.size(), f);
    fclose(f);
    return true;
}

bool file_exists(const std::string& path)
{
    DWORD attr = GetFileAttributesA(path.c_str());
    return attr != INVALID_FILE_ATTRIBUTES && !(attr & FILE_ATTRIBUTE_DIRECTORY);
}

bool is_dir(const std::string& path)
{
    DWORD attr = GetFileAttributesA(path.c_str());
    return attr != INVALID_FILE_ATTRIBUTES && (attr & FILE_ATTRIBUTE_DIRECTORY);
}

std::vector<std::string> list_dir(const std::string& dir)
{
    std::vector<std::string> files;
    std::string search = dir + "\\*.*";
    WIN32_FIND_DATAA find_data;
    HANDLE h = FindFirstFileA(search.c_str(), &find_data);
    if (h == INVALID_HANDLE_VALUE) return files;

    do
    {
        std::string name = find_data.cFileName;
        if (name == "." || name == "..") continue;
        files.push_back(name);
    } while (FindNextFileA(h, &find_data));

    FindClose(h);
    return files;
}

void init_server_env()
{
    if (!file_exists("conf")) create_dir("conf");
    if (!file_exists("www")) create_dir("www");

    std::string conf = "# PASS-Server default config\nlisten 8080;\nroot \"./www\";\nautoindex on;\n";
    if (!file_exists("conf\\server.conf"))
        write_file("conf\\server.conf", conf);

    std::string index = "<html><head><meta charset=\"utf-8\"><title>PASS‑Server</title></head><body><h1>Welcome to PASS‑Server</h1><p>Static HTML Web Server</p></body></html>";
    if (!file_exists("www\\index.html"))
        write_file("www\\index.html", index);
}

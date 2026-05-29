#ifndef PASS_SOCKET_H
#define PASS_SOCKET_H

#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

using sock_t = SOCKET;
constexpr SOCKET invalid_sock = INVALID_SOCKET;

namespace pass
{
    bool socket_init();
    sock_t create_tcp_socket();
    bool bind_socket(sock_t sock, int port);
    bool listen_socket(sock_t sock, int backlog = 5);
    sock_t accept_socket(sock_t server_sock);
    int send_data(sock_t sock, const std::string& data);
    std::string recv_data(sock_t sock, int buf_size = 4096);
    void close_socket(sock_t sock);
    void socket_cleanup();
}

#endif

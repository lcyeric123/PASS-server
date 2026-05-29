#include "pass_socket.h"

namespace pass
{
    bool socket_init()
    {
        WSADATA wsa_data;
        return WSAStartup(MAKEWORD(2, 2), &wsa_data) == 0;
    }

    sock_t create_tcp_socket()
    {
        return socket(AF_INET, SOCK_STREAM, 0);
    }

    bool bind_socket(sock_t sock, int port)
    {
        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(port);
        return bind(sock, (sockaddr*)&addr, sizeof(addr)) == 0;
    }

    bool listen_socket(sock_t sock, int backlog)
    {
        return listen(sock, backlog) == 0;
    }

    sock_t accept_socket(sock_t server_sock)
    {
        sockaddr_in client_addr{};
        int len = sizeof(client_addr);
        return accept(server_sock, (sockaddr*)&client_addr, &len);
    }

    int send_data(sock_t sock, const std::string& data)
    {
        return send(sock, data.c_str(), (int)data.size(), 0);
    }

    std::string recv_data(sock_t sock, int buf_size)
    {
        char* buf = new char[buf_size]{};
        int len = recv(sock, buf, buf_size, 0);
        std::string res(buf, len);
        delete[] buf;
        return res;
    }

    void close_socket(sock_t sock)
    {
        closesocket(sock);
    }

    void socket_cleanup()
    {
        WSACleanup();
    }
}

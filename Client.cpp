#include <iostream>
#include <string>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;
int main()
{
    char Buffer[1024] = {0};
    int Port = 3000;
    // Creating Socket
    // AF_INET - IPv4
    // SOCK_STREAM - TCP
    // Protocol Value = 0
    int Socket = socket(AF_INET, SOCK_STREAM, 0);
    if (Socket == 0)
    {
        cout << "Socket Creation Failed" << endl;
        exit;
    }

    // Connecting to the server
    struct sockaddr_in Server_Addr;
    Server_Addr.sin_family = AF_INET;
    Server_Addr.sin_port = htons(Port);
    // inet_pton(AF_INET, "127.0.0.1", &Server_Addr.sin_addr);
    int Connect = connect(Socket, (struct sockaddr *)&Server_Addr, sizeof(Server_Addr));
    if (Connect < 0)
    {
        cout << "Connection Failed" << endl;
        exit;
    }
    else
    {
        cout << "Connection Successful" << endl;
    }
    // receiving message from the server

    while (read(Socket, Buffer, sizeof(Buffer)) > 0)
    {
        cout << Buffer << endl;
        memset(Buffer, 0, sizeof(Buffer));
    }

    close(Socket);
    return 0;
}
#include "server.h"
#include <thread>

int main()
{
    // Jalankan server Crow di thread terpisah untuk menangani permintaan HTTP
    std::thread server_thread(StartServer);
}

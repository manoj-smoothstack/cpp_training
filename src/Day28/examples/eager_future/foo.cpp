Acceptor acceptor{443};
while (true) {
    Socket socket = acceptor.accept(); // blocking
    auto request = socket.read(); // blocking
    auto response = handleRequest(request);
    socket.write(response); // blocking
}

Acceptor acceptor{443}
while (true) {
    Socket socket = co_await acceptor.request();
    auto request = co_await socket.read();
    auto response = handleRequest(request);
    co_await socket.write(response);
}


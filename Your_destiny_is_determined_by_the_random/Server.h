#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace asio = boost::asio;
using asio::ip::tcp;

class Server {
    asio::io_service& io_service_;
    tcp::acceptor acceptor_;
    tcp::socket socket_;
    asio::streambuf receive_buff_;

public:
    Server(asio::io_service& io_service)
        : io_service_(io_service),
        acceptor_(io_service, tcp::endpoint(tcp::v4(), 31400)),
        socket_(io_service){}

    void start();

private:
    // 接続待機
    void start_accept();

    // 接続待機完了
    void on_accept(const boost::system::error_code& error);

    // メッセージ受信
    void start_receive();

    // 受信完了
    // error : エラー情報
    // bytes_transferred : 受信したバイト数
    void on_receive(const boost::system::error_code& error, size_t bytes_transferred);
};
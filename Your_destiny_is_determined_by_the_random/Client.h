#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace asio = boost::asio;
using asio::ip::tcp;

class Client {
private:
    asio::io_service& io_service_;
    tcp::socket socket_;
    std::string send_data_; // 送信データ

    // 接続
    void connect();

    // 接続完了
    void on_connect(const boost::system::error_code& error);

    // メッセージ送信
    void send();

    // 送信完了
    // error : エラー情報
    // bytes_transferred : 送信したバイト数
    void on_send(const boost::system::error_code& error, size_t bytes_transferred);

public:
    Client(asio::io_service& io_service)
        : io_service_(io_service),
        socket_(io_service){}

    void start();

};

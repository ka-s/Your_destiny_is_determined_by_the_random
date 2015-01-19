#include "Server.h"

void Server::start(){

    start_accept();

}

// 接続待機
void Server::start_accept(){

    acceptor_.async_accept(
        socket_,
        boost::bind(&Server::on_accept, this, asio::placeholders::error));

}

// 接続待機完了
void Server::on_accept(const boost::system::error_code& error){

    if (error) {
        std::cout << "accept failed: " << error.message() << std::endl;
        return;
    }

    start_receive();

}

// メッセージ受信
void Server::start_receive(){

    boost::asio::async_read(
        socket_,
        receive_buff_,
        asio::transfer_all(),
        boost::bind(&Server::on_receive, this,
        asio::placeholders::error, asio::placeholders::bytes_transferred));

}

// 受信完了
// error : エラー情報
// bytes_transferred : 受信したバイト数
void Server::on_receive(const boost::system::error_code& error, size_t bytes_transferred){

    if (error && error != boost::asio::error::eof) {
        std::cout << "receive failed: " << error.message() << std::endl;
    }
    else {
        const char* data = asio::buffer_cast<const char*>(receive_buff_.data());
        std::cout << data << std::endl;

        receive_buff_.consume(receive_buff_.size());
    }

}

#include "Client.h"

Client::Client(asio::io_service& io_service) : io_service_(io_service), socket_(io_service){

}

void Client::start(){

    connect();

}

// �ڑ�
void Client::connect(){

    socket_.async_connect(
        tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 31400),
        boost::bind(&Client::on_connect, this, asio::placeholders::error));

}


// �ڑ�����
void Client::on_connect(const boost::system::error_code& error){

    if (error) {
        std::cout << "connect failed : " << error.message() << std::endl;
        return;
    }

    send();
}

// ���b�Z�[�W���M
void Client::send(){

    send_data_ = "ping";
    asio::async_write(
        socket_,
        asio::buffer(send_data_),
        boost::bind(&Client::on_send, this,
        asio::placeholders::error,
        asio::placeholders::bytes_transferred));

}

// ���M����
// error : �G���[���
// bytes_transferred : ���M�����o�C�g��
void Client::on_send(const boost::system::error_code& error, size_t bytes_transferred){

    if (error) {
        std::cout << "send failed: " << error.message() << std::endl;
    }
    else {
        std::cout << "send correct!" << std::endl;
    }

}

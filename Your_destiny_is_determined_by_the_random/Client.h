#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace asio = boost::asio;
using asio::ip::tcp;

class Client {
private:
    asio::io_service& io_service_;
    tcp::socket socket_;
    std::string send_data_; // ���M�f�[�^

    // �ڑ�
    void connect();

    // �ڑ�����
    void on_connect(const boost::system::error_code& error);

    // ���b�Z�[�W���M
    void send();

    // ���M����
    // error : �G���[���
    // bytes_transferred : ���M�����o�C�g��
    void on_send(const boost::system::error_code& error, size_t bytes_transferred);

public:
    Client(asio::io_service& io_service)
        : io_service_(io_service),
        socket_(io_service){}

    void start();

};

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
    // �ڑ��ҋ@
    void start_accept();

    // �ڑ��ҋ@����
    void on_accept(const boost::system::error_code& error);

    // ���b�Z�[�W��M
    void start_receive();

    // ��M����
    // error : �G���[���
    // bytes_transferred : ��M�����o�C�g��
    void on_receive(const boost::system::error_code& error, size_t bytes_transferred);
};
#pragma once
#include <QString>
#include "ValidatorCls.h"
#include <boost/asio.hpp>
#include <string>
#include <cerrno>
#include <iostream>


bool ValidatorIPAddresses::isValidIp(const QString& address)
{
    boost::system::error_code ec;
    bool pResult = true;
    boost::asio::ip::address::from_string(address.toStdString(),ec);
    if (ec)
    {
        std::cerr << ec.message() << std::endl;
        pResult = false;
    }
    return pResult;
}

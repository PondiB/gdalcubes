/*
    MIT License

    Copyright (c) 2019 Marius Appel <marius.appel@hs-bochum.de>

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#include "error.h"

#include "config.h"

namespace gdalcubes {

std::mutex logger::_m;
// TODO: move mutex to specific error handler implementations
void logger::error(std::string msg, std::string where, int error_code) {
    _m.lock();
    config::instance()->get_error_handler()(error_level::ERRLVL_ERROR, msg, where, error_code);
    _m.unlock();
}
void logger::warn(std::string msg, std::string where, int error_code) {
    _m.lock();
    config::instance()->get_error_handler()(error_level::ERRLVL_WARNING, msg, where, error_code);
    _m.unlock();
}
void logger::debug(std::string msg, std::string where, int error_code) {
    _m.lock();
    config::instance()->get_error_handler()(error_level::ERRLVL_DEBUG, msg, where, error_code);
    _m.unlock();
}
void logger::fatal(std::string msg, std::string where, int error_code) {
    _m.lock();
    config::instance()->get_error_handler()(error_level::ERRLVL_FATAL, msg, where, error_code);
    _m.unlock();
}
void logger::trace(std::string msg, std::string where, int error_code) {
    _m.lock();
    config::instance()->get_error_handler()(error_level::ERRLVL_TRACE, msg, where, error_code);
    _m.unlock();
}
void logger::info(std::string msg, std::string where, int error_code) {
    _m.lock();
    config::instance()->get_error_handler()(error_level::ERRLVL_INFO, msg, where, error_code);
    _m.unlock();
}

}  // namespace gdalcubes

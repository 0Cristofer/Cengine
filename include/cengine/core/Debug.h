//
// Created by hugovs on 11/08/18.
//

#ifndef CENGINE_LOGGER_H
#define CENGINE_LOGGER_H

#include <string>
#include <chrono>
#include <iostream>

#define TEXT_RED    "\033[1;31m"
#define TEXT_YELLOW "\033[1;33m"
#define TEXT_BLUE   "\033[1;34m"
#define TEXT_WHITE  "\033[1;37m"
#define TEXT_RESET  "\033[0m"

#define BACKGROUND_RED  "\033[1;41m"

namespace cengine::core::debug {

    class Logger {

    public:

        enum Type {
            NORMAL, WARNING, ERROR, FATAL
        };

        static void Log(Type type, std::string msg) {
            switch (type) {
                case NORMAL:    std::cout << TEXT_BLUE << currentDateTime() << TEXT_WHITE       << "\t MESSAGE : " << msg << TEXT_RESET << std::endl; break;
                case WARNING:   std::cout << TEXT_BLUE << currentDateTime() << TEXT_YELLOW      << "\t WARNING : " << msg << TEXT_RESET << std::endl; break;
                case ERROR:     std::cerr << TEXT_BLUE << currentDateTime() << TEXT_RED         << "\t ERROR   : " << msg << TEXT_RESET << std::endl; break;
                case FATAL:     std::cerr << BACKGROUND_RED << currentDateTime() << BACKGROUND_RED   << "\t FATAL   : " << msg << TEXT_RESET << std::endl; break;
            }

        }

    private:
        static const std::string currentDateTime() {
            time_t     now = time(0);
            struct tm  tstruct;
            char       buf[80];
            tstruct = *localtime(&now);
            // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
            // for more information about date/time format
            strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

            return buf;
        }

    };

}

#endif //CENGINE_LOGGER_H

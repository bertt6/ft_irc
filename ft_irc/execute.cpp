#include "execute.hpp"

Exec::Exec() {

}


string Exec::cmd(std::string& wholeMsg){
    return (wholeMsg.substr(0, wholeMsg.find(' ')));
}


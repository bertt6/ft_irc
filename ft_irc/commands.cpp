// #include "commands.hpp"
// #include "server.hpp"

// void Commands::nameCmd(string msg, int clientSocket) {
//     this->user.setName(msg.substr(5, msg.find(' ') + 1));
//     string newMessage = "Name changed. Updated name : " + user.getName();
//     SendToClient(clientSocket, newMessage);
// }

// void Commands::whoCmd(string msg, int clientSocket) {
//     (void)msg;
//     if (this->user.getName().empty()) {
//             string clientReq = "Bulunamadi\n";
//             SendToClient(clientSocket, clientReq);
//         } 
//         else {
//             string clientReq = "[Kullanici adiniz] : " + this->user.getName() + "\n";
//             SendToClient(clientSocket, clientReq);
//         }
// }
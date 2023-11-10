#include "../commands.hpp"

void showAscii(string msg) {
    int i = 0;
    int cha; 
    cout << "------------------------" << endl;
    while(msg[i]) {
        cha = msg[i];
        cout << i << " " << cha << endl; 
        i++;
    }
    cha = msg[4];
    cout << "5 " << cha << endl;
    cout << endl << "------------------------" << endl;
}

void Commands::Pass(User& user, int clientSocket, string msg, string svPasswd) {
    if (user._isRegister && !msg.empty()) {
        string passwd;
        string message;
        //PASS komutu gelince 
        if(!msg.empty())
            passwd = msg.substr(5, msg.find(' '));
        if(!passwd.empty() && passwd == svPasswd) {
            message = "You're auth now!\n";
            SendToClient(clientSocket, message);
            user._isAuth = true;
        }
        else if (passwd.empty() && passwd != svPasswd) {
            message = "Wrong password!\n";
            SendToClient(clientSocket, message);
        }
    }
}
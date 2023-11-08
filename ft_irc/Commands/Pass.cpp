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
    if (user._isRegister) {
        (void)user;
        string passwd;
        string message;
        passwd = msg.substr(5, msg.find(' '));
        svPasswd = svPasswd + '\n';
        cout << "Passwd is : " << passwd << endl;
        cout << "--------------" << "ARG PASSWD " << "--------------" << endl;
        showAscii(svPasswd);    
        cout << "--------------" << "PASS PASSWD " << "--------------" << endl;
        showAscii(passwd);
        if(!passwd.empty() && passwd == svPasswd) {
            //message = "You're passed now! You can use NICK command!\n"; mantik hatsi
            SendToClient(clientSocket, message);
            user._isAuth = true;
        }
        else if (passwd.empty() && passwd != svPasswd) {
            message = "Wrong password!\n";
            SendToClient(clientSocket, message);
        }
    }
}
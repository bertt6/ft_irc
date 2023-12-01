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

void Commands::Pass(User& user, int clientSocket, string svPasswd) {
    if(args.size() == 2)
    {
        if(user._isAuth) 
        {
            errorHandle(user, "", clientSocket, 462);
            return;
        }
        if (user._isRegister) {
            (void)user;
            string message;
            vector<string>::iterator it = args.begin() + 1;
            if(!(*it).empty() && *it == svPasswd) {
                message = user.getClientName() + " :You're auth now!\n";
                SendToClient(clientSocket, message);
                user._isAuth = true;
            }
            else if ((*it).empty() && *it != svPasswd)
                errorHandle(user, NULL, clientSocket, ERR_PASSWDMISMATCH);
        }
    }   
}
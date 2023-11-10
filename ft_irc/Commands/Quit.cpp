#include "../commands.hpp"

//çıkış yapıldığında aynı kanalda olan insanlara sebebi ile beraber gönderilir
//eğer kullanıcı quit komutu ile çıkmazsa aynı kanaldaki bütün client'lere mesaj göndermesi zorunludur.

void Commands::Quit(User &user, int clientSocket, string reason) {
    if(!user.getNickName().empty())
    {
        string msg = "QUIT :" + user.getNickName() + reason;
        SendToClient(clientSocket, msg);
    }
    close(clientSocket);
}
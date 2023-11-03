

#include "CWebStudio.h"
CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    char *name = cweb.request.get_param(request,"name");
    
    if(!name){
        return  cweb.response.send_text("You didint prvided the name", 200);
    }

    char formated[30] = {0};
    sprintf(formated,"Hello %s",name);
    return cweb.response.send_text(formated, 200);

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer server = newCwebSever(5000, main_sever);
    server.single_process = true;
    cweb.server.start(&server);
    return 0;
}
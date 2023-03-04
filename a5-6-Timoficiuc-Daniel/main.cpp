#include "Ui/Ui.h"
#include "Test.h"



int main(){
    Test test;
    test.testAll();
    Database<Dog> dat;
    Database<Dog> dat2;
    Service serv(dat);
    serv.addDog("milo","golden",10,"idk");
    serv.addDog("otto","bichon",5,"idk");
    serv.addDog("chip","golden",2,"idk");
    serv.addDog("rex","golden",3,"idk");
    serv.addDog("amo","aussie",7,"idk");
    serv.addDog("gus","aussie",12,"idk");
    serv.addDog("smol","aussie",13,"idk");
    serv.addDog("bigus","hotdog",8,"idk");
    serv.addDog("fat","bichon",2,"idk");
    serv.addDog("originality","golden",1,"idk");
    serv.addDog("hotdog","hotdog",7,"idk");
    Service userServ(dat2);
    Administrator admin(serv);
    User user(serv,userServ);
    Ui ui(admin,user);
    ui.run();
}
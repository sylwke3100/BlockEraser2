#include "events.h"

Events::Events(){
}

void Events::addEvent(std::string Name,
                      std::function<void(void)> callback ){
    lista.emplace_back(Name, callback);

}

void Events::runEvent(std::string Name){
    for(auto&& a: lista)
            if(a.first == Name){
                a.second();
            }
}

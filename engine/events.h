#ifndef EVENTS_H
#define EVENTS_H
#include <string>
#include <vector>
#include <memory>


class Events
{
    typedef std::function<void()>* funct;
    std::vector< std::pair<std::string,  std::function<void()>> > lista;
public:
    Events();
    void addEvent(std::string Name,   std::function<void()> callback);
    void runEvent(std::string Name);
};

#endif // EVENTS_H

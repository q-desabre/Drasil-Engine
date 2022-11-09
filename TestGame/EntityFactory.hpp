
#pragma once

#include "Event.hpp"
#include "Packet.hpp"

class EntityFactory
{
public:
    static EntityFactory& getInstance();

    void Init();

    void CreateEntity(drasil::Event& e);

protected:
    EntityFactory();

private:
};

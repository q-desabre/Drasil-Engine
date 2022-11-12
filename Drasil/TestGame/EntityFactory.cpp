
#include "EntityFactory.hpp"
#include "ECS.hpp"
#include "Macro.hpp"

EntityFactory& EntityFactory::getInstance()
{
    static EntityFactory instance;
    return instance;
}

EntityFactory::EntityFactory()
{
    std::cout << "Factory created" << std::endl;
    BIND_PACKET_RECV(EntityFactory::CreateEntity);
}

void EntityFactory::Init()
{
    std::cout << "Factory initialized" << std::endl;
}

void EntityFactory::CreateEntity(drasil::Event& e)
{
    drasil::Packet p =
        e.GetParam<drasil::Packet>(drasil::Events::Network::PACKET);
    int type;
    p >> type;
    std::cout << "Recieved Create !" << std::endl;
    if (type == 1)
    {
    }
    // Create entity
}
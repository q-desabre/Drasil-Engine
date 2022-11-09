Engine
[ ] Animated Sprite
[ ] Parallax
[ ] Replace bitset Input
[ ] Sound System # Event / Simple Singleton ? is system really necessary
[ ] 3D Actor - Need OpenGL Context -> rework Render :(
[X] Change Render by IRender in coordinator
[X] Change network by INetwork in coordinator
[ ] Add Drasil Namespace to engine

Network
[X] Network System \_o_/
[X] Handle start Server/client
[ ] Lifecycle Network
[ ] cfg network

Game
Incoming...





Brainstorm Network

ComponentNetwork
Create
Update
Delete

Bullet.addComponentNetwork
-> .create = bind
-> .update = bind
-> .delete = bind

Doc for replicated component you must implement this methods and bind in your constructor

Bullet::Bullet()
{
    SetNetworkCreate(Bullet::NetworkCreate);
    ....

    
}

Bullet::NetworkCreate()
{
    Event event(Events::Network::Entity);
    Packet p;
    // Define in RFC
    p << PACKET_TYPE << ID << PARAMS << ...;
    event.setParam(Events::Network::Entity::Create, p);
    Coordinator.SendEvent(Event);
}

// Server
Game::Start()
{
    Bullet b; -> ID and bind of methods
    // Network System Catch un event Network::Entity
    // Il send le packet à tout les clients

    while (1)
     b.update(); // Idem que pour create mais en event update
}

//  Client
Game::Start()
{
    // Network System Catch un Network::PACKAGE_RECEIVED
    // Switch on PACKET_TYPE
    // if CREATE
    // Go to Factory ou implé du choix (partie game)
}


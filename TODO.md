Dynamic Loading
[X] Interface Game ( Level from ECS, typedef to end user ? )
[X] CrossPlatform Loading 
[X] Interface Graphic
[X] Rework Render Component
[X] Load a Simple Level
[X] Dynamic Loader
[X] Test Dynamic Graphic
[ ] Change Runtime of Graphic -> Destruction of a Render System
[ ] 
[ ] Do the same for the network (.....)

Render
[X] SFML - Resize still need works
[ ] Ncurses
[ ] SDL ( for testing prupose )
[ ] Raylib
[ ] Opengl ( sfml context ? )

Game
[ ] Menu ( en cours ... )
[ ] Snake
[ ] Pong
[ ] Casse Brique
[ ] Runner
[ ] Pacman ( pas envie ... )

Engine
[ ] cfg parser
[ ] Animated Sprite
[ ] Add Draw Priority ( use Z axis ? by sorting mEntities in RenderSystem) it's here but not used
[ ] Button V2 [Add Custom Text inside] // Waiting TextClass
[ ] Sound System # Event / Simple Singleton ? is system really necessary
[X] [? Custom event ?] overload sendEvent with std::string ?
[X] Re-add Static Event for perf
[X] AddEvent to notify RenderSystem a new Entity is born ( for size init )
[X] Replace bitset Input
[X] Create Genereric Data Structs for Mouse/Keyboard
[X] Upgrade handling input Mouse/Keyboard
[X] Logger
[X] Button V1 [SwapTexture, onClick]
[X] Text V1 [Font, size]
[X] Text V2 [Color]
[X] Text V3 [Outline + font + size]
[X] Change Render by IRender in coordinator
[X] Change network by INetwork in coordinator
[X] Add Drasil Namespace to engine

Network
[X] Network System \_o_/
[X] Handle start Server/client
[X] Lifecycle Network
[ ] Add TCP kek
[ ] Input Client to Network
[ ] cfg network

Render
[X] Crash aftZer change in .dll ( possibly from singleton, possible fix include manager in reader system but it sucks, unique_ptr in coordinator with a call to destroy may be better)

Game
[X] Parallax
[ ] A player that move
[ ] Network player that move

Rework
[ ] GetID Actor -> surcharge vector pour actor possédant d'autres actors
[X] Rename IRenderSystem to ARenderSystem
[X] Remove Ref to Level on Game Class to simplify Level creation

BONUS
[ ] 3D Actor - Need OpenGL Context | Custom Render System (need tweek on coordinator)
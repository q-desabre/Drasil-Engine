Engine
[ ] Animated Sprite
[ ] Add Draw Priority ( use Z axis ? by sorting mEntities in RenderSystem)
[X] Replace bitset Input
[X] Create Genereric Data Structs for Mouse/Keyboard
[X] Upgrade handling input Mouse/Keyboard
[ ] Sound System # Event / Simple Singleton ? is system really necessary
[ ] Logger | Bind Event
[X] Button V1 [SwapTexture, onClick]
[ ] Button V2 [Add Custom Text inside] // Waiting TextClass
[ ] Text V1 [Font, size, color]
[ ] Widgets [Button, Text], custom event ? overload sendEvent with std::string ?

[X] Change Render by IRender in coordinator
[X] Change network by INetwork in coordinator
[X] Add Drasil Namespace to engine

Network
[X] Network System \_o_/
[X] Handle start Server/client
[X] Lifecycle Network
[ ] cfg network

Render
[X] Crash aftZer change in .dll ( possibly from singleton, possible fix include manager in reader system but it sucks, unique_ptr in coordinator with a call to destroy may be better)

Game
[X] Parallax

Rework
[ ] GetID Actor -> surcharge vector pour actor possédant d'autres actors
[ ] Rename IRenderSystem to ARenderSystem

BONUS
[ ] 3D Actor - Need OpenGL Context -> rework Render :(
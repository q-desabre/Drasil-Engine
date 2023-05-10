#include "PlayerControlSystem.hpp"
#include "../../../Common/Types/Types.hpp"
#include "../../Components/Components.hpp"
#include "../../Coordinator/Coordinator.hpp"

using namespace drasil;

void PlayerControlSystem::InitSignature()
{
    Signature signature;
    signature.set(gCoordinator.GetComponentType<InputComponent>());
    signature.set(gCoordinator.GetComponentType<TransformComponent>());
    signature.set(gCoordinator.GetComponentType<StatusComponent>());
    gCoordinator.SetSystemSignature<PlayerControlSystem>(signature);

    gCoordinator.AddEventListener(
        METHOD_LISTENER("keyboard", PlayerControlSystem::InputListener));
}

void PlayerControlSystem::Update(float dt) {}

void PlayerControlSystem::InputListener(Event& event) {}

// Copyright Armchair Developers / Sean Kahler. Licensed under GPLv3.

#include <Entity/Overrides/QuitGameEntity.h>

#include <Utilities/ErrorUtils.h>

#include <Entity/KyberSettings.h>
#include <Core/Program.h>
#include <cstdlib>

namespace Kyber
{
KB_IMPLEMENT_ENTITY_OVERRIDE(QuitGameEntity, QuitGameEntityData);

QuitGameEntity::QuitGameEntity(EntityManager* entityManager, NativeEntity* entity, QuitGameEntityData* data)
    : KyberEntity(entity, data)
{
    // KYBER_LOG(Warning, "[QuitGame] Created.");
}

void QuitGameEntity::Event(EntityEvent* event)
{
    KYBER_LOG(Info, "[QuitGameEntityData] Received command to quit.");
    // ErrorUtils::CloseGame("The game has been closed by a QuitGameEntity.");
    // // This is how Kyber.CrashGame does it, so blame them not me.
    // int* ptr = nullptr;
    // *ptr = 1;
    ExitProcess(EXIT_FAILURE);
}
} // namespace Kyber
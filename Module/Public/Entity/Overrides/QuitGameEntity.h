#pragma once

#include <Entity/NativeEntityManager.h>

#include <Core/DebugHooks.h>

namespace Kyber
{
class QuitGameEntity : public KyberEntity<QuitGameEntityData>
{
public:
    QuitGameEntity(EntityManager* entityManager, NativeEntity* entity, QuitGameEntityData* data);

    void Event(EntityEvent* event) override;
};
} // namespace Kyber
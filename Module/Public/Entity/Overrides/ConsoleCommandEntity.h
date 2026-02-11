# pragma once

#include <Entity/NativeEntityManager.h>

#include <Core/DebugHooks.h>
#include <Core/Console.h>

namespace Kyber
{
class ConsoleCommandEntity : public KyberEntity<ConsoleCommandEntityData>
{
public:
    ConsoleCommandEntity(EntityManager* entityManager, NativeEntity* entity, ConsoleCommandEntityData* data);
    // ~ConsoleCommandEntity();

    // void Execute(ConsoleContext& cc);
    // void Update(const UpdateParameters& params) override;
    void Event(EntityEvent* event) override;
private:
    bool m_enabled;

    FBArray<const char*> m_commands;
};
} // namespace Kyber
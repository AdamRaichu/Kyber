#include <Entity/Overrides/ConsoleCommandEntity.h>

#include <Entity/KyberSettings.h>
#include <Core/Program.h>

namespace Kyber
{
static void** g_realmContext = (void**) 0x143FBA4B8;
TL_DECLARE_FUNC(0x1471A19F0, void*, RealmContext_setCurrentContext, void* context);

KB_IMPLEMENT_ENTITY_OVERRIDE(ConsoleCommandEntity, ConsoleCommandEntityData);

ConsoleCommandEntity::ConsoleCommandEntity(EntityManager* entityManager, NativeEntity* entity, ConsoleCommandEntityData* data)
    : KyberEntity(entity, data)
{
    KYBER_LOG(Info, "Created a console command entity");
    // SetWantUpdates(true);
    m_commands = data->Commands;
}

// void ConsoleCommandEntity::Update(const UpdateParameters& params)
// {

// }

void ConsoleCommandEntity::Event(EntityEvent* event)
{
    KYBER_LOG(Debug, "[ConsoleCommandEntity] A console command entity was triggered.");
    FBArray<const char*> commands = m_commands;
    for (const char*& command : commands)
    {
        KYBER_LOG(Debug, "[ConsoleCommandEntity]   " << command);
        g_program->m_console->EnqueueCommand(command);
    }
}

} // namespace Kyber
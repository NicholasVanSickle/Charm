#include <Core/ControllerInterface.h>

#include "CommandDeleteEvent.h"

CommandDeleteEvent::CommandDeleteEvent( const Event& event, QObject* parent )
    : CharmCommand( "delete event", parent )
    , m_event( event )
{
}

CommandDeleteEvent::~CommandDeleteEvent()
{
}

bool CommandDeleteEvent::prepare()
{
    return true;
}

bool CommandDeleteEvent::execute( ControllerInterface* controller )
{
    qDebug() << "CommandDeleteEvent::execute: deleting:";
    m_event.dump();
    return controller->deleteEvent( m_event );
}

bool CommandDeleteEvent::rollback(ControllerInterface *controller)
{
    m_event = controller->cloneEvent(m_event);
    return m_event.isValid();
}

bool CommandDeleteEvent::finalize()
{
    return true;
}

#include "CommandDeleteEvent.moc"


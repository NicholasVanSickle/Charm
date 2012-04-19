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
    int oid = m_event.id();
    m_event = controller->cloneEvent(m_event);
    int nid = m_event.id();
    if(oid != nid)
        emit emitSlotEventIdChanged(oid, nid);
    return m_event.isValid();
}

bool CommandDeleteEvent::finalize()
{
    return true;
}

void CommandDeleteEvent::eventIdChanged(int oid, int nid)
{
    if(m_event.id() == oid)
        m_event.setId(nid);
}

#include "CommandDeleteEvent.moc"


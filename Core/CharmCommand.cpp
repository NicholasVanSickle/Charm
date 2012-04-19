#include "CommandEmitterInterface.h"
#include "CharmCommand.h"

CharmCommand::CharmCommand( const char *text, QObject *parent )
    : QObject( parent )
{
    m_commandText = tr(text);
    CommandEmitterInterface* emitter = dynamic_cast<CommandEmitterInterface*>( parent );
    if ( emitter ) {
        m_owner = emitter;
    } else {
        Q_ASSERT_X( false, "CharmCommand ctor",
                    "CharmCommand widget pointers have to implement the "
                    "CommandEmitterInterface." );
    }
}

CharmCommand::~CharmCommand()
{
}

QString CharmCommand::commandText()
{
    return m_commandText;
}

CommandEmitterInterface* CharmCommand::owner() const
{
    return m_owner;
}

void CharmCommand::requestExecute()
{
    emit emitExecute(this);
}

void CharmCommand::requestRollback()
{
    emit emitRollback(this);
}

void CharmCommand::requestSlotEventIdChanged(int oid, int nid)
{
    emit emitSlotEventIdChanged(oid,nid);
}

#include "CharmCommand.moc"

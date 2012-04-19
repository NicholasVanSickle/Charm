#include "UndoCharmCommandWrapper.h"

UndoCharmCommandWrapper::UndoCharmCommandWrapper(CharmCommand* command)
    : m_command(command)
{
    setText(command->commandText());
}

void UndoCharmCommandWrapper::undo()
{
    m_command->requestRollback();
}

void UndoCharmCommandWrapper::redo()
{
    m_command->requestExecute();
}

CharmCommand *UndoCharmCommandWrapper::command()
{
    return m_command;
}

#include "qisbcommand.h"

QisbCommand::QisbCommand(QisbCommand* parent)
  : QObject(parent), QUndoCommand(parent)
{

}

QisbCommand::~QisbCommand()
{

}

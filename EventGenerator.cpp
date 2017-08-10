#include "EventGenerator.h"

QString EventGenerator::getEvent(QString type)
{
    QString result = "{\n\
    \"type\": \"" + type + "\",\n\
    \"at\": \"" + QString::number(QDateTime::currentMSecsSinceEpoch()/1000) + "\"\n\
}";
    return result;
}

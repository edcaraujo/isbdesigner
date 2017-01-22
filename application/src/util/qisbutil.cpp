#include "qisbutil.h"

QString QisbUtil::Uid()
{
  QString uid = QUuid::createUuid().toString();
  uid = uid.replace("{","");
  uid = uid.replace("}","");
  uid = uid.replace("-","");

  return uid;
}

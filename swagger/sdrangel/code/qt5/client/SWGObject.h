#ifndef SWGObject_H_
#define SWGObject_H_

#include <QJsonValue>
#include <QJsonObject> // <-- Ваш доданий рядок (правильно)
#include <QObject>     // <-- Необхідний рядок
#include "export.h"  // <-- Необхідний рядок

namespace SWGSDRangel {

class SWG_API SWGObject { // <-- Додано макрос SWG_API
  public:
    virtual QJsonObject* asJsonObject() {
      return new QJsonObject();
    }
    virtual ~SWGObject() {}
    virtual SWGObject* fromJson(QString &jsonString) {
        Q_UNUSED(jsonString);
        return new SWGObject();
    }
    virtual void fromJsonObject(QJsonObject &json) {
        Q_UNUSED(json);
    }
    virtual QString asJson() {
        return QString("");
    }
    virtual bool isSet() {
        return false;
    }
};

}

#endif /* SWGObject_H_ */
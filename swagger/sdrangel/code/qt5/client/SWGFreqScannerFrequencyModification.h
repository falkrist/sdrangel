#ifndef SWG_SWGFreqScannerFrequencyModification_H
#define SWG_SWGFreqScannerFrequencyModification_H

#include "SWGObject.h"
#include <QString>
#include <QJsonObject> 

namespace SWGSDRangel {

class SWGFreqScannerFrequencyModification: public SWGObject {
public:
    SWGFreqScannerFrequencyModification();
    virtual ~SWGFreqScannerFrequencyModification();
    void init();
    void cleanup();

    QString asJson () override;
    QJsonObject* asJsonObject() override;
    void fromJsonObject(QJsonObject &json) override;

    qint64 getFrequency();
    void setFrequency(qint64 frequency);

    qint32 getEnabled();
    void setEnabled(qint32 enabled);

    virtual bool isSet() override;

private:
    qint64 m_frequency;
    bool m_frequency_isSet;
    qint32 m_enabled;
    bool m_enabled_isSet;
};

}

#endif
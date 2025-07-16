#include "SWGFreqScannerFrequencyModification.h"
#include "SWGHelpers.h"
#include <QJsonDocument>
#include <QJsonObject>

namespace SWGSDRangel {

SWGFreqScannerFrequencyModification::SWGFreqScannerFrequencyModification() {
    init();
}

SWGFreqScannerFrequencyModification::~SWGFreqScannerFrequencyModification() {
    cleanup();
}

void SWGFreqScannerFrequencyModification::init() {
    m_frequency = 0;
    m_frequency_isSet = false;
    m_enabled = 0;
    m_enabled_isSet = false;
}

void SWGFreqScannerFrequencyModification::cleanup() {
}

QJsonObject* SWGFreqScannerFrequencyModification::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_frequency_isSet){
        obj->insert("frequency", QJsonValue(m_frequency));
    }
    if(m_enabled_isSet){
        obj->insert("enabled", QJsonValue(m_enabled));
    }
    return obj;
}

void SWGFreqScannerFrequencyModification::fromJsonObject(QJsonObject &json) {
    if (json.contains("frequency")) {
        m_frequency = json["frequency"].toVariant().toLongLong();
        m_frequency_isSet = true;
    }
    if (json.contains("enabled")) {
        m_enabled = json["enabled"].toVariant().toInt();
        m_enabled_isSet = true;
    }
}

QString SWGFreqScannerFrequencyModification::asJson() {
    QJsonObject* obj = this->asJsonObject();
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

qint64 SWGFreqScannerFrequencyModification::getFrequency() {
    return m_frequency;
}

void SWGFreqScannerFrequencyModification::setFrequency(qint64 frequency) {
    m_frequency = frequency;
    m_frequency_isSet = true;
}

qint32 SWGFreqScannerFrequencyModification::getEnabled() {
    return m_enabled;
}

void SWGFreqScannerFrequencyModification::setEnabled(qint32 enabled) {
    m_enabled = enabled;
    m_enabled_isSet = true;
}

bool SWGFreqScannerFrequencyModification::isSet() {
    return m_frequency_isSet || m_enabled_isSet;
}

}
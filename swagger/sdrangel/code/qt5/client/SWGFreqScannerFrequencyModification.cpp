#include "SWGFreqScannerFrequencyModification.h"
#include "SWGHelpers.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

namespace SWGSDRangel {

// --- Конструктори та ініціалізація ---
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
    // В цьому класі немає динамічної пам'яті, тому тут порожньо
}

// --- Робота з JSON ---

SWGFreqScannerFrequencyModification* SWGFreqScannerFrequencyModification::fromJson(QString &jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void SWGFreqScannerFrequencyModification::fromJsonObject(QJsonObject &json) {
    // Зчитуємо значення з JSON і, що найважливіше, встановлюємо прапорці isSet
    if (json.contains("frequency")) {
        ::SWGSDRangel::setValue(&m_frequency, json["frequency"], "qint64", "");
        m_frequency_isSet = true;
    }
    if (json.contains("enabled")) {
        ::SWGSDRangel::setValue(&m_enabled, json["enabled"], "qint32", "");
        m_enabled_isSet = true;
    }
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

QString SWGFreqScannerFrequencyModification::asJson() {
    QJsonObject* obj = this->asJsonObject();
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

// --- Гетери та Сетери ---

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
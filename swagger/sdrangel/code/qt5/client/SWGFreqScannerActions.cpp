#include "SWGFreqScannerActions.h"
#include "SWGHelpers.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGFreqScannerActions::SWGFreqScannerActions(QString* json) {
    init();
    this->fromJson(*json);
}

SWGFreqScannerActions::SWGFreqScannerActions() {
    run = 0;
    m_run_isSet = false;
    clear_hits = 0;
    m_clear_hits_isSet = false;
    modify_frequency = nullptr;
    m_modify_frequency_isSet = false;
}

SWGFreqScannerActions::~SWGFreqScannerActions() {
    this->cleanup();
}

void
SWGFreqScannerActions::init() {
    run = 0;
    m_run_isSet = false;
    clear_hits = 0;
    m_clear_hits_isSet = false;
    modify_frequency = new SWGFreqScannerFrequencyModification();
    m_modify_frequency_isSet = false;
}

void
SWGFreqScannerActions::cleanup() {
    if(modify_frequency != nullptr) {
        delete modify_frequency;
    }
}

SWGFreqScannerActions*
SWGFreqScannerActions::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGFreqScannerActions::fromJsonObject(QJsonObject &pJson) {
    if (pJson.contains("run")) {
        ::SWGSDRangel::setValue(&run, pJson["run"], "qint32", "");
        this->m_run_isSet = true;
    }

    if (pJson.contains("clearHits")) {
        ::SWGSDRangel::setValue(&clear_hits, pJson["clearHits"], "qint32", "");
        this->m_clear_hits_isSet = true;
    }
    
    // ▼▼▼ ВИПРАВЛЕНО ▼▼▼
    if (pJson.contains("modifyFrequency")) {
        QJsonValue val = pJson["modifyFrequency"];
        // Використовуємо правильну допоміжну функцію setValue
        ::SWGSDRangel::setValue(modify_frequency, val, "SWGFreqScannerFrequencyModification", "SWGFreqScannerFrequencyModification");
        m_modify_frequency_isSet = true;
    }
}

QString
SWGFreqScannerActions::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGFreqScannerActions::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_run_isSet){
        obj->insert("run", QJsonValue(run));
    }
    if(m_clear_hits_isSet){
        obj->insert("clearHits", QJsonValue(clear_hits));
    }
    
    // ▼▼▼ ВИПРАВЛЕНО ▼▼▼
    // Цей блок переміщено перед `return obj`
    if((modify_frequency != nullptr) && (modify_frequency->isSet())){
        // Використовуємо правильну допоміжну функцію toJsonValue
        toJsonValue(QString("modifyFrequency"), modify_frequency, obj, QString("SWGFreqScannerFrequencyModification"));
    }

    return obj;
}

qint32
SWGFreqScannerActions::getRun() {
    return run;
}
void
SWGFreqScannerActions::setRun(qint32 run) {
    this->run = run;
    this->m_run_isSet = true;
}

qint32
SWGFreqScannerActions::getClearHits() {
    return clear_hits;
}
void
SWGFreqScannerActions::setClearHits(qint32 clear_hits) {
    this->clear_hits = clear_hits;
    this->m_clear_hits_isSet = true;
}

bool
SWGFreqScannerActions::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_run_isSet){
            isObjectUpdated = true; break;
        }
        if(m_clear_hits_isSet){
            isObjectUpdated = true; break;
        }
        if(m_modify_frequency_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}

bool
SWGFreqScannerActions::runIsSet() {
    return m_run_isSet;
}

bool
SWGFreqScannerActions::clearHitsIsSet() {
    return m_clear_hits_isSet;
}

SWGFreqScannerFrequencyModification*
SWGFreqScannerActions::getModifyFrequency() {
    return modify_frequency;
}
void
SWGFreqScannerActions::setModifyFrequency(SWGFreqScannerFrequencyModification* modify_frequency) {
    this->modify_frequency = modify_frequency;
    this->m_modify_frequency_isSet = true;
}
bool
SWGFreqScannerActions::modifyFrequencyIsSet() {
    return m_modify_frequency_isSet;
}

}
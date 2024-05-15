//
// Created by mia borko on 14/05/2024.
//

#include "JSONclass.h"
#include <QFile>
#include <QJsonDocument>
#include <QDebug>

QJsonArray JSONclass::parseJSON(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open JSON file";
        return QJsonArray();
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    if (!doc.isArray()) {
        qDebug() << "JSON file does not contain an array";
        return QJsonArray();
    }

    return doc.array();
}

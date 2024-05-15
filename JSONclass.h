//
// Created by mia borko on 14/05/2024.
//

#ifndef JSONCLASS_H
#define JSONCLASS_H
#include <QString>
#include <QJsonArray>

class JSONclass {
public:
    static QJsonArray parseJSON(const QString& filePath);
};
#endif //JSONCLASS_H

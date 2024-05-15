#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item {
private:
    QString shortDescription;
    QString longDescription;
    bool isTrack5Song;

public:
    Item(QString shortDesc, QString longDesc, bool isTrack5 = false);
    QString getShortDescription() const;
    QString getLongDescription() const;
    bool isTrack5() const;
};

#endif // ITEM_H

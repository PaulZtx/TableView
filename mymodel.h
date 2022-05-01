#ifndef MYMODEL_H
#define MYMODEL_H
#define COLUMN_COUNT 4

#include <QAbstractTableModel>
#include <student.h>
#include <QColor>

class MyModel : public QAbstractTableModel
{
public:
    explicit MyModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void SetStudents(const QVector<Student> &students);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool insertRows(int row, int count, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);

private:
    QVector<Student> * Students;
    enum columns{
        sId = 0,
        sFIO,
        sAge,
        sGroup
    };

};

#endif // MYMODEL_H

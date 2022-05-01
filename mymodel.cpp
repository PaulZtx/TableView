#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    Students = new QVector<Student>();

}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return Students->size();
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    return COLUMN_COUNT;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{

    switch (index.column()) {
    case sId:
        if(role == Qt::DisplayRole)
            return Students->at(index.row()).id;
        if(role == Qt::BackgroundRole && Students->at(index.row()).id < 0)
            return QColor("#ff3370");
        if(role == Qt::ToolTipRole)
            return "int";
        break;
    case sFIO:

        if(role == Qt::BackgroundRole && Students->at(index.row()).fio.isEmpty())
            return QColor("#ff3370");
        if(role == Qt::DisplayRole)
            return Students->at(index.row()).fio;
        if(role == Qt::ToolTipRole)
            return "string";
        break;
    case sAge:
        if(role == Qt::DisplayRole)
            return Students->at(index.row()).age;
        if(role == Qt::BackgroundRole && Students->at(index.row()).age == 0)
            return QColor("#ff3370");
        if(role == Qt::ToolTipRole)
            return "int";
        break;
    case sGroup:
        if(role == Qt::BackgroundRole && Students->at(index.row()).group.isEmpty())
            return QColor("#ff3370");
        if(role == Qt::DisplayRole)
            return Students->at(index.row()).group;
        if(role == Qt::ToolTipRole)
            return "string";
    }

    return QVariant();

}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Vertical)
        return Students->size();

    if(role == Qt::DisplayRole){
        switch (section) {
        case sId:
            return "ID";
        case sFIO:
            return "FIO";
        case sAge:
            return "AGE";
        case sGroup:
            return "GROUP";


        }
    }
    return QVariant();
}

void MyModel::SetStudents(const QVector<Student> &students)
{

    foreach(auto value, students)
        Students->append(value);

}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);

    if(index.isValid())
        flags |= Qt::ItemIsEditable;
    return flags;
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::EditRole){
        Student student = Students->at(index.row());
        switch(index.column()){

            case sId:
                student.id = value.toInt();
                break;

            case sFIO:
                student.fio = value.toString();
                break;

            case sAge:
                student.age = value.toInt();
            break;

            case sGroup:
                student.group = value.toString();
            break;

        }

        Students->replace(index.row(), student);
        emit dataChanged( index, index );
        return true;
    }


    return false;
}

bool MyModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(QModelIndex(), Students->size(), Students->size());

    Students->append(Student(-1, "", 0, ""));
    endInsertRows();
}

bool MyModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(QModelIndex(), row, row);

    Students->removeAt(row);
    endRemoveRows();
}

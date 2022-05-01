#include "mytableview.h"


MytableView::MytableView()
{

}

void MytableView::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Return)
        this->model()->insertRows(0, 0, QModelIndex());
    if((event->key() == Qt::Key_Delete || event->key() == Qt::Key_Backspace)
            && !this->selectionModel()->selectedRows().isEmpty())
        this->model()->removeRows(this->selectionModel()->selectedRows().at(0).row(), 0, QModelIndex());
}

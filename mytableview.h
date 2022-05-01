#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include <QTableView>
#include <QKeyEvent>
#include <mymodel.h>

class MytableView : public QTableView
{
public:
    MytableView();

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);

};

#endif // MYTABLEVIEW_H

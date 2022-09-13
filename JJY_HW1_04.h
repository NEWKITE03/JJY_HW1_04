#pragma once

#include <QtWidgets/QMainWindow>
#include <qpainter.h>
#include <qevent.h>
#include <vector>
#include "Shape.h"
#include "ui_JJY_HW1_04.h"

class JJY_HW1_04 : public QMainWindow
{
    Q_OBJECT

public:
    JJY_HW1_04(QWidget *parent = nullptr);
    ~JJY_HW1_04();

protected:
    virtual void paintEvent(QPaintEvent* event) override;
    virtual void resizeEvent(QResizeEvent* event) override;

private:
    Ui::JJY_HW1_04 ui;
    std::vector<Shape*> shapes;
};

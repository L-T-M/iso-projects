#ifndef CHOOSEARCHITECTURE_H
#define CHOOSEARCHITECTURE_H

#include <QWidget>
#include <DLabel>
#include <QHBoxLayout>
#include <DFontSizeManager>

DWIDGET_USE_NAMESPACE

class chooseArchitecture : public QWidget
{
    Q_OBJECT
public:
    explicit chooseArchitecture(QWidget *parent = nullptr);
    ~chooseArchitecture();

signals:

public slots:

private:
    DLabel *m_pLabel;
};

#endif // CHOOSEARCHITECTURE_H

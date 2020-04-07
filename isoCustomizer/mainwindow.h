#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DApplication>
#include <DMainWindow>
#include <QWidget>
#include <DTitlebar>
#include <DStackedWidget>
#include <DListView>
#include <DGroupBox>
#include <QString>
#include <QDir>
#include <DMenu>
#include <QHash>

#include <DStandardPaths>
#include <QHBoxLayout>

#include "chooseiso.h"
#include "choosearchitecture.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
public:
    MainWindow(DMainWindow *parent = nullptr);
    ~MainWindow();

private:
    QWidget *m_pCentralWidget;
    QHash<QString, QWidget*> m_has_ItemName_ItemWiget;
    ChooseISO *m_pChooseISO;
    chooseArchitecture *m_pChooseArchitecture;
    DListView *m_pDlistView;
    DGroupBox *m_pGroupBox;
    DStackedWidget *m_pStackWidget;
    QHBoxLayout *m_pHBoxLayout;
    QString m_strConfDir;
    QString m_strConfPath;

public slots:
    void listViewItemClikedSlots(const QModelIndex &index);
private:
    void settingsInit();
};

#endif // MAINWINDOW_H

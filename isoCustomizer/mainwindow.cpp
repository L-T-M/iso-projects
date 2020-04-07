#include "mainwindow.h"
#include <QString>
#include <DTabBar>
#include <QStatusBar>

MainWindow::MainWindow(DMainWindow *parent)
    : DMainWindow(parent)
    , m_pDlistView(new DListView)
    , m_pGroupBox(new DGroupBox)
    , m_pStackWidget(new DStackedWidget)
    , m_pChooseISO(new ChooseISO)
    , m_pChooseArchitecture(new chooseArchitecture)
    , m_pCentralWidget(new QWidget)
{
    settingsInit();
    titlebar()->setIcon(QIcon::fromTheme("iso定制工具-16px",QIcon(":/images/iso定制工具-24px.svg")));
    const QString str = "ISO定制工具";
    titlebar()->setTitle(str);
    this->statusBar()->setSizeGripEnabled(true);

    m_pHBoxLayout = new QHBoxLayout;
    m_pHBoxLayout->addWidget(m_pDlistView,3);
    //m_pHBoxLayout->addWidget(m_pGroupBox);
    m_pHBoxLayout->addWidget(m_pStackWidget,8);

    QPalette pal(m_pDlistView->palette());
    pal.setColor(QPalette::Background, Qt::white);
    m_pDlistView->setAutoFillBackground(true);
    m_pDlistView->setPalette(pal);

    QStandardItemModel *pItemModel = new QStandardItemModel(this);
    QStandardItem *pItemSelectISO = new QStandardItem("选择ISO");
    m_pStackWidget->addWidget(m_pChooseISO);
    m_has_ItemName_ItemWiget.insert("选择ISO",m_pChooseISO);
    pItemModel->appendRow(pItemSelectISO);

    QStandardItem *pItemSelectArchitecture = new QStandardItem("选择架构");
    m_pStackWidget->addWidget(m_pChooseArchitecture);
    m_has_ItemName_ItemWiget.insert("选择架构",m_pChooseArchitecture);
    pItemModel->appendRow(pItemSelectArchitecture);


    m_pDlistView->setModel(pItemModel);
    m_pStackWidget->setCurrentWidget(m_pChooseISO);
    connect(m_pDlistView,&DListView::clicked,this,&MainWindow::listViewItemClikedSlots,Qt::QueuedConnection);
    m_pCentralWidget->setLayout(m_pHBoxLayout);
    setCentralWidget(m_pCentralWidget);

}

MainWindow::~MainWindow()
{

}

void MainWindow::listViewItemClikedSlots(const QModelIndex &index)
{
    QString strItemName = index.data().toString();
    m_pStackWidget->setCurrentWidget(m_has_ItemName_ItemWiget.value(strItemName));
}

void MainWindow::settingsInit()
{
    m_strConfDir =DStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    m_strConfPath = m_strConfDir + QDir::separator() + "iso-customizer";
}

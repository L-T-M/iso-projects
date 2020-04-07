#include "choosearchitecture.h"

chooseArchitecture::chooseArchitecture(QWidget *parent)
    : QWidget(parent)
    , m_pLabel(new DLabel)
{
    QHBoxLayout *p_MainLayout = new QHBoxLayout(this);
    QVBoxLayout *pVBoxLayout = new QVBoxLayout;
    pVBoxLayout->addSpacing(20);

    m_pLabel->setText("选择架构");
    QFont font;
    font.setBold(true);
    m_pLabel->setFont(font);
    DFontSizeManager::instance()->bind(m_pLabel, DFontSizeManager::T3);
    pVBoxLayout->addWidget(m_pLabel);
    pVBoxLayout->addStretch();

    p_MainLayout->addLayout(pVBoxLayout);
}

chooseArchitecture::~chooseArchitecture()
{

}

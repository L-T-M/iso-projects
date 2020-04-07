#include "chooseiso.h"

ChooseISO::ChooseISO(QWidget *parent)
    : QWidget (parent)
    , m_pLabel (new DLabel)
    , m_pFileChooseEdit (new DFileChooserEdit)
    , m_pButton(new DPushButton)
{
    QHBoxLayout *p_MainLayout = new QHBoxLayout(this);
    QVBoxLayout *pVBoxLayout = new QVBoxLayout;
    pVBoxLayout->addSpacing(20);

    m_pLabel->setText("选择ISO");
    QFont font;
    font.setBold(true);
    m_pLabel->setFont(font);
    DFontSizeManager::instance()->bind(m_pLabel, DFontSizeManager::T3);
    pVBoxLayout->addWidget(m_pLabel);
    pVBoxLayout->setSpacing(10);

    pVBoxLayout->addWidget(m_pFileChooseEdit);
    pVBoxLayout->addStretch();

    QHBoxLayout *pHBoxLayout = new QHBoxLayout;
    pHBoxLayout->addSpacing(147);
    m_pButton->setText("下一步");
    m_pButton->setMinimumWidth(260);
    pHBoxLayout->addWidget(m_pButton);
    pHBoxLayout->addStretch();

    pVBoxLayout->addLayout(pHBoxLayout);
    p_MainLayout->addSpacing(30);
    p_MainLayout->addLayout(pVBoxLayout);
    p_MainLayout->addSpacing(30);
}

ChooseISO::~ChooseISO()
{

}

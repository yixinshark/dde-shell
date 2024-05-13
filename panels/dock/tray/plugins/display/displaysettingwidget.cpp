// Copyright (C) 2021 ~ 2022 Uniontech Software Technology Co.,Ltd.
// SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "displaysettingwidget.h"
#include "settingbutton.h"

#include <QPushButton>
#include <QVBoxLayout>

#include <DDBusSender>

const int ItemSpacing = 10;

DisplaySettingWidget::DisplaySettingWidget(BrightnessModel *model, QWidget *parent)
    : QWidget(parent)
    , m_brightnessAdjWidget(new BrightnessAdjWidget(model, this))
    , m_settingBtn(new SettingButton(tr("Display Settings"), this))
{
    initUI();
    connect(m_settingBtn, &SettingButton::clicked, this, [ this ](){
        DDBusSender().service("org.deepin.dde.ControlCenter1")
            .path("/org/deepin/dde/ControlCenter1")
            .interface("org.deepin.dde.ControlCenter1")
            .method("ShowPage").arg(QString("display")).call();
        Q_EMIT requestHide();
    });
}

void DisplaySettingWidget::initUI()
{
    setContentsMargins(10, 10, 10, 10);
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(ItemSpacing);

    mainLayout->addWidget(m_brightnessAdjWidget);
    mainLayout->addWidget(m_settingBtn);
    mainLayout->addStretch();

    setLayout(mainLayout);

    resizeWidgetHeight();
    connect(m_brightnessAdjWidget, &BrightnessAdjWidget::sizeChanged,
            this, &DisplaySettingWidget::resizeWidgetHeight);
}

void DisplaySettingWidget::resizeWidgetHeight()
{
    QMargins margins = this->contentsMargins();
    setFixedHeight(margins.top() + margins.bottom() + m_brightnessAdjWidget->height() +
                   m_settingBtn->height() + ItemSpacing);
}

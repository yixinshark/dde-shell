// Copyright (C) 2015 ~ 2018 Deepin Technology Co., Ltd.
// SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -c DBusAccount -p dbusaccount org.deepin.dde.Accounts1.xml
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "dbusaccount.h"

/*
 * Implementation of interface class DBusAccount
 */

DBusAccount::DBusAccount(QObject *parent)
    : QDBusAbstractInterface(staticService(), staticInterfacePath(), staticInterfaceName(), QDBusConnection::systemBus(), parent)
{
    QDBusConnection::systemBus().connect(this->service(), this->path(), "org.freedesktop.DBus.Properties",  "PropertiesChanged","sa{sv}as", this, SLOT(__propertyChanged__(QDBusMessage)));
}

DBusAccount::~DBusAccount()
{
    QDBusConnection::systemBus().disconnect(service(), path(), "org.freedesktop.DBus.Properties",  "PropertiesChanged",  "sa{sv}as", this, SLOT(propertyChanged(QDBusMessage)));
}
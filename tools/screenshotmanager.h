/*
 * Copyright (C) 2011  Christian Kaiser
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
#ifndef SCREENSHOTMANAGER_H
#define SCREENSHOTMANAGER_H

#include <QObject>
#include <QList>

#include "screenshot.h"

class QSettings;
class ScreenshotManager : public QObject
{
  Q_OBJECT

public:
  enum State
  {
    Idle  = 0,
    Busy = 1,
    Disabled  = 2
  };

public:
  ScreenshotManager(QObject *parent);
  ~ScreenshotManager();
  static ScreenshotManager *instance();

  void setCount(const unsigned int c){ mCount = c; }
  unsigned int count() const { return mCount; }
  QSettings *settings() const { return mSettings; }

public slots:
  void take(Screenshot::Options &options);
  void askConfirmation();
  void cleanup();

signals:
  void confirm(Screenshot* screenshot);
  void windowCleanup(Screenshot::Options &options);

private:
  static ScreenshotManager* mInstance;
  QSettings *mSettings;
  int mCount; // Concurrent screenshot count.

};

#endif // SCREENSHOTMANAGER_H

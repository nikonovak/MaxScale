/*
 * Copyright (c) 2016 MariaDB Corporation Ab
 *
 * Use of this software is governed by the Business Source License included
 * in the LICENSE.TXT file and at www.mariadb.com/bsl11.
 *
 * Change Date: 2019-07-01
 *
 * On the date above, in accordance with the Business Source License, use
 * of this software will be governed by version 2 or later of the General
 * Public License.
 */

#include "maxscale/workertask.hh"
#include <maxscale/atomic.h>

namespace maxscale
{

//
// WorkerTask
//
WorkerTask::~WorkerTask()
{
}

//
// WorkerDisposableTask
//
WorkerDisposableTask::WorkerDisposableTask()
    : m_count(0)
{
}

void WorkerDisposableTask::inc_count()
{
    atomic_add(&m_count, 1);
}

void WorkerDisposableTask::dec_count()
{
    if (atomic_add(&m_count, -1) == 1)
    {
        delete this;
    }
}

}

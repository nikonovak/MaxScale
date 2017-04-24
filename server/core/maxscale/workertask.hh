#pragma once
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

#include <maxscale/cppdefs.hh>

namespace maxscale
{

class Worker;

/**
 * A WorkerTask represents a task to be performed by a Worker.
 */
class WorkerTask
{
public:
    /**
     * Destructor
     */
    virtual ~WorkerTask();

    /**
     * @brief Called in the context of a specific worker.
     *
     * @param worker  The worker in whose context `execute` is called.
     *
     * @attention As the function is called by a worker, the body of `execute`
     *            should execute quickly and not perform any blocking operations.
     */
    virtual void execute(Worker& worker) = 0;
};

/**
 * A WorkerDisposableTask represents a task to be performed by a Worker.
 *
 * When the task has been executed, the instance will automatically be
 * deleted.
 */
class WorkerDisposableTask : public WorkerTask
{
protected:
    WorkerDisposableTask();

private:
    friend class Worker;

    void inc_count();
    void dec_count();

private:
    int32_t m_count;
};

}

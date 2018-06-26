#include <abt.h>
#include "thallium/abt_errors.hpp"

namespace thallium {

static const char* const abt_errors[] = {
"ABT_SUCCESS",                  "Successful return code",
"ABT_ERR_UNINITIALIZED",        "Uninitialized",
"ABT_ERR_MEM",                  "Memory allocation failure",
"ABT_ERR_OTHER",                "Other error",
"ABT_ERR_INV_XSTREAM",          "Invalid ES",
"ABT_ERR_INV_XSTREAM_RANK",     "Invalid ES rank",
"ABT_ERR_INV_XSTREAM_BARRIER",  "Invalid ES barrier",
"ABT_ERR_INV_SCHED",            "Invalid scheduler",
"ABT_ERR_INV_SCHED_KIND",       "Invalid scheduler kind",
"ABT_ERR_INV_SCHED_PREDEF",     "Invalid predefined scheduler",
"ABT_ERR_INV_SCHED_TYPE",       "Invalid scheduler type",
"ABT_ERR_INV_SCHED_CONFIG",     "Invalid scheduler config",
"ABT_ERR_INV_POOL",             "Invalid pool",
"ABT_ERR_INV_POOL_KIND",        "Invalid pool kind",
"ABT_ERR_INV_POOL_ACCESS",      "Invalid pool access mode",
"ABT_ERR_INV_UNIT",             "Invalid scheduling unit",
"ABT_ERR_INV_THREAD",           "Invalid ULT",
"ABT_ERR_INV_THREAD_ATTR",      "Invalid ULT attribute",
"ABT_ERR_INV_TASK",             "Invalid tasklet",
"ABT_ERR_INV_KEY",              "Invalid key",
"ABT_ERR_INV_MUTEX",            "Invalid mutex",
"ABT_ERR_INV_MUTEX_ATTR",       "Invalid mutex attribute",
"ABT_ERR_INV_COND",             "Invalid condition variable",
"ABT_ERR_INV_RWLOCK",           "Invalid rw lock",
"ABT_ERR_INV_EVENTUAL",         "Invalid eventual",
"ABT_ERR_INV_FUTURE",           "Invalid future",
"ABT_ERR_INV_BARRIER",          "Invalid barrier",
"ABT_ERR_INV_TIMER",            "Invalid timer",
"ABT_ERR_INV_EVENT",            "Invalid event",
"ABT_ERR_XSTREAM",              "ES-related error",
"ABT_ERR_XSTREAM_STATE",        "ES state error",
"ABT_ERR_XSTREAM_BARRIER",      "ES barrier-related error",
"ABT_ERR_SCHED",                "Scheduler-related error",
"ABT_ERR_SCHED_CONFIG",         "Scheduler config error",
"ABT_ERR_POOL",                 "Pool-related error",
"ABT_ERR_UNIT",                 "Scheduling unit-related error",
"ABT_ERR_THREAD",               "ULT-related error",
"ABT_ERR_TASK",                 "Task-related error",
"ABT_ERR_KEY",                  "Key-related error",
"ABT_ERR_MUTEX",                "Mutex-related error",
"ABT_ERR_MUTEX_LOCKED",         "Return value when mutex is locked",
"ABT_ERR_COND",                 "Condition-related error",
"ABT_ERR_COND_TIMEDOUT",        "Return value when cond is timed out",
"ABT_ERR_RWLOCK",               "Rwlock-related error",
"ABT_ERR_EVENTUAL",             "Eventual-related error",
"ABT_ERR_FUTURE",               "Future-related error",
"ABT_ERR_BARRIER",              "Barrier-related error",
"ABT_ERR_TIMER",                "Timer-related error",
"ABT_ERR_EVENT",                "Event-related error",
"ABT_ERR_MIGRATION_TARGET",     "Migration target error",
"ABT_ERR_MIGRATION_NA",         "Migration not available",
"ABT_ERR_MISSING_JOIN",         "An ES or more did not join",
"ABT_ERR_FEATURE_NA",           "Feature not available"
};

const char* abt_error_get_name(int err) {
    return abt_errors[err*2];
}

const char* abt_error_get_description(int err) {
    return abt_errors[err*2+1];
}

}
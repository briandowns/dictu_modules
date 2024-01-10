#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int64_t Duration;

Duration microseconds(const Duration d) {
    return (Duration)d * 1e3;
}

Duration milliseconds(const Duration d) {
    return (Duration)d * 1e6;
}

Duration parseDuration(const char *s) {
    // convert strings like "1s" to a duration of 1 second
    Duration d;
    return d;
}

typedef struct {
    int64_t wall;
    int64_t mono;
} DateTime;

DateTime now() {
    struct timespec wall, mono;

    clock_gettime(CLOCK_MONOTONIC, &mono);
    clock_gettime(CLOCK_REALTIME, &wall);

    DateTime dt;
    dt.mono = mono.tv_sec;
    dt.wall = wall.tv_sec;

    return dt;
}

DateTime add(const DateTime dt, Duration d) {
    DateTime ndt;
    ndt.wall += dt.wall;
    return ndt;
}

DateTime sub(const DateTime dt, Duration d) {
    DateTime ndt;
    ndt.wall -= dt.wall;
    return ndt;
}

Duration since(const DateTime dt, const Duration d) {
    DateTime ndt = sub(now(), d);
    return (Duration)ndt.wall;
}

int main(void) {
    const char *timestamp = "1901-06-25 05:32:06.963";

    struct tm tm;
    time_t epoch;
    if ( strptime(timestamp, "%Y-%m-%d %H:%M:%S", &tm) != NULL )
        epoch = mktime(&tm);

    printf("%lld\n", (int64_t)epoch);
    DateTime dt = now();

    return 0;
}
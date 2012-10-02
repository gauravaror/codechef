#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

uint8_t g_buffer[256 * 1024];

int main() {
    uint8_t *const pbegin = g_buffer;
    uint8_t *pend;
    uint8_t *p = g_buffer;
    unsigned int in, ik, n = 0;
    pend = pbegin + read(0, p, sizeof(g_buffer));
    for (in = 0; *p >= '0' && *p <= '9'; ++p) in = in * 10 + (*p - '0');
    for (; *p < '0' || *p > '9'; ++p);
    for (ik = 0; *p >= '0' && *p <= '9'; ++p) ik = ik * 10 + (*p - '0');
    for (; (p < pend) && (*p < '0' || *p > '9'); ++p);
    for (unsigned int i = 0, v; i < in; ++i) {
        if (pend - p < 16) {
            memcpy(pbegin, p, pend - p);
            pend = pbegin + (pend - p) + read(0, pbegin + (pend - p), sizeof(g_buffer) - (pend - p));
            p = pbegin;
        }
        v = 0;
        if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
            if (*p >= '0' && *p <= '9') { v = v * 10 + (*p++ - '0');
        }}}}}}}}}}
        if (*p < '0' || *p > '9') { ++p;
            if (*p < '0' || *p > '9') { ++p;
        }}
        if (v % ik == 0) ++n;
    }
    printf("%u\n", n);
    return 0;
}

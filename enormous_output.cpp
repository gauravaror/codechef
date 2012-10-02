#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
uint32_t clog2(uint32_t n) {
for (uint32_t i = 0;; ++i, n >>= 1) if (!n) return i;
}
 
void InitFastDiv(uint32_t d, uint32_t *m, uint32_t *s) {
uint32_t l = clog2(d - 1);
*m = static_cast<uint32_t>((0x100000000ULL << l) / d - 0xffffffffUL);
*s = l;
}
 
uint32_t FastDiv(uint32_t n, uint32_t m, uint32_t s, uint32_t d) {
uint32_t t;
asm("mull %[n]\n" : [t] "=d" (t), [m] "+a" (m) : [n] "r" (n));
return (t + n) >> s;
}
 
uint8_t __restrict__ g_buffer[32768 + 4];
 
int main() {
unsigned int in, ik, n = 0;
unsigned int off = 0, bsize;
bsize = read(0, g_buffer, sizeof(g_buffer));
for (in = 0; g_buffer[off] >= '0'; ++off) in = in * 10 + (g_buffer[off] - '0');
for (; g_buffer[off] < '0'; ++off);
for (ik = 0; g_buffer[off] >= '0'; ++off) ik = ik * 10 + (g_buffer[off] - '0');
for (; g_buffer[off] < '0'; ++off);

 
if (ik == 1) {
printf("%u\n", in);
return 0;
}
 
uint32_t m, s;
InitFastDiv(ik, &m, &s);
uint32_t v = 0;
for (; off % 4; ++off) {
if (g_buffer[off] >= '0') v = v * 10 + g_buffer[off] - 48;
else {
n += (v == FastDiv(v, m, s, ik) * ik);
v = 0;
}
}
do {
for (; off + 3 < bsize; off += 4) {
uint32_t h = *((uint32_t *) (g_buffer + off)) & 0x20202020;
if (h >= 0x20002020) {
if (h >= 0x20202000) {
if (h == 0x20202020) {
v = v * 10000 + g_buffer[off] * 1000 + g_buffer[off + 1] * 100 + g_buffer[off + 2] * 10 + g_buffer[off + 3] - 53328;
} else {
n += (v == FastDiv(v, m, s, ik) * ik);
v = g_buffer[off + 1] * 100 + g_buffer[off + 2] * 10 + g_buffer[off + 3] - 5328;
}
} else {
if (h == 0x20200020) {
v = v * 10 + g_buffer[off] - 48;
n += (v == FastDiv(v, m, s, ik) * ik);
v = g_buffer[off + 2] * 10 + g_buffer[off + 3] - 528;
} else {
v = v * 100 + g_buffer[off] * 10 + g_buffer[off + 1] - 528;
n += (v == FastDiv(v, m, s, ik) * ik);
v = g_buffer[off + 3] - 48;
}
}
} else {
if (h >= 0x00202020) {
if (h == 0x20002000) {
n += (v == FastDiv(v, m, s, ik) * ik);
v = g_buffer[off + 1] - 48;
n += (v == FastDiv(v, m, s, ik) * ik);
v = g_buffer[off + 3] - 48;
} else {
v = v * 1000 + g_buffer[off] * 100 + g_buffer[off + 1] * 10 + g_buffer[off + 2] - 5328;
n += (v == FastDiv(v, m, s, ik) * ik);
v = 0;
}
} else {
if (h == 0x00202000) {
n += (v == FastDiv(v, m, s, ik) * ik);
v = g_buffer[off + 1] * 10 + g_buffer[off + 2] - 528;
n += (v == FastDiv(v, m, s, ik) * ik);
v = 0;
} else {
v = v * 10 + g_buffer[off] - 48;
n += (v == FastDiv(v, m, s, ik) * ik);
v = g_buffer[off + 2] - 48;
n += (v == FastDiv(v, m, s, ik) * ik);
v = 0;
}
}
}
}
if (off != bsize) {
for (; off < bsize; ++off) {
if (g_buffer[off] >= '0') v = v * 10 + g_buffer[off] - 48;
else {
n += (v == FastDiv(v, m, s, ik) * ik);
v = 0;
}
}
}
int r = read(0, g_buffer, sizeof(g_buffer));
bsize = r <= 0 ? 0 : r;
off = 0;
} while (bsize != 0);
printf("%u\n", n);
return 0;
}

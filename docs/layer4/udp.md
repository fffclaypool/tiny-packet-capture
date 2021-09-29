### udphdr構造体

/usr/include/netinet/udp.h

```c
struct udphdr
{
  u_int16_t uh_sport;           /* source port */
  u_int16_t uh_dport;           /* destination port */
  u_int16_t uh_ulen;            /* udp length */
  u_int16_t uh_sum;             /* udp checksum */
};
```

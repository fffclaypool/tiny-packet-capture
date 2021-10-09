<img width="840" src="https://user-images.githubusercontent.com/43327056/136646333-35ca223f-30c2-4a72-8d5c-3b4e403b9223.png">

/usr/include/netinet/udp.h

```c
struct udphdr
{
  u_int16_t source;
  u_int16_t dest;
  u_int16_t len;
  u_int16_t check;
};
```

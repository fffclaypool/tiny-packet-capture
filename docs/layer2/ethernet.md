### ether_header構造体

/usr/include/net/ethernet.h

```c
struct ether_header
{
  u_int8_t  ether_dhost[ETH_ALEN];      /* destination eth addr */
  u_int8_t  ether_shost[ETH_ALEN];      /* source ether addr    */
  u_int16_t ether_type;                 /* packet type ID field */
} __attribute__ ((__packed__));
```
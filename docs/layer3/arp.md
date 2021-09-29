### ether_arp構造体

/usr/include/netinet/if_ether.h

```c
struct  ether_arp {
        struct  arphdr ea_hdr;          /* fixed-size header */
        u_int8_t arp_sha[ETH_ALEN];     /* sender hardware address */
        u_int8_t arp_spa[4];            /* sender protocol address */
        u_int8_t arp_tha[ETH_ALEN];     /* target hardware address */
        u_int8_t arp_tpa[4];            /* target protocol address */
};
```

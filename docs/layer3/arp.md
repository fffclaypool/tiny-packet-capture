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

/usr/include/linux/if_ether.h

```c
#define ETH_ALEN        6               /* Octets in one ethernet addr   */
```

/usr/include/net/if_arp.h

```c
struct arphdr
  {
    unsigned short int ar_hrd;          /* Format of hardware address.  */
    unsigned short int ar_pro;          /* Format of protocol address.  */
    unsigned char ar_hln;               /* Length of hardware address.  */
    unsigned char ar_pln;               /* Length of protocol address.  */
    unsigned short int ar_op;           /* ARP opcode (command).  */
#if 0
    /* Ethernet looks like this : This bit is variable sized
       however...  */
    unsigned char __ar_sha[ETH_ALEN];   /* Sender hardware address.  */
    unsigned char __ar_sip[4];          /* Sender IP address.  */
    unsigned char __ar_tha[ETH_ALEN];   /* Target hardware address.  */
    unsigned char __ar_tip[4];          /* Target IP address.  */
#endif
  };
```
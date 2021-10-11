<img width="840" src="https://user-images.githubusercontent.com/43327056/136646334-12cd38ce-df76-49e0-a816-0aa0000edd31.png">

/usr/include/netinet/ip.h

```c
struct ip
  {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned int ip_hl:4;               /* header length */
    unsigned int ip_v:4;                /* version */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned int ip_v:4;                /* version */
    unsigned int ip_hl:4;               /* header length */
#endif
    u_int8_t ip_tos;                    /* type of service */
    u_short ip_len;                     /* total length */
    u_short ip_id;                      /* identification */
    u_short ip_off;                     /* fragment offset field */
#define IP_RF 0x8000                    /* reserved fragment flag */
#define IP_DF 0x4000                    /* dont fragment flag */
#define IP_MF 0x2000                    /* more fragments flag */
#define IP_OFFMASK 0x1fff               /* mask for fragmenting bits */
    u_int8_t ip_ttl;                    /* time to live */
    u_int8_t ip_p;                      /* protocol */
    u_short ip_sum;                     /* checksum */
    struct in_addr ip_src, ip_dst;      /* source and dest address */
  };
```

/usr/include/netinet/in.h

```c
typedef uint32_t in_addr_t;
struct in_addr
  {
    in_addr_t s_addr;
  };
```

| field | member variable | count of bits | overview |
| --- | --- | --- | --- |
| version | ip_v | 4 | バージョン |
| header length | ip_hl | 4 | ヘッダー長 |
| type of service | ip_tos | 8 | サービスのタイプ |
| total length | ip_len | 16 | パケット長 |
| identification | ip_id | 16 | 識別子 |
| fragment offset field | ip_off | 16 | フラグメントオフセット |
| time to live | ip_ttl | 8 | TTL(Time To Live) |
| protocol | ip_p | 8 | プロトコル番号 |
| checksum | ip_sum | 16 | ヘッダーチェックサム |
| source address | source | 32 | 送信元IPアドレス |
| dest address | dest | 32 | 宛先IPアドレス |

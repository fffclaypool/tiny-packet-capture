<img width="840" src="https://user-images.githubusercontent.com/43327056/136646338-66448b52-b03c-42d3-9f0b-0261e8afe9ec.png">

/usr/include/net/ethernet.h

```c
struct ether_header
{
  u_int8_t  ether_dhost[ETH_ALEN];      /* destination eth addr */
  u_int8_t  ether_shost[ETH_ALEN];      /* source ether addr    */
  u_int16_t ether_type;                 /* packet type ID field */
} __attribute__ ((__packed__));
```

| field | member variable | count of bits | overview |
| --- | --- | --- | --- |
| destination eth addr | ether_dhost | 48 | 宛先MACアドレス |
| source ether addr | ether_shost | 48 | 送信元MACアドレス |
| packet type ID field | ether_type | 16 | タイプ |

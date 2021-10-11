<img width="840" src="https://user-images.githubusercontent.com/43327056/136646330-fd12335c-fd8f-4305-a46f-ab348f1c7e54.png">

/usr/include/netinet/tcp.h

```c
struct tcphdr
  {
    u_int16_t source;
    u_int16_t dest;
    u_int32_t seq;
    u_int32_t ack_seq;
#  if __BYTE_ORDER == __LITTLE_ENDIAN
    u_int16_t res1:4;
    u_int16_t doff:4;
    u_int16_t fin:1;
    u_int16_t syn:1;
    u_int16_t rst:1;
    u_int16_t psh:1;
    u_int16_t ack:1;
    u_int16_t urg:1;
    u_int16_t res2:2;
#  elif __BYTE_ORDER == __BIG_ENDIAN
    u_int16_t doff:4;
    u_int16_t res1:4;
    u_int16_t res2:2;
    u_int16_t urg:1;
    u_int16_t ack:1;
    u_int16_t psh:1;
    u_int16_t rst:1;
    u_int16_t syn:1;
    u_int16_t fin:1;
#  else
#   error "Adjust your <bits/endian.h> defines"
#  endif
    u_int16_t window;
    u_int16_t check;
    u_int16_t urg_ptr;
};
```

| field | member variable | count of bits | overview |
| --- | --- | --- | --- |
| source port | source | 16 | 送信元ポート番号の値 |
| destination port | dest | 16 | 宛先のポート番号の値 |
| sequence number | seq | 32 | シーケンス番号 |
| acknowledgement number | ack_seq | 32 | 確認応答番号 |
| data offset | doff | 4 | データオフセット |
| reserved | res1 | 4 | 予約領域 |
| reserved | res2 | 2 | 予約領域 |
| URG | urg | 1 | 緊急を表すフラグ |
| ACK | ack | 1 | 確認応答を表すフラグ |
| PSH | psh | 1 | 速やかにアプリケーションにデータを渡すフラグ |
| RST | rst | 1 | コネクションを強制切断するフラグ |
| SYN | syn | 1 | コネクションを開始するフラグ |
| FIN | fin | 1 | コネクションを終了するフラグ |
| window | window | 16 | 受信ウィンドウ |
| checksum  | check | 16 | チェックサム |
| urgent pointer  | urg_ptr | 16 | 緊急ポインタ |

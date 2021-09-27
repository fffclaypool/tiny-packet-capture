#include <iostream>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXSIZE 8192

class Socket
{
public:
    int generate();
};

int Socket::generate()
{
    int sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock_raw < 0)
    {
        perror("socket");
        return -1;
    }
    struct sockaddr_ll sa;
    sa.sll_family = AF_PACKET;
    sa.sll_protocol = htons(ETH_P_ALL);
    sa.sll_ifindex = if_nametoindex("packet-capture");
    if (bind(sock_raw, (struct sockaddr *)&sa, sizeof(sa)) < 0)
    {
        perror("bind");
        return -1;
    }
    return sock_raw;
}

int main()
{
    while (1)
    {
        Socket socket;
        char buff[MAXSIZE];
        if (read(socket.generate(), buff, MAXSIZE) < 0)
        {
            perror("read");
            return -1;
        }

        char *p = buff;
        struct ether_header *eth = (struct ether_header *)p; // print_ethernet
        p += sizeof(struct ether_header);

        switch (ntohs(eth->ether_type))
        {
        case ETHERTYPE_ARP:
        {
            struct ether_arp *arp = (struct ether_arp *)p; // print_arp
            std::cout << "arp" << std::endl;
            break;
        }
        case ETHERTYPE_IP:
        {
            struct ip *ip = (struct ip *)p; // print_ip
            p += ((int)(ip->ip_hl) << 2);
            std::cout << "ip" << std::endl;

            switch (ip->ip_p)
            {
            case IPPROTO_TCP:
            {
                struct tcphdr *tcp = (struct tcphdr *)p; // print_tcp
                p += ((int)(tcp->doff) << 2);
                std::cout << "tcp" << std::endl;
                break;
            }
            case IPPROTO_UDP:
            {
                struct udphdr *udp = (struct udphdr *)p; // print_udp
                p += sizeof(struct udphdr);
                std::cout << "udp" << std::endl;
                break;
            }
            case IPPROTO_ICMP:
            {
                struct icmp *icmp = (struct icmp *)p; // print_icmp
                p = (char *)icmp->icmp_data;
                std::cout << "icmp" << std::endl;
                break;
            }
            default:
                break;
            }
            break;
        }
        }
    }
    return 0;
}

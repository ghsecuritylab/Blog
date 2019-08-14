#include "lwip_app.h"
#include "mem.h"
#include "string.h"
struct netif enc28j60_netif;
//#define USE_DHCP
void Lwip_init(void)
{
	//����ip�����ء����������ַ�ṹ��
	 ip4_addr_t ip_addr,gw_addr,netmask;
	
	//��ʼ��lwip�ں�
	lwip_init();
	printf("lwip_init success\n");
#ifdef USE_DHCP	
	//���ip�����ء����������ַ
	ip4_addr_set_zero(&ip_addr);
	ip4_addr_set_zero(&gw_addr);
	ip4_addr_set_zero(&netmask);
#else
    IP4_ADDR(&ip_addr, 192,168,1,37);
	IP4_ADDR(&gw_addr, 192,168,1,1);
	IP4_ADDR(&netmask, 255,255,255,0);
#endif	
	//������ڵ�Ĭ������
	netif_add(&enc28j60_netif,&ip_addr,&netmask,&gw_addr,NULL,ethernetif_init,ethernet_input);
	netif_set_default(&enc28j60_netif);
	netif_set_up(&enc28j60_netif);

//    dhcp_start(&enc28j60_netif);
}

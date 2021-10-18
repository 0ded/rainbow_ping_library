#ifndef rainbow_ping
#define rainbow_ping

void chars_2_IPV4(char * ip_str, unsigned char * ipv4 );
void char_2_ip_part(char * str, unsigned char ip_part);
int ping_IPV4(char * ipv4, int ping_amount, char mute);
void command_add_amount(char * command, int amount);
void command_mute(char * command);
int next_ip(unsigned char ip[4], unsigned char end_ip[4]);
int compare_ip(char ip1[4], char ip2[4]);
void copy_ip(char target[4], char origin[4]);
int ping_next_IPV4(char ip_start[4], char end_ip[4] );
#endif
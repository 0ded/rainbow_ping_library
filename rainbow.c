#include "rainbow.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int ping_next_IPV4(char ip_start[4], char end_ip[4])
{
	int code = ping_IPV4(ip_start, 1, 1);

	if(!next_ip(ip_start, end_ip))
	{
		return -1;
	}
	return code;
}

//mute not 0 to mute
int ping_IPV4(char * ipv4, int ping_amount, char mute)
{
	char command[64] = "ping ";
	command_add_amount(command, ping_amount);
	chars_2_IPV4(command, ipv4);
	//strcat(command, ipv4);
	if(mute != 0)
	{
		command_mute(command);
	}
	else
	{
		printf("%s\r\n", command);
	}
	int code = system(command);
	return code;
}


int next_ip(unsigned char ip[4], unsigned char end_ip[4])
{
	if(compare_ip(ip, end_ip))
	{
		return 0;
	}
	ip[3] = ip[3] + 1;
	for(int i = 3; i >= 0 && (ip[i]) == 255; i--)
	{
		ip[i] = 0;
		ip[i-1] = ip[i-1] + 1;
	}

	return 1;
}


void copy_ip(char target[4], char origin[4])
{
	for(int i = 0; i < 4; i++)
	{
		target[i] = origin[i];
	}
}


void char_2_ip_part(char * str, unsigned char ip_part)
{
	char str_part[14];
	sprintf(str_part, "%u", ip_part);
	strcat(str, str_part);
}


//
void chars_2_IPV4(char * ip_str, unsigned char * ipv4 )
{
	for(int i = 0; i < 4; i++)
	{
		char_2_ip_part(ip_str, ipv4[i]);
		if(i != 3)
		{
			strcat(ip_str, ".");
		}
	}
}


void command_add_amount(char * command, int amount)
{
	if(amount <= 0)
	{
		amount = 1;
	}
	if(amount > 999)
	{
		amount = 999;
	}
	#ifdef __linux__
	strcat(command, "-c 1 -t ");
	#elif __WIN32
	strcat(command, "-t ");
	#endif
	char str_amount[14];
	sprintf(str_amount, "%d ", amount);
	strcat(command, str_amount);
}


void command_mute(char * command)
{
	#ifdef __linux__
	strcat(command, " > /dev/null");
	#elif __WIN32
	strcat(command, " > null");
	#endif
}


int compare_ip(char ip1[4], char ip2[4])
{
	if(ip1[0] == ip2[0] && ip1[1] == ip2[1]
		&& ip1[2] == ip2[2] && ip1[3] == ip2[3])
	{
		return 1;
	}
	return 0;
}

#ifndef RULES_H
#define RULES_H


#define MAX_RULES 100

typedef struct{
  char ip[16];    // ipv4
  int port;       // puerto
  int protocolo;  // 6 = tcp, 17 = udp
  int action;     // 0 = BLOCK, 1 = ALLOW
} Rule;

void add_rule(conts char *ip, int port, int protocol, int action);
void list_rules();
int should_block(conts char *ip, int port, int protocol);


#endif


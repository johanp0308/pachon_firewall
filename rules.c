#include "rules.h"
#include <stdio.h>
#include <string.h>

static Rule rules[MAX_RULES];
static int rule_count = 0;

void add_rule(const char *ip, int port, int protocol, int action){
  if(rule_count >= MAX_RULES){
    printf("Regla no añadida: limite alcanzado. \n");
    return;
  }

  Rule r;

  strncpy(r.ip, ip, sizeof(r.ip));
  r.port = port;
  r.protocol = protocol;
  r.action = action;
  rules[rule_count++] = r;
}

void list_rules(){
  printf("Relgas cargadas:\n");
  for(int i = 0; i < rule_count; i++){
    printf("[%d] IP: %s, Puerto: %d, Protocol: %d, Accion: %s\n",
       i,
       rules[i].ip,
       rules[i].port,
       rules[i].protocol,
       rules[i].action == 0 ? "Block" : "Allow");
  }
}

int should_block(const char *ip, int port, int protocol){
  for (int i = 0; i < rule_count; i++){
    if(strcmp(rules[i].ip, ip) == 0 &&
      rules[i].port == port &&
      rules[i].protocol == protocol){
      return rules[i].action == 0;
    }
  }

  return 0;
}

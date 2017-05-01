#include <unistd.h>
#include <sys/types.h>
#include <string>
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "server_base.h"

const char* sim_IP = "10.236.48.17";
const char* sim_PORT = "23456";
const char* au_PORT =  "34567";

int main(int argc, char* argv[]){
  if(argc < 4){
    std::cerr<<"usage: ./server <purchase_id to start> <worldid> <num_wh>\n";
    exit(1);
  }
  int purchase_id = atoi(argv[1]);
  int worldid = atoi(argv[2]);
  int wh_count = atoi(argv[3]);

  // connect to database
  // connection* C = create_connection();
  
  
  // connect to sim
  int sockfd, numbytes;  
  struct addrinfo hints, *servinfo, *p;
  int rv;
  char s[INET6_ADDRSTRLEN];
  set_hints(&hints);
  get_addr_info(&hints, &servinfo, &rv, sim_PORT, sim_IP);  
  connect_sock(&servinfo, sockfd,  s);


  
  // accept connection from UPS
  int sockfd_server, new_fd;  // listen on sock_fd, new connection on new_fd
  struct addrinfo hints_server;
  struct addrinfo* servinfo_server;
  struct sockaddr_storage their_addr_server; // connector's address information
  socklen_t sin_size_server;
  struct sigaction sa_server;
  int yes_server=1;
  char s_server[INET6_ADDRSTRLEN];
  int rv_server;
  

  set_socket(&hints_server);
  get_addr_info_server(&hints_server, &servinfo_server, &rv_server, au_PORT);
  bind_sock(&servinfo_server, &sockfd_server, &yes_server);
  listen_sock(&sockfd_server);
  sigaction(&sa_server);
  printf("server: waiting for connections from UPS...\n");            

  new_fd = accept_sock(sockfd_server, their_addr_server);
  while(new_fd == -1){
    new_fd = accept_sock(sockfd_server, their_addr_server);
  }

  return 0;
}
